#include"QuestionsManageUI.h"
#include<QMessageBox>
#include<QDebug>

QuestionsManageUI::QuestionsManageUI(QWidget *parent):QWidget(parent)
{
    setupUi(this);
    connect(obTable,SIGNAL(itemClicked(QTableWidgetItem*)),this,SLOT(showCurrentQue(QTableWidgetItem*)));
    connect(subTable,SIGNAL(itemClicked(QTableWidgetItem*)),this,SLOT(showCurrentQue(QTableWidgetItem*)));

    obTable->verticalHeader()->setHidden(true);
    subTable->verticalHeader()->setHidden(true);

    obTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    subTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    obTable->setSelectionBehavior(QAbstractItemView::SelectRows);//点击选择一行
    obTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//自适应列宽
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
        choiceQuestions->setSubjectID(QString(User::GetInstance().getType()));
        emit this->addOb_Questoins(choiceQuestions);
        QMessageBox::about(this,QStringLiteral("信息"),QStringLiteral("添加成功！"));
        delete(choiceQuestions);
    }
    else if(tabWidget->currentIndex() == 1)
    {
        EssayQuestions *essayQuestions = new EssayQuestions;
        essayQuestions->setQuestionTitle(textEdit2_Content->toPlainText());
        essayQuestions->setSubjectID(QString(User::GetInstance().getType()));
        qDebug()<<essayQuestions->getQuestionTitle();
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

//Question
void QuestionsManageUI::modify()
{
    QMessageBox msg;
    msg.setText(QStringLiteral("确定要修改吗？"));
    msg.setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
    int ret = msg.exec();
    if(ret == QMessageBox::Ok)
    {
        if(tabWidget->currentIndex() == 0)
        {
            ChoiceQuestions *choiceQuestions = new ChoiceQuestions;
            choiceQuestions->setQuestionId(obTable->item(obTable->currentRow(),0)->text().toInt());
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
            choiceQuestions->setSubjectID(QString(User::GetInstance().getType()));
            emit this->modifyOb_Questoins(choiceQuestions);
            delete(choiceQuestions);
        }
        else if(tabWidget->currentIndex() == 1)
        {
            EssayQuestions *essayQuestions = new EssayQuestions;
            essayQuestions->setQuestionId(subTable->item(subTable->currentRow(),0)->text().toInt());
            essayQuestions->setQuestionTitle(textEdit2_Content->toPlainText());
            essayQuestions->setSubjectID(QString(User::GetInstance().getType()));
            emit this->modifySub_Questoins(essayQuestions);
            delete(essayQuestions);
        }
    }


}

void QuestionsManageUI::showQuestions(QList<ChoiceQuestions *> obList, QList<EssayQuestions *> subList)
{
    //显示客观题
    _typeList.clear();

    obTable->setRowCount(obList.count());
    for(int i = 0; i < obList.count(); i++)
    {
        QString title = obList.at(i)->getQuestionTitle();
        QString s_maintitle = title.mid(0,title.indexOf("@a"));
        QString s_ansA = title.mid(title.indexOf("@a")+2,title.indexOf("@b")-title.indexOf("@a")-2);
        QString s_ansB = title.mid(title.indexOf("@b")+2,title.indexOf("@c")-title.indexOf("@b")-2);
        QString s_ansC = title.mid(title.indexOf("@c")+2,title.indexOf("@d")-title.indexOf("@c")-2);
        QString s_ansD = title.mid(title.indexOf("@d")+2,title.length()-title.indexOf("@d")-2);

        QTableWidgetItem *maintitle = new QTableWidgetItem(s_maintitle);
        QTableWidgetItem *ansA = new QTableWidgetItem(s_ansA);
        QTableWidgetItem *ansB = new QTableWidgetItem(s_ansB);
        QTableWidgetItem *ansC = new QTableWidgetItem(s_ansC);
        QTableWidgetItem *ansD = new QTableWidgetItem(s_ansD);
        QTableWidgetItem *correctAns = new QTableWidgetItem(obList.at(i)->getAnswer());
        QTableWidgetItem *type = new QTableWidgetItem(obList.at(i)->getSubjectID());
        QTableWidgetItem *id = new QTableWidgetItem(QString::number(obList.at(i)->getQuestionId()));
        maintitle->setToolTip(maintitle->text());
        obTable->setItem(i,0,id);
        obTable->setItem(i,1,type);
        obTable->setItem(i,2,maintitle);
        obTable->setItem(i,3,ansA);
        obTable->setItem(i,4,ansB);
        obTable->setItem(i,5,ansC);
        obTable->setItem(i,6,ansD);
        obTable->setItem(i,7,correctAns);

        if(!_typeList.contains(obList.at(i)->getSubjectID()))
        {
            _typeList<<obList.at(i)->getSubjectID();
        }

    }
    //显示主观题
    subTable->setSelectionBehavior(QAbstractItemView::SelectRows);//点击选择一行
    subTable->horizontalHeader()->setStretchLastSection(true);//自适应列宽
    subTable->setRowCount(subList.count());
    for(int i = 0; i<subList.count(); i++)
    {
        QTableWidgetItem *id = new QTableWidgetItem(QString::number(subList.at(i)->getQuestionId()));
        QTableWidgetItem *title = new QTableWidgetItem(subList.at(i)->getQuestionTitle());
        QTableWidgetItem *type = new QTableWidgetItem(subList.at(i)->getSubjectID());
        subTable->setItem(i,0,id);
        subTable->setItem(i,1,type);
        subTable->setItem(i,2,title);

        if(!_typeList.contains(subList.at(i)->getSubjectID()))
        {
            _typeList << subList.at(i)->getSubjectID();
        }
    }
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
    _mode = 1;
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
        qDebug() << textEdit2_Content->toPlainText();
    }
}

void QuestionsManageUI::on_Button_Save_clicked()
{
    if(_mode == 1)
    {
        this->modify();
    }
    if(_mode == 0)
    {
        this->add();
    }
}

void QuestionsManageUI::on_Button_new_clicked()
{
    _mode = 0;
    textClear();
    textEdit->setText(QStringLiteral("请输入新题目的内容"));
    textEdit2_Content->setText(QStringLiteral("请输入新题目的内容"));
}
