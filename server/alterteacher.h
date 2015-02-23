#ifndef ALTERTEACHER_H
#define ALTERTEACHER_H

#include <QWidget>
#include <QMessageBox>
#include <QDialog>
#include "data.h"
#include "ui_alterteacher.h"

class AlterTeacher : public QDialog, public Ui::alterTeacher
{
    Q_OBJECT

public:
    explicit AlterTeacher();
    ~AlterTeacher();\

signals:
    void updateTeacher(User *);

private slots:
    void showTeacher(User *);
    void showTypeList(QList<QString>);

    void on_pushButton_Save_clicked();
    void on_pushButton_Cancel_clicked();
};

#endif // ALTERTEACHER_H

