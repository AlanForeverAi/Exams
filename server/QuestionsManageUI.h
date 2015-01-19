#ifndef QuestionsManageUI_H
#define QuestionsManageUI_H

#include<QWidget>
#include"ui_QuestionsManageUI.h"
#include"data.h"
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

private slots:
    void return_clicked();
    void add();
    void on_Button_delete_clicked();
    void modify();
    void on_Button_Save_clicked();
    void on_Button_new_clicked();
    //void on_Button_addtype_clicked();
    void showCurrentQue(QTableWidgetItem*);
    void textClear();
    void showQuestions(QList<ChoiceQuestions*>,QList<EssayQuestions*>);
private:
    QStringList _typeList;
    int _mode;
};

#endif // QuestionsManageUI_H
