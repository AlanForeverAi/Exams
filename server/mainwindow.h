#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#pragma execution_character_set("utf-8")
#pragma warning(disable: 4819)

#include <QMainWindow>
#include <QCloseEvent>
#include "data.h"
#include "ui_mainwindow.h"
#include "questionsmanage.h"
#include "papermanage.h"
#include "examctrl.h"
#include "submark.h"
#include "membermanage.h"
#include "login.h"
#include "mainmenu.h"
#include "config.h"
#include "scoremanage.h"
#include "inoutput.h"

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
    void addOb_Questoins(ChoiceQuestions*);
    void addSub_Questoins(EssayQuestions*);
    void modifyOb_Questoins(ChoiceQuestions*);
    void modifySub_Questoins(EssayQuestions*);
    void deleteOb_Questoins(int);
    void deleteSub_Questoins(int);
    void showQuestions(QList<ChoiceQuestions*>,QList<EssayQuestions*>);
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
    void loginSignal(User);
    void getManager();
    void getStudent();
    void getTeacher();
    void addStudent(Student*);
    void addTeacher(User *);
    void addManger(User *);
    void deleteUserId(QString);
    void deleteManagerId(int);
    void showManager(QList<User *>);
    void showStudent(QList<Student *>);
    void showTeacher(QList<User *>);
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

    void showSubject(QList<QString>);
    void getSubject();
    void showType(QMap<int, QString>);
    void getType();

    void addType(int, QString);
    void deleteType(int);

    void updateStudent(Student *);
    void updateTeacher(User *);
    void updateManager(User *);
    void updateType(int, QString);
    void updateStudentList(QList<Student *>);
    void updateTeacherList(QList<User *>);
    void updateManagerList(QList<User *>);
    void updateTypeList(QMap<int, QString>);

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
    Ui::MainWindow *_ui;
    QStatusBar *_statusBar;

};

#endif // MAINWINDOW_H
