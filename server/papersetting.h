#ifndef PAPERSETTING_H
#define PAPERSETTING_H

#include <QWidget>
#include <QDebug>
#include "ui_papersetting.h"
#include "data.h"

class PaperSetting : public QWidget, public Ui::PaperSetting
{
    Q_OBJECT
public:
    explicit PaperSetting(QWidget *parent = 0);
    ~PaperSetting();

signals:
//    void showStudent(QList<Student *>);
    void getSelectStudent(int id);

private slots:
    void setPaperList(QList<Paper *>);
    void setStudentList(QList<Student *>);
//    void setSelectedStudent(QList<Student *>);
    void showPaper(QList<Paper *>);
    void changePaper(QTableWidgetItem *);
    void showSelectStudent(QStringList);

private:
    QList<Paper *> paperList;
    QList<Student *> studentList;
    QStringList selectedStudent;

};

#endif // PAPERSETTING_H
