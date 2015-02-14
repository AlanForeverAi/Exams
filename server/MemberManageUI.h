#ifndef MEMBERMANAGEUI_H
#define MEMBERMANAGEUI_H
//
#include <QWidget>
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
    void alterStudent(Student *);
    void updateStudent(Student *);

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
    void updateStudentList(Student *);

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
