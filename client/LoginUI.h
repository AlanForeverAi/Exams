#ifndef LOGINUI_H
#define LOGINUI_H

#include <QWidget>
#include "ui_LoginUI.h"
#include "data.h"
class LoginUI : public QWidget,public Ui::LoginUI
{
    Q_OBJECT
public:
    explicit LoginUI(QWidget *parent = 0);

signals:
    void loginSignal(Student);
public slots:
    void on_pushButton_login_clicked();
};

#endif // LOGINUI_H
