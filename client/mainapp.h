#ifndef MAINAPP_H
#define MAINAPP_H
#include"mainwindow.h"
#include"client.h"

enum ServerState
{
    STATE_NOEXAM,
    STATE_PAPERREADY,
    STATE_EXAMING,
    STATE_PAUSE
};
class MainApp :public QObject
{
    Q_OBJECT
public:
    MainApp();
    ~MainApp();

    void iniClient();
    void iniMainWindow();
    void readConfig();
signals:
    void paperReady(Paper);
    void showPaper();
    void endExam();
    void LoginOK();
    void showUserInfo(Student);
    void showScore(QList<Combo>);
    void updateInfo(QString);
    void showMessage(QString);
    void pauseExam();
    void continueExam();
    void receiveMessage(QString);

public slots:
    void connected();
    void messageArrive(qint32,QVariant);
    void getPaper();
    void sendAnswersSingle(AllAnswers);
    void sendAnswers(AllAnswers);
    //响应登录界面的函数
    void Login(Student);
    //以下这两个槽响应用户信息界面传来的信号
    void getUserInfo();             //取得当前用户信息
private:

    MainWindow _window;
    Client *_client;
    Student _currentUser;
    Paper _currentpaper;
    QString _ip;
    int _port;
    int _serverState;
    QString _infolist;


};
#endif // MAINAPP_H
