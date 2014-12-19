#include "LoginUI.h"
#include <QMessageBox>
#include <iostream>
LoginUI::LoginUI(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    this->setGeometry(0,100,1280,720);

}

void LoginUI::on_pushButton_login_clicked()
{
    //std::cout << "!!!!!!" << std::endl;
    Student student;
    student.setID(lineEdit_ID->text());
    student.setPassword(lineEdit_PW->text());
    emit this->loginSignal(student);
}
