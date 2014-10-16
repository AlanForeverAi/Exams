#include "PaperManageUI.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QTime>
#include <QDebug>
#include<QHeaderView>
PaperManageUI::PaperManageUI(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    table_allpaper->setSelectionBehavior(QAbstractItemView::SelectRows);//点击选择一行
    table_allpaper->horizontalHeader()->setStretchLastSection(true);//自适应列宽
    tableWidget_allpaper->setSelectionBehavior(QAbstractItemView::SelectRows);//点击选择一行
    tableWidget_allpaper->horizontalHeader()->setStretchLastSection(true);//自适应列宽
    tableWidget_alluser->setSelectionBehavior(QAbstractItemView::SelectRows);//点击选择一行
    tableWidget_alluser->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//自适应列宽
    tableWidget_selectuser->setSelectionBehavior(QAbstractItemView::SelectRows);//点击选择一行
    tableWidget_selectuser->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//自适应列宽
    tableWidget_alluser->setSortingEnabled(true);
    tableWidget_selectuser->setSortingEnabled(true);
    connect(this->tableWidget_allpaper,SIGNAL(itemClicked(QTableWidgetItem*)),this,SLOT(paperChange(QTableWidgetItem*)));
    spinBox_time->setMinimum(1);//设置最小值
    lineEdit_totalmark->setText("100");
        QRegExp regExp("[1-9][0-9]+");//正则表达式：1开头的整数
        QRegExpValidator *validator = new QRegExpValidator (regExp,this);
              lineEdit_totalmark->setValidator(validator );
    spinBox_Percentage_Ob->setValue(100);
    pushButton_unmodify->setEnabled(false);
    tabWidget_main->setCurrentIndex(0);
    connect(comboBox_ob,SIGNAL(currentIndexChanged(int)),comboBox_sub,SLOT(setCurrentIndex(int)));
    connect(comboBox_sub,SIGNAL(currentIndexChanged(int)),comboBox_ob,SLOT(setCurrentIndex(int)));
    connect(comboBox_ob,SIGNAL(currentIndexChanged(QString)),this,SLOT(typeChange(QString)));
    connect(comboBox_sub,SIGNAL(currentIndexChanged(QString)),this,SLOT(typeChange(QString)));

}

PaperManageUI::~PaperManageUI()
{

}

void PaperManageUI::on_horizontalSlider_valueChanged(int value)
{
    spinBox_Percentage_Ob->setValue(100-value);
    this->averageChange();
}
void PaperManageUI::on_spinBox_Percentage_Ob_valueChanged(int value)
{
    spinBox_Percentage_Sub->setValue(100-value);
}

