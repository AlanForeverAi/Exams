#include"server.h"
#include<QThread>

/*
Server类构造函数
参数port为构造时传进来的端口信息，
调用listen函数在port端口上监听所有进来的连接，
如果监听失败则退出
*/
Server::Server(QObject *parent, int port): QTcpServer(parent)
{
    if( !listen(QHostAddress::Any,port) )
    {
        qDebug("server start fail!");
        exit(2);
    }
    qDebug("server start!");
}

/*新连接进入处理函数*/
void Server::incomingConnection(int socketDescriptor)
{
    ServerThread *thread=new ServerThread(socketDescriptor,this);
    /*当线程完成执行时，自动销毁*/
    connect(thread,SIGNAL(finished()),thread,SLOT(deleteLater()));
    /*连接消息到达信号*/
    connect(thread,SIGNAL(messageArrive(int,qint32,QVariant)),
            this,SIGNAL(messageArrive(int,qint32,QVariant)));
    /*连接消息发送信号*/
    connect(this,SIGNAL(sendData(int,qint32,QVariant)),
            thread,SIGNAL(sendData(int,qint32,QVariant)),Qt::DirectConnection);
    /*连接客户端断开信号，参数为套接字描述符，
    在clientDisconnect函数中会将拥有该描述符的线程从threadList中移除*/
    connect(thread, SIGNAL(disconnect(int)),
            this, SLOT(clientDisconnect(int)),Qt::QueuedConnection);
    thread->start();//线程启动
    _threadList.append(thread);
}

/*接收到线程发出的连接断开信号后，在线程数组中查找该线程并移除*/
void Server::clientDisconnect(int descriptor)
{
    for (int i=0; i<_threadList.count(); i++)
    {
        if(_threadList.at(i)->getDescriptor()==descriptor)
        {
            _threadList.at(i)->exit();
            _threadList.removeAt(i);
            emit removeUser(descriptor);
            return;
        }
    }
}

/*ServerThread构造函数*/
ServerThread::ServerThread(int descriptor, QObject *parent):QThread(parent)
{
    _descriptor=descriptor;
}

/*告诉server套接字为m_descriptor的连接已经断开*/
void ServerThread::threadFinished()
{
    emit this->disconnect(_descriptor);
}

/*返回套接字描述符*/
int ServerThread::getDescriptor()
{
    return _descriptor;
}

/*线程启动时调用的函数*/
void ServerThread::run()
{
    _socket=new ClientSocket;
    /*用ServerThread保存的套接字描述符初始化套接字*/
    if(!_socket->setSocketDescriptor(_descriptor))
    {
        qDebug("socket create fail!");
        this->finished();
        return;
    }
    /*连接消息发送信号*/
    connect(this,SIGNAL(sendData(int,qint32,QVariant)),
            _socket,SLOT(sendData(int,qint32,QVariant)));
    /*连接消息到达信号*/
    connect(_socket,SIGNAL(messageArrive(int,qint32,QVariant)),
            this,SIGNAL(messageArrive(int,qint32,QVariant)));
    /*连接客户端断开信号*/
    connect(_socket,SIGNAL(disconnected()),this,SLOT(threadFinished()));
    /*连接数据到达信号*/
    connect(_socket,SIGNAL(readyRead()),_socket,SLOT(readData()));
    exec();
}

/*CientSocket构造函数*/
ClientSocket::ClientSocket()
{
    _totalBytes=0;
}

/*数据读取函数*/
void ClientSocket::readData()
{
    QDataStream in;
    in.setDevice(this);
    in.setVersion(QDataStream::Qt_4_7);

    QVariant v;
    AllAnswers allans;
    Student u;
    /*如果还没有块大小信息则尝试去读取*/
    if(_totalBytes==0)
    {
        /*如果缓存区中可读数据的大小小于块大小信息的大小则返回*/
        if(this->bytesAvailable()<sizeof(qint32))
            return;
        /*写入块大小信息*/
        in>>_totalBytes;
    }
    /*如果缓存区可读信息的大小小于块大小则返回*/
    if(this->bytesAvailable()<_totalBytes)
        return;
    /*反之则说明完整的数据块已经到达缓存区，可以开始读取*/
    /*写入信息类型*/
    in>>_messageType;
    /*根据信息类型写入信息内容*/
    switch(_messageType)
    {
    case MSG_NEWCONNECT:
        in>>u;
        v.setValue(u);
        break;
    case MSG_LOGIN:
        in>>u;
        u.setSockDescriptor(this->socketDescriptor());
        v.setValue(u);
        break;
    case MSG_GETPAPER:
        in>>u;
        v.setValue(u);
        break;
    case MSG_ANSWER:
        in>>allans;
        v.setValue(allans);
        break;
    case MSG_ANSWERSINGLE:
        in>>allans;
        v.setValue(allans);
        break;
    }
    /*将块大小信息重置为0，准备接收下一个数据块*/
    _totalBytes=0;
    /*发送信息到达信号*/
    emit this->messageArrive(this->socketDescriptor(),_messageType,v);
}

/*数据发送预处理函数*/
void ClientSocket::sendData(int descriptor,qint32 m, QVariant v)
{
    if(this->socketDescriptor()==descriptor||descriptor==-1)
    {
        _messageType=m;
        _data=v;
        this->send();
        _data.clear();
    }
}

/*数据发送函数*/
void ClientSocket::send()
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_7);
    /*预留一位用于填写数据大小*/
    out<<(qint32)0;
    /*写入信息类型*/
    out<<_messageType;
    Paper p;
    Student u;
    QString s;
    /*根据信息类型将信息还原成原来的数据类型并写入*/
    switch(_messageType)
    {
    case MSG_NEWCONNECT:
        s=_data.value<QString>();
        out<<s;
        break;
    case MSG_LOGIN:
        u=_data.value<Student>();
        out<<u;
        break;
    case MSG_GETPAPER:
        p=_data.value<Paper>();
        out<<p;
        break;
    case MSG_ERROR:
        s=_data.value<QString>();
        out<<s;
        break;
    case MSG_BEGINEXAM:
        break;
    case MSG_ENDEXAM:
        break;
    }
    /*返回第一位并将数据大小写入*/
    out.device()->seek(0);
    out << (qint32)(block.size() - sizeof(qint32));
    /*将数据块写入TCP发送缓存区*/
    this->write(block,block.size());
}
