#include "score.h"

Score::Score(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    tableWidget_score->setSelectionBehavior(QAbstractItemView::SelectRows);//点击选择一行
    tableWidget_score->horizontalHeader()->setStretchLastSection(true);//自适应列宽
}

void Score::showScore(QList<Combo> list)
{

    tableWidget_score->setRowCount(list.count());
    for(int i=0;i<list.count();i++)
    {

        QTableWidgetItem *papername=new QTableWidgetItem(list.value(i).getPaperName());
        QTableWidgetItem *obmark=new QTableWidgetItem(QString::number(list.value(i).getObmark()));
        QTableWidgetItem *subbmark=new QTableWidgetItem(QString::number(list.value(i).getSubMark()));
        QTableWidgetItem *totalmark=new QTableWidgetItem(QString::number(list.value(i).getPaper_mark()));
        tableWidget_score->setItem(i,0,papername);
        tableWidget_score->setItem(i,1,obmark);
        tableWidget_score->setItem(i,2,subbmark);
        tableWidget_score->setItem(i,3,totalmark);
    }
}
