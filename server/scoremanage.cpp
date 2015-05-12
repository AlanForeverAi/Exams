#include "scoremanage.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>

ScoreManageUI::ScoreManageUI(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    tableWidget_paper->verticalHeader()->setHidden(true);
    tableWidget_Detail->verticalHeader()->setHidden(true);

    tableWidget_Detail->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableWidget_Detail->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableWidget_paper->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableWidget_paper->setSelectionMode(QAbstractItemView::SingleSelection);
    tableWidget_paper->horizontalHeader()->setStretchLastSection(true);

    tableWidget_paper->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableWidget_Detail->setEditTriggers(QAbstractItemView::NoEditTriggers);

    radioButton_paperID->setChecked(true);
    radioButton_studentID->setChecked(true);

    paperSelect.addButton(radioButton_paperID, 0);
    paperSelect.addButton(radioButton_papername, 1);
    comboSelect.addButton(radioButton_studentID, 0);
    comboSelect.addButton(radioButton_class, 1);
    comboSelect.addButton(radioButton_grade, 2);

    connect(tableWidget_paper,SIGNAL(itemClicked(QTableWidgetItem*)),this,SLOT(paperChange(QTableWidgetItem*)));
}

ScoreManageUI::~ScoreManageUI()
{

}

void ScoreManageUI::showPapers(QList<Paper *> paperList)
{
    tableWidget_paper->setRowCount(paperList.count());
    for(int i = 0; i < paperList.count(); i++)
    {
        QTableWidgetItem *id = new QTableWidgetItem(QString::number(paperList.at(i)->getPaperId()));
        QTableWidgetItem *description = new QTableWidgetItem(paperList.at(i)->getDescription());
        tableWidget_paper->setItem(i,0,id);
        tableWidget_paper->setItem(i,1,description);
    }
}

void ScoreManageUI::paperChange(QTableWidgetItem * item)
{
    int pid = tableWidget_paper->item( item->row(),0)->text().toInt();
    emit this->getCombo_paperid(pid);
}

void ScoreManageUI::setPapers(QList<Paper *> paperlist)
{
    papers = paperlist;
}

void ScoreManageUI::setCombo(QList<Combo *> combolist)
{
    combos = combolist;
}

//void ScoreManageUI::on_pushButton_search_clicked()
//{
//    emit this->getCombo_id(lineEdit->text());
//}

void ScoreManageUI::showCombo(QList<Combo *> combolist)
{
    tableWidget_Detail->setRowCount(combolist.count());

    for(int i = 0; i < combolist.count(); ++i)
    {

        QTableWidgetItem *u_id = new QTableWidgetItem(combolist.at(i)->getUserId());
        QTableWidgetItem *u_name = new QTableWidgetItem(combolist.at(i)->getName());
        QTableWidgetItem *u_grade = new QTableWidgetItem(QString::number(combolist.at(i)->getGrade()));
        QTableWidgetItem *u_class = new QTableWidgetItem(QString::number(combolist.at(i)->getClass()));

//        QTableWidgetItem *paper_id = new QTableWidgetItem(QString::number(combolist.at(i)->getPaperId()));
        QTableWidgetItem *paper_mark = new QTableWidgetItem(QString::number(combolist.at(i)->getPaperMark()));
        QTableWidgetItem *obmark = new QTableWidgetItem(QString::number(combolist.at(i)->getObmark()));
        QTableWidgetItem *submark = new QTableWidgetItem(QString::number(combolist.at(i)->getSubMark()));
//        QTableWidgetItem *papername = new QTableWidgetItem(combolist.at(i)->getPaperName());

        tableWidget_Detail->setItem(i,0,u_id);
        tableWidget_Detail->setItem(i,1,u_name);
        tableWidget_Detail->setItem(i,2,u_grade);
        tableWidget_Detail->setItem(i,3,u_class);
//        tableWidget_Detail->setItem(i,4,paper_id);
//        tableWidget_Detail->setItem(i,5,papername);
        tableWidget_Detail->setItem(i,4,obmark);
        tableWidget_Detail->setItem(i,5,submark);
        tableWidget_Detail->setItem(i,6,paper_mark);
    }
}

