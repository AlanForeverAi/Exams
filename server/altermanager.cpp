#include "altermanager.h"

AlterManager::AlterManager()
{
    setupUi(this);
    lineEdit_ID->setFocusPolicy(Qt::NoFocus);
}

AlterManager::~AlterManager()
{

}

void AlterManager::showManager(User *manager)
{
    lineEdit_ID->setText(manager->getID());
    lineEdit_Name->setText(manager->getName());
    lineEdit_Password->setText(manager->getPassword());
}

void AlterManager::on_pushButton_Save_clicked()
{
    User *manager = new User();
    manager->setID(lineEdit_ID->text());
    manager->setName(lineEdit_Name->text());
    manager->setPassword(lineEdit_Password->text());

    emit this->updateManager(manager);
    this->close();
}

void AlterManager::on_pushButton_Cancel_clicked()
{
    this->close();
}
