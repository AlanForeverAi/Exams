#ifndef MAINFRAMEUI_H
#define MAINFRAMEUI_H

#include <QWidget>
#include "ui_MainFrameUI.h"
#include "ExamUI.h"
#include "data.h"
class MainFrameUI : public QWidget,public Ui::MainFrameUI
{
    Q_OBJECT
public:
    explicit MainFrameUI(QWidget *parent = 0);

signals:
    void sendAnswers(AllAnswers);
    void endExam();
    void sendAnswersSingle(AllAnswers);
public slots:
    void paperReady(Paper);
    void showUserInfo(Student);
    void showMessage(QString);
    void showPaper();
    void endExamslot();
    void sendExamslot();
    void pauseExam();
    void continueExam();
//    void receiveMessage(QString);

private:
    ExamUI *_exam;
};

#endif // MAINFRAMEUI_H
