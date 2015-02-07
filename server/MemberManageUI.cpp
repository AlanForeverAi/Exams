#include "MemberManageUI.h"
#include "DBManager.h"
#include <iostream>
#include <QMessageBox>
#include <QDebug>

MemberManageUI::MemberManageUI(QWidget *parent) : QWidget(parent)
{
    setupUi(this);
}

MemberManageUI::~MemberManageUI()
{

}

void MemberManageUI::showManager(QList<User *> listManager)
{
    if(managerList.empty())
        managerList = listManager;

    tableWidget_Manager->setSelectionBehavior(QAbstractItemView::SelectRows);//点击选择一行
    tableWidget_Manager->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//自适应列宽
    tableWidget_Manager->setRowCount(listManager.count());
    for(int i = 0; i < listManager.count(); ++i){
        QTableWidgetItem *id = new QTableWidgetItem(QString::number(listManager.at(i)->getId()));
        QTableWidgetItem *name= new QTableWidgetItem(listManager.at(i)->getName());
        QTableWidgetItem *password = new QTableWidgetItem(listManager.at(i)->getPassword());

        tableWidget_Manager->setItem(i, 0, id);
        tableWidget_Manager->setItem(i, 1, name);
        tableWidget_Manager->setItem(i, 2, password);
    }
}

void MemberManageUI::showUser(QList<Student *> listStudent, QList<User *> listTeacher)
{
    if(studentList.empty())
        studentList = listStudent;

    if(teacherList.empty())
        teacherList = listTeacher;

    tableWidget_Student->setSelectionBehavior(QAbstractItemView::SelectRows);//点击选择一行
    tableWidget_Student->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//自适应列宽
    tableWidget_Student->setRowCount(listStudent.count());
    for(int i = 0; i < listStudent.count(); ++i)
    {
        QTableWidgetItem *u_id = new QTableWidgetItem(listStudent.at(i)->getID());
        QTableWidgetItem *u_name = new QTableWidgetItem(listStudent.at(i)->getName());
        QTableWidgetItem *u_grade = new QTableWidgetItem(QString::number(listStudent.at(i)->getGrade()));
        QTableWidgetItem *u_class = new QTableWidgetItem(QString::number(listStudent.at(i)->getClass()));
        QTableWidgetItem *u_password = new QTableWidgetItem(listStudent.at(i)->getPassword());

        tableWidget_Student->setItem(i,0,u_id);
        tableWidget_Student->setItem(i,1,u_name);
        tableWidget_Student->setItem(i,2,u_grade);
        tableWidget_Student->setItem(i,3,u_class);
        tableWidget_Student->setItem(i,4,u_password);
    }

    tableWidget_Teacher->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableWidget_Teacher->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//自适应列宽
    tableWidget_Teacher->setRowCount(listTeacher.count());
    for(int i = 0; i < listTeacher.count(); ++i)
    {
        QTableWidgetItem *t_id = new QTableWidgetItem(QString::number(listTeacher.at(i)->getId()));
        QTableWidgetItem *t_name = new QTableWidgetItem(listTeacher.at(i)->getName());
        QTableWidgetItem *t_password = new QTableWidgetItem(listTeacher.at(i)->getPassword());
        QTableWidgetItem *t_subject = new QTableWidgetItem(listTeacher.at(i)->getSubject());

        tableWidget_Teacher->setItem(i,0,t_id);
        tableWidget_Teacher->setItem(i,1,t_name);
        tableWidget_Teacher->setItem(i,2,t_password);
        tableWidget_Teacher->setItem(i,3,t_subject);
    }
}

void MemberManageUI::showUserType(QList<QString> typeList)
{
    for(int i = 0; i < typeList.count(); ++i){
        comboBox->addItem(typeList.at(i));
    }
}