void PaperManageUI::averageChange()
{
    if(select_Ob.count()==0||select_Sub.count()==0)
    {
        if(select_Ob.count()==0&&select_Sub.count()==0)//题数(OB,SUB)=(0,0)
        {
            double average_ob=0;
            textEdit_Show_Average_Ob->setText(QString::number(average_ob));
            double average_sub=0;
            textEdit_Show_Average_Sub->setText(QString::number(average_sub));
        }
        else//题数(OB,SUB)=(n,0)
        {
            if(select_Ob.count()!=0)
            {
                double average_ob=(double)lineEdit_totalmark->text().toInt()/select_Ob.count();
                textEdit_Show_Average_Ob->setText(QString::number(average_ob));
                double average_sub=0;
                textEdit_Show_Average_Sub->setText(QString::number(average_sub));
            }
            else//题数(OB,SUB)=(0,n)
            {
                double average_ob=0;
                textEdit_Show_Average_Ob->setText(QString::number(average_ob));
                double average_sub=(double)lineEdit_totalmark->text().toInt()/select_Sub.count();
                textEdit_Show_Average_Sub->setText(QString::number(average_sub));
            }
        }
    }
    else//题数(OB,SUB)=(n,n)
    {
        double average_ob=(double)lineEdit_totalmark->text().toInt()*spinBox_Percentage_Ob->value()/100/select_Ob.count();
        textEdit_Show_Average_Ob->setText(QString::number(average_ob));
        double average_sub=(double)lineEdit_totalmark->text().toInt()*spinBox_Percentage_Sub->value()/100/select_Sub.count();
        textEdit_Show_Average_Sub->setText(QString::number(average_sub));
    }
}
void PaperManageUI::showQuestions(QList<Ob_questions*> obList, QList<Sub_questions*> subList)
{

    all_Ob=obList;
    all_Sub=subList;

    spinBox_obnum->setMaximum(obList.count());
    spinBox_subnum->setMaximum(subList.count());

    //显示客观题
    tableWidget_All_Ob->setSelectionBehavior(QAbstractItemView::SelectRows);//点击选择一行
    tableWidget_All_Ob->horizontalHeader()->setStretchLastSection(true);//自适应列宽
    tableWidget_All_Ob->setRowCount(obList.count());
    for(int i=0;i<obList.count();++i)
    {
        QString title=obList.at(i)->getTitle();
        QString s_maintitle=title.mid(0,title.indexOf("@a"));

        QTableWidgetItem *id=new QTableWidgetItem(QString::number(obList.at(i)->getOb_id()));
        QTableWidgetItem *maintitle=new QTableWidgetItem(s_maintitle);
        QTableWidgetItem *type=new QTableWidgetItem(obList.at(i)->getType());
        //QTableWidgetItem *mark=new QTableWidgetItem(QString(obList.at(i)->getMark()));
        tableWidget_All_Ob->setItem(i,0,id);
        tableWidget_All_Ob->setItem(i,1,type);
        tableWidget_All_Ob->setItem(i,2,maintitle);
        if(!typelist.contains(obList.at(i)->getType()))
        {

                typelist<<obList.at(i)->getType();
        }

    }
    //显示主观题
    tableWidget_All_Sub->setSelectionBehavior(QAbstractItemView::SelectRows);//点击选择一行
    tableWidget_All_Sub->horizontalHeader()->setStretchLastSection(true);//自适应列宽
    tableWidget_All_Sub->setRowCount(subList.count());
    for(int i=0;i<subList.count();++i)
    {
        QTableWidgetItem *id=new QTableWidgetItem(QString::number(subList.at(i)->getSub_id()));
        QTableWidgetItem *title=new QTableWidgetItem(subList.at(i)->getTitle());
        QTableWidgetItem *type=new QTableWidgetItem(subList.at(i)->getType());
        tableWidget_All_Sub->setItem(i,0,id);
        tableWidget_All_Sub->setItem(i,1,type);
        tableWidget_All_Sub->setItem(i,2,title);

        if(!typelist.contains(subList.at(i)->getType()))
        {
                typelist<<subList.at(i)->getType();
        }
    }
    comboBox_ob->addItem(QString("全部"));
    comboBox_sub->addItem(QString("全部"));
    comboBox_ob->addItems(typelist);
    comboBox_sub->addItems(typelist);

}

void PaperManageUI::showAllPaper(QList<Paper *> pList)
{
    paperList=pList;

    table_allpaper->setRowCount(paperList.count());
    tableWidget_allpaper->setRowCount(paperList.count());
    for(int i=0;i<paperList.count();i++)
    {

        QTableWidgetItem *id=new QTableWidgetItem(QString::number(paperList.at(i)->getPaper_id()));
        QTableWidgetItem *description=new QTableWidgetItem(paperList.at(i)->getDescription());
        table_allpaper->setItem(i,0,id);
        table_allpaper->setItem(i,1,description);
    }

    for(int i=0;i<paperList.count();i++)
    {

        QTableWidgetItem *id=new QTableWidgetItem(QString::number(paperList.at(i)->getPaper_id()));
        QTableWidgetItem *description=new QTableWidgetItem(paperList.at(i)->getDescription());
        tableWidget_allpaper->setItem(i,0,id);
        tableWidget_allpaper->setItem(i,1,description);
    }
}


void PaperManageUI::on_pushButton_Add_Ob_clicked()
{
    if(tableWidget_All_Ob->currentRow()<0)
    {
        QMessageBox::about(this,"msg",QString("请选择题目"));
        return;
    }


    QString id_string=tableWidget_All_Ob->item(tableWidget_All_Ob->currentRow(),0)->text();
    if(-1==ob_que_ids.indexOf(id_string))
    {
        for(int i=0;i<all_Ob.count();i++)
        {
            if(all_Ob.at(i)->getOb_id()==id_string.toInt())
            {
                select_Ob.append(all_Ob.at(i));
            }
        }
        ob_que_ids.append(id_string);
        ob_que_ids.append(",");
        this->updateSelectTable();
        this->averageChange();
    }
    else
    {
        QMessageBox::about(this,"msg",QString("此题目已存在"));
    }

}

