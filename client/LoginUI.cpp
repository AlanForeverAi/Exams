#include "LoginUI.h"
#include "data.h"
#include <QMessageBox>
#include <iostream>
LoginUI::LoginUI(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    this->setGeometry(0,100,1280,720);
    pushButton_login->setShortcut(QKeySequence::InsertParagraphSeparator);
}

void LoginUI::on_pushButton_login_clicked()
{
//    lineEdit_ID->setText("20112100001");
//    lineEdit_PW->setText("123");
    Student::GetInstance().setID(lineEdit_ID->text());
    Student::GetInstance().setPassword(lineEdit_PW->text());
    emit this->loginSignal(Student::GetInstance());
}
