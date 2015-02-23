#include "alterteacher.h"

AlterTeacher::AlterTeacher()
{
    setupUi(this);
    lineEdit_ID->setFocusPolicy(Qt::NoFocus);
}

AlterTeacher::~AlterTeacher()
{

}

void AlterTeacher::showTeacher(User *teacher)
{
    int index = comboBox->findText(teacher->getSubject());
    lineEdit_ID->setText(teacher->getID());
    lineEdit_Name->setText(teacher->getName());
    lineEdit_Password->setText(teacher->getPassword());
    comboBox->setCurrentIndex(index);
}

void AlterTeacher::showTypeList(QList<QString> typeList)
{
    for(int i = 0; i < typeList.count(); ++i){
        comboBox->addItem(typeList.at(i));
    }
}

void AlterTeacher::on_pushButton_Save_clicked()
{
    if(lineEdit_Name->text() == "" || lineEdit_Password->text() == "")
    {
        QMessageBox::about(this, "msg", QString("某项信息未填写！"));
        return ;
    }

    User *teacher = new User();
    teacher->setID(lineEdit_ID->text());
    teacher->setName(lineEdit_Name->text());
    teacher->setPassword(lineEdit_Password->text());
    teacher->setSubject(comboBox->currentText());

    emit this->updateTeacher(teacher);
    this->close();
}

void AlterTeacher::on_pushButton_Cancel_clicked()
{
    this->close();
}