void ScoreManageUI::on_pushButton_print_clicked()
{
    if(tableWidget_paper->currentRow() >= 0)
    {
        QString filename;
        filename.append(QStringLiteral("data/考试成绩_"));
        filename.append(tableWidget_paper->item(tableWidget_paper->currentRow(),1)->text());
        filename.append(".txt");
        QFile print(filename);
        if(!print.open(QIODevice::WriteOnly|QIODevice::Text))
            return;
        QTextStream out(&print);
        out << tableWidget_paper->item(tableWidget_paper->currentRow(),1)->text() << "\n";
        QString temp;
        for(int i = 0; i < tableWidget_Detail->columnCount(); i++)
        {
            temp.append(tableWidget_Detail->horizontalHeaderItem(i)->text());
            temp.append("\t");
        }
        out << temp << "\n";
        temp.clear();

        for(int i = 0; i < tableWidget_Detail->rowCount(); i++)
        {
            for(int j = 0; j < tableWidget_Detail->columnCount(); j++)
            {
                temp.append(tableWidget_Detail->item(i,j)->text());
                temp.append("\t");
            }
            out << temp << "\n";
            temp.clear();
        }
        print.close();
        QMessageBox::about(this,"msg",QStringLiteral("导出成功，文档保存在程序所在data目录下"));
    }
    else
    {
        QMessageBox::about(this,"msg",QStringLiteral("请选择一场考试"));
    }
}

void ScoreManageUI::on_pushButton_delete_clicked()
{
    if(tableWidget_paper->currentRow() >= 0)
    {
        if(tableWidget_Detail->currentRow() >= 0)
        {
            int pid = tableWidget_paper->item(tableWidget_paper->currentRow(),0)->text().toInt();
            QList<QTableWidgetItem *> selectItems = tableWidget_Detail->selectedItems();
            for(int i = 0; i < selectItems.count(); ++i){
                qlonglong uid = tableWidget_Detail->item(selectItems.at(i)->row(), 0)->text().toLongLong();
                emit this->delete_score(pid, uid);
            }
            emit this->getCombo_paperid(pid);
        }
        else
        {
            QMessageBox::about(this,"msg",QStringLiteral("请选择一一个考生"));
        }
    }
    else
    {
        QMessageBox::about(this,"msg",QStringLiteral("请选择一场考试"));
    }
}

void ScoreManageUI::on_pushButton_searchPaper_clicked()
{
    selectedPapers.clear();
    QString s = lineEdit_paper->text();
    if(s == ""){
        QMessageBox::about(this, "msg", QStringLiteral("请填写查找信息！"));
        return ;
    }

    if(paperSelect.checkedId() == 0){
        for(int i = 0; i < papers.count(); ++i){
            if(papers.at(i)->getPaperId() == s.toInt()){
                selectedPapers.append(papers.at(i));
            }
        }
    }
    else if(paperSelect.checkedId() == 1){
        for(int i = 0; i < papers.count(); ++i){
            if(papers.at(i)->getDescription() == s){
                selectedPapers.append(papers.at(i));
            }
        }
    }
    showPapers(selectedPapers);
}

void ScoreManageUI::on_pushButton_allPaper_clicked()
{
    showPapers(papers);
}

void ScoreManageUI::on_pushButton_searchstudent_clicked()
{
    selectedCombos.clear();
    QString s = lineEdit_student->text();
    if(s == ""){
        QMessageBox::about(this, "msg", QStringLiteral("请填写查找信息！"));
        return ;
    }

    if(comboSelect.checkedId() == 0){
        for(int i = 0; i < combos.count(); ++i){
            if(combos.at(i)->getUserId().startsWith(s)){
                selectedCombos.append(combos.at(i));
            }
        }
    }
    else if(comboSelect.checkedId() == 1){
        for(int i = 0; i < combos.count(); ++i){
            if(combos.at(i)->getClass() == s.toInt()){
                selectedCombos.append(combos.at(i));
            }
        }
    }
    else if(comboSelect.checkedId() == 2){
        for(int i = 0; i < combos.count(); ++i){
            if(combos.at(i)->getGrade() == s.toInt()){
                selectedCombos.append(combos.at(i));
            }
        }
    }

    showCombo(combos);
}

void ScoreManageUI::on_pushButton_allStudent_clicked()
{
    showCombo(combos);
}
