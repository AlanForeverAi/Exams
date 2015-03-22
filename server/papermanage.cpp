#include "papermanage.h"

PaperManageUI::PaperManageUI(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    table_allpaper->verticalHeader()->setHidden(true);
//    tableWidget_allpaper->verticalHeader()->setHidden(true);
//    tableWidget_alluser->verticalHeader()->setHidden(true);
//    tableWidget_selectuser->verticalHeader()->setHidden(true);
//    tableWidget_allpaper->setEditTriggers(QAbstractItemView::NoEditTriggers);
//    tableWidget_alluser->setEditTriggers(QAbstractItemView::NoEditTriggers);
//    tableWidget_selectuser->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table_allpaper->setSelectionBehavior(QAbstractItemView::SelectRows);//点击选择一行
    table_allpaper->horizontalHeader()->setStretchLastSection(true);//自适应列宽
//    tableWidget_allpaper->setSelectionBehavior(QAbstractItemView::SelectRows);//点击选择一行
//    tableWidget_allpaper->horizontalHeader()->setStretchLastSection(true);//自适应列宽
//    tableWidget_alluser->setSelectionBehavior(QAbstractItemView::SelectRows);//点击选择一行
//    tableWidget_alluser->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//自适应列宽
//    tableWidget_selectuser->setSelectionBehavior(QAbstractItemView::SelectRows);//点击选择一行
//    tableWidget_selectuser->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//自适应列宽
//    tableWidget_alluser->setSortingEnabled(true);
//    tableWidget_selectuser->setSortingEnabled(true);
//    connect(this->tableWidget_allpaper,SIGNAL(itemClicked(QTableWidgetItem*)),this,SLOT(paperChange(QTableWidgetItem*)));
    connect(this->table_allpaper, SIGNAL(itemDoubleClicked(QTableWidgetItem*)), this, SLOT(alterPaper(QTableWidgetItem*)));
    QRegExp regExp("[1-9][0-9]+");//正则表达式：1开头的整数
//    pushButton_unmodify->setEnabled(false);
//    tabWidget_main->setCurrentIndex(0);
}

PaperManageUI::~PaperManageUI()
{

}

void PaperManageUI::showAllPaper(QList<Paper *> pList)
{
    _paperList = pList;
    table_allpaper->setRowCount(_paperList.count());
//    tableWidget_allpaper->setRowCount(_paperList.count());
	//试卷内容管理显示试卷
    for(int i = 0; i<_paperList.count(); i++)
    {

        QTableWidgetItem *id = new QTableWidgetItem(QString::number(_paperList.at(i)->getPaperId()));
        QTableWidgetItem *description = new QTableWidgetItem(_paperList.at(i)->getDescription());
        table_allpaper->setItem(i,0,id);
        table_allpaper->setItem(i,1,description);
    }
	//考试学生配置显示试卷
//    for(int i = 0; i<_paperList.count(); i++)
//    {

//        QTableWidgetItem *id = new QTableWidgetItem(QString::number(_paperList.at(i)->getPaperId()));
//        QTableWidgetItem *description = new QTableWidgetItem(_paperList.at(i)->getDescription());
//        tableWidget_allpaper->setItem(i,0,id);
//        tableWidget_allpaper->setItem(i,1,description);
//    }
}

void PaperManageUI::on_pushButton_delete_clicked()
{

    QMessageBox msg;
    msg.setText(QStringLiteral("确定要删除吗？"));
    msg.setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
    if(table_allpaper->currentRow() >= 0)
    {
        int ret = msg.exec();
        if(ret == QMessageBox::Ok)
        {
            int id;
            id = table_allpaper->item(table_allpaper->currentRow(),0)->text().toInt();
            emit this->deletePaper(id);
        }
        else
            return;
    }
    else
    {
        QMessageBox::about(this,"msg",QStringLiteral("请选择一个试卷"));
    }
}

