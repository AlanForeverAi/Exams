#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include "ui_menu.h"
#include "data.h"

class Menu : public QWidget, public Ui::Menu
{
    Q_OBJECT
public:
    explicit Menu(QWidget *parent = 0);
    ~Menu();

signals:
    void action_QuestionsManager();
    void action_makepaper();
    void action_examctrl();
    void action_subscore();
    void action_memmanager();
    void action_config();
    void action_scoremanage();
    void action_inoutput();
    void action_papersetting();
    void action_examsetting();
    void examprepare();

private slots:
    void on_pushButton_mem_clicked();
    void on_pushButton_examsetting_clicked();
    void on_pushButton_examctrl_clicked();
    void on_pushButton_config_clicked();
    void on_pushButton_question_clicked();
    void on_pushButton_paper_clicked();
    void on_pushButton_papersetting_clicked();
    void on_pushButton_subscore_clicked();
    void on_pushButton_scoremanage_clicked();
    void setState(int);

private:
    int state;
};

#endif // MENU_H