void PaperManageUI::on_pushButton_Add_Sub_clicked()
{
    if(tableWidget_All_Sub->currentRow()<0)
    {
        QMessageBox::about(this,"msg",QString("请选择题目"));
        return;
    }


    QString id_string=tableWidget_All_Sub->item(tableWidget_All_Sub->currentRow(),0)->text();

    if(-1==sub_que_ids.indexOf(id_string))
    {

        for(int i=0;i<all_Sub.count();i++)
        {
            if(all_Sub.at(i)->getSub_id()==id_string.toInt())
            {
                select_Sub.append(all_Sub.at(i));
            }
        }
        sub_que_ids.append(id_string);
        sub_que_ids.append(",");
        this->updateSelectTable();
        this->averageChange();
    }
    else
    {
        QMessageBox::about(this,"msg",QString("此题目已存在"));
    }
}

void PaperManageUI::updateSelectTable()
{
    tableWidget_Select_Ob->setSelectionBehavior(QAbstractItemView::SelectRows);//点击选择一行
    tableWidget_Select_Ob->horizontalHeader()->setStretchLastSection(true);
    tableWidget_Select_Ob->setRowCount(select_Ob.count());
    for(int i=0;i<select_Ob.count();i++)
    {
        QString t=select_Ob.at(i)->getTitle();
        QString s_maintitle=t.mid(0,t.indexOf("@a"));
        QTableWidgetItem *id=new QTableWidgetItem(QString::number(select_Ob.at(i)->getOb_id()));
        QTableWidgetItem *title=new QTableWidgetItem(s_maintitle);
        QTableWidgetItem *type=new QTableWidgetItem(select_Ob.at(i)->getType());
        tableWidget_Select_Ob->setItem(i,0,id);
        tableWidget_Select_Ob->setItem(i,1,type);
        tableWidget_Select_Ob->setItem(i,2,title);
    }

    tableWidget_Select_Sub->setSelectionBehavior(QAbstractItemView::SelectRows);//点击选择一行
    tableWidget_Select_Sub->horizontalHeader()->setStretchLastSection(true);
    tableWidget_Select_Sub->setRowCount(select_Sub.count());
    for(int i=0;i<select_Sub.count();i++)
    {
        QTableWidgetItem *id=new QTableWidgetItem(QString::number(select_Sub.at(i)->getSub_id()));
        QTableWidgetItem *title=new QTableWidgetItem(select_Sub.at(i)->getTitle());
        QTableWidgetItem *type=new QTableWidgetItem(select_Sub.at(i)->getType());
        tableWidget_Select_Sub->setItem(i,0,id);
        tableWidget_Select_Sub->setItem(i,1,type);
        tableWidget_Select_Sub->setItem(i,2,title);
    }
    spinBox_obnum->setValue(select_Ob.count());
    spinBox_subnum->setValue(select_Sub.count());

}

void PaperManageUI::on_pushButton_Delete_Ob_clicked()
{
    if(tableWidget_Select_Ob->currentRow()<0)
    {
        QMessageBox::about(this,"msg",QString("请选择题目"));
        return;
    }
    else
    {
        QString id_string=tableWidget_Select_Ob->item(tableWidget_Select_Ob->currentRow(),0)->text();
        ob_que_ids.remove(ob_que_ids.indexOf(id_string),id_string.length()+1);
        for(int i=0;i<select_Ob.count();i++)
        {
            if(select_Ob.at(i)->getOb_id()==id_string.toInt())
            {
                select_Ob.removeAt(i);
            }
        }


        this->updateSelectTable();
        this->averageChange();
    }

}

