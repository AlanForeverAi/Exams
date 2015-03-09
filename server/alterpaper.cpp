#include "alterpaper.h"

AlterPaper::AlterPaper()
{
    setupUi(this);
    tableWidget_objectquestion->verticalHeader()->setHidden(true);
    tableWidget_subjectquestion->verticalHeader()->setHidden(true);
    tableWidget_selectobject->verticalHeader()->setHidden(true);
    tableWidget_selectsubject->verticalHeader()->setHidden(true);
    tableWidget_objectquestion->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableWidget_objectquestion->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableWidget_objectquestion->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableWidget_selectobject->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableWidget_selectobject->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableWidget_selectobject->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableWidget_subjectquestion->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableWidget_subjectquestion->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableWidget_subjectquestion->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableWidget_selectsubject->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableWidget_selectsubject->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableWidget_selectsubject->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

AlterPaper::~AlterPaper()
{

}

void AlterPaper::showPaper(Paper *currentPaper)
{
    type = 1;
    paper = currentPaper;
    setObjectMark();
    setSubjectMark();
    updateMark();
    setSelectedChoice(paper->getObQuIds());
    setSelectedEssay(paper->getSubQuIds());
    showSelectedChoice();
    showSelectedEssay();
    showChoiceQuestions();
    showEssayQuestions();
    lineEdit_papername->setText(paper->getDescription());
    lineEdit_mark->setText(QString::number(paper->getTotalMark()));
    spinBox_time->setValue(paper->getTime() / 60);
}

void AlterPaper::addPaperMode()
{
    type = 0;
    paper = new Paper();
    selectedChoice.clear();
    selectedEssay.clear();
    showChoiceQuestions();
    showEssayQuestions();
}

void AlterPaper::setChoiceQuestions(QList<ChoiceQuestions *> questionlist)
{
    choiceQuestions= questionlist;
}

void AlterPaper::setEssayQuestions(QList<EssayQuestions *> questionlist)
{
    essayQuestions = questionlist;
}

void AlterPaper::setSelectedChoice(QString ids)
{
    selectedChoice.clear();
    QStringList idList = ids.split(',');
    for(int i = 0; i < choiceQuestions.count(); ++i){
        if(idList.contains(QString::number(choiceQuestions.at(i)->getQuestionId()))){
            selectedChoice.append(choiceQuestions.at(i));
        }
    }
}

void AlterPaper::setSelectedEssay(QString ids)
{
    selectedEssay.clear();
    QStringList idList = ids.split(',');
    for(int i = 0; i < essayQuestions.count(); ++i){
        if(idList.contains(QString::number(essayQuestions.at(i)->getQuestionId()))){
            selectedEssay.append(essayQuestions.at(i));
        }
    }
}

void AlterPaper::showChoiceQuestions()
{
    int cnt = 0;
    tableWidget_objectquestion->setRowCount(choiceQuestions.count() - selectedChoice.count());
    for(int i = 0; i < choiceQuestions.count(); ++i){
        if(selectedChoice.indexOf(choiceQuestions.at(i)) == -1){
            QTableWidgetItem *id = new QTableWidgetItem(QString::number(choiceQuestions.at(i)->getQuestionId()));
            QTableWidgetItem *title = new QTableWidgetItem(choiceQuestions.at(i)->getQuestionTitle());

            tableWidget_objectquestion->setItem(cnt, 0, id);
            tableWidget_objectquestion->setItem(cnt, 1, title);
            ++cnt;
        }
    }
}

void AlterPaper::showEssayQuestions()
{
    int cnt = 0;
    tableWidget_subjectquestion->setRowCount(essayQuestions.count() - selectedEssay.count());
    for(int i = 0; i < essayQuestions.count(); ++i){
        if(selectedEssay.indexOf(essayQuestions.at(i)) == -1){
            QTableWidgetItem *id = new QTableWidgetItem(QString::number(essayQuestions.at(i)->getQuestionId()));
            QTableWidgetItem *title = new QTableWidgetItem(essayQuestions.at(i)->getQuestionTitle());

            tableWidget_subjectquestion->setItem(cnt, 0, id);
            tableWidget_subjectquestion->setItem(cnt, 1, title);
            ++cnt;
        }
    }
}

void AlterPaper::showSelectedChoice()
{
    tableWidget_selectobject->setRowCount(selectedChoice.count());
    for(int i = 0; i < selectedChoice.count(); ++i){
        QTableWidgetItem *id = new QTableWidgetItem(QString::number(selectedChoice.at(i)->getQuestionId()));
        QTableWidgetItem *title = new QTableWidgetItem(selectedChoice.at(i)->getQuestionTitle());
        QTableWidgetItem *mark = new QTableWidgetItem(objectMarks.at(i));

        tableWidget_selectobject->setItem(i, 0, id);
        tableWidget_selectobject->setItem(i, 1, title);
        tableWidget_selectobject->setItem(i, 2, mark);
    }
}

void AlterPaper::showSelectedEssay()
{
    tableWidget_selectsubject->setRowCount(selectedEssay.count());
    for(int i= 0; i < selectedEssay.count(); ++i){
        QTableWidgetItem *id = new QTableWidgetItem(QString::number(selectedEssay.at(i)->getQuestionId()));
        QTableWidgetItem *title = new QTableWidgetItem(selectedEssay.at(i)->getQuestionTitle());
        QTableWidgetItem *mark = new QTableWidgetItem(subjectMarks.at(i));

        tableWidget_selectsubject->setItem(i, 0, id);
        tableWidget_selectsubject->setItem(i, 1, title);
        tableWidget_selectsubject->setItem(i, 2, mark);
    }
}

void AlterPaper::updateChoiceMark(int mark)
{
    label_objectmark->setText(QString::number(mark));
}

void AlterPaper::updateEssayMark(int mark)
{
    label_subjectmark->setText(QString::number(mark));
}

void AlterPaper::updateTotalMark()
{
    label_totalmark->setText(QString::number(label_objectmark->text().toInt() + label_subjectmark->text().toInt()));
}

void AlterPaper::updateMark()
{
    int sum = 0;
    for(int i = 0; i < objectMarks.count(); ++i){
        sum += objectMarks.at(i).toInt();
    }
    updateChoiceMark(sum);

    sum = 0;
    for(int i = 0; i < subjectMarks.count(); ++i){
        sum += subjectMarks.at(i).toInt();
    }
    updateEssayMark(sum);
    updateTotalMark();
}

void AlterPaper::on_pushButton_add_clicked()
{
    if(tabWidget_question->currentIndex() == 0){
        if(tableWidget_objectquestion->currentRow() < 0){
            QMessageBox::about(this,"msg",QStringLiteral("请选择题目"));
            return;
        }
        else {
            int mark = 0;
            SetMark *setMarkDialog = new SetMark();
            setMarkDialog->exec();
            mark = setMarkDialog->getMark();

            if(mark == 0){
                QMessageBox::about(this,"msg",QStringLiteral("分数不能为零！"));
                return;
            }
            if(lineEdit_mark->text().toInt() < label_totalmark->text().toInt() + mark){
                QMessageBox::about(this,"msg",QStringLiteral("分数超过试卷总分！"));
                return;
            }

            int id = tableWidget_objectquestion->item(tableWidget_objectquestion->currentRow(), 0)->text().toInt();
            for(int i = 0; i < choiceQuestions.count(); ++i){
                if(choiceQuestions.at(i)->getQuestionId() == id){
                    selectedChoice.append(choiceQuestions.at(i));
                    objectMarks.append(QString::number(mark));
                    break;
                }
            }
            showSelectedChoice();
            showChoiceQuestions();
        }
    }
    else if(tabWidget_question->currentIndex() == 1){
        if(tableWidget_subjectquestion->currentRow() < 0){
            QMessageBox::about(this,"msg",QStringLiteral("请选择题目"));
            return;
        }
        else {
            int mark = 0;
            SetMark *setMarkDialog = new SetMark();
            setMarkDialog->exec();
            mark = setMarkDialog->getMark();

            if(mark == 0){
                QMessageBox::about(this,"msg",QStringLiteral("分数不能为零！"));
                return;
            }
            if(lineEdit_mark->text().toInt() < label_totalmark->text().toInt() + mark){
                QMessageBox::about(this,"msg",QStringLiteral("分数超过试卷总分！"));
                return;
            }

            int id = tableWidget_subjectquestion->item(tableWidget_subjectquestion->currentRow(), 0)->text().toInt();
            for(int i = 0; i < essayQuestions.count(); ++i){
                if(essayQuestions.at(i)->getQuestionId() == id){
                    selectedEssay.append(essayQuestions.at(i));
                    subjectMarks.append(QString::number(mark));
                    break;
                }
            }
            showSelectedEssay();
            showEssayQuestions();
        }
    }
    updateMark();
}

void AlterPaper::on_pushButton_remove_clicked()
{\
    if(tabWidget_question->currentIndex() == 0){
        if(tableWidget_selectobject->currentRow() < 0){
            QMessageBox::about(this,"msg",QStringLiteral("请选择题目"));
            return;
        }
        else {
            int id = tableWidget_selectobject->item(tableWidget_selectobject->currentRow(), 0)->text().toInt();
            for(int i = 0; i < selectedChoice.count(); ++i){
                if(selectedChoice.at(i)->getQuestionId() == id){
                    selectedChoice.removeAt(i);
                    objectMarks.removeAt(i);
                    break;
                }
            }
            showSelectedChoice();
            showChoiceQuestions();
        }
    }
    else if(tabWidget_question->currentIndex() == 1){
        if(tableWidget_selectsubject->currentRow() < 0){
            QMessageBox::about(this,"msg",QStringLiteral("请选择题目"));
            return;
        }
        else {
            int id = tableWidget_selectsubject->item(tableWidget_selectsubject->currentRow(), 0)->text().toInt();
            for(int i = 0; i < selectedEssay.count(); ++i){
                if(selectedEssay.at(i)->getQuestionId() == id){
                    selectedEssay.removeAt(i);
                    subjectMarks.removeAt(i);
                    break;
                }
            }
            showSelectedEssay();
            showEssayQuestions();
        }
    }
    updateMark();
}

void AlterPaper::on_pushButton_submit_clicked()
{
    QString objectIds, subjectIds, objectMark, subjectMark;
    for(int i = 0; i < selectedChoice.count(); ++i){
        objectIds += QString::number(selectedChoice.at(i)->getQuestionId());
        objectIds += ",";
    }
    for(int i = 0; i < selectedEssay.count(); ++i){
        subjectIds += QString::number(selectedEssay.at(i)->getQuestionId());
        subjectIds += ",";
    }
    for(int i = 0; i < objectMarks.count(); ++i){
        objectMark += objectMarks.at(i);
        objectMark += ",";
    }
    for(int i = 0; i < subjectMarks.count(); ++i){
        subjectMark += subjectMarks.at(i);
        subjectMark += ",";
    }
    qDebug() << objectIds;
    qDebug() << subjectIds;
    qDebug() << objectMark;
    qDebug() << subjectMark;

    paper->setObQuIds(objectIds);
    paper->setSubQuIds(subjectIds);
    paper->setObjectMark(objectMark);
    paper->setSubjectMark(subjectMark);
    paper->setPercent(label_objectmark->text().toInt());
    paper->setDescription(lineEdit_papername->text());
    paper->setTotalMark(lineEdit_mark->text().toInt());
    paper->setTime(spinBox_time->text().toInt() * 60);

    if(type == 1){
        emit this->updatePaper(paper);
    }
    else {
        paper->setSubject(User::GetInstance().getType());
        emit this->addPaper(paper);
    }
    this->close();
}

void AlterPaper::on_pushButton_cancel_clicked()
{
    this->close();
}

void AlterPaper::setObjectMark()
{
    QString marks = paper->getObjectMark();
    marks = marks.remove(marks.count()-1, 1);
    objectMarks = marks.split(',');
}

void AlterPaper::setSubjectMark()
{
    QString marks = paper->getSubjectMark();
    marks = marks.remove(marks.count()-1, 1);
    subjectMarks = marks.split(',');
}
