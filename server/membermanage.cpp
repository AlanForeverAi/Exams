#include "membermanage.h"
#include "alterstudent.h"
#include "alterteacher.h"
#include "altermanager.h"
#include "altertype.h"
#include <iostream>
#include <QMessageBox>
#include <QDebug>

MemberManageUI::MemberManageUI(QWidget *parent) : QWidget(parent)
{
    setupUi(this);
    studentButton.addButton(radioButton_studentid, 0);
    studentButton.addButton(radioButton_class, 1);
    studentButton.addButton(radioButton_grade, 2);
    radioButton_studentid->setChecked(true);
    teacherButton.addButton(radioButton_teacherid, 0);
    teacherButton.addButton(radioButton_subject, 1);
    radioButton_teacherid->setChecked(true);
    managerButton.addButton(radioButton_managerid, 0);
    managerButton.addButton(radioButton_managername, 1);
    radioButton_managerid->setChecked(true);
    tableWidget_Manager->verticalHeader()->setHidden(true);
    tableWidget_Student->verticalHeader()->setHidden(true);
    tableWidget_Teacher->verticalHeader()->setHidden(true);
    tableWidget_Type->verticalHeader()->setHidden(true);

    tableWidget_Manager->setSelectionBehavior(QAbstractItemView::SelectRows);//点击选择一行
    tableWidget_Manager->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//自适应列宽
    tableWidget_Student->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableWidget_Student->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableWidget_Teacher->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableWidget_Teacher->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableWidget_Type->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableWidget_Type->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    tableWidget_Student->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableWidget_Teacher->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableWidget_Manager->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableWidget_Type->setEditTriggers(QAbstractItemView::NoEditTriggers);

    connect(tableWidget_Student, SIGNAL(itemDoubleClicked(QTableWidgetItem *)), this, SLOT(studentDialog(QTableWidgetItem *)));
    connect(tableWidget_Teacher, SIGNAL(itemDoubleClicked(QTableWidgetItem *)), this, SLOT(teacherDialog(QTableWidgetItem *)));
    connect(tableWidget_Manager, SIGNAL(itemDoubleClicked(QTableWidgetItem *)), this, SLOT(managerDialog(QTableWidgetItem *)));
    connect(tableWidget_Type, SIGNAL(itemDoubleClicked(QTableWidgetItem *)), this, SLOT(typeDialog(QTableWidgetItem *)));
}

MemberManageUI::~MemberManageUI()
{

}

void MemberManageUI::showManager(QList<User *> listManager)
{
    tableWidget_Manager->setRowCount(listManager.count());
    for(int i = 0; i < listManager.count(); ++i){
        QTableWidgetItem *id = new QTableWidgetItem(listManager.at(i)->getID());
        QTableWidgetItem *name= new QTableWidgetItem(listManager.at(i)->getName());
        QTableWidgetItem *password = new QTableWidgetItem(listManager.at(i)->getPassword());

        tableWidget_Manager->setItem(i, 0, id);
        tableWidget_Manager->setItem(i, 1, name);
        tableWidget_Manager->setItem(i, 2, password);
    }
}

void MemberManageUI::showStudent(QList<Student *> listStudent)
{
    tableWidget_Student->setRowCount(listStudent.count());
    for(int i = 0; i < listStudent.count(); ++i)
    {
        QTableWidgetItem *u_id = new QTableWidgetItem(listStudent.at(i)->getID());
        QTableWidgetItem *u_name = new QTableWidgetItem(listStudent.at(i)->getName());
        QTableWidgetItem *u_grade = new QTableWidgetItem(QString::number(listStudent.at(i)->getGrade()));
        QTableWidgetItem *u_class = new QTableWidgetItem(QString::number(listStudent.at(i)->getClass()));
        QTableWidgetItem *u_password = new QTableWidgetItem(listStudent.at(i)->getPassword());

        tableWidget_Student->setItem(i, 0, u_id);
        tableWidget_Student->setItem(i, 1, u_name);
        tableWidget_Student->setItem(i, 2, u_grade);
        tableWidget_Student->setItem(i, 3, u_class);
        tableWidget_Student->setItem(i, 4, u_password);
    }
}

