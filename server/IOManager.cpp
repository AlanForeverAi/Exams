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
    ExcelEngine excel;
    excel.Open(path, 1, false);
    int cnt = excel.GetRowCount();
    for(int i = 2; i <= cnt; ++i){
        ChoiceQuestions* objectQuestions = new ChoiceQuestions();
        objectQuestions->setQuestionTitle(excel.GetCellData(i, 1).toString());
        objectQuestions->setAnswer(excel.GetCellData(i, 2).toString());
        oblist.append(objectQuestions);
    }
    excel.Close();
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
    ExcelEngine excel;
    excel.Open(path, 1, false);
    int cnt = excel.GetRowCount();
    for(int i = 2; i <= cnt; ++i){
        EssayQuestions *subquestion = new EssayQuestions();
        subquestion->setQuestionTitle(excel.GetCellData(i, 1).toString());
        sublist.append(subquestion);
    }
    excel.Close();
    return sublist;
}

void IOManager::exportChoiceQuestion(QList<ChoiceQuestions *> questionlist, QString filename)
{
    ExcelEngine excel;
    excel.Open(filename, 1, false);
    excel.SetCellData(1, 1, QStringLiteral("题目"));
    excel.SetCellData(1, 2, QStringLiteral("答案"));
    int cnt = 2;
    for(int i = 0; i < questionlist.count(); ++i){
        excel.SetCellData(cnt+i, 1, questionlist.at(i)->getQuestionTitle());
        excel.SetCellData(cnt+i, 2, questionlist.at(i)->getAnswer());
    }
    excel.Save();
    excel.Close();
}

void IOManager::exportEssayQuestion(QList<EssayQuestions *> questionlist, QString filename)
{
    ExcelEngine excel;
    excel.Open(filename, 1, false);
    excel.SetCellData(1, 1, QStringLiteral("题目"));
    int cnt = 2;
    for(int i = 0; i < questionlist.count(); ++i){
        excel.SetCellData(cnt+i, 1, questionlist.at(i)->getQuestionTitle());
    }
    excel.Save();
    excel.Close();
}

void IOManager::exportStudent(QList<Student *> studentlist, QString filename)
{
    ExcelEngine excel;
    excel.Open(filename, 1, false);
    excel.SetCellData(1, 1, QStringLiteral("学号"));
    excel.SetCellData(1, 2, QStringLiteral("姓名"));
    excel.SetCellData(1, 3, QStringLiteral("年级"));
    excel.SetCellData(1, 4, QStringLiteral("班级"));
    excel.SetCellData(1, 5, QStringLiteral("密码"));
    int cnt = 2;
    for(int i = 0; i < studentlist.count(); ++i){
        excel.SetCellData(cnt+i, 1, studentlist.at(i)->getID());
        excel.SetCellData(cnt+i, 2, studentlist.at(i)->getName());
        excel.SetCellData(cnt+i, 3, studentlist.at(i)->getGrade());
        excel.SetCellData(cnt+i, 4, studentlist.at(i)->getClass());
        excel.SetCellData(cnt+i, 5, studentlist.at(i)->getPassword());
    }
    excel.Save();
    excel.Close();
}

void IOManager::exportTeacher(QList<User *> teacherlist, QString filename)
{
    ExcelEngine excel;
    excel.Open(filename, 1, false);
    excel.SetCellData(1, 1, QStringLiteral("老师工号"));
    excel.SetCellData(1, 2, QStringLiteral("姓名"));
    excel.SetCellData(1, 3, QStringLiteral("密码"));
    excel.SetCellData(1, 4, QStringLiteral("类型"));
    int cnt = 2;
    for(int i = 0; i < teacherlist.count(); ++i){
        excel.SetCellData(cnt+i, 1, teacherlist.at(i)->getID());
        excel.SetCellData(cnt+i, 2, teacherlist.at(i)->getName());
        excel.SetCellData(cnt+i, 3, teacherlist.at(i)->getPassword());
        excel.SetCellData(cnt+i, 4, teacherlist.at(i)->getSubject());
    }
    excel.Save();
    excel.Close();
}

