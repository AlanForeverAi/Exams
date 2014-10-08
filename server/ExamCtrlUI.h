#ifndef EXAMCTRL_H
#define EXAMCTRL_H


#include<QWidget>
#include <QTimer>
#include"ui_ExamCtrlUI.h"
#include"data.h"
class ExamCtrlUI:public QWidget,public Ui::ExamCtrlUI
{
    Q_OBJECT
public:
    ExamCtrlUI(QWidget *parent=0);
    ~ExamCtrlUI();


signals:
    void sendPaper(int);
    void endExam();
    void sendPaperTime(int,int);
    void sendInfo(QStringList);
private slots:
    void showPapers(QList<Paper*>);
    void on_pushButton_send_clicked();
    void on_pushButton_begin_clicked();

    void counttimeUpdate();
    void datetimeUpdate();
    void updateUserTable(QList<User*>);
    void on_pushButton_end_clicked();
    void getcurrentPaperTime(int);
private:
     QTimer *counttimer;
     QTimer *datetimer;
     QTime counttime;

};



#endif // EXAMCTRL_H
