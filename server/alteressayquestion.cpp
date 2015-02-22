#include "alteressayquestion.h"

AlterEssayQuestion::AlterEssayQuestion()
{
    setupUi(this);
}

AlterEssayQuestion::~AlterEssayQuestion()
{

}

void AlterEssayQuestion::showQuestion(EssayQuestions *question)
{
    questionId = question->getQuestionId();
    textEdit_Question->setText(question->getQuestionTitle());
}

void AlterEssayQuestion::on_pushButton_Save_clicked()
{
    EssayQuestions *question = new EssayQuestions();
    question->setQuestionId(questionId);
    question->setQuestionTitle(textEdit_Question->toPlainText());

    emit this->updateEssayQuestion(question);
    delete(question);
    this->close();
}

void AlterEssayQuestion::on_pushButton_Cnacel_clicked()
{
    this->close();
}
