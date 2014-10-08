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
    void sendAnswers(All_answers);
    void endExam();
     void sendAnswersSingle(All_answers);
public slots:
    void paperReady(Paper);
    void showUserInfo(User);
    void showMessage(QString);
    void showPaper();
    void endExamslot();
     void sendExamslot();
private:
    ExamUI *exam;
};

#endif // MAINFRAMEUI_H
