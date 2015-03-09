#ifndef SETMARK_H
#define SETMARK_H

#include <QDialog>
#include <QMessageBox>
#include "ui_setmark.h"


class SetMark : public QDialog, public Ui::SetMark
{
    Q_OBJECT
public:
    SetMark();
    ~SetMark();
    int getMark();

signals:
//    void getMark(int);

private slots:
    void on_pushButton_submit_clicked();
    void on_pushButton_cancel_clicked();

private:
    int mark;
};

#endif // SETMARK_H
