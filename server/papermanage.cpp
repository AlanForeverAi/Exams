#include "papermanage.h"

PaperManageUI::PaperManageUI(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    table_allpaper->verticalHeader()->setHidden(true);
    table_allpaper->setSelectionBehavior(QAbstractItemView::SelectRows);//点击选择一行
    table_allpaper->horizontalHeader()->setStretchLastSection(true);//自适应列宽
    connect(this->table_allpaper, SIGNAL(itemDoubleClicked(QTableWidgetItem*)), this, SLOT(alterPaper(QTableWidgetItem*)));
    QRegExp regExp("[1-9][0-9]+");//正则表达式：1开头的整数
}

PaperManageUI::~PaperManageUI()
{

}

void PaperManageUI::showAllPaper(QList<Paper *> pList)
{
    _paperList = pList;
    table_allpaper->setRowCount(_paperList.count());
	//试卷内容管理显示试卷
    for(int i = 0; i<_paperList.count(); i++)
    {

        QTableWidgetItem *id = new QTableWidgetItem(QString::number(_paperList.at(i)->getPaperId()));
        QTableWidgetItem *description = new QTableWidgetItem(_paperList.at(i)->getDescription());
        table_allpaper->setItem(i,0,id);
        table_allpaper->setItem(i,1,description);
    }
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
    alterPaperDialog->setWindowTitle("添加试卷");
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
        alterPaperDialog->setWindowTitle("修改试卷");
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

}

void PaperManageUI::showSelectUser(QList<Student *> studentsList)
{

}

void PaperManageUI::on_pushButton_searchall_clicked()
{

}

void PaperManageUI::on_pushButton_searchselect_clicked()
{

}

void PaperManageUI::on_pushButton_all_1_clicked()	
{
    this->showStudent(_userList);
}

void PaperManageUI::on_pushButton_all_2_clicked()
{
    this->showSelectUser(_selectUserList);
}

void PaperManageUI::alterPaper(QTableWidgetItem *item)
{
    AlterPaper *alterPaperDialog = new AlterPaper();
    alterPaperDialog->setWindowTitle("修改试卷");
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
