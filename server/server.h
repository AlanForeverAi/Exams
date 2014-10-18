#ifndef SERVER_H
#define SERVER_H
#include<QtNetwork>
#include"data.h"

/*定义信息类型*/
enum MessageType
{
    MSG_LOGIN,
    MSG_GETPAPER,
    MSG_ANSWER,
    MSG_ANSWERSINGLE,
    MSG_BEGINEXAM,
    MSG_ENDEXAM,
    MSG_ERROR,
    MSG_NEWCONNECT
};

/*套接字类*/
class ClientSocket : public QTcpSocket
{
    Q_OBJECT
public:
    ClientSocket();
signals:
    void messageArrive(int,qint32,QVariant);//信息到达信号
public slots:
    void readData();//数据读取槽
    void sendData(int,qint32,QVariant);//数据发送预处理槽
private:
    QVariant data;//信息内容
    qint32 messageType;//信息类型
    qint32 totalBytes;//块大小
    void send();//发送函数
};

/*服务器线程类，每一个实例对应一个连接*/
class ServerThread : public QThread
{
Q_OBJECT
public:
    ServerThread(int descriptor,QObject *parent);
    void run();
    int Descriptor();//返回socket的套接字

signals:
    void disconnect(int);//断开信号
    void messageArrive(int,qint32,QVariant);//信息到达信号
    void sendData(int,qint32,QVariant);//信息发送信号
    void finished();
public slots:
    void threadFinished();//线程结束函数
private:
    int m_descriptor;//套接字描述符
    ClientSocket *socket;//套接字对象
};

/*服务器类*/
class Server : public QTcpServer
{
Q_OBJECT
public:
    Server(QObject *parent = 0,int port=0);
signals:
    void messageArrive(int,qint32,QVariant);//信息到达信号
    void sendData(int,qint32,QVariant);//信息发送信号
    void removeUser(int);
public slots:
    void clientDisconnect(int);//客户端断开槽
protected:
    void incomingConnection(int socketDescriptor);//新连接进入处理函数
private:
    QList<ServerThread *> threadList;//服务器线程数组，用来保存多个连接的线程
};
#endif // SERVER_H
