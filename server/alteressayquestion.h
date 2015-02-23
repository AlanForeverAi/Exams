#ifndef ALTERESSAYQUESTION_H
#define ALTERESSAYQUESTION_H

#include <QDialog>
#include "ui_showessayquestion.h"
#include "data.h"

class AlterEssayQuestion : public QDialog, public Ui::AlterEssayQuestion
{
    Q_OBJECT

public:
    AlterEssayQuestion();
    ~AlterEssayQuestion();

signals:
    void updateEssayQuestion(EssayQuestions *question);

private slots:
    void showQuestion(EssayQuestions *question);
    void on_pushButton_Save_clicked();
    void on_pushButton_Cnacel_clicked();

private:
    int questionId;
};

#endif // ALTERESSAYQUESTION_H
