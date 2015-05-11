#include "addstudent.h"

AddStudent::AddStudent()
{
    setupUi(this);
    studentSelect.addButton(radioButton_studentnumber, 0);
    studentSelect.addButton(radioButton_grade, 1);
    studentSelect.addButton(radioButton_class, 2);
}

AddStudent::~AddStudent()
{

}

void AddStudent::setStudentList(QList<Student *> students)
{
    studentList = students;
}

void AddStudent::setSelectStudent(QStringList studentIDs)
{
    selectStudentIDs = studentIDs;
}

void AddStudent::showStudent()
{
    showStudentList(studentList);
}

void AddStudent::showStudentList(QList<Student *> students)
{
    int count = 0;
    for(int i = 0; i < students.count(); ++i){
        if(selectStudentIDs.contains(students.at(i)->getID()))
            ++count;
    }
    int cnt = 0;
    disconnect(tableWidget_allstudent, SIGNAL(cellChanged(int,int)), this, SLOT(updateCheckStudentIDs(int,int)));
    tableWidget_allstudent->setRowCount(students.count() - count);
    for(int i = 0; i < students.count(); ++i){
        if(!selectStudentIDs.contains(students.at(i)->getID())){
            QTableWidgetItem *check = new QTableWidgetItem();
            if(checkStudentIDs.contains(students.at(i)->getID()))
                check->setCheckState(Qt::Checked);
            else
                check->setCheckState(Qt::Unchecked);
            QTableWidgetItem *id = new QTableWidgetItem(students.at(i)->getID());
            QTableWidgetItem *name = new QTableWidgetItem(students.at(i)->getName());
            QTableWidgetItem *grade = new QTableWidgetItem(QString::number(students.at(i)->getGrade()));
            QTableWidgetItem *_class = new QTableWidgetItem(QString::number(students.at(i)->getClass()));

            tableWidget_allstudent->setItem(cnt, 0, check);
            tableWidget_allstudent->setItem(cnt, 1, id);
            tableWidget_allstudent->setItem(cnt, 2, name);
            tableWidget_allstudent->setItem(cnt, 3, grade);
            tableWidget_allstudent->setItem(cnt, 4, _class);
            ++cnt;
        }
    }
    connect(tableWidget_allstudent, SIGNAL(cellChanged(int,int)), this, SLOT(updateCheckStudentIDs(int,int)));
}

void AddStudent::updateCheckStudentIDs(int row, int col)
{
    if(tableWidget_allstudent->item(row, col)->checkState() == Qt::Checked){
        checkStudentIDs.append(tableWidget_allstudent->item(row, 1)->text());
    }
    else{
        if(checkStudentIDs.isEmpty())
            return;
        checkStudentIDs.removeOne(tableWidget_allstudent->item(row, 1)->text());
    }
}

void AddStudent::on_pushButton_searchstudent_clicked()
{
    QString s = lineEdit_searchstudent->text();
    if(s == ""){
        QMessageBox::about(this, "msg", QStringLiteral("请填写查找信息！"));
        return ;
    }

    QList<Student *> searchStudent;
    if(studentSelect.checkedId() == 0){
        for(int i = 0; i < studentList.count(); ++i){
            if(s == studentList.at(i)->getID()){
                searchStudent.append(studentList.at(i));
            }
        }
    }
    else if(studentSelect.checkedId() == 1){
        for(int i = 0; i < studentList.count(); ++i){
            if(s.toInt() == studentList.at(i)->getGrade()){
                searchStudent.append(studentList.at(i));
            }
        }
    }
    else if(studentSelect.checkedId() == 2){
        for(int i = 0; i < studentList.count(); ++i){
            if(s.toInt() == studentList.at(i)->getClass()){
                searchStudent.append(studentList.at(i));
            }
        }
    }
    showStudentList(searchStudent);
}

void AddStudent::on_pushButton_allstudent_clicked()
{
    showStudent();
}

void AddStudent::on_pushButton_add_clicked()
{
    emit this->appendExaminee(checkStudentIDs);
    this->close();
}

void AddStudent::on_pushButton_cancel_clicked()
{
    this->close();
}
