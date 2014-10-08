#ifndef IOMANAGER_H
#define IOMANAGER_H
#include "data.h"
class IOManager:public QObject
{
    Q_OBJECT
public:
    IOManager();
   ~IOManager();

    void outputUser(QList<User*>);
    QList<User*> inputUser(QString);
    void outputPaper(QList<Paper*>);
    QList<Paper*> inputPaper(QString);
    void outputOb(QList<Ob_questions*>);
    QList<Ob_questions*> inputOb(QString);
    void outputSub(QList<Sub_questions*>);
    QList<Sub_questions*> inputSub(QString);

};

#endif // IOMANAGER_H
