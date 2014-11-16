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
    void addOb_Questoins(ObQuestions*);
    void addSub_Questoins(SubQuestions*);
    void modifyOb_Questoins(ObQuestions*);
    void modifySub_Questoins(SubQuestions*);
    void deleteOb_Questoins(int);
    void deleteSub_Questoins(int);

private slots:
    void return_clicked();
    void add();
    void on_Button_delete_clicked();
    void modify();
    void on_Button_Save_clicked();
    void on_Button_new_clicked();
    void on_Button_addtype_clicked();
    void showCurrentQue(QTableWidgetItem*);
    void textClear();
    void showQuestions(QList<ObQuestions*>,QList<SubQuestions*>);
private:
    QStringList typelist;
    int mode;
};

#endif // QuestionsManageUI_H