void PaperManageUI::on_pushButton_Delete_Sub_clicked()
{
    if(tableWidget_Select_Sub->currentRow()<0)
    {
        QMessageBox::about(this,"msg",QString("请选择题目"));
        return;
    }
    else
    {
        QString id_string=tableWidget_Select_Sub->item(tableWidget_Select_Sub->currentRow(),0)->text();
        sub_que_ids.remove(sub_que_ids.indexOf(id_string),id_string.length()+1);
        for(int i=0;i<select_Sub.count();i++)
        {
            if(select_Sub.at(i)->getSub_id()==id_string.toInt())
            {
                select_Sub.removeAt(i);
            }
        }


        this->updateSelectTable();
        this->averageChange();
    }
}



void PaperManageUI::on_pushButton_delete_clicked()
{

    QMessageBox msg;
    msg.setText(QString("确定要删除吗？"));
    msg.setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
    if(table_allpaper->currentRow()>=0)
    {
        int ret=msg.exec();
        if(ret==QMessageBox::Ok)
        {
            int id;
            id=table_allpaper->item(table_allpaper->currentRow(),0)->text().toInt();
            emit this->deletePaper(id);
        }
        else
            return;
    }
    else
    {
        QMessageBox::about(this,"msg",QString("请选择一个试卷"));
    }
}

void PaperManageUI::on_pushButton_AddorMoidfy_clicked()
{
    Paper currentpaper;
    currentpaper.setDescription(lineEdit_Papername->text());
    currentpaper.setOb_qu_ids(ob_que_ids);
    currentpaper.setSub_qu_ids(sub_que_ids);
    currentpaper.setTotal_mark(lineEdit_totalmark->text().toInt());
    currentpaper.setPercent(spinBox_Percentage_Ob->value());
    currentpaper.setTime(spinBox_time->value()*60);
    QString state=pushButton_AddorMoidfy->text();
    if(state==QString("创建试卷"))
    {

        emit this->addPaper(currentpaper);
        ob_que_ids.clear();//清记录
        sub_que_ids.clear();//
    }
    else
        if(state==QString("确认修改"))
        {
            pushButton_AddorMoidfy->setText(QString("创建试卷"));
            pushButton_unmodify->setEnabled(false);
            pushButton_tomodify->setEnabled(true);


            currentpaper.setPaper_id(currentPaperId);
            emit this->modifyPaper(currentpaper);
            ob_que_ids.clear();//清记录
            sub_que_ids.clear();//
        }
    this->clear();
}

void PaperManageUI::on_pushButton_tomodify_clicked()
{
    if(table_allpaper->currentRow()>=0)
    {
        int id;
        id=table_allpaper->item(table_allpaper->currentRow(),0)->text().toInt();
        emit this->getPaperById(id);
    }
    else
    {
        QMessageBox::about(this,"msg",QString("请选择一个试卷"));
    }
}

void PaperManageUI::on_pushButton_unmodify_clicked()
{
    pushButton_tomodify->setEnabled(true);
    pushButton_AddorMoidfy->setText(QString("创建试卷"));
    pushButton_unmodify->setEnabled(false);
    select_Ob.clear();
    select_Sub.clear();
    ob_que_ids.clear();
    sub_que_ids.clear();
    this->clear();
    lineEdit_Papername->setText(QString("请输入新的试卷名称"));

}

void PaperManageUI::showCurrentPaper(Paper p)
{
    pushButton_AddorMoidfy->setText(QString("确认修改"));
    pushButton_tomodify->setEnabled(false);
    pushButton_unmodify->setEnabled(true);


    currentPaperId=p.getPaper_id();


    ob_que_ids=p.getOb_qu_ids();
    select_Ob.clear();
    for(int i=0;i<all_Ob.count();i++)
    {
        if(0<=ob_que_ids.indexOf(QString::number(all_Ob.at(i)->getOb_id())))
        {
            select_Ob.append(all_Ob.at(i));

        }

    }

    tableWidget_Select_Ob->setRowCount(select_Ob.count());



    sub_que_ids=p.getSub_qu_ids();
    select_Sub.clear();
    for(int i=0;i<all_Sub.count();i++)
    {
        if(0<=sub_que_ids.indexOf(QString::number(all_Sub.at(i)->getSub_id())))
        {
            select_Sub.append(all_Sub.at(i));
        }
    }

    tableWidget_Select_Sub->setRowCount(select_Sub.count());
    this->updateSelectTable();

    ob_que_ids=p.getOb_qu_ids();
    sub_que_ids=p.getSub_qu_ids();
    lineEdit_totalmark->setText(QString::number(p.getTotal_mark()));
    spinBox_Percentage_Ob->setValue(p.getPercent());
    lineEdit_Papername->setText(p.getDescription());
    spinBox_time->setValue(p.getTime()/60);
}

