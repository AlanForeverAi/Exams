#include "alterstudent.h"

AlterStudent::AlterStudent()
{
    setupUi(this);
    lineEdit_ID->setFocusPolicy(Qt::NoFocus);
}

AlterStudent::~AlterStudent()
{

}

void AlterStudent::showStudent(Student *student)
{
    lineEdit_ID->setText(student->getID());
    lineEdit_Name->setText(student->getName());
    lineEdit_Class->setText(QString::number(student->getClass()));
    lineEdit_Grade->setText(QString::number(student->getGrade()));
    lineEdit_Password->setText(student->getPassword());
}


void AlterStudent::on_pushButton_Save_clicked()
{
    Student *student = new Student();
    student->setID(lineEdit_ID->text());
    student->setName(lineEdit_Name->text());
    student->setClass(lineEdit_Class->text().toInt());
    student->setGrade(lineEdit_Grade->text().toInt());
    student->setPassword(lineEdit_Password->text());

    emit this->updateStudent(student);
    this->close();
}

void AlterStudent::on_pushButton_Cancel_clicked()
{
    this->close();
}
