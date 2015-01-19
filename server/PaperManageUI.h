#ifndef PAPAERMANAGEUI_H
#define PAPAERMANAGEUI_H

#include <QWidget>
#include <iostream>
#include "ui_PaperManageUI.h"
#include "data.h"


class PaperManageUI : public QWidget,public Ui::PaperManageUI
{
    Q_OBJECT

public:
    explicit PaperManageUI(QWidget *parent = 0);
    ~PaperManageUI();

    void averageChange();		//题目平均分
    void updateSelectTable();	//更新选择题目列表
    void clear();				//清除
signals:
    void addPaper(Paper);
    void getAllPaper();
    void deletePaper(int);
    void modifyPaper(Paper);
    void getPaperById(int);
    void queryPaperMark(int,QString);
    void saveUsertoPaperMark(int,QList<Student*>);
private slots:
    void on_horizontalSlider_valueChanged(int value);	//调整题目比例
    void on_pushButton_Add_Ob_clicked();				//添加选择题
    void on_pushButton_Add_Sub_clicked();				//添加文档题
    void on_pushButton_Delete_Ob_clicked();				//删除
    void on_pushButton_Delete_Sub_clicked();			//删除
    void on_spinBox_Percentage_Ob_valueChanged(int value);	//修改选择题分值比例
    void on_pushButton_AddorMoidfy_clicked();
    void on_pushButton_tomodify_clicked();
    void on_pushButton_unmodify_clicked();
    void on_pushButton_delete_clicked();
    void on_pushButton_searchall_clicked();
    void on_pushButton_all_1_clicked();					//显示所有用户
    void on_pushButton_searchselect_clicked();			
    void on_pushButton_all_2_clicked();					//显示所有选择用户
    void on_pushButton_adduser_clicked();
    void on_pushButton_deleteuser_clicked();
    void on_pushButton_saveuser_clicked();
    void on_pushButton_print_clicked();
    void on_pushButton_random_clicked();
    void showQuestions(QList<ChoiceQuestions*>,QList<EssayQuestions*>);
    void showAllPaper(QList<Paper*>);
    void showCurrentPaper(Paper);
    void showAllUser(QList<Student*>,QList<USER*>);
    void showSelectUser(QList<Student*>);
    void paperChange(QTableWidgetItem*);
//    void typeChange(QString);
    void showCurrentType(QList<ChoiceQuestions*>,QList<EssayQuestions*>);
    void on_comboBoxselect_currentIndexChanged(const QString &arg1);

private:
    int _currentPaperId;
    //又又见到坑爹的东西。。。。。。。
    QList<ChoiceQuestions *> _allOb;
    QList<ChoiceQuestions *> _selectOb;
    QList<EssayQuestions *> _allSub;
    QList<EssayQuestions *> _selectSub;
    QList<ChoiceQuestions *> _tempOb;
    QList<EssayQuestions *> _tempSub;
    QString  _obQueIds;
    QString _subQueIds;
    QList<Paper *> _paperList;
    QList<Student *> _userList;
    QList<Student *> _selectUserList;
    QList<Student *> _searchList;
    QStringList _typeList;

};

#endif // PAPAERMANAGEUI_H
