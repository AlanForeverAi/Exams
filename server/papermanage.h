void on_pushButton_unmodify_clicked();
#ifndef PAPAERMANAGEUI_H
#define PAPAERMANAGEUI_H

#include <QWidget>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QTime>
#include <QDebug>
#include <QHeaderView>
#include "ui_papermanage.h"
#include "data.h"
#include "alterpaper.h"

class PaperManageUI : public QWidget,public Ui::PaperManageUI
{
    Q_OBJECT

public:
    explicit PaperManageUI(QWidget *parent = 0);
    ~PaperManageUI();

signals:
    void addPaper(Paper);
    void getAllPaper();
    void deletePaper(int);
    void modifyPaper(Paper);
    void getPaperById(int);
    void queryPaperMark(int,QString);
    void saveUsertoPaperMark(int,QList<Student*>);
    void showPaper(Paper *);
    void showChoiceQuestions(QList<ChoiceQuestions *>);
    void showEssayQuestions(QList<EssayQuestions *>);
    void updatePaper(Paper *);
    void addPaperMode();
    void insertPaper(Paper *);

private slots:
    void on_pushButton_AddorMoidfy_clicked();
    void on_pushButton_tomodify_clicked();
    void on_pushButton_delete_clicked();
    void on_pushButton_searchall_clicked();
    void on_pushButton_all_1_clicked();					//显示所有用户
    void on_pushButton_searchselect_clicked();			
    void on_pushButton_all_2_clicked();					//显示所有选择用户
    void showAllPaper(QList<Paper*>);
    void showStudent(QList<Student *>);
    void showSelectUser(QList<Student*>);
    void alterPaper(QTableWidgetItem *);
    void setChoiceQuestions(QList<ChoiceQuestions *>);
    void setEssayQuestions(QList<EssayQuestions *>);

private:
    int _currentPaperId;
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
    QList<ChoiceQuestions *> choicequestions;
    QList<EssayQuestions *> essayquestions;
};

#endif // PAPAERMANAGEUI_H
