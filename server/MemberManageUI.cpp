#include "MemberManageUI.h"
#include<QMessageBox>
#include<QDebug>
MemberManageUI::MemberManageUI(QWidget *parent) : QWidget(parent)
{
    setupUi(this);
}

MemberManageUI::~MemberManageUI()
{
}

void MemberManageUI::showUser(QList<Student *> userList,QList<Manager *> managerList)
{
    if(userlist.isEmpty())
        userlist=userList;
    if(managerlist.isEmpty())
        managerlist=managerList;

    tableWidget_Student->setSelectionBehavior(QAbstractItemView::SelectRows);//点击选择一行
    tableWidget_Student->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//自适应列宽
    tableWidget_Student->setRowCount(userList.count());
    for(int i=0;i<userList.count();++i)
    {

        QTableWidgetItem *u_id=new QTableWidgetItem(userList.at(i)->getID());
        QTableWidgetItem *u_name=new QTableWidgetItem(userList.at(i)->getName());
        QTableWidgetItem *u_grade=new QTableWidgetItem(QString::number(userList.at(i)->getGrade()));
        QTableWidgetItem *u_class=new QTableWidgetItem(QString::number(userList.at(i)->getClass()));
        QTableWidgetItem *u_password=new QTableWidgetItem(userList.at(i)->getPassword());

       tableWidget_Student->setItem(i,0,u_id);
       tableWidget_Student->setItem(i,1,u_name);
       tableWidget_Student->setItem(i,2,u_grade);
       tableWidget_Student->setItem(i,3,u_class);
       tableWidget_Student->setItem(i,4,u_password);
     }

    tableWidget_Teacher->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableWidget_Teacher->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//自适应列宽

    for(int i=0;i<managerList.count();++i)
    {
        tableWidget_Teacher->setRowCount(managerList.count());
        QTableWidgetItem *t_id=new QTableWidgetItem(QString::number(managerList.at(i)->getId()));
        QTableWidgetItem *t_name=new QTableWidgetItem(managerList.at(i)->getName());
        QTableWidgetItem *t_password=new QTableWidgetItem(managerList.at(i)->getPassword());

       tableWidget_Teacher->setItem(i,0,t_id);
       tableWidget_Teacher->setItem(i,1,t_name);
       tableWidget_Teacher->setItem(i,2,t_password);
    }

}

void MemberManageUI::on_pushButton_add_user_clicked()
{
    if(tabWidget->currentIndex()==0)
    {
       Student * userptr =  new Student;
       userptr->setID(lineEdit_userID->text());
       userptr->setName(lineEdit_userName->text());
       userptr->setGrade(lineEdit_userGrade->text().toInt());
       userptr->setClass(lineEdit_userClass->text().toInt());
       userptr->setPassword(lineEdit_userPwd->text());

       emit this->addUser(userptr);
       delete(userptr);
    }
    else if(tabWidget->currentIndex()==1)
    {
        Manager *managerptr = new Manager;
        managerptr->setId(lineEdit_managerId->text().toInt());
        managerptr->setName(lineEdit_managerName->text());
        managerptr->setPassword(lineEdit_managerPwd->text());
        emit this->addManager(managerptr);
        delete(managerptr);
    }

    this->textClear();
}

void MemberManageUI::on_pushButton_delete_user_clicked()
{
    QMessageBox msg;
    msg.setText(QString("确定要删除吗？"));
    msg.setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
    if(tabWidget->currentIndex()==0&&tableWidget_Student->currentRow()>=0)
    {
        int ret = msg.exec();
        if(ret==QMessageBox::Ok)
            emit this->deleteUserId(tableWidget_Student->item(tableWidget_Student->currentRow(),0)->text());
        else
            return;
    }
    else
        if(tabWidget->currentIndex()==1&&tableWidget_Teacher->currentRow()>=0)
        {
                int ret = msg.exec();
                if(ret==QMessageBox::Ok)
                    emit this->deleteManagerId(tableWidget_Teacher->item(tableWidget_Teacher->currentRow(),0)->text().toInt());
                else
                    return;
        }
        else
            {
                QMessageBox::about(this,"msg",QString("请选择一个用户"));
            }

}

void MemberManageUI::on_pushButton_search_clicked()
{
    if(tabWidget->currentIndex()==0)
        {
            usearchlist.clear();
            QString s_tosearch;
            s_tosearch=lineEdit_search->text();
            for(int i=0;i<userlist.count();i++)
                {
                            if(userlist.at(i)->getID()==s_tosearch||
                                userlist.at(i)->getName()==s_tosearch||
                                userlist.at(i)->getGrade()==s_tosearch.toInt()||
                                userlist.at(i)->getClass()==s_tosearch.toInt())
                                {
                                        usearchlist.append(userlist.at(i));
                                }
                }
                this->showUser(usearchlist,managerlist);
        }
    else if(tabWidget->currentIndex()==1)
        {
            msearchlist.clear();
            QString s_tosearch;
            s_tosearch=lineEdit_search->text();
            for(int i=0;i<managerlist.count();i++)
                {
                            if(managerlist.at(i)->getId()==s_tosearch.toInt()||
                                managerlist.at(i)->getName()==s_tosearch
                                )
                                {
                                        msearchlist.append(managerlist.at(i));
                                }
                }
                this->showUser(userlist,msearchlist);
        }
}

void MemberManageUI::on_pushButton_all_clicked()
{
    this->showUser(userlist,managerlist);
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