void MemberManageUI::showTeacher(QList<User *>listTeacher)
{
    tableWidget_Teacher->setRowCount(listTeacher.count());
    for(int i = 0; i < listTeacher.count(); ++i)
    {
        QTableWidgetItem *t_id = new QTableWidgetItem(listTeacher.at(i)->getID());
        QTableWidgetItem *t_name = new QTableWidgetItem(listTeacher.at(i)->getName());
        QTableWidgetItem *t_password = new QTableWidgetItem(listTeacher.at(i)->getPassword());
        QTableWidgetItem *t_subject = new QTableWidgetItem(listTeacher.at(i)->getSubject());

        tableWidget_Teacher->setItem(i, 0, t_id);
        tableWidget_Teacher->setItem(i, 1, t_name);
        tableWidget_Teacher->setItem(i, 2, t_password);
        tableWidget_Teacher->setItem(i, 3, t_subject);
    }
}

void MemberManageUI::showSubject(QList<QString> typeList)
{

}

void MemberManageUI::showType(QMap<int, QString> type)
{
    if(typeList.count() == 0)
        typeList = type;

    tableWidget_Type->setRowCount(type.count());
    QMap<int, QString>::iterator ite = type.begin();
    for(int i = 0; ite != type.end(); ++i, ++ite){
        QTableWidgetItem *id = new QTableWidgetItem(QString::number(ite.key()));
        QTableWidgetItem *type = new QTableWidgetItem(ite.value());

        tableWidget_Type->setItem(i, 0, id);
        tableWidget_Type->setItem(i, 1, type);
    }
}

void MemberManageUI::on_pushButton_add_user_clicked()
{
    AddInformation *addinformationDialog = new AddInformation;
    addinformationDialog->setWindowTitle("添加用户");
    connect(addinformationDialog, SIGNAL(addStudent(Student*)), this, SIGNAL(addStudent(Student*)));
    connect(addinformationDialog, SIGNAL(addTeacher(User*)), this, SIGNAL(addTeacher(User*)));
    connect(addinformationDialog, SIGNAL(addManager(User*)), this, SIGNAL(addManager(User*)));
    connect(addinformationDialog, SIGNAL(addType(int,QString)), this, SIGNAL(addType(int,QString)));

    addinformationDialog->exec();
}

void MemberManageUI::on_pushButton_delete_user_clicked()
{
    QMessageBox msg;
    msg.setText(QStringLiteral("确定要删除吗？"));
    msg.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    if(tabWidget->currentIndex() == 0 && tableWidget_Student->currentRow() >= 0)
    {
        int ret = msg.exec();
        if(ret == QMessageBox::Ok){
            QList<QTableWidgetItem *> selectItems = tableWidget_Student->selectedItems();
            for(int i = 0; i < selectItems.count(); ++i){
                emit this->deleteUserId(tableWidget_Student->item(selectItems.at(i)->row(), 0)->text());
            }
        }
        else
            return;
    }
    else if(tabWidget->currentIndex() == 1 && tableWidget_Teacher->currentRow() >= 0)
    {
        int ret = msg.exec();
        if(ret == QMessageBox::Ok){
            QList<QTableWidgetItem *> selectItems = tableWidget_Teacher->selectedItems();
            for(int i = 0; i < selectItems.count(); ++i){
                emit this->deleteManagerId(tableWidget_Teacher->item(selectItems.at(i)->row(), 0)->text().toInt());
            }
        }
        else
            return;
    }
    else if(tabWidget->currentIndex() == 2 && tableWidget_Manager->currentRow() >= 0){
        int ret = msg.exec();
        if(ret == QMessageBox::Ok){
            QList<QTableWidgetItem *> selectItems = tableWidget_Manager->selectedItems();
            for(int i = 0; i < selectItems.count(); ++i){
                emit this->deleteManagerId(tableWidget_Manager->item(selectItems.at(i)->row(), 0)->text().toInt());
            }
        }
        else
            return;
    }
    else if(tabWidget->currentIndex() == 3 && tableWidget_Type->currentRow() >= 0){
        int ret = msg.exec();
        if(ret == QMessageBox::Ok){
            QList<QTableWidgetItem *> selectItems = tableWidget_Type->selectedItems();
            for(int i = 0; i < selectItems.count(); ++i){
                emit this->deleteType(tableWidget_Type->item(selectItems.at(i)->row(), 0)->text().toInt());
            }
        }
        else
            return;
    }
    else
    {
        QMessageBox::about(this, "msg", QStringLiteral("请选择你要删除的一项"));
    }
}

void MemberManageUI::textClear()
{

}

