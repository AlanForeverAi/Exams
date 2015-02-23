#ifndef ALTERCHOICEQUESTION_H
#define ALTERCHOICEQUESTION_H

#include <QDialog>
#include "ui_showchoicequestion.h"
#include "data.h"

class AlterChoiceQuestion : public QDialog, public Ui::AlterChoiceQuestion
{
    Q_OBJECT

public:
    AlterChoiceQuestion();
    ~AlterChoiceQuestion();

signals:
    void updateChoiceQuestion(ChoiceQuestions *question);

private slots:
    void showQuestion(ChoiceQuestions *question);
    void on_pushButton_Save_clicked();
    void on_pushButton_Cancel_clicked();

private:
    int questionId;
};

#endif // ALTERCHOICEQUESTION_H