void PaperManageUI::clear()
{
    tableWidget_Select_Ob->clear();
    tableWidget_Select_Sub->clear();
    select_Ob.clear();
    select_Sub.clear();
    QStringList header;
    header<<QString("题目编号")<<QString("题干");
    tableWidget_Select_Ob->setHorizontalHeaderLabels(header);
    tableWidget_Select_Sub->setHorizontalHeaderLabels(header);
    lineEdit_Papername->setText(QString("请输入新的试卷名称"));
    spinBox_Percentage_Ob->setValue(100);
    spinBox_time->setValue(1);
    lineEdit_totalmark->setText("100");//
    this->updateSelectTable();

}

void PaperManageUI::showAllUser(QList<Student *> ulist, QList<Manager *> m)
{
    if(userlist.isEmpty())
        {
        userlist=ulist;
        }
    tableWidget_alluser->setRowCount(ulist.count());
    for(int i=0;i<ulist.count();++i)
    {

        QTableWidgetItem *u_id=new QTableWidgetItem(ulist.at(i)->getID());
        QTableWidgetItem *u_name=new QTableWidgetItem(ulist.at(i)->getName());
        QTableWidgetItem *u_grade=new QTableWidgetItem(QString::number(ulist.at(i)->getGrade()));
        QTableWidgetItem *u_class=new QTableWidgetItem(QString::number(ulist.at(i)->getClass()));

       tableWidget_alluser->setItem(i,0,u_id);
       tableWidget_alluser->setItem(i,1,u_name);
       tableWidget_alluser->setItem(i,2,u_grade);
       tableWidget_alluser->setItem(i,3,u_class);

     }
}

void PaperManageUI::showSelectUser(QList<Student *> ulist)
{
    if(selectuserlist.isEmpty())
        {
        selectuserlist=ulist;
        }
    tableWidget_selectuser->setRowCount(ulist.count());
    for(int i=0;i<ulist.count();++i)
    {

        QTableWidgetItem *u_id=new QTableWidgetItem(ulist.at(i)->getID());
        QTableWidgetItem *u_name=new QTableWidgetItem(ulist.at(i)->getName());
        QTableWidgetItem *u_grade=new QTableWidgetItem(QString::number(ulist.at(i)->getGrade()));
        QTableWidgetItem *u_class=new QTableWidgetItem(QString::number(ulist.at(i)->getClass()));

       tableWidget_selectuser->setItem(i,0,u_id);
       tableWidget_selectuser->setItem(i,1,u_name);
       tableWidget_selectuser->setItem(i,2,u_grade);
       tableWidget_selectuser->setItem(i,3,u_class);

     }
}

void PaperManageUI::on_pushButton_searchall_clicked()
{

    searchlist.clear();
    QString s_tosearch;
    s_tosearch=lineEdit_searchall->text();
    for(int i=0;i<userlist.count();i++)
        {
                    if(userlist.at(i)->getID()==s_tosearch||
                        userlist.at(i)->getName()==s_tosearch||
                        userlist.at(i)->getGrade()==s_tosearch.toInt()||
                        userlist.at(i)->getClass()==s_tosearch.toInt())
                        {
                                searchlist.append(userlist.at(i));
                        }
        }
    QList<Manager*> l;//没用的，凑参数。。
    this->showAllUser(searchlist,l);
}

void PaperManageUI::on_pushButton_searchselect_clicked()
{

    searchlist.clear();
    QString s_tosearch;
    s_tosearch=lineEdit_searchselect->text();
    for(int i=0;i<selectuserlist.count();i++)
        {
                    if(selectuserlist.at(i)->getID()==s_tosearch||
                        selectuserlist.at(i)->getName()==s_tosearch||
                        selectuserlist.at(i)->getGrade()==s_tosearch.toInt()||
                        selectuserlist.at(i)->getClass()==s_tosearch.toInt())
                        {
                                searchlist.append(selectuserlist.at(i));
                        }
        }
    this->showSelectUser(searchlist);
}

