#include "addinformation.h"

AddInformation::AddInformation()
{
    setupUi(this);
}

AddInformation::~AddInformation()
{

}

void AddInformation::showSubject(QList<QString> subjectList)
{
    for(int i = 0; i < subjectList.count(); ++i){
        comboBox->addItem(subjectList.at(i));
    }
}

void AddInformation::on_pushButton_Add_clicked()
{
    if(tabWidget->currentIndex() == 0){
        if(lineEdit_StudentID->text() == "" || lineEdit_StudentName->text() == "" || lineEdit_StudentPassword->text() == "" ||
                lineEdit_Class->text() == "" || lineEdit_Grade->text() == ""){
            QMessageBox::about(this, "msg", QStringLiteral("某项信息未填写！"));
            return ;
        }

        Student *student = new Student();
        student->setID(lineEdit_StudentID->text());
        student->setName(lineEdit_StudentName->text());
        student->setClass(lineEdit_Class->text().toInt());
        student->setGrade(lineEdit_Grade->text().toInt());
        student->setPassword(lineEdit_StudentPassword->text());

        emit this->addStudent(student);
        delete(student);
    }
    else if(tabWidget->currentIndex() == 1){
        if(lineEdit_TeahcerID->text() == "" || lineEdit_TeacherName->text() == "" || lineEdit_TeahcerID->text() == ""){
            QMessageBox::about(this, "msg", QStringLiteral("某项信息未填写！"));
            return ;
        }

        if(comboBox->currentText() == QStringLiteral("  未选择")){
            QMessageBox::about(this, "msg", QStringLiteral("用户类型未选择！"));
            return ;
        }

        User *teacher = new User();
        teacher->setID(lineEdit_TeahcerID->text());
        teacher->setName(lineEdit_TeacherName->text());
        teacher->setPassword(lineEdit_TeacherPassword->text());
        teacher->setSubject(comboBox->currentText());

        emit this->addTeacher(teacher);
        delete(teacher);
    }
    else if(tabWidget->currentIndex() == 2){
        if(lineEdit_ManagerID->text() == "" || lineEdit_ManagerName->text() == "" || lineEdit_ManagerPassword->text() == ""){
            QMessageBox::about(this, "msg", QStringLiteral("某项信息未填写！"));
            return ;
        }

        User *manager = new User();
        manager->setID(lineEdit_ManagerID->text());
        manager->setName(lineEdit_ManagerName->text());
        manager->setPassword(lineEdit_ManagerPassword->text());

        emit this->addManager(manager);
        delete(manager);
    }
    else if(tabWidget->currentIndex() == 3){
        if(lineEdit_TypeID->text() == "" || lineEdit_TypeName->text() == ""){
            QMessageBox::about(this, "msg", QStringLiteral("某项信息未填写！"));
            return ;
        }

        emit this->addType(lineEdit_TypeID->text().toInt(), lineEdit_TypeName->text());
    }
}

void AddInformation::on_pushButton_Cancel_clicked()
{
    this->close();
}