void MemberManageUI::studentDialog(QTableWidgetItem *item)
{
    AlterStudent *alterStudentDialog = new AlterStudent();
    alterStudentDialog->setWindowTitle("修改学生");
    connect(this, SIGNAL(showStudent(Student*)), alterStudentDialog, SLOT(showStudent(Student*)));
    connect(alterStudentDialog, SIGNAL(updateStudent(Student*)), this, SIGNAL(updateStudent(Student*)));

    Student *student = NULL;
    QString id = tableWidget_Student->item(item->row(), 0)->text();
    for(QList<Student *>::iterator ite = studentList.begin(); ite != studentList.end(); ++ite){
        if((*ite)->getID() == id){
            student = *ite;
        }
    }

    emit this->showStudent(student);
    alterStudentDialog->exec();
}

void MemberManageUI::teacherDialog(QTableWidgetItem *item)
{
    AlterTeacher *alterTeacherDialog = new AlterTeacher();
    alterTeacherDialog->setWindowTitle("修改教师");
    connect(this, SIGNAL(showTypeList(QList<QString>)), alterTeacherDialog, SLOT(showTypeList(QList<QString>)));
    connect(this, SIGNAL(showTeacher(User*)), alterTeacherDialog, SLOT(showTeacher(User*)));
    connect(alterTeacherDialog, SIGNAL(updateTeacher(User*)), this, SIGNAL(updateTeacher(User*)));

    User *teacher = NULL;
    QString id = tableWidget_Teacher->item(item->row(), 0)->text();
    for(QList<User *>::iterator ite = teacherList.begin(); ite != teacherList.end(); ++ite){
        if((*ite)->getID() == id){
            teacher = *ite;
        }
    }

    emit this->showTypeList(typeList.values());
    emit this->showTeacher(teacher);
    alterTeacherDialog->exec();
}

void MemberManageUI::managerDialog(QTableWidgetItem *item)
{
    AlterManager *alterManagerDialog = new AlterManager();
    alterManagerDialog->setWindowTitle("修改管理员");
    connect(this, SIGNAL(showManager(User*)), alterManagerDialog, SLOT(showManager(User*)));
    connect(alterManagerDialog, SIGNAL(updateManager(User*)), this, SIGNAL(updateManager(User*)));

    User *manager = NULL;
    QString id = tableWidget_Manager->item(item->row(), 0)->text();
    for(QList<User *>::iterator ite = managerList.begin(); ite != managerList.end(); ++ite){
        if((*ite)->getID() == id){
            manager = *ite;
        }
    }

    emit this->showManager(manager);
    alterManagerDialog->exec();
}

void MemberManageUI::typeDialog(QTableWidgetItem *item)
{
    AlterType *alterTypeDialog = new AlterType();
    alterTypeDialog->setWindowTitle("修改类型");
    connect(this, SIGNAL(showType(int, QString)), alterTypeDialog, SLOT(showType(int, QString)));
    connect(alterTypeDialog, SIGNAL(updateType(int, QString)), this, SIGNAL(updateType(int, QString)));

    int id = tableWidget_Type->item(item->row(), 0)->text().toInt();
    QString type;
    for(QMap<int, QString>::iterator ite = typeList.begin(); ite != typeList.end(); ++ite){
        if(ite.key() == id){
            type = ite.value();
        }
    }

    emit this->showType(id, type);
    alterTypeDialog->exec();
}

void MemberManageUI::updateStudentList(QList<Student *> students)
{
    studentList = students;
}

void MemberManageUI::updateTeacherList(QList<User *> teachers)
{
    teacherList = teachers;
}

void MemberManageUI::updateManagerList(QList<User *> managers)
{
    managerList = managers;
}

void MemberManageUI::updateTypeList(QMap<int, QString> types)
{
    typeList = types;
}

void MemberManageUI::on_pushButton_export_clicked()
{
    QDir dir(".");
    if(!dir.exists("data"))
    {
        dir.mkdir("data");
    }
    if(tabWidget->currentIndex() == 0){
        QString filename = QFileDialog::getSaveFileName(this, QStringLiteral("导出学生"), "./data", QStringLiteral("excel Files (*.xls)"));
        emit this->exportStudent(studentList, filename);
    }
    else if(tabWidget->currentIndex() == 1){
        QString filename = QFileDialog::getSaveFileName(this, QStringLiteral("导出教师"), "./data", QStringLiteral("excel Files (*.xls)"));
        emit this->exportTeacher(teacherList, filename);
    }
    else if(tabWidget->currentIndex() == 2){
        QString filename = QFileDialog::getSaveFileName(this, QStringLiteral("导出管理员"), "./data", QStringLiteral("excel Files (*.xls)"));
        emit this->exportManager(managerList, filename);
    }
    else if(tabWidget->currentIndex() == 3){
        QString filename = QFileDialog::getSaveFileName(this, QStringLiteral("导出类型"), "./data", QStringLiteral("excel Files (*.xls)"));
        emit this->exportType(typeList, filename);
    }
}