void PaperManageUI::on_pushButton_all_1_clicked()
{
    QList<Manager*> l;//没用的，凑参数。。
    this->showAllUser(userlist,l);
}

void PaperManageUI::on_pushButton_all_2_clicked()
{
    this->showSelectUser(selectuserlist);
}

void PaperManageUI::on_pushButton_adduser_clicked()
{

    if(tableWidget_alluser->currentRow()<0)
    {
        return;
    }

    for(int j=0;j<tableWidget_alluser->selectedItems().count();j++)
        {
            QString id_string=tableWidget_alluser->selectedItems().at(j)->text();

            for(int i=0;i<userlist.count();i++)
                {
                    int isIn=0;
                    if(userlist.at(i)->getID()==id_string)
                        {
                            for(int n=0;n<selectuserlist.count();n++)
                                {
                                    if(selectuserlist.at(n)->getID()==id_string)
                                        {
                                            isIn=1;
                                            break;
                                        }
                                }
                            if(isIn==0)
                                {
                                    selectuserlist.append(userlist.at(i));
                                }

                        }
                }
        }
    this->showSelectUser(selectuserlist);

}

void PaperManageUI::on_pushButton_deleteuser_clicked()
{
    if(tableWidget_selectuser->currentRow()<0)
    {
        return;
    }

    for(int j=0;j<tableWidget_selectuser->selectedItems().count();j++)
        {
            QString id_string=tableWidget_selectuser->selectedItems().at(j)->text();
            for(int i=0;i<selectuserlist.count();i++)
                {
                    if(selectuserlist.at(i)->getID()==id_string)
                        {
                            selectuserlist.removeAt(i);
                        }
                }


        }
    this->showSelectUser(selectuserlist);
}

void PaperManageUI::paperChange(QTableWidgetItem *item)
{
    selectuserlist.clear();
    int pid=tableWidget_allpaper->item(item->row(),0)->text().toInt();

    emit this->queryPaperMark(pid,(this->comboBoxselect->currentText()));
}

void PaperManageUI::on_pushButton_saveuser_clicked()
{

    if(tableWidget_allpaper->currentRow()>=0)
    {
        int pid=tableWidget_allpaper->item(tableWidget_allpaper->currentRow(),0)->text().toInt();
        emit this->saveUsertoPaperMark(pid,selectuserlist);

   }
    else
    {
        QMessageBox::about(this,"msg",QString("请选择一份试卷"));
    }
}

