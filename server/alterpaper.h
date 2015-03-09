#ifndef ALTERPAPER_H
#define ALTERPAPER_H

#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include "data.h"
#include "setmark.h"
#include "ui_alterpaper.h"

class AlterPaper : public QDialog, public Ui::AlterPaper
{
    Q_OBJECT
public:
    AlterPaper();
    ~AlterPaper();

signals:
    void addPaper(Paper *);
    void updatePaper(Paper *);

private slots:
    void showPaper(Paper *);
    void addPaperMode();
    void setChoiceQuestions(QList<ChoiceQuestions *>);
    void setEssayQuestions(QList<EssayQuestions *>);
    void setSelectedChoice(QString);
    void setSelectedEssay(QString);
    void showChoiceQuestions();
    void showEssayQuestions();
    void showSelectedChoice();
    void showSelectedEssay();
    void updateChoiceMark(int);
    void updateEssayMark(int);
    void updateTotalMark();
    void updateMark();
    void on_pushButton_add_clicked();
    void on_pushButton_remove_clicked();
    void on_pushButton_submit_clicked();
    void on_pushButton_cancel_clicked();

    void setObjectMark();
    void setSubjectMark();

private:
    int type;
    Paper * paper;
    QList<ChoiceQuestions *> choiceQuestions;
    QList<EssayQuestions *> essayQuestions;
    QList<ChoiceQuestions *> selectedChoice;
    QList<EssayQuestions *> selectedEssay;
    QStringList objectMarks;
    QStringList subjectMarks;
};

#endif // ALTERPAPER_H
