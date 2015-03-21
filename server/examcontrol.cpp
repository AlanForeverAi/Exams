#include "examcontrol.h"

ExamControl::ExamControl()
{
    setupUi(this);
    mode = STATE_EXAMING;
    tableWidget_student->verticalHeader()->setHidden(true);
    tableWidget_student->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableWidget_student->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    _countTimer = new QTimer(this);
    _dateTimer = new QTimer(this);
    connect(_countTimer, SIGNAL(timeout()), this, SLOT(updateCountTime()));
    connect(_dateTimer, SIGNAL(timeout()), this, SLOT(updateDateTime()));
    _dateTimer->start(1000);
    pushButton_pause->setEnabled(false);
    pushButton_continue->setEnabled(false);
    pushButton_end->setEnabled(false);
}

ExamControl::~ExamControl()
{

}

void ExamControl::updateStudentTable(QList<Student *> students)
{
    int numberLogin = 0;
    int numbersubmit = 0;
    tableWidget_student->setRowCount(students.count());
    for(int i = 0; i < students.count(); ++i){
        if(students.at(i)->getState() != QString("未登录"))
            numberLogin++;
        else if(students.at(i)->getState() == QString("已经交卷"))
            numbersubmit++;

        QTableWidgetItem *hostname = new QTableWidgetItem(students.at(i)->getHostname());
        QTableWidgetItem *id = new QTableWidgetItem(students.at(i)->getID());
        QTableWidgetItem *name = new QTableWidgetItem(students.at(i)->getName());
        QTableWidgetItem *grade = new QTableWidgetItem(QString::number(students.at(i)->getGrade()));
        QTableWidgetItem *_class = new QTableWidgetItem(QString::number(students.at(i)->getClass()));
        QTableWidgetItem *state = new QTableWidgetItem(students.at(i)->getState());

        if(state->text() == QString("未登录"))
        {
            state->setTextColor(QColor("red"));
        }

        tableWidget_student->setItem(i, 0, hostname);
        tableWidget_student->setItem(i, 1, id);
        tableWidget_student->setItem(i, 2, name);
        tableWidget_student->setItem(i, 3, grade);
        tableWidget_student->setItem(i, 4, _class);
        tableWidget_student->setItem(i, 5, state);
    }
    label_studentcount->setText(QString("共有%1名学生 已登录%2人 已交卷%3人").arg(students.count()).arg(numberLogin).arg(numbersubmit));
}

void ExamControl::setTime(QTime examTime)
{
    _countTime = examTime;
    timeEdit_papertime->setTime(_countTime);
}

void ExamControl::setPaperName(QString paperName)
{
    label_name->setText(paperName);
}

void ExamControl::updateDateTime()
{
    dateTimeEdit->setTime(QTime::currentTime());
}

void ExamControl::updateCountTime()
{
    _countTime = _countTime.addSecs(-1);
    timeEdit_papertime->setTime(_countTime);
    if(_countTime.secsTo(QTime(0, 0, 0)) == 0){
        _countTimer->stop();

        emit this->endExam();
        label_state->setText(QString("考试结束！！！"));
    }
}

void ExamControl::getcurrentPaperTime(int descriptor)
{
    int time = _countTime.hour() * 3600 + _countTime.minute() * 60 + _countTime.second();
    emit this->sendPaperTime(descriptor, time);
}

void ExamControl::on_pushButton_begin_clicked()
{
    emit this->beginExam();
    _countTimer->start(1000);
    label_state->setText(QString("考试进行中"));
    pushButton_begin->setEnabled(false);
    pushButton_pause->setEnabled(true);
    pushButton_end->setEnabled(true);
    pushButton_back->setEnabled(false);
}

void ExamControl::on_pushButton_pause_clicked()
{
    emit this->pauseExam();   
    if(mode == STATE_EXAMING){
        _countTimer->stop();
        label_state->setText(QString("考试暂停"));
        mode = STATE_PAUSE;
    }
    else if(mode == STATE_PAUSE){
        _countTimer->start(1000);
        label_state->setText(QString("考试进行中"));
        mode = STATE_EXAMING;
    }
}

void ExamControl::on_pushButton_continue_clicked()
{
    emit this->continueExam();
    _countTimer->start(1000);
    label_state->setText(QString("考试进行中"));
    pushButton_continue->setEnabled(false);
    pushButton_pause->setEnabled(true);
}

void ExamControl::on_pushButton_end_clicked()
{
    emit this->endExam();
    pushButton_pause->setEnabled(false);
    pushButton_continue->setEnabled(false);
    pushButton_back->setEnabled(true);
}

