#ifndef EXAMCONTROL_H
#define EXAMCONTROL_H

#include <QWidget>
#include <QTimer>
#include <QTime>
#include "ui_examcontrol.h"
#include "data.h"
#include "sendmessage.h"

enum STATE {
    STATE_EXAMING,
    STATE_PAUSE
};

class ExamControl : public QWidget, public Ui::ExamControl
{
    Q_OBJECT
public:
    ExamControl();
    ~ExamControl();

signals:
    void beginExam();
    void endExam();
    void pauseExam();
    void continueExam();
    void sendMessage(QString);
    void sendPaperTime(int, int);

private slots:
    void updateStudentTable(QList<Student *>);
    void setTime(QTime);
    void setPaperName(QString);
    void updateDateTime();
    void updateCountTime();
    void getcurrentPaperTime(int);
    void on_pushButton_begin_clicked();
    void on_pushButton_pause_clicked();
    void on_pushButton_continue_clicked();
    void on_pushButton_end_clicked();

private:
    QTimer *_countTimer;
    QTimer *_dateTimer;
    QTime _countTime;
    int mode;
};

#endif // EXAMCONTROL_H