void MemberManageUI::on_pushButton_import_clicked()
{
    QDir dir(".");
    if(!dir.exists("data"))
    {
        dir.mkdir("data");
    }
    if(tabWidget->currentIndex() == 0){
        QString filename = QFileDialog::getOpenFileName(this, QStringLiteral("导入学生"), "./data", QStringLiteral("excel Files (*.xls)"));
        if(filename != "")
            emit this->importStudent(filename);
    }
    else if(tabWidget->currentIndex() == 1){
        QString filename = QFileDialog::getOpenFileName(this, QStringLiteral("导入老师"), "./data", QStringLiteral("excel Files (*.xls)"));
        if(filename != "")
            emit this->importTeacher(filename);
    }
    else if(tabWidget->currentIndex() == 2){
        QString filename = QFileDialog::getOpenFileName(this, QStringLiteral("导入管理员"), "./data", QStringLiteral("excel Files (*.xls)"));
        if(filename != "")
            emit this->importManager(filename);
    }
    else if(tabWidget->currentIndex() == 3){
        QString filename = QFileDialog::getOpenFileName(this, QStringLiteral("导入科目"), "./data", QStringLiteral("excel Files (*.xls)"));
        if(filename != "")
            emit this->importType(filename);
    }
}

void MemberManageUI::on_search_student_clicked()
{
    studentSearchList.clear();
    QString s = lineEdit_student->text();
    if(s == ""){
        QMessageBox::about(this, "msg", QStringLiteral("请填写查找信息！"));
        return ;
    }

    if(studentButton.checkedId() == 0){
        for(int i =  0; i < studentList.count(); ++i){
            if(studentList.at(i)->getID().startsWith(s)){
                studentSearchList.append(studentList.at(i));
            }
        }
    }

    else if(studentButton.checkedId() == 1){
        for(int i = 0; i < studentList.count(); ++i){
            if(studentList.at(i)->getClass() == s.toInt()){
                studentSearchList.append(studentList.at(i));
            }
        }
    }

    else if(studentButton.checkedId() == 2){
        for(int i = 0; i < studentList.count(); ++i){
            if(studentList.at(i)->getGrade() == s.toInt()){
                studentSearchList.append(studentList.at(i));
            }
        }
    }
    showStudent(studentSearchList);
}

void MemberManageUI::on_all_student_clicked()
{
    showStudent(studentList);
}

void MemberManageUI::on_search_teacher_clicked()
{
    teacherSearchList.clear();
    QString s = lineEdit_teacher->text();
    if(s == ""){
        QMessageBox::about(this, "msg", QStringLiteral("请填写查找信息！"));
        return ;
    }

    if(teacherButton.checkedId() == 0){
        for(int i = 0; i < teacherList.count(); ++i){
            if(teacherList.at(i)->getID().startsWith(s)){
                teacherSearchList.append(teacherList.at(i));
            }
        }
    }

    else if(teacherButton.checkedId() == 1){
        for(int i = 0; i < teacherList.count(); ++i){
            if(teacherList.at(i)->getSubject() == s){
                teacherSearchList.append(teacherList.at(i));
            }
        }
    }

    showTeacher(teacherSearchList);
}

void MemberManageUI::on_all_teacher_clicked()
{
    showTeacher(teacherList);
}

void MemberManageUI::on_search_manager_clicked()
{
    managerSearchList.clear();
    QString s = lineEdit_manager->text();
    if(s == ""){
        QMessageBox::about(this, "msg", QStringLiteral("请填写查找信息！"));
        return ;
    }

    if(managerButton.checkedId() == 0){
        for(int i = 0; i < managerList.count(); ++i){
            if(managerList.at(i)->getID().startsWith(s)){
                managerSearchList.append(managerList.at(i));
            }
        }
    }
    else if(managerButton.checkedId() == 1){
        for(int i = 0; i < managerList.count(); ++i){
            if(managerList.at(i)->getName() == s){
                managerSearchList.append(managerList.at(i));
            }
        }
    }

    showManager(managerSearchList);
}

void MemberManageUI::on_all_manager_clicked()
{
    showManager(managerList);
}
