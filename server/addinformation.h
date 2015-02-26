#ifndef ADDINFORMATION_H
#define ADDINFORMATION_H

#include <QDialog>
#include "data.h"
#include "ui_addinformation.h"

class AddInformation : public QDialog, public Ui::Addinformation
{
    Q_OBJECT
public:
    AddInformation();
    ~AddInformation();

signals:
    void addStudent(Student *);
    void addTeacher(User *);
    void addManager(User *);
    void addType(int, QString);

private slots:
    void showSubject(QList<QString> subjectList);
    void on_pushButton_Add_clicked();
    void on_pushButton_Cancel_clicked();
};

#endif // ADDINFORMATION_H
