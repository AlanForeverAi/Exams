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
    void readDB();
    void readServer();
public slots:
    void onPushbuttonSaveClicked();

};

#endif // CONFIGUI_H