void PaperManageUI::on_pushButton_AddorMoidfy_clicked()
{
    AlterPaper *alterPaperDialog = new AlterPaper();
    connect(this, SIGNAL(showChoiceQuestions(QList<ChoiceQuestions*>)), alterPaperDialog, SLOT(setChoiceQuestions(QList<ChoiceQuestions*>)));
    connect(this,SIGNAL(showEssayQuestions(QList<EssayQuestions*>)), alterPaperDialog, SLOT(setEssayQuestions(QList<EssayQuestions*>)));
    connect(this, SIGNAL(addPaperMode()), alterPaperDialog, SLOT(addPaperMode()));
    connect(alterPaperDialog, SIGNAL(addPaper(Paper*)), this, SIGNAL(insertPaper(Paper*)));

    emit this->showChoiceQuestions(choicequestions);\
    emit this->showEssayQuestions(essayquestions);
    emit this->addPaperMode();

    alterPaperDialog->exec();
}

void PaperManageUI::on_pushButton_tomodify_clicked()
{
    if(table_allpaper->currentRow() >= 0)
    {
        AlterPaper *alterPaperDialog = new AlterPaper();
        connect(this, SIGNAL(showChoiceQuestions(QList<ChoiceQuestions*>)), alterPaperDialog, SLOT(setChoiceQuestions(QList<ChoiceQuestions*>)));
        connect(this, SIGNAL(showEssayQuestions(QList<EssayQuestions*>)), alterPaperDialog, SLOT(setEssayQuestions(QList<EssayQuestions*>)));
        connect(this, SIGNAL(showPaper(Paper*)), alterPaperDialog, SLOT(showPaper(Paper*)));
        connect(alterPaperDialog, SIGNAL(updatePaper(Paper*)), this, SIGNAL(updatePaper(Paper*)));

        emit this->showChoiceQuestions(choicequestions);
        emit this->showEssayQuestions(essayquestions);

        Paper *paper = NULL;
        for(int i = 0; i < _paperList.count(); ++i){
            if(_paperList.at(i)->getPaperId() == table_allpaper->item(table_allpaper->currentRow(),0)->text().toInt()){
                paper = _paperList.at(i);
                break;
            }
        }

        emit this->showPaper(paper);

        alterPaperDialog->exec();

    }
    else
    {
        QMessageBox::about(this,"msg",QStringLiteral("请选择一个试卷"));
    }
}

void PaperManageUI::showStudent(QList<Student *> studentsList)
{
//    if(_userList.isEmpty())
//    {
//        _userList = studentsList;
//    }
//    tableWidget_alluser->setRowCount(studentsList.count());
//    for(int i = 0; i<studentsList.count(); ++i)
//    {
//        QTableWidgetItem *u_id = new QTableWidgetItem(studentsList.at(i)->getID());
//        QTableWidgetItem *u_name = new QTableWidgetItem(studentsList.at(i)->getName());
//        QTableWidgetItem *u_grade = new QTableWidgetItem(QString::number(studentsList.at(i)->getGrade()));
//        QTableWidgetItem *u_class = new QTableWidgetItem(QString::number(studentsList.at(i)->getClass()));

//        tableWidget_alluser->setItem(i,0,u_id);
//        tableWidget_alluser->setItem(i,1,u_name);
//        tableWidget_alluser->setItem(i,2,u_grade);
//        tableWidget_alluser->setItem(i,3,u_class);
//    }
}

void PaperManageUI::showSelectUser(QList<Student *> studentsList)
{
//    if(_selectUserList.isEmpty())
//    {
//        _selectUserList = studentsList;
//    }
//    tableWidget_selectuser->setRowCount(studentsList.count());
//    for(int i = 0; i<studentsList.count(); ++i)
//    {
//        QTableWidgetItem *u_id = new QTableWidgetItem(studentsList.at(i)->getID());
//        QTableWidgetItem *u_name = new QTableWidgetItem(studentsList.at(i)->getName());
//        QTableWidgetItem *u_grade = new QTableWidgetItem(QString::number(studentsList.at(i)->getGrade()));
//        QTableWidgetItem *u_class = new QTableWidgetItem(QString::number(studentsList.at(i)->getClass()));

//        tableWidget_selectuser->setItem(i,0,u_id);
//        tableWidget_selectuser->setItem(i,1,u_name);
//        tableWidget_selectuser->setItem(i,2,u_grade);
//        tableWidget_selectuser->setItem(i,3,u_class);
//    }
}

