#include "mainmenu.h"

MainMenu::MainMenu(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
}

void MainMenu::on_pushButton_startexam_clicked()
{
    emit this->action_startexam();
}

void MainMenu::on_pushButton_userinfo_clicked()
{
    emit this->action_userinfo();
}

void MainMenu::on_pushButton_mark_clicked()
{
    emit this->action_mark();
}