void PaperManageUI::on_pushButton_print_clicked()
{
    if(tableWidget_allpaper->currentRow()>=0)
    {
        QString filename;
        filename.append(QString("data/考试名单_"));
        filename.append(tableWidget_allpaper->item(tableWidget_allpaper->currentRow(),1)->text());
        filename.append(".txt");
        QFile print(filename);
        if(!print.open(QIODevice::WriteOnly|QIODevice::Text))
            return;
        QTextStream out(&print);
        out<<tableWidget_allpaper->item(tableWidget_allpaper->currentRow(),1)->text()<<"\n";
        QString temp;
        for(int i=0;i<tableWidget_selectuser->columnCount();i++)
        {
            temp.append(tableWidget_selectuser->horizontalHeaderItem(i)->text());
            temp.append("\t");
        }
        out<<temp<<"\n";
        temp.clear();

        for(int i=0;i<tableWidget_selectuser->rowCount();i++)
        {
            for(int j=0;j<tableWidget_selectuser->columnCount();j++)
            {
                temp.append(tableWidget_selectuser->item(i,j)->text());
                temp.append("\t");
            }
            out<<temp<<"\n";
            temp.clear();
        }
        print.close();
        QMessageBox::about(this,"msg",QString("导出成功，文档保存在程序所在data目录下"));
    }
else
    {
        QMessageBox::about(this,"msg",QString("请选择一个试卷"));
    }
}
void PaperManageUI::on_pushButton_random_clicked()
{
    if(spinBox_subnum->value()==0&&spinBox_obnum->value()==0)
    {

    QMessageBox::about(this,"msg",QString("客观题和主观题题数不可同时为0"));

    }
    else
    {
        select_Ob.clear();
        select_Sub.clear();
        ob_que_ids.clear();
        sub_que_ids.clear();
        QList<Ob_questions*> oblist;
        QList<Sub_questions*> sublist;
        oblist=temp_Ob;
        qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
        for(int i=0;i<spinBox_obnum->value();i++)
            {
                int j=qrand()%oblist.count();
                select_Ob.append(oblist.at(j));
                ob_que_ids.append(QString::number(oblist.at(j)->getOb_id()));
                ob_que_ids.append(",");
                oblist.removeAt(j);
            }
        sublist=temp_Sub;
        for(int i=0;i<spinBox_subnum->value();i++)
            {
                int j=qrand()%sublist.count();
                select_Sub.append(sublist.at(j));
                sub_que_ids.append(QString::number(sublist.at(j)->getSub_id()));
                sub_que_ids.append(",");
                sublist.removeAt(j);
            }

        this->updateSelectTable();
        this->averageChange();
        QMessageBox::about(this,"msg",QString("生成题目成功"));

    }

}
void PaperManageUI::typeChange(QString t)
{
    temp_Ob.clear();
    temp_Sub.clear();
    if(t==QString("全部"))
        {
            temp_Ob=all_Ob;
            temp_Sub=all_Sub;
        }

    for(int i=0;i<all_Ob.count();i++)
        {
            if(all_Ob.at(i)->getType()==t)
                temp_Ob.append(all_Ob.at(i));
        }
    for(int i=0;i<all_Sub.count();i++)
        {
            if(all_Sub.at(i)->getType()==t)
                temp_Sub.append(all_Sub.at(i));
        }
    this->showCurrentType(temp_Ob,temp_Sub);
}

void PaperManageUI::showCurrentType(QList<Ob_questions *> obList, QList<Sub_questions *> subList)
{
    spinBox_obnum->setMaximum(obList.count());
    spinBox_subnum->setMaximum(subList.count());

    tableWidget_All_Ob->setRowCount(obList.count());
    for(int i=0;i<obList.count();++i)
    {
        QString title=obList.at(i)->getTitle();
        QString s_maintitle=title.mid(0,title.indexOf("@a"));

        QTableWidgetItem *id=new QTableWidgetItem(QString::number(obList.at(i)->getOb_id()));
        QTableWidgetItem *maintitle=new QTableWidgetItem(s_maintitle);
        QTableWidgetItem *type=new QTableWidgetItem(obList.at(i)->getType());
        //QTableWidgetItem *mark=new QTableWidgetItem(QString(obList.at(i)->getMark()));
        tableWidget_All_Ob->setItem(i,0,id);
        tableWidget_All_Ob->setItem(i,1,type);
        tableWidget_All_Ob->setItem(i,2,maintitle);


    }
    //显示主观题

    tableWidget_All_Sub->setRowCount(subList.count());
    for(int i=0;i<subList.count();++i)
    {
        QTableWidgetItem *id=new QTableWidgetItem(QString::number(subList.at(i)->getSub_id()));
        QTableWidgetItem *title=new QTableWidgetItem(subList.at(i)->getTitle());
        QTableWidgetItem *type=new QTableWidgetItem(subList.at(i)->getType());
        tableWidget_All_Sub->setItem(i,0,id);
        tableWidget_All_Sub->setItem(i,1,type);
        tableWidget_All_Sub->setItem(i,2,title);
    }
}


void PaperManageUI::on_comboBoxselect_currentIndexChanged(const QString &arg1)
{
    selectuserlist.clear();
    QTableWidgetItem *item=tableWidget_allpaper->currentItem();
    int pid=tableWidget_allpaper->item(item->row(),0)->text().toInt();

    emit this->queryPaperMark(pid,(this->comboBoxselect->currentText()));
    if((comboBoxselect->currentText())==QString("已完成")){pushButton_adduser->setEnabled(false);pushButton_deleteuser->setEnabled(false);pushButton_saveuser->setEnabled(false);}
    else{pushButton_adduser->setEnabled(true);pushButton_deleteuser->setEnabled(true);pushButton_saveuser->setEnabled(true);}
}
