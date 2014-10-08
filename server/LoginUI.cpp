#include "LoginUI.h"
#include <QMessageBox>
LoginUI::LoginUI(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
}

void LoginUI::on_pushButton_login_clicked()
{
            Manager m;
            m.setId(lineEdit_ID->text().toInt());
            m.setPassword(lineEdit_PW->text());
            emit this->loginSignal(m);
}
