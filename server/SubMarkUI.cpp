#include "SubMarkUI.h"
#include<QDebug>
#include<QMessageBox>
SubMarkUI::SubMarkUI(QWidget *parent) :QWidget(parent)
{
    setupUi(this);
    pushButton_Pre->setEnabled(false);
    pushButton_Next->setEnabled(false);
    pushButton_submit->setEnabled(false);
    tableWidget_examInfo->horizontalHeader()->setStretchLastSection(true);
    tableWidget_userInfo->horizontalHeader()->setStretchLastSection(true);

    connect(tableWidget_paper,SIGNAL(itemClicked(QTableWidgetItem*)),this,SLOT(paperTableChange(QTableWidgetItem*)));
    connect(tableWidget_userInfo,SIGNAL(itemClicked(QTableWidgetItem*)),this,SLOT(userTableChange(QTableWidgetItem*)));
}

SubMarkUI::~SubMarkUI()
{

}

void SubMarkUI::showPapers(QList<Paper *> pList)
{
    paperList=pList;
    tableWidget_paper->setSelectionBehavior(QAbstractItemView::SelectRows);//点击选择一行
    tableWidget_paper->horizontalHeader()->setStretchLastSection(true);//自适应列宽
    tableWidget_paper->setRowCount(pList.count());
    for(int i=0; i<pList.count(); i++)
    {

        QTableWidgetItem *id=new QTableWidgetItem(QString::number(pList.at(i)->getPaper_id()));
        QTableWidgetItem *description=new QTableWidgetItem(pList.at(i)->getDescription());

        tableWidget_paper->setItem(i,0,id);
        tableWidget_paper->setItem(i,1,description);


    }
}

void SubMarkUI::paperTableChange(QTableWidgetItem *item)
{

    currentPaperid=tableWidget_paper->item(item->row(),0)->text();

    for(int i=0; i<paperList.count(); i++)
    {
        if(paperList.at(i)->getPaper_id()==currentPaperid.toInt())
        {

            int obnumber=paperList.at(i)->getOb_qu_ids().count(",");
            int subnumber=paperList.at(i)->getSub_qu_ids().count(",");

            QTableWidgetItem* id=new QTableWidgetItem(QString::number(paperList.at(i)->getPaper_id()));
            QTableWidgetItem* description=new QTableWidgetItem(paperList.at(i)->getDescription());
            QTableWidgetItem* obn=new QTableWidgetItem(QString::number(obnumber));
            QTableWidgetItem* subn=new QTableWidgetItem(QString::number(subnumber));

            tableWidget_examInfo->setItem(0,0,id);
            tableWidget_examInfo->setItem(1,0,description);
            tableWidget_examInfo->setItem(2,0,obn);
            tableWidget_examInfo->setItem(3,0,subn);

            int mark=0;
            if(subnumber)
                mark=paperList.at(i)->getTotal_mark()*(100-paperList.at(i)->getPercent())/100/subnumber;
            lineEdit_mark->setText(QString::number(mark));

            QIntValidator *validator = new QIntValidator(0,mark,this);//0-mark值之间的整数验证器
            lineEdit_GotMark->setValidator( validator );//0-mark值之间的整数验证器


        }
    }
    pushButton_Pre->setEnabled(false);
    pushButton_Next->setEnabled(false);
    emit this->getUserByPaperId(currentPaperid.toInt(),QString("已完成"));
}

void SubMarkUI::showUserByPaperId(QList<Student*> ulist)
{
    tableWidget_userInfo->setSelectionBehavior(QAbstractItemView::SelectRows);//点击选择一行
    tableWidget_userInfo->setRowCount(ulist.count());
    for(int i=0; i<ulist.count(); i++)
    {

        QTableWidgetItem *id=new QTableWidgetItem(ulist.at(i)->getID());
        QTableWidgetItem *name=new QTableWidgetItem(ulist.at(i)->getName());
        QTableWidgetItem *grade=new QTableWidgetItem(QString::number(ulist.at(i)->getGrade()));
        QTableWidgetItem *clas=new QTableWidgetItem(QString::number(ulist.at(i)->getClass()));
        QTableWidgetItem *state=new QTableWidgetItem(ulist.at(i)->getState());
        if(state->text()==QString("未批改"))
        {
            state->setTextColor(QColor("red"));
        }
        tableWidget_userInfo->setItem(i,0,id);
        tableWidget_userInfo->setItem(i,1,name);
        tableWidget_userInfo->setItem(i,2,grade);
        tableWidget_userInfo->setItem(i,3,clas);
        tableWidget_userInfo->setItem(i,4,state);

    }
}

void SubMarkUI::userTableChange(QTableWidgetItem *item)
{

    currentUserid=tableWidget_userInfo->item(item->row(),0)->text();

    emit this->getSubAnswer(currentPaperid.toInt(),currentUserid);
}

void SubMarkUI::showSubAnswer(QVector<QString> s)
{
    sub=s;
    subNo=0;
    submark.resize(sub.size()/2);


    submark.fill("0");

    pushButton_Pre->setEnabled(true);
    pushButton_Next->setEnabled(true);
    pushButton_submit->setEnabled(true);
    this->showCurrentAnswer(subNo);
}

void SubMarkUI::on_pushButton_Pre_clicked()
{
    submark.replace(subNo,lineEdit_GotMark->text());
    if(subNo-1>=0)
    {
        subNo--;
        this->showCurrentAnswer(subNo);
    }
}

void SubMarkUI::on_pushButton_Next_clicked()
{
    submark.replace(subNo,lineEdit_GotMark->text());
    if(subNo+1<sub.size()/2)
    {
        subNo++;
        this->showCurrentAnswer(subNo);
    }
}

void SubMarkUI::showCurrentAnswer(int n)
{

    lineEdit_GotMark->setText(submark.at(n));
    textBrowser_answser->setText(sub.at(n));
    textBrowser_title->setText(sub.at(sub.size()/2+n));



    if(n>0&&n<sub.size()/2)
        pushButton_Pre->setEnabled(true);
    pushButton_Next->setEnabled(true);
    if(n+1==sub.size()/2)
        pushButton_Next->setEnabled(false);
    if(n==0)
        pushButton_Pre->setEnabled(false);
}

void SubMarkUI::on_pushButton_submit_clicked()
{
    submark.replace(subNo,lineEdit_GotMark->text());
    pushButton_Pre->setEnabled(false);
    pushButton_Next->setEnabled(false);
    pushButton_submit->setEnabled(false);


    QString mark;
    for(int i=0; i<submark.size(); i++)
    {
        mark.append(submark.at(i));
        mark.append(",");
    }
    QStringList list;
    list.append(currentPaperid);
    list.append(currentUserid);
    list.append(mark);
    emit this->submitSubMark(list);
    QMessageBox::about(this,QString("信息"),QString("你的批改已经保存。"));
    tableWidget_userInfo->item(tableWidget_userInfo->currentRow(),4)->setText(QString("已批改"));


}
