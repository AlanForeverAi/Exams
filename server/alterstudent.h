#ifndef ALTERSTUDENT_H
#define ALTERSTUDENT_H

#include <QWidget>
#include <QDialog>
#include "ui_alterstudent.h"
#include "data.h"

class AlterStudent : public QDialog, public Ui::alterDialog
{
    Q_OBJECT

public:
    explicit AlterStudent();
    ~AlterStudent();

signals:
    void updateStudent(Student *);

private slots:
    void showStudent(Student *);
    void on_pushButton_Save_clicked();
    void on_pushButton_Cancel_clicked();
};

#endif // ALTERSTUDENT_H

