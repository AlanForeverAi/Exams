#ifndef MEMBERMANAGEUI_H
#define MEMBERMANAGEUI_H
//
#include <QWidget>
#include <QFileDialog>
#include <QFile>
#include <QDir>
#include "ui_MemberManageUI.h"
#include "data.h"

class MemberManageUI : public QWidget,public Ui::MemberManageUI
{
    Q_OBJECT

public:
    explicit MemberManageUI(QWidget *parent = 0);
    ~MemberManageUI();
signals:
    void addStudent(Student *);
    void addTeacher(User *);
    void addManager(User *);
    void addType(int, QString);
    void deleteUserId(QString);
    void deleteManagerId(int);
    void deleteType(int);
    void showStudent(Student *);
    void updateStudent(Student *);
    void showTeacher(User *);
    void showTypeList(QList<QString>);
    void updateTeacher(User *);
    void showManager(User *);
    void updateManager(User *);
    void showType(int, QString);
    void updateType(int, QString);
    void exportStudent(QList<Student *>, QString);
    void exportTeacher(QList<User *>, QString);
    void exportManager(QList<User *>, QString);
    void exportType(QMap<int, QString>, QString);
    void importStudent(QString);
    void importTeacher(QString);
    void importManager(QString);
    void importType(QString);

private slots:
    void on_pushButton_add_user_clicked();
    void on_pushButton_delete_user_clicked();
    void on_pushButton_search_clicked();
    void on_pushButton_all_clicked();
    void showManager(QList<User *>);
    void showStudent(QList<Student *>);
    void showTeacher(QList<User *>);
    void showSubject(QList<QString>);
    void showType(QMap<int, QString>);
    void textClear();
    void studentDialog(QTableWidgetItem *);
    void teacherDialog(QTableWidgetItem *);
    void managerDialog(QTableWidgetItem *);
    void typeDialog(QTableWidgetItem *);
    void updateStudentList(QList<Student *>);
    void updateTeacherList(QList<User *>);
    void updateManagerList(QList<User *>);
    void updateTypeList(QMap<int, QString>);

    void on_pushButton_import_clicked();

    void on_pushButton_export_clicked();

private:
    QList<Student *> studentList;
    QList<User *>    teacherList;
    QList<User *>    managerList;
    QList<Student *> studentSearchList;
    QList<User *>    teacherSearchList;
    QList<User *>    managerSearchList;
    QMap<int, QString> typeList;
    QMap<int, QString> typeSearchList;
};

#endif // MEMBERMANAGEUI_H
