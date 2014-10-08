#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "data.h"
#include "ui_mainwindow.h"
#include"ExamUI.h"
#include "LoginUI.h"
#include "MainFrameUI.h"
#include<QMessageBox>
#include<QCloseEvent>
namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QStatusBar *statusbar;
signals:
    void paperReady(Paper);
    void showPaper();
    void getPaper();
    void sendAnswers(All_answers);
    void endExam();
    void loginSignal(User);
    void getUserInfo();
    void showUserInfo(User);
    void showMessage(QString);
    void sendAnswersSingle(All_answers);
private slots:


     void do_login();
     void do_mainframe();
     void LoginOK();
     void updateInfo(QString);
     void closeEvent(QCloseEvent *);

private:
    Ui::MainWindow *ui;
    MainFrameUI *m;
    LoginUI *loginPage;




};

#endif // MAINWINDOW_H
