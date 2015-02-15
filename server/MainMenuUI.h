#ifndef MAINMENUUI_H
#define MAINMENUUI_H

#include <iostream>
#include <QWidget>
#include "ui_MainMenuUI.h"
class MainMenuUI : public QWidget, public Ui::MainMenuUI
{
    Q_OBJECT
public:
    explicit MainMenuUI(QWidget *parent = 0);

signals:
    void action_QuestionsManager();
    void action_makepaper();
    void action_examctrl();
    void action_subscore();
    void action_memmanager();
    void action_config();
    void action_scoremanage();
    void action_inoutput();
public slots:
    void on_pushButton_question_clicked();
    void on_pushButton_paper_clicked();
    void on_pushButton_mem_clicked();
    void on_pushButton_examctrl_clicked();
    void on_pushButton_subscore_clicked();
    void on_pushButton_config_clicked();
    void on_pushButton_scoremanage_clicked();
    void on_pushButton_inoutput_clicked();

};

#endif // MAINMENUUI_H
