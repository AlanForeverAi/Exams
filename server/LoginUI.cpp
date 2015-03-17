#include "login.h"
#include <QMessageBox>
LoginUI::LoginUI(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    pushButton_login->setShortcut(QKeySequence::InsertParagraphSeparator);	//将回车键与登录按钮绑定在一起
}

void LoginUI::on_pushButton_login_clicked()
{
    lineEdit_ID->setText("123");
    lineEdit_PW->setText("123");
    User::GetInstance().setID(lineEdit_ID->text());
    User::GetInstance().setPassword(lineEdit_PW->text());
    emit this->loginSignal(User::GetInstance());
}

