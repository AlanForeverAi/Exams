#ifndef PAPERSETTING_H
#define PAPERSETTING_H

#include <QWidget>
#include <QDebug>
#include <QMessageBox>
#include "ui_papersetting.h"
#include "data.h"

class PaperSetting : public QWidget, public Ui::PaperSetting
{
    Q_OBJECT
public:
    explicit PaperSetting(QWidget *parent = 0);
    ~PaperSetting();

signals:
    void getSelectStudent(int id);

private slots:
    void setPaperList(QList<Paper *>);
    void setStudentList(QList<Student *>);
    void showPaper(QList<Paper *>);
    void changePaper(QTableWidgetItem *);
    void showSelectStudent(QStringList);
    void setSelectStudent(QStringList);
    void on_pushButton_searchpaper_clicked();
    void on_pushButton_allpaper_clicked();
    void on_pushButton_searchselectstudent_clicked();
    void on_pushButton_allselectstudent_clicked();

private:
    QList<Paper *> paperList;
    QList<Student *> studentList;
    QStringList selectedStudent;
    QButtonGroup paperSelect;
    QButtonGroup studentSelect;
};

#endif // PAPERSETTING_H
