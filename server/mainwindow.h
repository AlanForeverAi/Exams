#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include "data.h"
#include "ui_mainwindow.h"
#include "QuestionsManageUI.h"
#include "PaperManageUI.h"
#include "ExamCtrlUI.h"
#include "SubMarkUI.h"
#include "MemberManageUI.h"
#include "LoginUI.h"
#include "MainMenuUI.h"
#include "ConfigUI.h"
#include "ScoreManageUI.h"
#include "InOutPutUI.h"
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
signals:
    void getQuestions();
    void addOb_Questoins(ObQuestions*);
    void addSub_Questoins(SubQuestions*);
    void modifyOb_Questoins(ObQuestions*);
    void modifySub_Questoins(SubQuestions*);
    void deleteOb_Questoins(int);
    void deleteSub_Questoins(int);
    void showQuestions(QList<ObQuestions*>,QList<SubQuestions*>);
    void addPaper(Paper);
    void getAllPaper();
    void showAllPaper(QList<Paper*>);
    void deletePaper(int);
    void queryPaperMark(int);
    void saveUsertoPaperMark(int,QList<Student*>);
    void modifyPaper(Paper);
    void showCurrentPaper(Paper);
    void getPaperById(int);
    void sendPaper(int);
    void beginExam();
    void getUserList();
    void updateUserTable(QList<Student*>);
    void endExam();
    void getUserByPaperId(int,QString);
    void showUserByPaperId(QList<Student*>);
    void getSubAnswer(int,QString);
    void showSubAnswer(QVector<QString>);
    void submitSubMark(QStringList);
    void loginSignal(USER);
    void getUser();/////
    void addUser(Student*);//////增加用户
    void addManager(USER *);
    void deleteUserId(QString);
    void deleteManagerId(int);
    void showUser(QList<Student*>,QList<USER*>);/////
    void getcurrentPaperTime(int);
    void sendPaperTime(int,int);
    void getCombo_id(QString);//根据userid 获得
    void getCombo_paperid(int );
    void showCombo(QList<Combo *>);
    void delete_score(int,qlonglong);
    void outputUser();
    void outputOb();
    void outputSub();
    void outputPaper();
    void inputUser(QString);
    void inputOb(QString);
    void inputSub(QString);
    void inputPaper(QString);
    void sendInfo(QStringList);
private slots:
    void on_action_QuestionsManager_triggered();
    void on_action_makepaper_triggered();
    void on_action_examctrl_triggered();
    void on_action_subscore_triggered();
    void on_action_memmanager_triggered();
    void on_action_login_triggered();
    void on_action_mainmenu_triggered();
    void on_action_config_triggered();
    void on_action_scomanage_triggered();
    void on_action_inoutput_triggered();
    void on_action_Qt_triggered();
    void examMode();
    void endExamMode();
    void LoginOK();
    void backToMenu();
    void closeEvent(QCloseEvent *);
private:
    Ui::MainWindow *ui;
    void do_QuestionsManager();
    void do_makepaper();
    void do_examctrl();
    void do_subscore();
    void do_memmanage();
    void do_login();
    void do_mainmenu();
    void do_config();
    void do_scomanage();
    void do_inoutput();
    QStatusBar *statusbar;


};

#endif // MAINWINDOW_H
