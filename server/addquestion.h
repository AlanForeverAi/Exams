#ifndef ADDQUESTION_H
#define ADDQUESTION_H

#include <QDialog>
#include "data.h"
#include "ui_addquestion.h"

class AddQuestion : public QDialog, public Ui::AddQuestion
{
    Q_OBJECT

public:
    AddQuestion();
    ~AddQuestion();

signals:
    void addChoiceQuestion(ChoiceQuestions *);
    void addEssayQuestion(EssayQuestions *);

private slots:
    void on_pushButton_Save_clicked();
    void on_pushButton_Cancel_clicked();
};

#endif // ADDQUESTION_H
