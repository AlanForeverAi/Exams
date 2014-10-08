#ifndef CONFIGUI_H
#define CONFIGUI_H

#include <QWidget>
#include "ui_ConfigUI.h"
class ConfigUI : public QWidget,public Ui::ConfigUI
{
    Q_OBJECT
public:
    explicit ConfigUI(QWidget *parent = 0);

signals:
    void reDB();
    void reServer();
public slots:
    void on_pushButton_save_clicked();

};

#endif // CONFIGUI_H
