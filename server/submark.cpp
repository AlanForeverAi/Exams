#include "submark.h"
#include <QDebug>
#include <QMessageBox>
SubMarkUI::SubMarkUI(QWidget *parent) :QWidget(parent)
{
    setupUi(this);
    pushButton_Pre->setEnabled(false);
    pushButton_Next->setEnabled(false);
    pushButton_submit->setEnabled(false);
    tableWidget_examInfo->horizontalHeader()->setStretchLastSection(true);
    tableWidget_userInfo->horizontalHeader()->setStretchLastSection(true);

    tableWidget_paper->verticalHeader()->setHidden(true);
    tableWidget_userInfo->verticalHeader()->setHidden(true);

    tableWidget_paper->setSelectionBehavior(QAbstractItemView::SelectRows);//点击选择一行
    tableWidget_paper->horizontalHeader()->setStretchLastSection(true);//自适应列宽
    tableWidget_userInfo->setSelectionBehavior(QAbstractItemView::SelectRows);//点击选择一行

    tableWidget_paper->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableWidget_userInfo->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableWidget_examInfo->setEditTriggers(QAbstractItemView::NoEditTriggers);

    connect(tableWidget_paper,SIGNAL(itemClicked(QTableWidgetItem*)),this,SLOT(paperTableChange(QTableWidgetItem*)));
    connect(tableWidget_userInfo,SIGNAL(itemClicked(QTableWidgetItem*)),this,SLOT(userTableChange(QTableWidgetItem*)));
}

SubMarkUI::~SubMarkUI()
{

}

//显示试卷。。。
void SubMarkUI::showPapers(QList<Paper *> pList)
{
    _paperList = pList;
    tableWidget_paper->setRowCount(pList.count());
    for(int i = 0; i < pList.count(); i++)
    {
        QTableWidgetItem *id = new QTableWidgetItem(QString::number(pList.at(i)->getPaperId()));
        QTableWidgetItem *description = new QTableWidgetItem(pList.at(i)->getDescription());
        tableWidget_paper->setItem(i,0,id);
        tableWidget_paper->setItem(i,1,description);
    }
}

void SubMarkUI::paperTableChange(QTableWidgetItem *item)
{
    _currentPaperId = tableWidget_paper->item(item->row(),0)->text();
    for(int i = 0; i < _paperList.count(); i++)
    {
        if(_paperList.at(i)->getPaperId() == _currentPaperId.toInt())
        {
            int obnumber = _paperList.at(i)->getObQuIds().count(",");
            int subnumber = _paperList.at(i)->getSubQuIds().count(",");

            QTableWidgetItem* id = new QTableWidgetItem(QString::number(_paperList.at(i)->getPaperId()));
            QTableWidgetItem* description = new QTableWidgetItem(_paperList.at(i)->getDescription());
            QTableWidgetItem* obn = new QTableWidgetItem(QString::number(obnumber));
            QTableWidgetItem* subn = new QTableWidgetItem(QString::number(subnumber));

            tableWidget_examInfo->setItem(0,0,id);
            tableWidget_examInfo->setItem(1,0,description);
            tableWidget_examInfo->setItem(2,0,obn);
            tableWidget_examInfo->setItem(3,0,subn);

            int mark = 0;
            if(subnumber)
                mark = _paperList.at(i)->getTotalMark() * (100 - _paperList.at(i)->getPercent()) / 100 / subnumber;
            lineEdit_mark->setText(QString::number(mark));

            QIntValidator *validator  =  new QIntValidator(0,mark,this);//0-mark值之间的整数验证器
            lineEdit_GotMark->setValidator( validator );//0-mark值之间的整数验证器
        }
    }
    pushButton_Pre->setEnabled(false);
    pushButton_Next->setEnabled(false);
    emit this->getUserByPaperId(_currentPaperId.toInt(),QStringLiteral("已完成"));
}

void SubMarkUI::showUserByPaperId(QList<Student*> ulist)
{
    tableWidget_userInfo->setRowCount(ulist.count());
    for(int i = 0; i < ulist.count(); i++)
    {

        QTableWidgetItem *id = new QTableWidgetItem(ulist.at(i)->getID());
        QTableWidgetItem *name = new QTableWidgetItem(ulist.at(i)->getName());
        QTableWidgetItem *grade = new QTableWidgetItem(QString::number(ulist.at(i)->getGrade()));
        QTableWidgetItem *clas = new QTableWidgetItem(QString::number(ulist.at(i)->getClass()));
        QTableWidgetItem *state = new QTableWidgetItem(ulist.at(i)->getState());
        if(state->text() == QStringLiteral("未批改"))
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
    _currentUserId = tableWidget_userInfo->item(item->row(),0)->text();
    emit this->getSubAnswer(_currentPaperId.toInt(),_currentUserId);
}

void SubMarkUI::showSubAnswer(QVector<QString> s)
{
    _sub = s;
    _subNo = 0;
    _subMark.resize(_sub.size() / 2);
    _subMark.fill("0");
    pushButton_Pre->setEnabled(true);
    pushButton_Next->setEnabled(true);
    pushButton_submit->setEnabled(true);
    this->showCurrentAnswer(_subNo);
}

void SubMarkUI::on_pushButton_Pre_clicked()
{
    _subMark.replace(_subNo,lineEdit_GotMark->text());
    if(_subNo - 1 >= 0)
    {
        _subNo--;
        this->showCurrentAnswer(_subNo);
    }
}

void SubMarkUI::on_pushButton_Next_clicked()
{
    _subMark.replace(_subNo,lineEdit_GotMark->text());
    if(_subNo + 1 < (_sub.size() / 2))
    {
        _subNo++;
        this->showCurrentAnswer(_subNo);
    }
}

void SubMarkUI::showCurrentAnswer(int n)
{
    lineEdit_GotMark->setText(_subMark.at(n));
    textBrowser_answser->setText(_sub.at(n));
    textBrowser_title->setText(_sub.at(_sub.size() / 2 + n));
    if(n > 0 && n < _sub.size() / 2)
        pushButton_Pre->setEnabled(true);
    pushButton_Next->setEnabled(true);
    if(n + 1 == _sub.size() / 2)
        pushButton_Next->setEnabled(false);
    if(n == 0)
        pushButton_Pre->setEnabled(false);
}

void SubMarkUI::on_pushButton_submit_clicked()
{
    _subMark.replace(_subNo,lineEdit_GotMark->text());
    pushButton_Pre->setEnabled(false);
    pushButton_Next->setEnabled(false);
    pushButton_submit->setEnabled(false);

    QString mark;
    for(int i = 0; i < _subMark.size(); i++)
    {
        mark.append(_subMark.at(i));
        mark.append(",");
    }
    QStringList list;
    list.append(_currentPaperId);
    list.append(_currentUserId);
    list.append(mark);
    emit this->submitSubMark(list);
    QMessageBox::about(this,QStringLiteral("信息"),QStringLiteral("你的批改已经保存。"));
    tableWidget_userInfo->item(tableWidget_userInfo->currentRow(),4)->setText(QStringLiteral("已批改"));
}
