#include "questionsmanage.h"
#include <QMessageBox>
#include <QDebug>

QuestionsManageUI::QuestionsManageUI(QWidget *parent):QWidget(parent)
{
    setupUi(this);

    connect(obTable, SIGNAL(itemDoubleClicked(QTableWidgetItem*)), this, SLOT(showChoiceQuestion(QTableWidgetItem*)));
    connect(subTable, SIGNAL(itemDoubleClicked(QTableWidgetItem*)), this, SLOT(showEssayQuestion(QTableWidgetItem*)));

    obTable->verticalHeader()->setHidden(true);
    subTable->verticalHeader()->setHidden(true);

    obTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    subTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    obTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    obTable->horizontalHeader()->setStretchLastSection(true);
    subTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    subTable->horizontalHeader()->setStretchLastSection(true);
}

QuestionsManageUI::~QuestionsManageUI()
{

}

void QuestionsManageUI::return_clicked()
{
    this->close();
}

void QuestionsManageUI::on_Button_delete_clicked()
{
    QMessageBox msg;
    msg.setText(QStringLiteral("确定要删除吗？"));
    msg.setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
    if(tabWidget_2->currentIndex() == 0 && obTable->currentRow() >= 0)
    {
        int ret = msg.exec();
        if(ret == QMessageBox::Ok){
            QList<QTableWidgetItem *> selectItems = obTable->selectedItems();
            for(int i = 0; i < selectItems.count(); ++i){
                emit this->deleteOb_Questoins(obTable->item(selectItems.at(i)->row(), 0)->text().toInt());
            }
        }
        else
            return ;
    }
    else if(tabWidget_2->currentIndex() == 1 && subTable->currentRow() >= 0)
    {
        int ret  =  msg.exec();
        if(ret == QMessageBox::Ok){
            QList<QTableWidgetItem *> selectItems = subTable->selectedItems();
            for(int i = 0; i < selectItems.count(); ++i){
                emit this->deleteSub_Questoins(subTable->item(selectItems.at(i)->row(), 0)->text().toInt());
            }
        }
        else
            return;
    }
    else
    {
        QMessageBox::about(this,"msg",QStringLiteral("请选择一个题目"));
    }
}

void QuestionsManageUI::showChoiceQuestionList(QList<ChoiceQuestions *> obList)
{
    obTable->setRowCount(obList.count());
    for(int i = 0; i < obList.count(); i++)
    {
        QString title = obList.at(i)->getQuestionTitle();
        QString s_maintitle = title.mid(0,title.indexOf("@a"));

        QTableWidgetItem *maintitle = new QTableWidgetItem(s_maintitle);
        QTableWidgetItem *id = new QTableWidgetItem(QString::number(obList.at(i)->getQuestionId()));
        maintitle->setToolTip(maintitle->text());
        obTable->setItem(i,0,id);
        obTable->setItem(i,1,maintitle);
    }
}

void QuestionsManageUI::showEssayQuestionList(QList<EssayQuestions *> subList)
{
    subTable->setRowCount(subList.count());
    for(int i = 0; i < subList.count(); i++)
    {
        QTableWidgetItem *id = new QTableWidgetItem(QString::number(subList.at(i)->getQuestionId()));
        QTableWidgetItem *title = new QTableWidgetItem(subList.at(i)->getQuestionTitle());
        subTable->setItem(i,0,id);
        subTable->setItem(i,1,title);
    }
}

void QuestionsManageUI::setChoiceQuestions(QList<ChoiceQuestions *> questionList)
{
    choiceQuestionList = questionList;
}

void QuestionsManageUI::setEssayQuestions(QList<EssayQuestions *> questionList)
{
    essayQuestionList = questionList;
}

void QuestionsManageUI::showChoiceQuestion(QTableWidgetItem *item)
{
    AlterChoiceQuestion *alterChoiceQuestionDialog = new AlterChoiceQuestion();
    connect(this, SIGNAL(showChoiceQuestion(ChoiceQuestions*)), alterChoiceQuestionDialog, SLOT(showQuestion(ChoiceQuestions*)));
    connect(alterChoiceQuestionDialog, SIGNAL(updateChoiceQuestion(ChoiceQuestions*)), this, SIGNAL(updateChoiceQuestion(ChoiceQuestions*)));

    ChoiceQuestions *question = NULL;
    int id = obTable->item(item->row(), 0)->text().toInt();
    for(QList<ChoiceQuestions*>::iterator ite = choiceQuestionList.begin(); ite != choiceQuestionList.end(); ++ite){
        if((*ite)->getQuestionId() == id){
            question = *ite;
        }
    }
    emit this->showChoiceQuestion(question);
    alterChoiceQuestionDialog->exec();
}

void QuestionsManageUI::showEssayQuestion(QTableWidgetItem *item)
{
    AlterEssayQuestion *alterEssayQuestionDialog = new AlterEssayQuestion();
    connect(this, SIGNAL(showEssayQuestion(EssayQuestions*)), alterEssayQuestionDialog, SLOT(showQuestion(EssayQuestions*)));
    connect(alterEssayQuestionDialog, SIGNAL(updateEssayQuestion(EssayQuestions*)), this, SIGNAL(updateEssayQuestion(EssayQuestions*)));

    EssayQuestions *question = NULL;
    int id = subTable->item(item->row(), 0)->text().toInt();
    for(QList<EssayQuestions*>::iterator ite = essayQuestionList.begin(); ite != essayQuestionList.end(); ++ite){
        if((*ite)->getQuestionId() == id){
            question = *ite;
        }
    }
    emit this->showEssayQuestion(question);
    alterEssayQuestionDialog->exec();
}

void QuestionsManageUI::on_Button_new_clicked()
{
    AddQuestion *addQuestionDialog = new AddQuestion();
    connect(addQuestionDialog, SIGNAL(addChoiceQuestion(ChoiceQuestions*)), this, SIGNAL(addOb_Questoins(ChoiceQuestions*)));
    connect(addQuestionDialog, SIGNAL(addEssayQuestion(EssayQuestions*)), this, SIGNAL(addSub_Questoins(EssayQuestions*)));

    addQuestionDialog->exec();
}
