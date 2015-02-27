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
namespace Ui
{
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
    void sendAnswers(AllAnswers);
    void endExam();
    void loginSignal(Student);
    void getUserInfo();
    void showUserInfo(Student);
    void showMessage(QString);
    void sendAnswersSingle(AllAnswers);
    void pauseExam();
    void continueExam();

private slots:
    void do_login();
    void do_mainframe();
    void LoginOK();
    void updateInfo(QString);
    void closeEvent(QCloseEvent *);

private:
    Ui::MainWindow *_ui;
    MainFrameUI *_mainFrame;
    LoginUI *_loginPage;




};

#endif // MAINWINDOW_H
