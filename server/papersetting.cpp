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
    radioButton_paperid->setChecked(true);
    radioButton_selectstudentnumber->setChecked(true);

    paperSelect.addButton(radioButton_paperid, 0);
    paperSelect.addButton(radioButton_papername, 1);

    studentSelect.addButton(radioButton_selectstudentnumber, 0);
    studentSelect.addButton(radioButton_selectgrade, 1);
    studentSelect.addButton(radioButton_selectclass, 2);
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
    appendStudent.clear();
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

void PaperSetting::setSelectStudent(QStringList studentIDs)
{
    selectedStudent = studentIDs;
}

void PaperSetting::appendExaminee(QStringList studentIDs)
{
    appendStudent.operator +=(studentIDs);
    showSelectStudent(selectedStudent.operator +(appendStudent));
}

void PaperSetting::on_pushButton_searchpaper_clicked()
{
    QString s = lineEdit->text();
    if(s == ""){
        QMessageBox::about(this, "msg", QStringLiteral("请填写查找信息！"));
        return ;
    }

    QList<Paper *> papers;
    if(paperSelect.checkedId() == 0){
        for(int i = 0; i < paperList.count(); ++i){
            if(paperList.at(i)->getPaperId() == s.toInt()){
                papers.append(paperList.at(i));
            }
        }
    }
    else{
        for(int i = 0; i < paperList.count(); ++i){
            if(paperList.at(i)->getDescription() == s){
                papers.append(paperList.at(i));
            }
        }
    }
    showPaper(papers);
}

void PaperSetting::on_pushButton_allpaper_clicked()
{
    showPaper(paperList);
}

void PaperSetting::on_pushButton_searchselectstudent_clicked()
{
    QString s = lineEdit_searchselectstudent->text();
    if(s == ""){
        QMessageBox::about(this, "msg", QStringLiteral("请填写查找信息！"));
        return ;
    }

    QStringList studentIDs;
    if(studentSelect.checkedId() == 0){
        for(int i = 0; i < selectedStudent.count(); ++i){
            if(selectedStudent.at(i) == s){
                studentIDs.append(selectedStudent.at(i));
            }
        }
    }
    else if(studentSelect.checkedId() == 1){
        for(int i = 0; i < studentList.count(); ++i){
            if(studentList.at(i)->getGrade() == s.toInt()){
                if(selectedStudent.contains(studentList.at(i)->getID())){
                    studentIDs.append(studentList.at(i)->getID());
                }
            }
        }
    }
    else{
        for(int i = 0; i < studentList.count(); ++i){
            if(studentList.at(i)->getClass() == s.toInt()){
                if(selectedStudent.contains(studentList.at(i)->getID())){
                    studentIDs.append(studentList.at(i)->getID());
                }
            }
        }
    }
    showSelectStudent(studentIDs);
}

void PaperSetting::on_pushButton_allselectstudent_clicked()
{
    showSelectStudent(selectedStudent);
}

void PaperSetting::on_pushButton_addstudent_clicked()
{
    AddStudent *addStudentDialog = new AddStudent();
    connect(this, SIGNAL(passStudentList(QList<Student*>)), addStudentDialog, SLOT(setStudentList(QList<Student*>)));
    connect(this, SIGNAL(passSelectStudent(QStringList)), addStudentDialog, SLOT(setSelectStudent(QStringList)));
    connect(addStudentDialog, SIGNAL(appendExaminee(QStringList)), this, SLOT(appendExaminee(QStringList)));
    connect(this, SIGNAL(showStudent()), addStudentDialog, SLOT(showStudent()));

    emit this->passStudentList(studentList);
    emit this->passSelectStudent(selectedStudent + appendStudent);
    emit this->showStudent();

    addStudentDialog->exec();
}

void PaperSetting::on_pushButton_deletestudent_clicked()
{

}

void PaperSetting::on_pushButton_import_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, QStringLiteral("导入考生"), "./data", QStringLiteral("csv Files (*.csv)"));
    emit this->importExaminee(filename);
}

void PaperSetting::on_pushButton_save_clicked()
{
    int id = tableWidget_allpaper->item(tableWidget_allpaper->currentRow(), 0)->text().toInt();
    selectedStudent += appendStudent;
    appendStudent.clear();
    emit this->saveExaminee(id, selectedStudent);
}
