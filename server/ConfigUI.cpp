#include "ConfigUI.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

ConfigUI::ConfigUI(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    QFile Config("config.ini");
    if(!Config.open(QIODevice::ReadOnly|QIODevice::Text))
        return;
    QTextStream in(&Config);
    QString temp;
    temp=in.readLine();
    temp=temp.mid(temp.indexOf(" ")+1);
    lineEdit_DBname->setText(temp);
    temp=in.readLine();
    temp=temp.mid(temp.indexOf(" ")+1);
    lineEdit_DBuser->setText(temp);
    temp=in.readLine();
    temp=temp.mid(temp.indexOf(" ")+1);
    lineEdit_DBpw->setText(temp);
    temp=in.readLine();
    temp=temp.mid(temp.indexOf(" ")+1);
    lineEdit_port->setText(temp);
    Config.close();
}

void ConfigUI::on_pushButton_save_clicked()
{
    QFile configFile("config.ini");
    if(!configFile.open(QIODevice::WriteOnly|QIODevice::Text))
        return;
    QTextStream out(&configFile);
    out<<"DBname ";
    out<<lineEdit_DBname->text()<<"\n";
    out<<"DBuser ";
    out<<lineEdit_DBuser->text()<<"\n";
    out<<"DBpassword ";
    out<<lineEdit_DBpw->text()<<"\n";
    out<<"port ";
    out<<lineEdit_port->text()<<"\n";
    configFile.close();

    QMessageBox::about(this,"ConfigMSG",tr("保存成功"));

}