void PaperManageUI::on_pushButton_searchall_clicked()
{
//    _searchList.clear();
//    QString s_tosearch;
//    s_tosearch = lineEdit_searchall->text();
//    for(int i = 0; i < _userList.count(); i++)
//    {
//        if(_userList.at(i)->getID() == s_tosearch ||
//                _userList.at(i)->getName() == s_tosearch ||
//                _userList.at(i)->getGrade() == s_tosearch.toInt()||
//                _userList.at(i)->getClass() == s_tosearch.toInt())
//        {
//            _searchList.append(_userList.at(i));
//        }
//    }
//    this->showStudent(_searchList);
}

void PaperManageUI::on_pushButton_searchselect_clicked()
{
//    _searchList.clear();
//    QString s_tosearch;
//    s_tosearch = lineEdit_searchselect->text();
//    for(int i = 0; i < _selectUserList.count(); i++)
//    {
//        if(_selectUserList.at(i)->getID() == s_tosearch||
//                _selectUserList.at(i)->getName() == s_tosearch||
//                _selectUserList.at(i)->getGrade() == s_tosearch.toInt()||
//                _selectUserList.at(i)->getClass() == s_tosearch.toInt())
//        {
//            _searchList.append(_selectUserList.at(i));
//        }
//    }
//    this->showSelectUser(_searchList);
}

void PaperManageUI::on_pushButton_all_1_clicked()	
{
    this->showStudent(_userList);
}

void PaperManageUI::on_pushButton_all_2_clicked()
{
    this->showSelectUser(_selectUserList);
}

//void PaperManageUI::on_pushButton_adduser_clicked()
//{

//    if(tableWidget_alluser->currentRow()<0)
//    {
//        return;
//    }

//    for(int j = 0; j < tableWidget_alluser->selectedItems().count(); j++)
//    {
//        QString id_string = tableWidget_alluser->selectedItems().at(j)->text();

//        for(int i = 0; i < _userList.count(); i++)
//        {
//            int isIn = 0;
//            if(_userList.at(i)->getID() == id_string)
//            {
//                for(int n = 0; n < _selectUserList.count(); n++)
//                {
//                    if(_selectUserList.at(n)->getID() == id_string)
//                    {
//                        isIn = 1;
//                        break;
//                    }
//                }
//                if(isIn == 0)
//                {
//                    _selectUserList.append(_userList.at(i));
//                }

//            }
//        }
//    }
//    this->showSelectUser(_selectUserList);
//}

//void PaperManageUI::on_pushButton_deleteuser_clicked()
//{
//    if(tableWidget_selectuser->currentRow()<0)
//    {
//        return;
//    }

//    for(int j = 0; j < tableWidget_selectuser->selectedItems().count(); j++)
//    {
//        QString id_string = tableWidget_selectuser->selectedItems().at(j)->text();
//        for(int i = 0; i < _selectUserList.count(); i++)
//        {
//            if(_selectUserList.at(i)->getID() == id_string)
//            {
//                _selectUserList.removeAt(i);
//            }
//        }

//    }
//    this->showSelectUser(_selectUserList);
//}

//void PaperManageUI::paperChange(QTableWidgetItem *item)
//{
//    _selectUserList.clear();
//    int pid = tableWidget_allpaper->item(item->row(),0)->text().toInt();

//    emit this->queryPaperMark(pid,(this->comboBoxselect->currentText()));
//}

//void PaperManageUI::on_pushButton_saveuser_clicked()
//{

//    if(tableWidget_allpaper->currentRow() >= 0)
//    {
//        int pid = tableWidget_allpaper->item(tableWidget_allpaper->currentRow(),0)->text().toInt();
//        emit this->saveUsertoPaperMark(pid,_selectUserList);