void MemberManageUI::on_pushButton_add_user_clicked()
{
    if(tabWidget->currentIndex() == 0)
    {
        Student * studentptr =  new Student;
        studentptr->setID(lineEdit_userID->text());
        studentptr->setName(lineEdit_userName->text());
        studentptr->setGrade(lineEdit_userGrade->text().toInt());
        studentptr->setClass(lineEdit_userClass->text().toInt());
        studentptr->setPassword(lineEdit_userPwd->text());

        studentList.append(studentptr);
        emit this->addStudent(studentptr);
        delete(studentptr);
    }
    else if(tabWidget->currentIndex() == 1)
    {
        if(comboBox->currentText() == QStringLiteral("  未选择")){
            QMessageBox::about(this,"msg",QStringLiteral("用户类型未选择！"));
            return ;
        }
        User *teacherptr = new User;
        teacherptr->setId(lineEdit_teacherId->text().toInt());
        teacherptr->setName(lineEdit_teacherName->text());
        teacherptr->setPassword(lineEdit_teacherPwd->text());
        teacherptr->setSubject(comboBox->currentText());

        teacherList.append(teacherptr);
        emit this->addTeacher(teacherptr);       
        delete(teacherptr);
    }
    else if(tabWidget->currentIndex() == 2){
        User *managerptr = new User;
        managerptr->setId(lineEdit_managerId->text().toInt());
        managerptr->setName(lineEdit_managerName->text());
        managerptr->setPassword(lineEdit_managerPwd->text());

        managerList.append(managerptr);
        emit this->addManager(managerptr);
        delete(managerptr);
    }
    this->textClear();
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
            Student *student = NULL;
            for(QList<Student *>::iterator ite = studentList.begin(); ite != studentList.end(); ++ite){
                if((*ite)->getID() == tableWidget_Student->item(tableWidget_Student->currentRow(), 0)->text()){
                    student = *ite;
                    break;
                }
            }
            studentList.removeOne(student);

            emit this->deleteUserId(tableWidget_Student->item(tableWidget_Student->currentRow(), 0)->text());
        }
        else
            return;
    }
    else if(tabWidget->currentIndex() == 1 && tableWidget_Teacher->currentRow() >= 0)
    {
        int ret = msg.exec();
        if(ret == QMessageBox::Ok){
            User *teacher = NULL;
            for(QList<User *>::iterator ite = teacherList.begin(); ite != teacherList.end(); ++ite){
                if((*ite)->getId() == tableWidget_Teacher->item(tableWidget_Teacher->currentRow(), 0)->text().toInt()){
                    teacher = *ite;
                    break;
                }
            }
            teacherList.removeOne(teacher);

            emit this->deleteManagerId(tableWidget_Teacher->item(tableWidget_Teacher->currentRow(), 0)->text().toInt());
        }
        else
            return;
    }
    else if(tabWidget->currentIndex() == 2 && tableWidget_Manager->currentRow() >= 0){
        int ret = msg.exec();
        if(ret == QMessageBox::Ok){
            User *manager = NULL;
            for(QList<User *>::iterator ite = managerList.begin(); ite != managerList.end(); ++ite){
                if((*ite)->getId() == tableWidget_Manager->item(tableWidget_Manager->currentRow(), 0)->text().toInt()){
                    manager = *ite;
                    break;
                }
            }
            managerList.removeOne(manager);

            emit this->deleteManagerId(tableWidget_Manager->item(tableWidget_Manager->currentRow(), 0)->text().toInt());
        }
        else
            return;
    }
    else
    {
        QMessageBox::about(this,"msg",QStringLiteral("请选择一个用户"));
    }
}

void MemberManageUI::on_pushButton_search_clicked()
{
    if(tabWidget->currentIndex() == 0)
    {
        studentSearchList.clear();
        QString s_tosearch;
        s_tosearch = lineEdit_search->text();
        for(int i = 0; i < studentList.count(); i++)
        {
            if(studentList.at(i)->getID() == s_tosearch ||
                    studentList.at(i)->getName() == s_tosearch ||
                    studentList.at(i)->getGrade() == s_tosearch.toInt() ||
                    studentList.at(i)->getClass() == s_tosearch.toInt())
            {
                studentSearchList.append(studentList.at(i));
            }
        }
        this->showUser(studentSearchList,teacherList);
    }
    else if(tabWidget->currentIndex() == 1)
    {
        teacherSearchList.clear();
        QString s_tosearch;
        s_tosearch = lineEdit_search->text();
        for(int i = 0; i < teacherList.count(); i++)
        {
            if(teacherList.at(i)->getId() == s_tosearch.toInt() ||
                    teacherList.at(i)->getName() == s_tosearch)
            {
                teacherSearchList.append(teacherList.at(i));
            }
        }
        this->showUser(studentList,teacherSearchList);
    }
    else if(tabWidget->currentIndex() == 2)
    {
        managerSearchList.clear();
        QString s_tosearch;
        s_tosearch = lineEdit_search->text();
        for(int i = 0; i < managerList.count(); i++){
            if(managerList.at(i)->getId() == s_tosearch.toInt() ||
                    managerList.at(i)->getName() == s_tosearch)
            {
                managerSearchList.append(managerList.at(i));
            }
        }
        this->showManager(managerSearchList);
    }
}

void MemberManageUI::on_pushButton_all_clicked()
{
    this->showUser(studentList,teacherList);
    this->showManager(managerList);
}

void MemberManageUI::textClear()
{
    lineEdit_userID->clear();
    lineEdit_userName->clear();
    lineEdit_userGrade->clear();
    lineEdit_userClass->clear();
    lineEdit_userPwd->clear();
    lineEdit_managerId->clear();
    lineEdit_managerName->clear();
    lineEdit_managerPwd->clear();
}
