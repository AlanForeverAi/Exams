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
    for(int i = 0; i < typeList.count(); ++i){
        comboBox->addItem(typeList.at(i));
    }
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
//    if(tabWidget->currentIndex() == 0)
//    {
//        if(lineEdit_userID->text() == "" || lineEdit_userName->text() == "" || lineEdit_userClass->text() == "" ||
//                lineEdit_userGrade->text() == "" || lineEdit_userPwd->text() == ""){
//            QMessageBox::about(this, "msg", QStringLiteral("某项信息未填写！"));
//            return ;
//        }

//        for(QList<Student *>::iterator ite = studentList.begin(); ite != studentList.end(); ++ite){
//            if((*ite)->getID() == lineEdit_userID->text()){
//                QMessageBox::about(this, "msg", QStringLiteral("学生ID已存在！"));
//                return ;
//            }
//        }
//        Student * studentptr =  new Student;
//        studentptr->setID(lineEdit_userID->text());
//        studentptr->setName(lineEdit_userName->text());
//        studentptr->setGrade(lineEdit_userGrade->text().toInt());
//        studentptr->setClass(lineEdit_userClass->text().toInt());
//        studentptr->setPassword(lineEdit_userPwd->text());

//        emit this->addStudent(studentptr);
//        delete(studentptr);
//    }
//    else if(tabWidget->currentIndex() == 1)
//    {
//        if(lineEdit_teacherId->text() == "" || lineEdit_teacherName->text() == "" || lineEdit_teacherPwd->text() == ""){
//            QMessageBox::about(this, "msg", QStringLiteral("某项信息未填写！"));
//            return ;
//        }

//        if(comboBox->currentText() == QStringLiteral("  未选择")){
//            QMessageBox::about(this, "msg", QStringLiteral("用户类型未选择！"));
//            return ;
//        }

//        for(QList<User *>::iterator ite = teacherList.begin(); ite !=  teacherList.end(); ++ite){
//            if((*ite)->getID() == lineEdit_teacherId->text()){
//                QMessageBox::about(this, "msg", QStringLiteral("ID已存在！"));
//                return ;
//            }
//        }
//        for(QList<User *>::iterator ite = managerList.begin(); ite != managerList.end(); ++ite){
//            if((*ite)->getID() == lineEdit_teacherId->text()){
//                QMessageBox::about(this, "msg", QStringLiteral("ID已存在！"));
//                return ;
//            }
//        }

//        User *teacherptr = new User;
//        teacherptr->setID(lineEdit_teacherId->text());
//        teacherptr->setName(lineEdit_teacherName->text());
//        teacherptr->setPassword(lineEdit_teacherPwd->text());
//        teacherptr->setSubject(comboBox->currentText());

//        emit this->addTeacher(teacherptr);
//        delete(teacherptr);
//    }
//    else if(tabWidget->currentIndex() == 2){
//        if(lineEdit_managerId->text() == "" || lineEdit_managerName->text() == "" || lineEdit_managerPwd->text() == ""){
//            QMessageBox::about(this, "msg", QStringLiteral("某项信息未填写！"));
//            return ;
//        }

//        for(QList<User *>::iterator ite = teacherList.begin(); ite != teacherList.end(); ++ite){
//            if((*ite)->getID() == lineEdit_teacherId->text()){
//                QMessageBox::about(this, "msg", QStringLiteral("ID已存在！"));
//                return ;
//            }
//        }

//        for(QList<User *>::iterator ite = managerList.begin(); ite != managerList.end(); ++ite){
//            if((*ite)->getID() == lineEdit_managerId->text()){
//                QMessageBox::about(this, "msg", QStringLiteral("ID已存在！"));
//                return ;
//            }
//        }

//        User *managerptr = new User;
//        managerptr->setID(lineEdit_managerId->text());
//        managerptr->setName(lineEdit_managerName->text());
//        managerptr->setPassword(lineEdit_managerPwd->text());

//        emit this->addManager(managerptr);
//        delete(managerptr);
//    }
//    else if(tabWidget->currentIndex() == 3){
//        if(lineEdit_typeId->text() == "" || lineEdit_typeName->text() == ""){
//            QMessageBox::about(this, "msg", QStringLiteral("某项信息未填写！"));
//            return ;
//        }

//        for(QMap<int, QString>::iterator ite = typeList.begin(); ite != typeList.end(); ++ite){
//            if(ite.key() == lineEdit_typeId->text().toInt()){
//                QMessageBox::about(this, "msg", QStringLiteral("类型ID已存在！"));
//                return ;
//            }
//            if(ite.value() == lineEdit_typeName->text()){
//                QMessageBox::about(this, "msg", QStringLiteral("类型已存在！"));
//                return ;
//            }
//        }

//        emit this->addType(lineEdit_typeId->text().toInt(), lineEdit_typeName->text());
//    }
//    this->textClear();

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
        this->showStudent(studentSearchList);
    }
    else if(tabWidget->currentIndex() == 1)
    {
        teacherSearchList.clear();
        QString s_tosearch;
        s_tosearch = lineEdit_search->text();
        for(int i = 0; i < teacherList.count(); i++)
        {
            if(teacherList.at(i)->getID() == s_tosearch ||
                    teacherList.at(i)->getName() == s_tosearch)
            {
                teacherSearchList.append(teacherList.at(i));
            }
        }
        this->showTeacher(teacherSearchList);
    }
    else if(tabWidget->currentIndex() == 2)
    {
        managerSearchList.clear();
        QString s_tosearch;
        s_tosearch = lineEdit_search->text();
        for(int i = 0; i < managerList.count(); i++){
            if(managerList.at(i)->getID() == s_tosearch ||
                    managerList.at(i)->getName() == s_tosearch)
            {
                managerSearchList.append(managerList.at(i));
            }
        }
        this->showManager(managerSearchList);
    }
    else if(tabWidget->currentIndex() == 3){
        typeSearchList.clear();
        QString s_tosearch;
        s_tosearch = lineEdit_search->text();
        for(QMap<int, QString>::iterator ite = typeList.begin(); ite != typeList.end(); ++ite){
            if(ite.key() == s_tosearch.toInt() || ite.value() == s_tosearch){
                typeSearchList[ite.key()] = ite.value();
            }
        }\
        this->showType(typeSearchList);
    }
}

void MemberManageUI::on_pushButton_all_clicked()
{
    this->showStudent(studentList);
    this->showTeacher(teacherList);
    this->showManager(managerList);
    this->showType(typeList);
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
    lineEdit_teacherId->clear();
    lineEdit_teacherName->clear();
    lineEdit_teacherPwd->clear();
    lineEdit_typeId->clear();
    lineEdit_typeName->clear();
}

void MemberManageUI::studentDialog(QTableWidgetItem *item)
{
    AlterStudent *alterStudentDialog = new AlterStudent();
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
