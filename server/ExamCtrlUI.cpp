#include "ExamCtrlUI.h"
#include <QMessageBox>
#include <QDebug>
ExamCtrlUI::ExamCtrlUI(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    pushButton_end->setEnabled(false);
    pushButton_begin->setEnabled(false);
    tableWidget_user->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//自适应列宽

    _countTimer = new QTimer(this);
    connect(_countTimer,SIGNAL(timeout()),this,SLOT(counttimeUpdate()));
    _dateTimer = new QTimer(this);
    connect(_dateTimer,SIGNAL(timeout()),this,SLOT(datetimeUpdate()));
    _dateTimer->start(1000);

    label_state->setText(QString("没有设置考试"));

}
ExamCtrlUI::~ExamCtrlUI()
{

}
void ExamCtrlUI::showPapers(QList<Paper*> pList)
{

    tableWidget_paper->setSelectionBehavior(QAbstractItemView::SelectRows);//点击选择一行
    tableWidget_paper->horizontalHeader()->setStretchLastSection(true);//自适应列宽
    tableWidget_paper->setRowCount(pList.count());
    for(int i = 0; i < pList.count(); i++)
    {

        QTableWidgetItem *id = new QTableWidgetItem(QString::number(pList.at(i)->getPaperId()));
        QTableWidgetItem *description = new QTableWidgetItem(pList.at(i)->getDescription());
        QTableWidgetItem *time = new QTableWidgetItem(QString::number(pList.at(i)->getTime()/60));
        tableWidget_paper->setItem(i,0,id);
        tableWidget_paper->setItem(i,1,description);
        tableWidget_paper->setItem(i,2,time);
    }
}



void ExamCtrlUI::on_pushButton_begin_clicked()
{

    QMessageBox::about(this,"msg",QString("考试已经开始，请不要关闭程序，在结束之前都不能切换到其他页面。"));

    pushButton_begin->setEnabled(false);
    pushButton_back->setEnabled(false);
    pushButton_end->setEnabled(true);
    pushButton_send->setEnabled(false);
    tableWidget_paper->setEnabled(false);
    _countTimer->start(1000);

    label_state->setText(QString("考试进行中"));

}

void ExamCtrlUI::on_pushButton_end_clicked()
{
    QMessageBox msg;
    msg.setText(QString("将要结束考试，并强制所有学生提交答案\n是否继续？"));
    int ret = msg.exec();
    if(ret == QMessageBox::Ok)
    {
        pushButton_send->setEnabled(true);
        pushButton_begin->setEnabled(true);
        pushButton_end->setEnabled(false);
        pushButton_back->setEnabled(true);
        tableWidget_paper->setEnabled(true);
        _countTimer->stop();
        emit this->endExam();
        label_state->setText(QString("考试已经结束"));
    }
    else
    {
        return;
    }
}

void ExamCtrlUI::counttimeUpdate()
{
    _countTime = _countTime.addSecs(-1);
    timeEdit_papertime->setTime(_countTime);
    if(_countTime.secsTo(QTime(0,0,0)) == 0)
    {
        pushButton_send->setEnabled(true);
        pushButton_begin->setEnabled(true);
        pushButton_end->setEnabled(false);
        pushButton_back->setEnabled(true);
        tableWidget_paper->setEnabled(true);
        _countTimer->stop();

        emit this->endExam();
        label_state->setText(QString("考试已经结束"));
    }

}

void ExamCtrlUI::datetimeUpdate()
{
    dateTimeEdit->setTime(QTime::currentTime());
}

void ExamCtrlUI::updateUserTable(QList<Student *> userlist)
{
    tableWidget_user->setSelectionBehavior(QAbstractItemView::SelectRows);//点击选择一行
    tableWidget_user->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//自适应列宽
    tableWidget_user->setRowCount(userlist.count());
    for(int i = 0; i < userlist.count(); i++)
    {

        QTableWidgetItem *hostname = new QTableWidgetItem(userlist.at(i)->getHostname());
        QTableWidgetItem *id = new QTableWidgetItem(userlist.at(i)->getID());
        QTableWidgetItem *username = new QTableWidgetItem(userlist.at(i)->getName());
        QTableWidgetItem *grade = new QTableWidgetItem(QString::number(userlist.at(i)->getGrade()));
        QTableWidgetItem *_class = new QTableWidgetItem(QString::number(userlist.at(i)->getClass()));
        QTableWidgetItem *state = new QTableWidgetItem(userlist.at(i)->getState());
        if(state->text() == QString("未登录"))
        {
            state->setTextColor(QColor("red"));
        }
        tableWidget_user->setItem(i,0,hostname);
        tableWidget_user->setItem(i,1,id);
        tableWidget_user->setItem(i,2,username);
        tableWidget_user->setItem(i,3,grade);
        tableWidget_user->setItem(i,4,_class);
        tableWidget_user->setItem(i,5,state);
    }

    int numberlogin = 0;
    int numbersubmit = 0;
    for(int i = 0; i < userlist.count(); i++)
    {
        if(userlist.at(i)->getState() != QString("未登录"))
            numberlogin++;
        if(userlist.at(i)->getState() == QString("已经交卷"))
            numbersubmit++;
    }
    label_usercount->setText(QString("共有%1名学生    已登录%2人  已交卷%3人")
                             .arg(userlist.count())
                             .arg(numberlogin)
                             .arg(numbersubmit));
}

void ExamCtrlUI::on_pushButton_send_clicked()
{
    if(tableWidget_paper->currentRow() >= 0)
    {
        label_name->setText(tableWidget_paper->item(tableWidget_paper->currentRow(),1)->text());
        int time = tableWidget_paper->item(tableWidget_paper->currentRow(),2)->text().toInt();
        _countTime.setHMS(time/60,time%60,0);
        timeEdit_papertime->setTime(_countTime);
        int paperid = tableWidget_paper->item(tableWidget_paper->currentRow(),0)->text().toInt();
        emit this->sendPaper(paperid);
    }
    else
    {
        QMessageBox::about(this,"msg",QString("请选择一个试卷"));
    }
    pushButton_begin->setEnabled(true);
    label_state->setText(QString("考试还没开始"));

    QStringList info;
    info.append(lineEdit_windowtitle->text());
    info.append(lineEdit_welcome->text());
    info.append(lineEdit_NO->text());
    info.append(lineEdit_pici->text());
    info.append(textEdit_message->toPlainText());

    this->sendInfo(info);
}

void ExamCtrlUI::getcurrentPaperTime(int descriptor)
{
    int time = _countTime.hour() * 3600 + _countTime.minute() * 60 + _countTime.second();
    emit this->sendPaperTime(descriptor,time);
}
