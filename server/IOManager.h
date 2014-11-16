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
    //下面又写死了。。。。
    void outputOb(QList<ObQuestions*>);
    QList<ObQuestions*> inputOb(QString);
    void outputSub(QList<SubQuestions*>);
    QList<SubQuestions*> inputSub(QString);

};

#endif // IOMANAGER_H
