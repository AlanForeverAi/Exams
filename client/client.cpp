#include"client.h"
#include"data.h"
#include<QMessageBox>
/*Client类构造函数*/
Client::Client(QObject *parent)
{
    _totalBytes=0;
    /*连接数据到达信号*/
    connect(this,SIGNAL(readyRead()),this,SLOT(readData()));
    /*连接错误信息显示信号*/
    connect(this,SIGNAL(error(QAbstractSocket::SocketError)),
            this,SLOT(displayError(QAbstractSocket::SocketError)));
}

/*连接到服务器函数*/
void Client::connectToServer(const QString host,qint32 port)
{
    this->abort();
    this->connectToHost(host,port);
}

/*数据发送预处理函数*/
void Client::sendData(qint32 m, QVariant v)
{
    _messageType=m;
    _data.setValue(v);
    this->send();
    _data.clear();
}

/*数据发送函数*/
void Client::send()
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_7);
    /*预留一位用于填写数据大小*/
    out << (qint32)0;
    /*写入信息类型*/
    out << _messageType;

    Student u;
    AllAnswers allans;
    /*根据信息类型将信息还原成原来的数据类型并写入*/
    switch(_messageType)
    {
    case MSG_NEWCONNECT:
        break;
    case MSG_LOGIN:
        u=_data.value<Student>();
        u.setHostname(QHostInfo::localHostName());
        out<<u;
        break;
    case MSG_GETPAPER:
        u=_data.value<Student>();
        out<<u;
        break;
    case MSG_ANSWER:
        allans=_data.value<AllAnswers>();
        out<<allans;
        break;
    case MSG_ANSWERSINGLE:
        allans=_data.value<AllAnswers>();
        out<<allans;
        break;
    }

    /*返回第一位并将数据大小写入*/
    out.device()->seek(0);
    out << (qint32)(block.size() - sizeof(qint32));
    /*将数据块写入TCP发送缓存区*/
    this->write(block,block.size());

}

/*数据读取函数*/
void Client::readData()
{
    QDataStream in;
    in.setDevice(this);
    in.setVersion(QDataStream::Qt_4_7);
    Paper p;
    QString s;
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
        in>>s;
        _data.setValue(s);
        break;
    case MSG_LOGIN:
        in>>u;
        _data.setValue(u);
        break;
    case MSG_GETPAPER:
        in>>p;
        _data.setValue(p);
        break;
    case MSG_ERROR:
        in>>s;
        _data.setValue(s);
        break;
    case MSG_BEGINEXAM:
        break;
    case MSG_ENDEXAM:
        break;
    }
    /*将块大小信息重置为0，准备接收下一个数据块*/
    _totalBytes=0;
    /*发送信息到达信号*/
    emit this->messageArrive(_messageType,_data);
    this->flush();
}

/*显示套接字返回的错误信息*/
void Client::displayError(QAbstractSocket::SocketError socketError)
{
    QMessageBox msgBox;
    switch (socketError)
    {
    case QAbstractSocket::ConnectionRefusedError:
        this->abort();
        msgBox.setText(QString("连接服务器失败"));
        msgBox.exec();
        break;
    default:
        QString s="The following error occurred: %1";
        qDebug()<<s.arg(socketError);
    }
}


