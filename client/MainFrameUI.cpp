#include "MainFrameUI.h"
#include <QPicture>
MainFrameUI::MainFrameUI(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    exam=new ExamUI;
    connect(exam,SIGNAL(sendAnswersingle(All_answers)),this,SIGNAL(sendAnswersSingle(All_answers)));
        connect(exam,SIGNAL(sendAnswersingle(All_answers)),this,SLOT(sendExamslot()));
    connect(exam,SIGNAL(sendAnswers(All_answers)),this,SIGNAL(sendAnswers(All_answers)));
    connect(exam,SIGNAL(sendAnswers(All_answers)),this,SLOT(endExamslot()));
    connect(this,SIGNAL(endExam()),exam,SLOT(submitAnswers()));
    connect(this,SIGNAL(endExam()),this,SLOT(endExamslot()));
    stackedWidget_main->addWidget(exam);
    stackedWidget_main->setCurrentIndex(0);
    label_date->setText(QDate::currentDate().toString());
    //this->showFullScreen();
}

void MainFrameUI::sendExamslot()
{
    label_m->setText(QString("上一题已经提交"));

}

void MainFrameUI::showUserInfo(User u)
{
    QString info=QString("<br>姓名：%1<br>学号：%2<br>年级：%3<br>班级：%4");

    label_userinfo->setText(info.arg(u.getName()).arg(u.getID()).arg(QString::number(u.getGrade())).arg(QString::number(u.getClass())));
}

void MainFrameUI::showMessage(QString message)
{
    label_m->setText(message);
}

void MainFrameUI::paperReady(Paper p)
{
    label_papername->setText(p.getDescription());
    exam->showPaper(p);
}

void MainFrameUI::showPaper()
{
    exam->timer->start(1000);
    stackedWidget_main->setCurrentIndex(1);

}

void MainFrameUI::endExamslot()
{
    label_m->setText(QString("考试已经结束"));
    stackedWidget_main->setCurrentIndex(0);
}
