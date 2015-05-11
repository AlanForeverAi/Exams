#include <iostream>
#include <QDebug>
#include "data.h"
#include "mainmenu.h"

MainMenuUI::MainMenuUI(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
}

void MainMenuUI::on_pushButton_question_clicked()
{
    emit this->action_QuestionsManager();
}

void MainMenuUI::on_pushButton_paper_clicked()
{
    emit this->action_makepaper();
}

void MainMenuUI::on_pushButton_examctrl_clicked()
{
    emit this->action_examctrl();
}

void MainMenuUI::on_pushButton_mem_clicked()
{
    emit this->action_memmanager();
}

void MainMenuUI::on_pushButton_subscore_clicked()
{
    emit this->action_subscore();
}

void MainMenuUI::on_pushButton_config_clicked()
{
    emit this->action_config();
}

void MainMenuUI::on_pushButton_scoremanage_clicked()
{
    emit this->action_scoremanage();
}

void MainMenuUI::on_pushButton_papersetting_clicked()
{
    emit this->action_papersetting();
}

void MainMenuUI::on_pushButton_examsetting_clicked()
{
    emit this->action_examsetting();
}
