#ifndef startexam_H
#define startexam_H

#include <QWidget>
#include "ui_startexam.h"
#include"data.h"
#include<QMessageBox>
#include<QTimer>
class startexam : public QWidget,public Ui::startexam
{
    Q_OBJECT

public:
    explicit startexam(QWidget *parent = 0);
    ~startexam();
    void showQuestion(int);
    void resetRadioGroup();
    QTimer *timer;
signals:
    void sendAnswers(All_answers);
public slots:
    void showPaper(Paper);
    void on_Button_prev_clicked();
    void on_Button_next_clicked();
    void on_pushButton_jump_clicked();
    void on_Button_findUndo_clicked();
    void on_pushButton_submit_clicked();
    void timeUpdate();
    void submitAnswers();
private:
    Paper currentPaper;
    int currentQue;
    int totalque;
    QVector<QString> obanslist;
    QVector<QString> subanslist;
    QMessageBox msg;
    QButtonGroup radionGroup;
    QTime examTime;

};

#endif // startexam_H