void IOManager::exportManager(QList<User *> managerlist, QString filename)
{
    ExcelEngine excel;
    excel.Open(filename, 1, false);
    excel.SetCellData(1, 1, QStringLiteral("管理员工号"));
    excel.SetCellData(1, 2, QStringLiteral("姓名"));
    excel.SetCellData(1, 3, QStringLiteral("密码"));
    int cnt = 2;
    for(int i = 0; i < managerlist.count(); ++i){
        excel.SetCellData(cnt+i, 1, managerlist.at(i)->getID());
        excel.SetCellData(cnt+i, 2, managerlist.at(i)->getName());
        excel.SetCellData(cnt+i, 3, managerlist.at(i)->getPassword());
    }
    excel.Save();
    excel.Close();
}

void IOManager::exportType(QMap<int, QString> typelist, QString filename)
{
    ExcelEngine excel;
    excel.Open(filename, 1, false);
    excel.SetCellData(1, 1, QStringLiteral("科目编号"));
    excel.SetCellData(1, 2, QStringLiteral("科目"));
    int cnt = 2, i = 0;
    for(QMap<int, QString>::iterator ite = typelist.begin(); ite != typelist.end(); ++ite){
        excel.SetCellData(cnt+i, 1, ite.key());
        excel.SetCellData(cnt+i, 2, ite.value());
        ++i;
    }
    excel.Save();
    excel.Close();
}

QList<Student *> IOManager::importStudent(QString filename)
{
    QList<Student *> studentlist;
    ExcelEngine excel;
    excel.Open(filename, 1, false);
    int cnt = excel.GetRowCount();
    for(int i = 2; i <= cnt; ++i){
        Student *student = new Student();
        student->setID(excel.GetCellData(i, 1).toString());
        student->setName(excel.GetCellData(i, 2).toString());
        student->setGrade(excel.GetCellData(i, 3).toInt());
        student->setClass(excel.GetCellData(i, 4).toInt());
        student->setPassword(excel.GetCellData(i, 5).toString());
        studentlist.append(student);
    }
    excel.Close();
    return studentlist;
}

QList<User *> IOManager::importTeacher(QString filename)
{
    QList<User *> teacherlist;
    ExcelEngine excel;
    excel.Open(filename, 1, false);
    int cnt = excel.GetRowCount();
    for(int i = 2; i <= cnt; ++i){
        User *teacher = new User();
        teacher->setID(excel.GetCellData(i, 1).toString());
        teacher->setName(excel.GetCellData(i, 2).toString());
        teacher->setPassword(excel.GetCellData(i, 3).toString());
        teacher->setSubject(excel.GetCellData(i, 4).toString());
        teacherlist.append(teacher);
    }
    excel.Close();
    return teacherlist;
}

QList<User *> IOManager::importManager(QString filename)
{
    QList<User *> managerlist;
    ExcelEngine excel;
    excel.Open(filename, 1, false);
    int cnt = excel.GetRowCount();
    for(int i = 2; i <= cnt; ++i){
        User *manager = new User();
        manager->setID(excel.GetCellData(i, 1).toString());
        manager->setName(excel.GetCellData(i, 2).toString());
        manager->setPassword(excel.GetCellData(i, 3).toString());
        managerlist.append(manager);
    }
    excel.Close();
    return managerlist;
}

QMap<int, QString> IOManager::importType(QString filename)
{
    QMap<int, QString> typelist;
    ExcelEngine excel;
    excel.Open(filename, 1, false);
    int cnt = excel.GetRowCount();
    for(int i = 2; i <= cnt; ++i){
        typelist[excel.GetCellData(i, 1).toInt()] = excel.GetCellData(i, 2).toString();
    }
    excel.Close();
    return typelist;
}

QStringList IOManager::importExaminee(QString filename)
{
    QStringList studentIDs;
    ExcelEngine excel;
    excel.Open(filename, 1, false);
    int cnt = excel.GetRowCount();
    for(int i = 2; i <= cnt; ++i){
        studentIDs.append(excel.GetCellData(i, 1).toString());
    }
    excel.Close();
    return studentIDs;
}
//以上为subquestions表读取文件
