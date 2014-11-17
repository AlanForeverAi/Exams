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
    if(_selectOb.count()==0||_selectSub.count()==0)
    {
        if(_selectOb.count()==0&&_selectSub.count()==0)//题数(OB,SUB)=(0,0)
        {
            double average_ob=0;
            textEdit_Show_Average_Ob->setText(QString::number(average_ob));
            double average_sub=0;
            textEdit_Show_Average_Sub->setText(QString::number(average_sub));
        }
        else//题数(OB,SUB)=(n,0)
        {
            if(_selectOb.count()!=0)
            {
                double average_ob=(double)lineEdit_totalmark->text().toInt()/_selectOb.count();
                textEdit_Show_Average_Ob->setText(QString::number(average_ob));
                double average_sub=0;
                textEdit_Show_Average_Sub->setText(QString::number(average_sub));
            }
            else//题数(OB,SUB)=(0,n)
            {
                double average_ob=0;
                textEdit_Show_Average_Ob->setText(QString::number(average_ob));
                double average_sub=(double)lineEdit_totalmark->text().toInt()/_selectSub.count();
                textEdit_Show_Average_Sub->setText(QString::number(average_sub));
            }
        }
    }
    else//题数(OB,SUB)=(n,n)
    {
        double average_ob=(double)lineEdit_totalmark->text().toInt()*spinBox_Percentage_Ob->value()/100/_selectOb.count();
        textEdit_Show_Average_Ob->setText(QString::number(average_ob));
        double average_sub=(double)lineEdit_totalmark->text().toInt()*spinBox_Percentage_Sub->value()/100/_selectSub.count();
        textEdit_Show_Average_Sub->setText(QString::number(average_sub));
    }
}
void PaperManageUI::showQuestions(QList<ObQuestions*> obList, QList<SubQuestions*> subList)
{

    _allOb=obList;
    _allSub=subList;

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

        QTableWidgetItem *id=new QTableWidgetItem(QString::number(obList.at(i)->getObId()));
        QTableWidgetItem *maintitle=new QTableWidgetItem(s_maintitle);
        QTableWidgetItem *type=new QTableWidgetItem(obList.at(i)->getType());
        //QTableWidgetItem *mark=new QTableWidgetItem(QString(obList.at(i)->getMark()));
        tableWidget_All_Ob->setItem(i,0,id);
        tableWidget_All_Ob->setItem(i,1,type);
        tableWidget_All_Ob->setItem(i,2,maintitle);
        if(!_typeList.contains(obList.at(i)->getType()))
        {

                _typeList<<obList.at(i)->getType();
        }

    }
    //显示主观题
    tableWidget_All_Sub->setSelectionBehavior(QAbstractItemView::SelectRows);//点击选择一行
    tableWidget_All_Sub->horizontalHeader()->setStretchLastSection(true);//自适应列宽
    tableWidget_All_Sub->setRowCount(subList.count());
    for(int i=0;i<subList.count();++i)
    {
        QTableWidgetItem *id=new QTableWidgetItem(QString::number(subList.at(i)->getsubId()));
        QTableWidgetItem *title=new QTableWidgetItem(subList.at(i)->getTitle());
        QTableWidgetItem *type=new QTableWidgetItem(subList.at(i)->getType());
        tableWidget_All_Sub->setItem(i,0,id);
        tableWidget_All_Sub->setItem(i,1,type);
        tableWidget_All_Sub->setItem(i,2,title);

        if(!_typeList.contains(subList.at(i)->getType()))
        {
                _typeList<<subList.at(i)->getType();
        }
    }
    comboBox_ob->addItem(QString("全部"));
    comboBox_sub->addItem(QString("全部"));
    comboBox_ob->addItems(_typeList);
    comboBox_sub->addItems(_typeList);

}

