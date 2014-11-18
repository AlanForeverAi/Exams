#ifndef MAINAPP_H
#define MAINAPP_H
#include"mainwindow.h"
#include"client.h"

enum ServerState
{
    STATE_NOEXAM,
    STATE_PAPERREADY,
    STATE_EXAMING
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

    MainWindow w;
    Client* client;
    Student currentUser;
    Paper currentpaper;
    QString IP;
    int port;
    int serverState;
    QString infolist;


};
#endif // MAINAPP_H
