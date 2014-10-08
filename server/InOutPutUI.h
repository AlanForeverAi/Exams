#ifndef INOUTPUTUI_H
#define INOUTPUTUI_H

#include <QWidget>
#include "ui_InOutPutUI.h"
class InOutPutUI : public QWidget,public Ui::InOutPutUI
{
    Q_OBJECT
public:
    explicit InOutPutUI(QWidget *parent = 0);

signals:
    void outputUser();
    void outputOb();
    void outputSub();
    void outputPaper();
    void inputUser(QString);
    void inputOb(QString);
    void inputSub(QString);
    void inputPaper(QString);
public slots:
    void on_pushButton_inuser_clicked();
    void on_pushButton_inob_clicked();
    void on_pushButton_insub_clicked();
    void on_pushButton_inpaper_clicked();
    void on_pushButton_outuser_clicked();
    void on_pushButton_outob_clicked();
    void on_pushButton_outsub_clicked();
    void on_pushButton_outpaper_clicked();

};

#endif // INOUTPUTUI_H