void PaperManageUI::showAllPaper(QList<Paper *> pList)
{
    _paperList=pList;

    table_allpaper->setRowCount(_paperList.count());
    tableWidget_allpaper->setRowCount(_paperList.count());
    for(int i=0;i<_paperList.count();i++)
    {

        QTableWidgetItem *id=new QTableWidgetItem(QString::number(_paperList.at(i)->getPaperId()));
        QTableWidgetItem *description=new QTableWidgetItem(_paperList.at(i)->getDescription());
        table_allpaper->setItem(i,0,id);
        table_allpaper->setItem(i,1,description);
    }

    for(int i=0;i<_paperList.count();i++)
    {

        QTableWidgetItem *id=new QTableWidgetItem(QString::number(_paperList.at(i)->getPaperId()));
        QTableWidgetItem *description=new QTableWidgetItem(_paperList.at(i)->getDescription());
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
    if(-1==_obQueIds.indexOf(id_string))
    {
        for(int i=0;i<_allOb.count();i++)
        {
            if(_allOb.at(i)->getObId()==id_string.toInt())
            {
                _selectOb.append(_allOb.at(i));
            }
        }
        _obQueIds.append(id_string);
        _obQueIds.append(",");
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

    if(-1==_subQueIds.indexOf(id_string))
    {

        for(int i=0;i<_allSub.count();i++)
        {
            if(_allSub.at(i)->getsubId()==id_string.toInt())
            {
                _selectSub.append(_allSub.at(i));
            }
        }
        _subQueIds.append(id_string);
        _subQueIds.append(",");
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
    tableWidget_Select_Ob->setRowCount(_selectOb.count());
    for(int i=0;i<_selectOb.count();i++)
    {
        QString t=_selectOb.at(i)->getTitle();
        QString s_maintitle=t.mid(0,t.indexOf("@a"));
        QTableWidgetItem *id=new QTableWidgetItem(QString::number(_selectOb.at(i)->getObId()));
        QTableWidgetItem *title=new QTableWidgetItem(s_maintitle);
        QTableWidgetItem *type=new QTableWidgetItem(_selectOb.at(i)->getType());
        tableWidget_Select_Ob->setItem(i,0,id);
        tableWidget_Select_Ob->setItem(i,1,type);
        tableWidget_Select_Ob->setItem(i,2,title);
    }

    tableWidget_Select_Sub->setSelectionBehavior(QAbstractItemView::SelectRows);//点击选择一行
    tableWidget_Select_Sub->horizontalHeader()->setStretchLastSection(true);
    tableWidget_Select_Sub->setRowCount(_selectSub.count());
    for(int i=0;i<_selectSub.count();i++)
    {
        QTableWidgetItem *id=new QTableWidgetItem(QString::number(_selectSub.at(i)->getsubId()));
        QTableWidgetItem *title=new QTableWidgetItem(_selectSub.at(i)->getTitle());
        QTableWidgetItem *type=new QTableWidgetItem(_selectSub.at(i)->getType());
        tableWidget_Select_Sub->setItem(i,0,id);
        tableWidget_Select_Sub->setItem(i,1,type);
        tableWidget_Select_Sub->setItem(i,2,title);
    }
    spinBox_obnum->setValue(_selectOb.count());
    spinBox_subnum->setValue(_selectSub.count());

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
        _obQueIds.remove(_obQueIds.indexOf(id_string),id_string.length()+1);
        for(int i=0;i<_selectOb.count();i++)
        {
            if(_selectOb.at(i)->getObId()==id_string.toInt())
            {
                _selectOb.removeAt(i);
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
        _subQueIds.remove(_subQueIds.indexOf(id_string),id_string.length()+1);
        for(int i=0;i<_selectSub.count();i++)
        {
            if(_selectSub.at(i)->getsubId()==id_string.toInt())
            {
                _selectSub.removeAt(i);
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
    currentpaper.setOb_qu_ids(_obQueIds);
    currentpaper.setSub_qu_ids(_subQueIds);
    currentpaper.setTotal_mark(lineEdit_totalmark->text().toInt());
    currentpaper.setPercent(spinBox_Percentage_Ob->value());
    currentpaper.setTime(spinBox_time->value()*60);
    QString state=pushButton_AddorMoidfy->text();
    if(state==QString("创建试卷"))
    {

        emit this->addPaper(currentpaper);
        _obQueIds.clear();//清记录
        _subQueIds.clear();//
    }
    else
        if(state==QString("确认修改"))
        {
            pushButton_AddorMoidfy->setText(QString("创建试卷"));
            pushButton_unmodify->setEnabled(false);
            pushButton_tomodify->setEnabled(true);


            currentpaper.setPaper_id(_currentPaperId);
            emit this->modifyPaper(currentpaper);
            _obQueIds.clear();//清记录
            _subQueIds.clear();//
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
    _selectOb.clear();
    _selectSub.clear();
    _obQueIds.clear();
    _subQueIds.clear();
    this->clear();
    lineEdit_Papername->setText(QString("请输入新的试卷名称"));

}

void PaperManageUI::showCurrentPaper(Paper p)
{
    pushButton_AddorMoidfy->setText(QString("确认修改"));
    pushButton_tomodify->setEnabled(false);
    pushButton_unmodify->setEnabled(true);


    _currentPaperId=p.getPaperId();


    _obQueIds=p.getObQuIds();
    _selectOb.clear();
    for(int i=0;i<_allOb.count();i++)
    {
        if(0<=_obQueIds.indexOf(QString::number(_allOb.at(i)->getObId())))
        {
            _selectOb.append(_allOb.at(i));

        }

    }

    tableWidget_Select_Ob->setRowCount(_selectOb.count());



    _subQueIds=p.getSubQuIds();
    _selectSub.clear();
    for(int i=0;i<_allSub.count();i++)
    {
        if(0<=_subQueIds.indexOf(QString::number(_allSub.at(i)->getsubId())))
        {
            _selectSub.append(_allSub.at(i));
        }
    }

    tableWidget_Select_Sub->setRowCount(_selectSub.count());
    this->updateSelectTable();

    _obQueIds=p.getObQuIds();
    _subQueIds=p.getSubQuIds();
    lineEdit_totalmark->setText(QString::number(p.getTotalMark()));
    spinBox_Percentage_Ob->setValue(p.getPercent());
    lineEdit_Papername->setText(p.getDescription());
    spinBox_time->setValue(p.getTime()/60);
}

void PaperManageUI::clear()
{
    tableWidget_Select_Ob->clear();
    tableWidget_Select_Sub->clear();
    _selectOb.clear();
    _selectSub.clear();
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

void PaperManageUI::showAllUser(QList<Student *> ulist, QList<USER *> m)
{
    if(userList.isEmpty())
        {
        userList=ulist;
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
    if(_selectUserList.isEmpty())
        {
        _selectUserList=ulist;
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

    _searchList.clear();
    QString s_tosearch;
    s_tosearch=lineEdit_searchall->text();
    for(int i=0;i<userList.count();i++)
        {
                    if(userList.at(i)->getID()==s_tosearch||
                        userList.at(i)->getName()==s_tosearch||
                        userList.at(i)->getGrade()==s_tosearch.toInt()||
                        userList.at(i)->getClass()==s_tosearch.toInt())
                        {
                                _searchList.append(userList.at(i));
                        }
        }
    QList<USER*> l;//没用的，凑参数。。
    this->showAllUser(_searchList,l);
}

void PaperManageUI::on_pushButton_searchselect_clicked()
{

    _searchList.clear();
    QString s_tosearch;
    s_tosearch=lineEdit_searchselect->text();
    for(int i=0;i<_selectUserList.count();i++)
        {
                    if(_selectUserList.at(i)->getID()==s_tosearch||
                        _selectUserList.at(i)->getName()==s_tosearch||
                        _selectUserList.at(i)->getGrade()==s_tosearch.toInt()||
                        _selectUserList.at(i)->getClass()==s_tosearch.toInt())
                        {
                                _searchList.append(_selectUserList.at(i));
                        }
        }
    this->showSelectUser(_searchList);
}

void PaperManageUI::on_pushButton_all_1_clicked()
{
    QList<USER*> l;//没用的，凑参数。。
    this->showAllUser(userList,l);
}

void PaperManageUI::on_pushButton_all_2_clicked()
{
    this->showSelectUser(_selectUserList);
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

            for(int i=0;i<userList.count();i++)
                {
                    int isIn=0;
                    if(userList.at(i)->getID()==id_string)
                        {
                            for(int n=0;n<_selectUserList.count();n++)
                                {
                                    if(_selectUserList.at(n)->getID()==id_string)
                                        {
                                            isIn=1;
                                            break;
                                        }
                                }
                            if(isIn==0)
                                {
                                    _selectUserList.append(userList.at(i));
                                }

                        }
                }
        }
    this->showSelectUser(_selectUserList);

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
            for(int i=0;i<_selectUserList.count();i++)
                {
                    if(_selectUserList.at(i)->getID()==id_string)
                        {
                            _selectUserList.removeAt(i);
                        }
                }


        }
    this->showSelectUser(_selectUserList);
}

void PaperManageUI::paperChange(QTableWidgetItem *item)
{
    _selectUserList.clear();
    int pid=tableWidget_allpaper->item(item->row(),0)->text().toInt();

    emit this->queryPaperMark(pid,(this->comboBoxselect->currentText()));
}

void PaperManageUI::on_pushButton_saveuser_clicked()
{

    if(tableWidget_allpaper->currentRow()>=0)
    {
        int pid=tableWidget_allpaper->item(tableWidget_allpaper->currentRow(),0)->text().toInt();
        emit this->saveUsertoPaperMark(pid,_selectUserList);

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
        _selectOb.clear();
        _selectSub.clear();
        _obQueIds.clear();
        _subQueIds.clear();
        QList<ObQuestions*> oblist;
        QList<SubQuestions*> sublist;
        oblist=_tempOb;
        qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
        for(int i=0;i<spinBox_obnum->value();i++)
            {
                int j=qrand()%oblist.count();
                _selectOb.append(oblist.at(j));
                _obQueIds.append(QString::number(oblist.at(j)->getObId()));
                _obQueIds.append(",");
                oblist.removeAt(j);
            }
        sublist=_tempSub;
        for(int i=0;i<spinBox_subnum->value();i++)
            {
                int j=qrand()%sublist.count();
                _selectSub.append(sublist.at(j));
                _subQueIds.append(QString::number(sublist.at(j)->getsubId()));
                _subQueIds.append(",");
                sublist.removeAt(j);
            }

        this->updateSelectTable();
        this->averageChange();
        QMessageBox::about(this,"msg",QString("生成题目成功"));

    }

}
void PaperManageUI::typeChange(QString t)
{
    _tempOb.clear();
    _tempSub.clear();
    if(t==QString("全部"))
        {
            _tempOb=_allOb;
            _tempSub=_allSub;
        }

    for(int i=0;i<_allOb.count();i++)
        {
            if(_allOb.at(i)->getType()==t)
                _tempOb.append(_allOb.at(i));
        }
    for(int i=0;i<_allSub.count();i++)
        {
            if(_allSub.at(i)->getType()==t)
                _tempSub.append(_allSub.at(i));
        }
    this->showCurrentType(_tempOb,_tempSub);
}

void PaperManageUI::showCurrentType(QList<ObQuestions *> obList, QList<SubQuestions *> subList)
{
    spinBox_obnum->setMaximum(obList.count());
    spinBox_subnum->setMaximum(subList.count());

    tableWidget_All_Ob->setRowCount(obList.count());
    for(int i=0;i<obList.count();++i)
    {
        QString title=obList.at(i)->getTitle();
        QString s_maintitle=title.mid(0,title.indexOf("@a"));

        QTableWidgetItem *id=new QTableWidgetItem(QString::number(obList.at(i)->getObId()));
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
        QTableWidgetItem *id=new QTableWidgetItem(QString::number(subList.at(i)->getsubId()));
        QTableWidgetItem *title=new QTableWidgetItem(subList.at(i)->getTitle());
        QTableWidgetItem *type=new QTableWidgetItem(subList.at(i)->getType());
        tableWidget_All_Sub->setItem(i,0,id);
        tableWidget_All_Sub->setItem(i,1,type);
        tableWidget_All_Sub->setItem(i,2,title);
    }
}


void PaperManageUI::on_comboBoxselect_currentIndexChanged(const QString &arg1)
{
    _selectUserList.clear();
    QTableWidgetItem *item=tableWidget_allpaper->currentItem();
    int pid=tableWidget_allpaper->item(item->row(),0)->text().toInt();

    emit this->queryPaperMark(pid,(this->comboBoxselect->currentText()));
    if((comboBoxselect->currentText())==QString("已完成")){pushButton_adduser->setEnabled(false);pushButton_deleteuser->setEnabled(false);pushButton_saveuser->setEnabled(false);}
    else{pushButton_adduser->setEnabled(true);pushButton_deleteuser->setEnabled(true);pushButton_saveuser->setEnabled(true);}
}
