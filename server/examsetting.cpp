#include "examsetting.h"
#include <QMessageBox>
#include <QDebug>

ExamSettingUI::ExamSettingUI(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    tableWidget_paper->verticalHeader()->setHidden(true);
    tableWidget_paper->setEditTriggers(QAbstractItemView::NoEditTriggers);
    pushButton_closeServer->setEnabled(false);
}
ExamSettingUI::~ExamSettingUI()
{

}
void ExamSettingUI::showPapers(QList<Paper*> pList)
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

void ExamSettingUI::on_pushButton_send_clicked()
{
     if(tableWidget_paper->currentRow() >= 0){
         QStringList info;
         info.append(lineEdit_windowtitle->text());
         info.append(lineEdit_welcome->text());
         info.append(lineEdit_NO->text());
         info.append(lineEdit_pici->text());
         info.append(textEdit_message->toPlainText());
         int paperid = tableWidget_paper->item(tableWidget_paper->currentRow(),0)->text().toInt();

//         ExamControl *examControlDialog = new ExamControl();
//         connect(this, SIGNAL(setExamName(QString)), examControlDialog, SLOT(setExamName(QString)));
//         connect(this, SIGNAL(setTime(QTime)), examControlDialog, SLOT(setTime(QTime)));
//         connect(this, SIGNAL(updateStudentTable(QList<Student*>)), examControlDialog, SLOT(updateStudentTable(QList<Student*>)));
//         connect(this, SIGNAL(getcurrentPaperTime(int)), examControlDialog, SLOT(getcurrentPaperTime(int)));
//         connect(examControlDialog, SIGNAL(beginExam()), this, SIGNAL(beginExam()));
//         connect(examControlDialog, SIGNAL(endExam()), this, SIGNAL(endExam()));
//         connect(examControlDialog, SIGNAL(pauseExam()), this, SIGNAL(pauseExam()));
//         connect(examControlDialog, SIGNAL(continueExam()), this, SIGNAL(continueExam()));
//         connect(examControlDialog, SIGNAL(sendMessage(QString)), this, SIGNAL(sendMessage(QString)));
//         connect(examControlDialog, SIGNAL(sendPaperTime(int,int)), this, SIGNAL(sendPaperTime(int,int)));

//         int time = tableWidget_paper->item(tableWidget_paper->currentRow(), 2)->text().toInt();
//         _countTime.setHMS(time / 60,time % 60, 0);

//         emit this->setExamName(tableWidget_paper->item(tableWidget_paper->currentRow(), 1)->text());
//         emit this->setTime(_countTime);
//         emit this->setPaper(paperid);
//         emit this->setInfo(info);
         emit this->sendPaper(paperid);
         emit this->sendInfo(info);
//         examControlDialog->exec();
     }
     else{
         QMessageBox::about(this,"msg",QStringLiteral("请选择一个试卷"));
     }
}

void ExamSettingUI::on_pushButton_startServer_clicked()
{
    emit this->startServer();
    pushButton_startServer->setEnabled(false);
}

void ExamSettingUI::on_pushButton_closeServer_clicked()
{
    emit this->closeServer();
}

