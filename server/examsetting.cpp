#include "examsetting.h"

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

         emit this->sendPaper(paperid);
         emit this->sendInfo(info);
         emit this->examPrepare();
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

