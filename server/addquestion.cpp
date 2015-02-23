#include "addquestion.h"

AddQuestion::AddQuestion()
{
    setupUi(this);
}

AddQuestion::~AddQuestion()
{

}

void AddQuestion::on_pushButton_Save_clicked()
{
    if(tabWidget->currentIndex() == 0){
        ChoiceQuestions *question = new ChoiceQuestions();
        QString content;
        content.append(textEdit_ChoiceQuestion->toPlainText());
        content.append("@a");
        content.append(lineEdit_A->text());
        content.append("@b");
        content.append(lineEdit_B->text());
        content.append("@c");
        content.append(lineEdit_C->text());
        content.append("@d");
        content.append(lineEdit_D->text());
        question->setQuestionTitle(content);
        QString answer = lineEdit_Answer->text() + "-";
        question->setAnswer(answer);
        question->setSubjectID(QString::number(User::GetInstance().getType()));

        emit this->addChoiceQuestion(question);
        delete(question);
    }
    else if(tabWidget->currentIndex() == 1){
        EssayQuestions *question = new EssayQuestions();
        QString content;
        question->setQuestionTitle(content);
        question->setSubjectID(QString::number(User::GetInstance().getType()));

        emit this->addEssayQuestion(question);
        delete(question);
    }
    this->close();
}

void AddQuestion::on_pushButton_Cancel_clicked()
{
    this->close();
}
