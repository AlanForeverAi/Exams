#ifndef ADDSTUDENT_H
#define ADDSTUDENT_H

#include <QDialog>
#include <QMessageBox>
#include "ui_addstudent.h"
#include "data.h"

class AddStudent : public QDialog, public Ui::AddStudent
{
    Q_OBJECT
public:
    AddStudent();
    ~AddStudent();

signals:
    void appendExaminee(QStringList);

private slots:
    void setStudentList(QList<Student *>);
    void setSelectStudent(QStringList);
    void showStudent();
    void showStudentList(QList<Student *>);
    void updateCheckStudentIDs(int, int);
    void on_pushButton_searchstudent_clicked();

    void on_pushButton_allstudent_clicked();

    void on_pushButton_add_clicked();

    void on_pushButton_cancel_clicked();

private:
    QList<Student *> studentList;
    QStringList selectStudentIDs;
    QStringList checkStudentIDs;
    QButtonGroup studentSelect;
};

#endif // ADDSTUDENT_H
