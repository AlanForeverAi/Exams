#include "alterchoicequestion.h"

AlterChoiceQuestion::AlterChoiceQuestion()
{
    setupUi(this);
}

AlterChoiceQuestion::~AlterChoiceQuestion()
{

}

void AlterChoiceQuestion::showQuestion(ChoiceQuestions *question)
{
    questionId = question->getQuestionId();
    QString content = question->getQuestionTitle();
    QStringList title = content.split('@');
    QString answer = question->getAnswer();
    answer = answer.mid(0, answer.indexOf("-"));
    textEdit_Question->setText(title.at(0));
    lineEdit_A->setText(title.at(1).mid(1));
    lineEdit_B->setText(title.at(2).mid(1));
    lineEdit_C->setText(title.at(3).mid(1));
    lineEdit_D->setText(title.at(4).mid(1));
    lineEdit_Answer->setText(answer);
}

void AlterChoiceQuestion::on_pushButton_Save_clicked()
{
    ChoiceQuestions *question = new ChoiceQuestions;
    QString content;
    content.append(textEdit_Question->toPlainText());
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
    question->setQuestionId(questionId);

    emit this->updateChoiceQuestion(question);
    delete(question);
    this->close();
}

void AlterChoiceQuestion::on_pushButton_Cancel_clicked()
{
    this->close();
}
