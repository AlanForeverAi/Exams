#ifndef QuestionsManageUI_H
#define QuestionsManageUI_H

#include <QWidget>
#include "ui_QuestionsManageUI.h"
#include "data.h"
#include "alterchoicequestion.h"
#include "alteressayquestion.h"
#include "addquestion.h"

class QuestionsManageUI:public QWidget,public Ui::QuestionsManageUI
{
    Q_OBJECT
public:
    QuestionsManageUI(QWidget *parent=0);
    ~QuestionsManageUI();

signals:
    void addOb_Questoins(ChoiceQuestions*);
    void addSub_Questoins(EssayQuestions*);
    void modifyOb_Questoins(ChoiceQuestions*);
    void modifySub_Questoins(EssayQuestions*);
    void deleteOb_Questoins(int);
    void deleteSub_Questoins(int);
    void showChoiceQuestion(ChoiceQuestions *);
    void showEssayQuestion(EssayQuestions *);
    void updateChoiceQuestion(ChoiceQuestions *);
    void updateEssayQuestion(EssayQuestions *);

private slots:
    void return_clicked();
    void on_Button_delete_clicked();
    void on_Button_Save_clicked();
    void on_Button_new_clicked();
    void showChoiceQuestion(QTableWidgetItem*);
    void showEssayQuestion(QTableWidgetItem*);
    void showChoiceQuestionList(QList<ChoiceQuestions*>);
    void showEssayQuestionList(QList<EssayQuestions*>);
    void setChoiceQuestions(QList<ChoiceQuestions*>);
    void setEssayQuestions(QList<EssayQuestions*>);

private:
    QList<ChoiceQuestions*> choiceQuestionList;
    QList<EssayQuestions*> essayQuestionList;
};

#endif // QuestionsManageUI_H
