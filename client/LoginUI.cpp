#include "LoginUI.h"
#include <QMessageBox>
LoginUI::LoginUI(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    this->setGeometry(0,100,1280,720);

}

void LoginUI::on_pushButton_login_clicked()
{
            User u;
            u.setID(lineEdit_ID->text());
            u.setPassword(lineEdit_PW->text());
            emit this->loginSignal(u);

}
