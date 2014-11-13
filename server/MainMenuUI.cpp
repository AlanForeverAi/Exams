#include <iostream>
#include <QDebug>
#include "data.h"
#include "MainMenuUI.h"

MainMenuUI::MainMenuUI(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    //根据用户类型设置选项是否可以执行。
    if(USER::GetInstance().getType() == 1)
    {
        pushButton_question->setEnabled(false);
        pushButton_paper->setEnabled(false);
        pushButton_examctrl->setEnabled(false);
        pushButton_subscore->setEnabled(false);
        pushButton_scoremanage->setEnabled(false);
    }
    else
    {
        pushButton_mem->setEnabled(false);
        pushButton_config->setEnabled(false);

    }
    //管理员和老师都需要用到导入导出功能
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

void MainMenuUI::on_pushButton_inoutput_clicked()
{
    emit this->action_inoutput();
}
