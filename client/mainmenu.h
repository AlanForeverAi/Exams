#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include "ui_MainMenu.h"
class MainMenu : public QWidget,public Ui::MainMenu
{
    Q_OBJECT
public:
    explicit MainMenu(QWidget *parent = 0);

signals:
    void action_startexam();
    void action_userinfo();
    void action_mark();
public slots:
    void on_pushButton_mark_clicked();
    void on_pushButton_userinfo_clicked();
    void on_pushButton_startexam_clicked();

};

#endif // MAINMENU_H
