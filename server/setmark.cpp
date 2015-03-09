#include "setmark.h"

SetMark::SetMark()
{
    setupUi(this);
}

SetMark::~SetMark()
{

}

int SetMark::getMark()
{
    return mark;
}

void SetMark::on_pushButton_submit_clicked()
{
    if(lineEdit_mark->text() == ""){
        QMessageBox::about(this,"msg",QString("请填写该题的分数"));
        this->close();
    }
    mark = lineEdit_mark->text().toInt();
//    emit this->getMark(mark);
    this->close();
}

void SetMark::on_pushButton_cancel_clicked()
{
    this->close();
}
