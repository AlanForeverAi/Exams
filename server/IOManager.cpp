#include "iomanager.h"
#include <QMessageBox>
#include <QTextStream>
#include <QFile>
#include <QDir>
#include <QDate>
#include <QDebug>
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
    out.setFieldWidth(18);
    out << "userid" << "name" << "grade" << "class" << "password" << "\n";
    for(int i = 0; i<userlist.count(); ++i)
    {
        out << userlist.at(i)->getID();
        out << userlist.at(i)->getName();
        out << userlist.at(i)->getGrade();
        out << userlist.at(i)->getClass();
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
//        temp = in.readLine();
//        temp = temp.mid(temp.indexOf(" ")+1);
//        obquestions->setQuestionId(temp.toInt());

        temp = in.readLine();
        temp = temp.mid(temp.indexOf(" ") + 1);
        obquestions->setQuestionTitle(temp);

        temp = in.readLine();
        temp = temp.mid(temp.indexOf(" ") + 1);
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
        subquestions->setQuestionTitle(temp);
        sublist.append(subquestions);
    }
    inouput.close();
    return sublist;
}

void IOManager::exportChoiceQuestion(QList<ChoiceQuestions *> questionlist, QString filename)
{
    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return ;
    QTextStream out(&file);
    for(int i = 0; i < questionlist.count(); ++i){
        out << QStringLiteral("题目： ");
        out << questionlist.at(i)->getQuestionTitle() << "\n";
        out << QStringLiteral("答案： ");
        out << questionlist.at(i)->getAnswer() << "\n";
    }
    file.close();
}

void IOManager::exportEssayQuestion(QList<EssayQuestions *> questionlist, QString filename)
{
    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return ;
    QTextStream out(&file);
    for(int i = 0; i < questionlist.count(); ++i){
        out << QStringLiteral("题目： ");
        out << questionlist.at(i)->getQuestionTitle() << "\n";
    }
    file.close();
}

void IOManager::exportStudent(QList<Student *> studentlist, QString filename)
{
    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    QTextStream out(&file);
    out << QStringLiteral("学号") << "," << QStringLiteral("姓名") << "," << QStringLiteral("年级") << ","
        << QStringLiteral("班级") << "," << QStringLiteral("密码") << "\n";
    for(int i = 0; i< studentlist.count(); ++i)
    {
        out << studentlist.at(i)->getID();
        out << ",";
        out << studentlist.at(i)->getName();
        out << ",";
        out << studentlist.at(i)->getGrade();
        out << ",";
        out << studentlist.at(i)->getClass();
        out << ",";
        out << studentlist.at(i)->getPassword() << "\n";
    }
    file.close();
}

void IOManager::exportTeacher(QList<User *> teacherlist, QString filename)
{
    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    QTextStream out(&file);
    out << QStringLiteral("老师工号") << "," << QStringLiteral("姓名") << "," << QStringLiteral("密码") << "," << QStringLiteral("类型") << "\n";
    for(int i = 0; i < teacherlist.count(); ++i){
        out << teacherlist.at(i)->getID();
        out << ",";
        out << teacherlist.at(i)->getName();
        out << ",";
        out << teacherlist.at(i)->getPassword();
        out << ",";
        out << teacherlist.at(i)->getSubject() << "\n";
    }
    file.close();
}

void IOManager::exportManager(QList<User *> managerlist, QString filename)
{
    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    QTextStream out(&file);
    out << QStringLiteral("管理员工号") << "," << QStringLiteral("姓名") << "," << QStringLiteral("密码") << "\n";
    for(int i = 0; i < managerlist.count(); ++i){
        out << managerlist.at(i)->getID();
        out << ",";
        out << managerlist.at(i)->getName();
        out << ",";
        out << managerlist.at(i)->getPassword() << "\n";
    }
    file.close();
}

void IOManager::exportType(QMap<int, QString> typelist, QString filename)
{
    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    QTextStream out(&file);
    out << QStringLiteral("科目编号") << "," << QStringLiteral("科目") << "\n";
    for(QMap<int, QString>::iterator ite = typelist.begin(); ite != typelist.end(); ++ite){
        out << ite.key();
        out << ",";
        out << ite.value() << "\n";
    }
    file.close();
}

QList<Student *> IOManager::importStudent(QString filename)
{
    QList<Student *> studentlist;
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return studentlist;
    QTextStream in(&file);
    QString temp;
    QStringList args;
    temp = in.readLine();
    while(!in.atEnd()){
        Student *student = new Student();
        temp = in.readLine();
        args = temp.split(',');
        args.removeAll("");
        student->setID(args.at(0));
        student->setName(args.at(1));
        student->setGrade(args.at(2).toInt());
        student->setClass(args.at(3).toInt());
        student->setPassword(args.at(4));
        studentlist.append(student);
    }
    file.close();
    return studentlist;
}

QList<User *> IOManager::importTeacher(QString filename)
{
    QList<User *> teacherlist;
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return teacherlist;
    QTextStream in(&file);
    QString temp;
    QStringList args;
    temp = in.readLine();
    while(!in.atEnd()){
        User *teacher = new User();
        temp = in.readLine();
        args = temp.split(',');
        args.removeAll("");
        teacher->setID(args.at(0));
        teacher->setName(args.at(1));
        teacher->setPassword(args.at(2));
        teacher->setSubject(args.at(3));
        teacherlist.append(teacher);
    }
    file.close();
    return teacherlist;
}

QList<User *> IOManager::importManager(QString filename)
{
    QList<User *> managerlist;
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return managerlist;
    QTextStream in(&file);
    QString temp;
    QStringList args;
    temp = in.readLine();
    while(!in.atEnd()){
        User *manager = new User();
        temp = in.readLine();
        args = temp.split(',');
        args.removeAll("");
        manager->setID(args.at(0));
        manager->setName(args.at(1));
        manager->setPassword(args.at(2));
        managerlist.append(manager);
    }
    file.close();
    return managerlist;
}

QMap<int, QString> IOManager::importType(QString filename)
{
    QMap<int, QString> typelist;
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return typelist;
    QTextStream in(&file);
    QString temp;
    QStringList args;
    temp = in.readLine();
    while(!in.atEnd()){
        temp = in.readLine();
        args = temp.split(',');
        args.removeAll("");
        typelist[args.at(0).toInt()] = args.at(1);
    }
    file.close();
    return typelist;
}

QStringList IOManager::importExaminee(QString filename)
{
    QStringList studentIDs;
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        return studentIDs;
    }
    QTextStream in(&file);
    QString temp;
    temp = in.readLine();
    while(!in.atEnd()){
        temp = in.readLine();
        studentIDs.append(temp.split(',').at(0));
    }
    file.close();
    return studentIDs;
}
//以上为subquestions表读取文件
