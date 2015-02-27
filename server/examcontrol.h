#ifndef EXAMCONTROL_H
#define EXAMCONTROL_H

#include <QDialog>
#include "ui_examcontrol.h"
#include "data.h"

class ExamControl : public QDialog, public Ui::ExamControl
{
    Q_OBJECT
public:
    explicit ExamControl();
    ~ExamControl();

signals:
    void beginExam();
    void endExam();
    void pauseExam();
    void continueExam();

private slots:
    void updateStudentTable(QList<Student*>);
    void setTime(QTime);
    void setExamName(QString);
    void on_pushButton_begin_clicked();
    void on_pushButton_sendMessage_clicked();
    void on_pushButton_pause_clicked();
    void on_pushButton_end_clicked();
    void on_pushButton_back_clicked();
    void on_pushButton_continue_clicked();
};

#endif // EXAMCONTROL_H
