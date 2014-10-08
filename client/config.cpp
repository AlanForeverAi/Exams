#include "config.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
Config::Config(QWidget *parent) :
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
    lineEdit_IP->setText(temp);
    temp=in.readLine();
    temp=temp.mid(temp.indexOf(" ")+1);
    lineEdit_port->setText(temp);
    Config.close();
}

void Config::on_pushButton_save_clicked()
{
    QFile configFile("config.ini");
    if(!configFile.open(QIODevice::WriteOnly|QIODevice::Text))
        return;
    QTextStream out(&configFile);
    out<<"IP ";
    out<<lineEdit_IP->text()<<"\n";
    out<<"port ";
    out<<lineEdit_port->text()<<"\n";
    configFile.close();

    QMessageBox::about(this,"msg",tr("保存成功。"));

}
