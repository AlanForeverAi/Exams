#include "InOutPutUI.h"
#include <QFileDialog>
InOutPutUI::InOutPutUI(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
}

void InOutPutUI::on_pushButton_inuser_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,QStringLiteral("选择文件"),"/",QStringLiteral("txt Files (*.txt)"));
    if(!filename.isEmpty())
        emit this->inputUser(filename);
}

void InOutPutUI::on_pushButton_inob_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,QStringLiteral("选择文件"),"/",QStringLiteral("txt Files (*.txt)"));
    if(!filename.isEmpty())
        emit this->inputOb(filename);
}

void InOutPutUI::on_pushButton_insub_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,QStringLiteral("选择文件"),"/",QStringLiteral("txt Files (*.txt)"));
    if(!filename.isEmpty())
        emit this->inputSub(filename);
}

void InOutPutUI::on_pushButton_inpaper_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,QStringLiteral("选择文件"),"/",QStringLiteral("txt Files (*.txt)"));
    if(!filename.isEmpty())
        emit this->inputPaper(filename);
}

void InOutPutUI::on_pushButton_outuser_clicked()
{
    this->outputUser();
}

void InOutPutUI::on_pushButton_outob_clicked()
{
    this->outputOb();
}

void InOutPutUI::on_pushButton_outsub_clicked()
{
    this->outputSub();
}

void InOutPutUI::on_pushButton_outpaper_clicked()
{
    this->outputPaper();
}
