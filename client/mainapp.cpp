#include"mainapp.h"
#include <iostream>

MainApp::MainApp()
{
    iniMainWindow();
    readConfig();
    iniClient();

}
MainApp::~MainApp()
{

    delete(_client);

}

void MainApp::readConfig()
{
    QFile Config("./config.ini");
    if(!Config.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QMessageBox msg;
        msg.setText(QStringLiteral("读取配置文件失败！将使用默认配置"));
        msg.exec();
        _ip = "localhost";
        _port = 3312;
        return;
    }

    QTextStream in(&Config);
    QString temp;
    temp = in.readLine();
    temp = temp.mid(temp.indexOf(" ")+1);
    _ip = temp;
    temp = in.readLine();
    temp = temp.mid(temp.indexOf(" ")+1);
    _port = temp.toInt();
    Config.close();
}

void MainApp::iniClient()
{
    _window.statusbar->showMessage(QStringLiteral("未连接"));
    _client = new Client(this);
    connect(_client,SIGNAL(connected()),this,SLOT(connected()));
    connect(_client,SIGNAL(messageArrive(qint32,QVariant)),this,SLOT(messageArrive(qint32,QVariant)),Qt::DirectConnection);
    _client->connectToServer(_ip,_port);
}

void MainApp::iniMainWindow()
{
    connect(this,SIGNAL(paperReady(Paper)),&_window,SIGNAL(paperReady(Paper)));
    connect(this,SIGNAL(showPaper()),&_window,SIGNAL(showPaper()));
    connect(&_window,SIGNAL(getPaper()),this,SLOT(getPaper()));
    connect(&_window,SIGNAL(sendAnswers(AllAnswers)),this,SLOT(sendAnswers(AllAnswers)));
    connect(this,SIGNAL(endExam()),&_window,SIGNAL(endExam()));
    connect(&_window,SIGNAL(loginSignal(Student)),this,SLOT(Login(Student)));
    connect(&_window,SIGNAL(sendAnswersSingle(AllAnswers)),this,SLOT(sendAnswersSingle(AllAnswers)));
    connect(this,SIGNAL(LoginOK()),&_window,SLOT(LoginOK()));
    connect(&_window,SIGNAL(getUserInfo()),this,SLOT(getUserInfo()));
    connect(this,SIGNAL(showUserInfo(Student)),&_window,SIGNAL(showUserInfo(Student)));
    connect(this,SIGNAL(updateInfo(QString)),&_window,SLOT(updateInfo(QString)));
    connect(this,SIGNAL(showMessage(QString)),&_window,SIGNAL(showMessage(QString)));
    _window.show();

}

void MainApp::sendAnswersSingle(AllAnswers allans)
{
    allans.setUserId(_currentUser.getID());
    QVariant v;
    v.setValue(allans);
    _client->sendData(MSG_ANSWERSINGLE,v);
}

void MainApp::connected()
{
    _client->sendData(MSG_NEWCONNECT,0);
    _window.statusbar->showMessage(QStringLiteral("已连接"));

}

void::MainApp::getPaper()
{
    QVariant v;
    v.setValue(_currentUser);
    _client->sendData(MSG_GETPAPER,v);
}


void MainApp::messageArrive(qint32 m, QVariant v)
{
    QMessageBox msg;
    switch(m)
    {
    case MSG_NEWCONNECT:
        _infolist = v.value<QString>();
        _serverState = _infolist.left(1).toInt();
        this->updateInfo(_infolist);
        if(_serverState == STATE_PAPERREADY || _serverState == STATE_EXAMING)
        {
            _client->sendData(MSG_GETPAPER,0);
        }
        break;
    case MSG_LOGIN:
        _currentUser = v.value<Student>();
        emit this->LoginOK();
        emit this->showUserInfo(_currentUser);
        if(_serverState == STATE_EXAMING)
        {
            emit this->showMessage(QStringLiteral("你目前处于锁定状态，\n请等待服务器审批你的考试要求"));

        }
        break;
    case MSG_GETPAPER:
        _currentpaper = v.value<Paper>();
        emit this->paperReady(_currentpaper);
        if(_serverState == STATE_EXAMING)
        {
            //emit this->showPaper();
        }
        break;
    case MSG_BEGINEXAM:
        emit  this->showPaper();
        break;
    case MSG_ENDEXAM:
        emit this->endExam();
        msg.setText(QStringLiteral("服务器已经结束考试，你的答案已自动提交"));
        msg.exec();
        break;
    case MSG_ERROR:
        QString errorstring;
        errorstring = v.value<QString>();
        msg.setText(errorstring);
        msg.exec();
        break;
    }
}
void MainApp::sendAnswers(AllAnswers allans)
{
    allans.setUserId(_currentUser.getID());
    QVariant v;
    v.setValue(allans);
    _client->sendData(MSG_ANSWER,v);
}

//登录函数
void MainApp::Login(Student u)
{
    QVariant v;
    v.setValue(u);
    _client->sendData(MSG_LOGIN,v);
}

void MainApp::getUserInfo()
{
    emit this->showUserInfo(_currentUser);
}
