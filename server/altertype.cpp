#include "altertype.h"

AlterType::AlterType()
{
    setupUi(this);
    lineEdit_ID->setFocusPolicy(Qt::NoFocus);
}

AlterType::~AlterType()
{

}

void AlterType::showType(int id, QString type)
{
    lineEdit_ID->setText(QString::number(id));
    lineEdit_Type->setText(type);
}

void AlterType::on_pushButton_Save_clicked()
{
    if(lineEdit_Type->text() == "")
    {
        QMessageBox::about(this, "msg", QString("某项信息未填写！"));
        return ;
    }

    emit this->updateType(lineEdit_ID->text().toInt(), lineEdit_Type->text());
    this->close();
}

void AlterType::on_pushButton_Cancel_clicked()
{
    this->close();
}
