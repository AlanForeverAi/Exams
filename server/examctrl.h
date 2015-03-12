#ifndef EXAMCTRL_H
#define EXAMCTRL_H

#include <QWidget>
#include <QTimer>
#include "ui_ExamCtrlUI.h"
#include "data.h"
#include "examcontrol.h"

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
    void updateStudentTable(QList<Student*>);
    void setTime(QTime);
//    void setTime(int);
    void setExamName(QString);
    void beginExam();
    void pauseExam();
    void continueExam();
    void sendMessage(QString);
    void getcurrentPaperTime(int);
    void startServer();
    void closeServer();

private slots:
    void showPapers(QList<Paper*>);
    void on_pushButton_send_clicked();
    void on_pushButton_closeServer_clicked();

    void on_pushButton_startServer_clicked();

private:
    QTimer *_countTimer;
    QTimer *_dateTimer;
    QTime _countTime;
};



#endif // EXAMCTRL_H
