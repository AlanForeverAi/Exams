#include "papersetting.h"

PaperSetting::PaperSetting(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    tableWidget_allpaper->verticalHeader()->setHidden(true);
    tableWidget_allpaper->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableWidget_allpaper->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableWidget_selectstudent->verticalHeader()->setHidden(true);
    tableWidget_selectstudent->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableWidget_selectstudent->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    connect(tableWidget_allpaper, SIGNAL(itemClicked(QTableWidgetItem*)), this, SLOT(changePaper(QTableWidgetItem*)));
}

PaperSetting::~PaperSetting()
{

}

void PaperSetting::setPaperList(QList<Paper *> papers)
{
    paperList = papers;
}

void PaperSetting::setStudentList(QList<Student *> students)
{
    studentList = students;
}

//void PaperSetting::setSelectedStudent(QList<Student *>)
//{

//}

void PaperSetting::showPaper(QList<Paper *> papers)
{
    tableWidget_allpaper->setRowCount(papers.count());
    for(int i = 0; i < papers.count(); ++i){
        QTableWidgetItem *id = new QTableWidgetItem(QString::number(papers.at(i)->getPaperId()));
        QTableWidgetItem *papername = new QTableWidgetItem(papers.at(i)->getDescription());

        tableWidget_allpaper->setItem(i, 0, id);
        tableWidget_allpaper->setItem(i, 1, papername);
    }
}

void PaperSetting::changePaper(QTableWidgetItem *item)
{
    tableWidget_selectstudent->clearContents();
    int paperID = tableWidget_allpaper->item(item->row(), 0)->text().toInt();
    emit this->getSelectStudent(paperID);
}

void PaperSetting::showSelectStudent(QStringList studentIDs)
{
    tableWidget_selectstudent->setRowCount(studentIDs.count());
    for(int i = 0, cnt = 0; i < studentList.count(); ++i){
        if(studentIDs.contains(studentList.at(i)->getID())){
            QTableWidgetItem *id = new QTableWidgetItem(studentList.at(i)->getID());
            QTableWidgetItem *name = new QTableWidgetItem(studentList.at(i)->getName());
            QTableWidgetItem *grade = new QTableWidgetItem(QString::number(studentList.at(i)->getGrade()));
            QTableWidgetItem *_class = new QTableWidgetItem(QString::number(studentList.at(i)->getClass()));

            tableWidget_selectstudent->setItem(cnt, 0, id);
            tableWidget_selectstudent->setItem(cnt, 1, name);
            tableWidget_selectstudent->setItem(cnt, 2, grade);
            tableWidget_selectstudent->setItem(cnt, 3, _class);
            ++cnt;
        }
    }
}