//    }
//    else
//    {
//        QMessageBox::about(this,"msg",QStringLiteral("请选择一份试卷"));
//    }
//}

//void PaperManageUI::on_pushButton_print_clicked()
//{
//    if(tableWidget_allpaper->currentRow() >= 0)
//    {
//        QString filename;
//        filename.append(QStringLiteral("data/考试名单_"));
//        filename.append(tableWidget_allpaper->item(tableWidget_allpaper->currentRow(),1)->text());
//        filename.append(".txt");
//        QFile print(filename);
//        if(!print.open(QIODevice::WriteOnly|QIODevice::Text))
//            return;
//        QTextStream out(&print);
//        out << tableWidget_allpaper->item(tableWidget_allpaper->currentRow(),1)->text() << "\n";
//        QString temp;
//        for(int i = 0; i < tableWidget_selectuser->columnCount(); i++)
//        {
//            temp.append(tableWidget_selectuser->horizontalHeaderItem(i)->text());
//            temp.append("\t");
//        }
//        out << temp << "\n";
//        temp.clear();

//        for(int i = 0; i < tableWidget_selectuser->rowCount(); i++)
//        {
//            for(int j = 0; j < tableWidget_selectuser->columnCount(); j++)
//            {
//                temp.append(tableWidget_selectuser->item(i,j)->text());
//                temp.append("\t");
//            }
//            out << temp << "\n";
//            temp.clear();
//        }
//        print.close();
//        QMessageBox::about(this,"msg",QStringLiteral("导出成功，文档保存在程序所在data目录下"));
//    }
//    else
//    {
//        QMessageBox::about(this,"msg",QStringLiteral("请选择一个试卷"));
//    }
//}

//void PaperManageUI::on_comboBoxselect_currentIndexChanged(const QString &arg1)
//{
//    _selectUserList.clear();
//    QTableWidgetItem *item = tableWidget_allpaper->currentItem();
//    int pid = tableWidget_allpaper->item(item->row(),0)->text().toInt();

//    emit this->queryPaperMark(pid,(this->comboBoxselect->currentText()));
//    if((comboBoxselect->currentText()) == QStringLiteral("已完成"))
//    {
//        pushButton_adduser->setEnabled(false);
//        pushButton_deleteuser->setEnabled(false);
//        pushButton_saveuser->setEnabled(false);
//    }
//    else
//    {
//        pushButton_adduser->setEnabled(true);
//        pushButton_deleteuser->setEnabled(true);
//        pushButton_saveuser->setEnabled(true);
//    }
//}

void PaperManageUI::alterPaper(QTableWidgetItem *item)
{
    AlterPaper *alterPaperDialog = new AlterPaper();
    connect(this, SIGNAL(showChoiceQuestions(QList<ChoiceQuestions*>)), alterPaperDialog, SLOT(setChoiceQuestions(QList<ChoiceQuestions*>)));
    connect(this, SIGNAL(showEssayQuestions(QList<EssayQuestions*>)), alterPaperDialog, SLOT(setEssayQuestions(QList<EssayQuestions*>)));
    connect(this, SIGNAL(showPaper(Paper*)), alterPaperDialog, SLOT(showPaper(Paper*)));
    connect(alterPaperDialog, SIGNAL(updatePaper(Paper*)), this, SIGNAL(updatePaper(Paper*)));

    emit this->showChoiceQuestions(choicequestions);
    emit this->showEssayQuestions(essayquestions);

    Paper *paper = NULL;
    for(int i = 0; i < _paperList.count(); ++i){
        if(_paperList.at(i)->getPaperId() == table_allpaper->item(item->row(), 0)->text().toInt()){
            paper = _paperList.at(i);
            break;
        }
    }

    emit this->showPaper(paper);

    alterPaperDialog->exec();
}

void PaperManageUI::setChoiceQuestions(QList<ChoiceQuestions *> questionlist)
{
    choicequestions = questionlist;
}

void PaperManageUI::setEssayQuestions(QList<EssayQuestions *> questionlist)
{
    essayquestions = questionlist;
}
