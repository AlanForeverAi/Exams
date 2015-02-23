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

//Question
void QuestionsManageUI::add()
{
    if(tabWidget->currentIndex() == 0)
    {
        ChoiceQuestions *choiceQuestions = new ChoiceQuestions;

        QString title;
        title.append(textEdit->toPlainText());
        title.append("@a");
        title.append(textEdit_A->toPlainText());
        title.append("@b");
        title.append(textEdit_B->toPlainText());
        title.append("@c");
        title.append(textEdit_C->toPlainText());
        title.append("@d");
        title.append(textEdit_D->toPlainText());
        choiceQuestions->setQuestionTitle(title);

        QString answer;
        if(radio_A->isChecked()) answer.append("A-");
        if(radio_B->isChecked()) answer.append("B-");
        if(radio_C->isChecked()) answer.append("C-");
        if(radio_D->isChecked()) answer.append("D-");
        choiceQuestions->setAnswer(answer);
        choiceQuestions->setSubjectID(QString::number(User::GetInstance().getType()));
        emit this->addOb_Questoins(choiceQuestions);
        delete(choiceQuestions);
    }
    else if(tabWidget->currentIndex() == 1)
    {
        EssayQuestions *essayQuestions = new EssayQuestions;
        essayQuestions->setQuestionTitle(textEdit2_Content->toPlainText());
        essayQuestions->setSubjectID(QString::number(User::GetInstance().getType()));
        emit this->addSub_Questoins(essayQuestions);
        delete(essayQuestions);
    }

    this->textClear();
}

void QuestionsManageUI::on_Button_delete_clicked()
{
    QMessageBox msg;
    msg.setText(QStringLiteral("确定要删除吗？"));
    msg.setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
    if(tabWidget_2->currentIndex() == 0 && obTable->currentRow() >= 0)
    {
        int ret = msg.exec();
        if(ret == QMessageBox::Ok)
            emit this->deleteOb_Questoins(obTable->item(obTable->currentRow(),0)->text().toInt());
        else
            return;

    }
    else if(tabWidget_2->currentIndex() == 1 && subTable->currentRow() >= 0)
    {
        int ret  =  msg.exec();
        if(ret == QMessageBox::Ok)
            emit this->deleteSub_Questoins(subTable->item(subTable->currentRow(),0)->text().toInt());
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
    for(int i = 0; i<subList.count(); i++)
    {
        QTableWidgetItem *id = new QTableWidgetItem(QString::number(subList.at(i)->getQuestionId()));
        QTableWidgetItem *title = new QTableWidgetItem(subList.at(i)->getQuestionTitle());
        QTableWidgetItem *type = new QTableWidgetItem(subList.at(i)->getSubjectID());
        subTable->setItem(i,0,id);
        subTable->setItem(i,1,type);
        subTable->setItem(i,2,title);
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

void QuestionsManageUI::textClear()
{
    textEdit->clear();
    textEdit_A->clear();
    textEdit_B->clear();
    textEdit_C->clear();
    textEdit_D->clear();
    radio_A->setChecked(false);
    radio_B->setChecked(false);
    radio_C->setChecked(false);
    radio_D->setChecked(false);
    textEdit2_Content->clear();
}

void QuestionsManageUI::showCurrentQue(QTableWidgetItem *item)
{
    textClear();
    if(tabWidget_2->currentIndex() == 0 && item->row() >= 0)
    {
        tabWidget->setCurrentIndex(0);

        textEdit->setText(obTable->item(item->row(),2)->text());
        textEdit_A->setText(obTable->item(item->row(),3)->text());
        textEdit_B->setText(obTable->item(item->row(),4)->text());
        textEdit_C->setText(obTable->item(item->row(),5)->text());
        textEdit_D->setText(obTable->item(item->row(),6)->text());
        QStringList list = obTable->item(item->row(),7)->text().split("-");
        for(int i = 0; i< list.count(); i++)
        {
            if(list.at(i) == "A") radio_A->setChecked(true);
            if(list.at(i) == "B") radio_B->setChecked(true);
            if(list.at(i) == "C") radio_C->setChecked(true);
            if(list.at(i) == "D") radio_D->setChecked(true);
        }
    }
    else if(tabWidget_2->currentIndex() == 1 && subTable->currentRow() >= 0)
    {
        tabWidget->setCurrentIndex(1);
        textEdit2_Content->setText(subTable->item(subTable->currentRow(),2)->text());
    }
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

void QuestionsManageUI::on_Button_Save_clicked()
{
    this->add();
    textClear();
}

void QuestionsManageUI::on_Button_new_clicked()
{
    this->add();
    textClear();
    textEdit->setText(QStringLiteral("请输入新题目的内容"));
    textEdit2_Content->setText(QStringLiteral("请输入新题目的内容"));
}
