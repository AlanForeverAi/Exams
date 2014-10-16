#ifndef SUBMARKUI_H
#define SUBMARKUI_H

#include <QWidget>
#include  "ui_SubMarkUI.h"
#include "data.h"
#include<QTableWidgetItem>

class SubMarkUI : public QWidget,public Ui::SubMarkUI
{
    Q_OBJECT

public:
    explicit SubMarkUI(QWidget *parent = 0);
    ~SubMarkUI();
signals:
    void getUserByPaperId(int,QString);
    void getSubAnswer(int,QString);
    void submitSubMark(QStringList);
private slots:
    void showPapers(QList<Paper*>);
    void paperTableChange(QTableWidgetItem*);
    void userTableChange(QTableWidgetItem*);
    void showUserByPaperId(QList<Student*>);
    void showSubAnswer(QVector<QString>);
    void on_pushButton_Pre_clicked();
    void on_pushButton_Next_clicked();
    void on_pushButton_submit_clicked();
private:
    void showCurrentAnswer(int);
private:
    QList<Paper*> paperList;
    int subNo;
    QVector<QString> submark;
    QVector<QString> sub;
    QString currentPaperid;
    QString currentUserid;


};

#endif // SUBMARKUI_H
