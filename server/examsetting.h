#ifndef EXAMSETTING_H
#define EXAMSETTING_H

#include <QWidget>
#include <QTimer>
#include <QMessageBox>
#include <QDebug>
#include "ui_examsetting.h"
#include "data.h"

class ExamSettingUI:public QWidget,public Ui::ExamCtrlUI
{
    Q_OBJECT
public:
    ExamSettingUI(QWidget *parent=0);
    ~ExamSettingUI();

signals:
    void sendPaper(int);
    void endExam();
    void sendPaperTime(int,int);
    void sendInfo(QStringList);
    void updateStudentTable(QList<Student*>);
//    void setTime(QTime);
//    void setTime(int);
    void setExamName(QString);
    void beginExam();
    void pauseExam();
    void continueExam();
    void sendMessage(QString);
    void getcurrentPaperTime(int);
    void startServer();
    void closeServer();
    void setPaper(int);
    void setInfo(QStringList);

private slots:
    void showPapers(QList<Paper*>);
    void on_pushButton_send_clicked();
    void on_pushButton_closeServer_clicked();

    void on_pushButton_startServer_clicked();

private:
//    QTimer *_countTimer;
//    QTimer *_dateTimer;
//    QTime _countTime;
};



#endif // EXAMSETTING_H
