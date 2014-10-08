#include "userinfo.h"
#include <QMessageBox>
UserInfo::UserInfo(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
}

void UserInfo::showUserInfo(User u)
{
    lineEdit_ID->setText(u.getID());
    lineEdit_name->setText(u.getName());
    lineEdit_grade->setText(QString::number(u.getGrade()));
    lineEdit_class->setText(QString::number(u.getClass()));

}

void UserInfo::on_pushButton_PW_clicked()
{
    if(lineEdit_PW->text()==lineEdit_PW2->text())
        {

            emit this->modifyUser(lineEdit_PW->text());
        }
    else
        {
            QMessageBox::about(this,"msg",tr("两次输入的密码不一致"));
        }
}

void UserInfo::on_pushButton_back_clicked()
{
    emit this->backToMenu();
}
