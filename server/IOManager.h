#ifndef IOMANAGER_H
#define IOMANAGER_H

#include "data.h"
#include "excelengine.h"

class IOManager:public QObject
{
    Q_OBJECT
public:
    IOManager();
    ~IOManager();

    void outputUser(QList<Student*>);
    QList<Student*> inputUser(QString);
    void outputPaper(QList<Paper*>);
    QList<Paper*> inputPaper(QString);
    void outputOb(QList<ChoiceQuestions*>);
    QList<ChoiceQuestions*> inputOb(QString);
    void outputSub(QList<EssayQuestions*>);
    QList<EssayQuestions*> inputSub(QString);

    void exportChoiceQuestion(QList<ChoiceQuestions *>, QString);
    void exportEssayQuestion(QList<EssayQuestions *>, QString);
    void exportStudent(QList<Student *>, QString);
    void exportTeacher(QList<User *>, QString);
    void exportManager(QList<User *>, QString);
    void exportType(QMap<int, QString>, QString);
    QList<Student *> importStudent(QString);
    QList<User *> importTeacher(QString);
    QList<User *> importManager(QString);
    QMap<int, QString> importType(QString);
    QStringList importExaminee(QString);
};

#endif // IOMANAGER_H
