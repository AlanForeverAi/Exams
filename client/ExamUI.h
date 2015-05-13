#ifndef EXAMUI_H
#define EXAMUI_H

#include <QWidget>
#include "ui_ExamUI.h"
#include "data.h"
#include <QMessageBox>
#include <QTimer>
#include <QDebug>

class ExamUI : public QWidget,public Ui::ExamUI
{
    Q_OBJECT

public:
    explicit ExamUI(QWidget *parent = 0);
    ~ExamUI();

    void resetRadioGroup();
    QTimer *timer;
signals:
    void sendAnswers(AllAnswers);
    void sendAnswersingle(AllAnswers);
public slots:
    void showPaper(Paper);
    void on_Button_prev_clicked();
    void on_Button_next_clicked();
    void on_pushButton_jump_clicked();
    void on_Button_mark_clicked();
    void showQueInfo(int);
    void iniQueInfo();
    void on_pushButton_submit_clicked();
    void timeUpdate();
    void submitAnswers();
    void showQuestion(int);
    void remoteSubmit();
private:
    Paper _currentPaper;
    int _currentQue;
    int _totalque;
    QVector<QString> _obansList;
    QVector<QString> _subansList;
    QMessageBox _msg;
    QButtonGroup _radionGroup;
    QButtonGroup *_btnGroup;
    QTime _examTime;

};

#endif // EXAMUI_H
