#ifndef CONFIG_H
#define CONFIG_H

#include <QWidget>
#include "ui_config.h"
class Config : public QWidget,public Ui::config
{
    Q_OBJECT
public:
    explicit Config(QWidget *parent = 0);

signals:

public slots:
    void on_pushButton_save_clicked();
};

#endif // CONFIG_H
