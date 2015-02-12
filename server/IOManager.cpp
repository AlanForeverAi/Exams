#include "IOManager.h"
#include <QMessageBox>
#include <QTextStream>
#include <QFile>
#include <QDir>
#include <QDate>
#include<QDebug>
IOManager::IOManager()
{

    QDir dir(".");
    if(!dir.exists("data"))
    {
        dir.mkdir("data");
    }
}

IOManager::~IOManager()
{

}

void IOManager::outputUser(QList<Student*> userlist)
{

    QString filename;
    filename.append(QStringLiteral("data/用户信息_"));
    filename.append(QDate::currentDate().toString());
    filename.append(".txt");
    QFile inouput(filename);
    if(!inouput.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    QTextStream out(&inouput);
    out << "userid " << "\t" << "\t" << "name " << "\t" << "grade " << "\t" << "class" << "\t" << "password " << "\n";
    for(int i = 0; i<userlist.count(); ++i)
    {
        out << userlist.at(i)->getID() << "\t";
        out << userlist.at(i)->getName() << "\t";
        out << userlist.at(i)->getGrade() << "\t";
        out << userlist.at(i)->getClass() << "\t";
        out << userlist.at(i)->getPassword() << "\n";
    }
    inouput.close();
}

//以上为写入文件


//以下为读取文件
QList<Student*> IOManager::inputUser(QString path)
{
    QList<Student*> userlist;

    QFile inouput(path);
    if(!inouput.open(QIODevice::ReadOnly | QIODevice::Text))
        return userlist;
    QTextStream in(&inouput);
    QString temp;
    QString remp;
    temp = in.readLine();
    qDebug() << "this is title:" << temp << "\n";
    while(!in.atEnd())
    {
        Student* user = new Student;
        temp = in.readLine();
        remp = temp.left(temp.indexOf("\t"));
        user->setID(remp);
        temp = temp.remove(0,remp.length()+1);
        remp = temp.left(temp.indexOf("\t"));
        user->setName(remp);
        temp = temp.remove(0,remp.length()+1);
        remp = temp.left(temp.indexOf("\t"));
        user->setGrade(remp.toInt());
        temp = temp.remove(0,remp.length()+1);
        remp = temp.left(temp.indexOf("\t"));
        user->setClass(remp.toInt());
        temp = temp.remove(0,remp.length()+1);
        user->setPassword(temp);
        userlist.append(user);
    }
    inouput.close();
    return userlist;

}
//以上为读取文件



//以下为paper表写入文件
void IOManager::outputPaper(QList<Paper*> paperlist)
{

    QString filename;
    filename.append(QStringLiteral("data/试卷信息_"));
    filename.append(QDate::currentDate().toString());
    filename.append(".txt");
    QFile inouput(filename);
    if(!inouput.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    QTextStream out(&inouput);
    for(int i = 0; i<paperlist.count(); ++i)
    {
        out << QStringLiteral("试卷ID ");
        out << paperlist.at(i)->getPaperId() << "\n";
        out << QStringLiteral("客观题ID ");
        out << paperlist.at(i)->getObQuIds() << "\n";
        out << QStringLiteral("主观题ID ");
        out << paperlist.at(i)->getSubQuIds() << "\n";
        out << QStringLiteral("总分 ");
        out << paperlist.at(i)->getTotalMark() << "\n";
        out << QStringLiteral("客观题分数比例 ");
        out << paperlist.at(i)->getPercent() << "\n";
        out << QStringLiteral("试卷名称 ");
        out << paperlist.at(i)->getDescription() << "\n";
        out << QStringLiteral("考试时间 ");
        out << paperlist.at(i)->getTime() << "\n";
    }
    inouput.close();
}
//以上为paper表写入文件


//以下为paper表读取文件
QList<Paper*> IOManager::inputPaper(QString path)
{
    QList<Paper*> paperlist;

    QFile inouput(path);
    if(!inouput.open(QIODevice::ReadOnly | QIODevice::Text))
        return paperlist;
    QTextStream in(&inouput);
    QString temp;

    while(!in.atEnd())
    {
        Paper* paper = new Paper;
        temp = in.readLine();
        temp = in.readLine();
        temp = temp.mid(temp.indexOf(" ")+1);
        paper->setObQuIds(temp);

        temp = in.readLine();
        temp = temp.mid(temp.indexOf(" ")+1);
        paper->setSubQuIds(temp);

        temp = in.readLine();
        temp = temp.mid(temp.indexOf(" ")+1);
        paper->setTotalMark(temp.toInt());

        temp = in.readLine();
        temp = temp.mid(temp.indexOf(" ")+1);
        paper->setPercent(temp.toInt());

        temp = in.readLine();
        temp = temp.mid(temp.indexOf(" ")+1);
        paper->setDescription(temp);

        temp = in.readLine();
        temp = temp.mid(temp.indexOf(" ")+1);
        paper->setTime(temp.toInt());
        temp = in.readLine();

        paperlist.append(paper);
    }
    inouput.close();
    return paperlist;

}
//以上为paper表读取文件



//以下为obquestions表写入文件
void IOManager::outputOb(QList<ChoiceQuestions*> obquestionlist)
{
    QString filename;
    filename.append(QStringLiteral("data/客观题信息_"));
    filename.append(QDate::currentDate().toString());
    filename.append(".txt");
    QFile inouput(filename);
    if(!inouput.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    QTextStream out(&inouput);
    for(int i = 0; i<obquestionlist.count(); ++i)
    {
        out << "obid ";
        out << obquestionlist.at(i)->getQuestionId() << "\n";
        out << "title ";
        out << obquestionlist.at(i)->getQuestionTitle() << "\n";
        out << "answer ";
        out << obquestionlist.at(i)->getAnswer() << "\n";

    }

    inouput.close();
}
//以上为obquestions表写入文件


//以下为obquestions表读取文件
QList<ChoiceQuestions*> IOManager::inputOb(QString path)
{
    QList<ChoiceQuestions*> oblist;

    QFile inouput(path);
    if(!inouput.open(QIODevice::ReadOnly | QIODevice::Text))
        return oblist;
    QTextStream in(&inouput);
    QString temp;

    while(!in.atEnd())
    {
        ChoiceQuestions* obquestions = new ChoiceQuestions;
        temp = in.readLine();
        temp = temp.mid(temp.indexOf(" ")+1);
        obquestions->setQuestionId(temp.toInt());

        temp = in.readLine();
        temp = temp.mid(temp.indexOf(" ")+1);
        obquestions->setQuestionTitle(temp);

        temp = in.readLine();
        temp = temp.mid(temp.indexOf(" ")+1);
        obquestions->setAnswer(temp);
        oblist.append(obquestions);
    }
    inouput.close();

    return oblist;
}

//以上为obquestions表读取文件

//以下为subquestions表写入文件
void IOManager::outputSub(QList<EssayQuestions*> subquestionlist)
{
    QString filename;
    filename.append(QStringLiteral("data/主观题信息_"));
    filename.append(QDate::currentDate().toString());
    filename.append(".txt");
    QFile inouput(filename);
    if(!inouput.open(QIODevice::WriteOnly | QIODevice::Text))
        return ;
    QTextStream out(&inouput);
    for(int i = 0; i<subquestionlist.count(); ++i)
    {
        out << "subid ";
        out << subquestionlist.at(i)->getQuestionId() << "\n";
        out << "title ";
        out << subquestionlist.at(i)->getQuestionTitle() << "\n";

    }
    inouput.close();
}
//以上为subquestions表写入文件

//以下为subquestions表读取文件
QList<EssayQuestions*> IOManager::inputSub(QString path)
{
    QList<EssayQuestions*> sublist;

    QFile inouput(path);
    if(!inouput.open(QIODevice::ReadOnly | QIODevice::Text))
        return sublist;
    QTextStream in(&inouput);
    QString temp;

    while(!in.atEnd())
    {
        EssayQuestions* subquestions = new EssayQuestions;
        temp = in.readLine();
        temp = temp.mid(temp.indexOf(" ")+1);
        subquestions->setQuestionId(temp.toInt());

        temp = in.readLine();
        temp = temp.mid(temp.indexOf(" ")+1);
        subquestions->setQuestionTitle(temp);
        sublist.append(subquestions);
    }
    inouput.close();
    return sublist;
}
//以上为subquestions表读取文件
