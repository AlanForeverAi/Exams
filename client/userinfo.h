#ifndef USERINFO_H
#define USERINFO_H

#include <QWidget>
#include "ui_UserInfo.h"
#include "data.h"
class UserInfo : public QWidget,public Ui::UserInfo
{
    Q_OBJECT
public:
    explicit UserInfo(QWidget *parent = 0);

signals:
    void backToMenu();
    void modifyUser(QString);
public slots:
    void showUserInfo(User);
    void on_pushButton_PW_clicked();
    void on_pushButton_back_clicked();
};

#endif // USERINFO_H
