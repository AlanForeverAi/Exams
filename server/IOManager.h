#ifndef IOMANAGER_H
#define IOMANAGER_H
#include "data.h"
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

};

#endif // IOMANAGER_H
