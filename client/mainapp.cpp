#include"mainapp.h"

MainApp::MainApp()
{
    iniMainWindow();
    readConfig();
    iniClient();

}
MainApp::~MainApp()
{

    delete(client);

}

void MainApp::readConfig()
{
    QFile Config("config.ini");
    if(!Config.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QMessageBox msg;
        msg.setText(QString("读取配置文件失败！将使用默认配置"));
        msg.exec();
        IP="localhost";
        port=3312;
        return;
    }

    QTextStream in(&Config);
    QString temp;
    temp=in.readLine();
    temp=temp.mid(temp.indexOf(" ")+1);
    IP=temp;
    temp=in.readLine();
    temp=temp.mid(temp.indexOf(" ")+1);
    port=temp.toInt();
    Config.close();
}

void MainApp::iniClient()
{

    w.statusbar->showMessage(QString("未连接"));
    client=new Client(this);
    connect(client,SIGNAL(connected()),this,SLOT(connected()));
    connect(client,SIGNAL(messageArrive(qint32,QVariant)),this,SLOT(messageArrive(qint32,QVariant)),Qt::DirectConnection);
    client->connectToServer(IP,port);



}

void MainApp::iniMainWindow()
{
    connect(this,SIGNAL(paperReady(Paper)),&w,SIGNAL(paperReady(Paper)));
    connect(this,SIGNAL(showPaper()),&w,SIGNAL(showPaper()));
    connect(&w,SIGNAL(getPaper()),this,SLOT(getPaper()));
    connect(&w,SIGNAL(sendAnswers(AllAnswers)),this,SLOT(sendAnswers(AllAnswers)));
    connect(this,SIGNAL(endExam()),&w,SIGNAL(endExam()));
    connect(&w,SIGNAL(loginSignal(Student)),this,SLOT(Login(Student)));
    connect(&w,SIGNAL(sendAnswersSingle(AllAnswers)),this,SLOT(sendAnswersSingle(AllAnswers)));
    connect(this,SIGNAL(LoginOK()),&w,SLOT(LoginOK()));
    connect(&w,SIGNAL(getUserInfo()),this,SLOT(getUserInfo()));
    connect(this,SIGNAL(showUserInfo(Student)),&w,SIGNAL(showUserInfo(Student)));
    connect(this,SIGNAL(updateInfo(QString)),&w,SLOT(updateInfo(QString)));
    connect(this,SIGNAL(showMessage(QString)),&w,SIGNAL(showMessage(QString)));
    w.show();

}

void MainApp::sendAnswersSingle(AllAnswers allans)
{
    allans.setUserId(currentUser.getID());
    QVariant v;
    v.setValue(allans);
    client->sendData(MSG_ANSWERSINGLE,v);
}

void MainApp::connected()
{
    client->sendData(MSG_NEWCONNECT,0);
    w.statusbar->showMessage(QString("已连接"));

}

void::MainApp::getPaper()
{
    QVariant v;
    v.setValue(currentUser);
    client->sendData(MSG_GETPAPER,v);
}


void MainApp::messageArrive(qint32 m, QVariant v)
{
    QMessageBox msg;
    //  QList<Combo> list;
    switch(m)
    {
    case MSG_NEWCONNECT:
        infolist=v.value<QString>();
        serverState=infolist.left(1).toInt();
        this->updateInfo(infolist);
        if(serverState==STATE_PAPERREADY||serverState==STATE_EXAMING)
        {
            client->sendData(MSG_GETPAPER,0);
        }
        break;
    case MSG_LOGIN:
        currentUser=v.value<User>();
        emit this->LoginOK();
        emit this->showUserInfo(currentUser);
        if(serverState==STATE_EXAMING)
        {
            emit this->showMessage(QString("你目前处于锁定状态，\n请等待服务器审批你的考试要求"));

        }
        break;
    case MSG_GETPAPER:
        currentpaper=v.value<Paper>();
        emit this->paperReady(currentpaper);
        if(serverState==STATE_EXAMING)
        {
            //emit this->showPaper();
        }
        break;
    case MSG_BEGINEXAM:
        emit  this->showPaper();
        break;
    case MSG_ENDEXAM:
        emit this->endExam();
        msg.setText(QString("服务器已经结束考试，你的答案已自动提交"));
        msg.exec();
        break;
    case MSG_ERROR:
        QString errorstring;
        errorstring=v.value<QString>();
        msg.setText(errorstring);
        msg.exec();
        break;
    }
}
void MainApp::sendAnswers(AllAnswers allans)
{
    allans.setUserId(currentUser.getID());
    QVariant v;
    v.setValue(allans);
    client->sendData(MSG_ANSWER,v);
}

//登录函数
void MainApp::Login(Student u)
{
    QVariant v;
    v.setValue(u);
    client->sendData(MSG_LOGIN,v);
}

void MainApp::getUserInfo()
{
    emit this->showUserInfo(currentUser);
}
