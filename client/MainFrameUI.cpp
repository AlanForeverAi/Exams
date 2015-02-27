#include "MainFrameUI.h"
#include <QPicture>
MainFrameUI::MainFrameUI(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    _exam = new ExamUI;
    connect(_exam,SIGNAL(sendAnswersingle(AllAnswers)),this,SIGNAL(sendAnswersSingle(AllAnswers)));
    connect(_exam,SIGNAL(sendAnswersingle(AllAnswers)),this,SLOT(sendExamslot()));
    connect(_exam,SIGNAL(sendAnswers(AllAnswers)),this,SIGNAL(sendAnswers(AllAnswers)));
    connect(_exam,SIGNAL(sendAnswers(AllAnswers)),this,SLOT(endExamslot()));
    connect(this,SIGNAL(endExam()),_exam,SLOT(submitAnswers()));
    connect(this,SIGNAL(endExam()),this,SLOT(endExamslot()));
    stackedWidget_main->addWidget(_exam);
    stackedWidget_main->setCurrentIndex(0);
    label_date->setText(QDate::currentDate().toString());
}

void MainFrameUI::sendExamslot()
{
    label_m->setText(QStringLiteral("上一题已经提交"));

}

void MainFrameUI::pauseExam()
{
    label_m->setText(QStringLiteral("考试暂停！！！"));
    stackedWidget_main->setCurrentIndex(0);
}

void MainFrameUI::continueExam()
{
    stackedWidget_main->setCurrentIndex(1);
}

void MainFrameUI::showUserInfo(Student u)
{
    QString info = QStringLiteral("<br>姓名：%1<br>学号：%2<br>年级：%3<br>班级：%4");

    label_userinfo->setText(info.arg(u.getName()).arg(u.getID()).arg(QString::number(u.getGrade())).arg(QString::number(u.getClass())));
}

void MainFrameUI::showMessage(QString message)
{
    label_m->setText(message);
}

void MainFrameUI::paperReady(Paper p)
{
    label_papername->setText(p.getDescription());
    _exam->showPaper(p);
}

void MainFrameUI::showPaper()
{
    _exam->timer->start(1000);
    stackedWidget_main->setCurrentIndex(1);
}

void MainFrameUI::endExamslot()
{
    label_m->setText(QStringLiteral("考试已经结束"));
    stackedWidget_main->setCurrentIndex(0);
}
