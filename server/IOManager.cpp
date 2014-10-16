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
    filename.append(QString("data/用户信息_"));
    filename.append(QDate::currentDate().toString());
    filename.append(".txt");
   QFile inouput(filename);
   if(!inouput.open(QIODevice::WriteOnly|QIODevice::Text))
          return;
   QTextStream out(&inouput);
   out<<"userid "<<"\t"<<"\t"<<"name "<<"\t"<<"grade "<<"\t"<<"class"<<"\t"<<"password "<<"\n";
   for(int i=0;i<userlist.count();++i)
      {
         out<<userlist.at(i)->getID()<<"\t";
         out<<userlist.at(i)->getName()<<"\t";
         out<<userlist.at(i)->getGrade()<<"\t";
         out<<userlist.at(i)->getClass()<<"\t";
         out<<userlist.at(i)->getPassword()<<"\n";
   }
  /* for(int i=0;i<userlist.count();++i)
    {
       out<<"userid ";
       out<<userlist.at(i)->getID()<<"\n";
       out<<"name ";
       out<<userlist.at(i)->getName()<<"\n";
       out<<"grade ";
       out<<userlist.at(i)->getGrade()<<"\n";
       out<<"class ";
       out<<userlist.at(i)->getClass()<<"\n";
       out<<"password ";
       out<<userlist.at(i)->getPassword()<<"\n";
 }*/

   inouput.close();
}

//以上为写入文件


//以下为读取文件
 QList<Student*> IOManager::inputUser(QString path)
 {
       QList<Student*> userlist;

   QFile inouput(path);
   if(!inouput.open(QIODevice::ReadOnly|QIODevice::Text))
       return userlist;
   QTextStream in(&inouput);
   QString temp;
   QString remp;
   temp=in.readLine();
   qDebug()<<"this is title:"<<temp<<"\n";
   while(!in.atEnd())
   {
       Student* user=new Student;
       temp=in.readLine();


          remp=temp.left(temp.indexOf("\t"));
          user->setID(remp);
          temp=temp.remove(0,remp.length()+1);


          remp=temp.left(temp.indexOf("\t"));
          user->setName(remp);
          temp=temp.remove(0,remp.length()+1);


          remp=temp.left(temp.indexOf("\t"));
          user->setGrade(remp.toInt());
          temp=temp.remove(0,remp.length()+1);


          remp=temp.left(temp.indexOf("\t"));
          user->setClass(remp.toInt());
          temp=temp.remove(0,remp.length()+1);



          user->setPassword(temp);
   /*temp=in.readLine();
   temp=temp.mid(temp.indexOf(" ")+1);
   user->setID(temp);
   temp=in.readLine();
   temp=temp.mid(temp.indexOf(" ")+1);
   user->setName(temp);
   temp=in.readLine();
   temp=temp.mid(temp.indexOf(" ")+1);
   user->setGrade(temp.toInt());
   temp=in.readLine();
   temp=temp.mid(temp.indexOf(" ")+1);
   user->setClass(temp.toInt());
   temp=in.readLine();
   temp=temp.mid(temp.indexOf(" ")+1);
   user->setPassword(temp);*/
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
     filename.append(QString("data/试卷信息_"));
     filename.append(QDate::currentDate().toString());
     filename.append(".txt");
    QFile inouput(filename);
 if(!inouput.open(QIODevice::WriteOnly|QIODevice::Text))
       return;
 QTextStream out(&inouput);
 for(int i=0;i<paperlist.count();++i)
  {
    out<<QString("试卷ID ");
    out<<paperlist.at(i)->getPaper_id()<<"\n";
    out<<QString("客观题ID ");
    out<<paperlist.at(i)->getOb_qu_ids()<<"\n";
    out<<QString("主观题ID ");
    out<<paperlist.at(i)->getSub_qu_ids()<<"\n";
    out<<QString("总分 ");
    out<<paperlist.at(i)->getTotal_mark()<<"\n";
    out<<QString("客观题分数比例 ");
    out<<paperlist.at(i)->getPercent()<<"\n";
    out<<QString("试卷名称 ");
    out<<paperlist.at(i)->getDescription()<<"\n";
    out<<QString("考试时间 ");
    out<<paperlist.at(i)->getTime()<<"\n";
   }

 inouput.close();
}
//以上为paper表写入文件


//以下为paper表读取文件
QList<Paper*> IOManager::inputPaper(QString path)
{
       QList<Paper*> paperlist;

       QFile inouput(path);
       if(!inouput.open(QIODevice::ReadOnly|QIODevice::Text))
       return paperlist;
       QTextStream in(&inouput);
       QString temp;

       while(!in.atEnd())
       {
           Paper* paper=new Paper;
           temp=in.readLine();
           temp=in.readLine();
       temp=temp.mid(temp.indexOf(" ")+1);
       paper->setOb_qu_ids(temp);

       temp=in.readLine();
       temp=temp.mid(temp.indexOf(" ")+1);
       paper->setSub_qu_ids(temp);

       temp=in.readLine();
       temp=temp.mid(temp.indexOf(" ")+1);
       paper->setTotal_mark(temp.toInt());

       temp=in.readLine();
       temp=temp.mid(temp.indexOf(" ")+1);
       paper->setPercent(temp.toInt());

       temp=in.readLine();
       temp=temp.mid(temp.indexOf(" ")+1);
       paper->setDescription(temp);

       temp=in.readLine();
       temp=temp.mid(temp.indexOf(" ")+1);
       paper->setTime(temp.toInt());
       temp=in.readLine();

       paperlist.append(paper);
       }
       inouput.close();
       return paperlist;

}
//以上为paper表读取文件



//以下为obquestions表写入文件
void IOManager::outputOb(QList<Ob_questions*> obquestionlist)
{
    QString filename;
    filename.append(QString("data/客观题信息_"));
    filename.append(QDate::currentDate().toString());
    filename.append(".txt");
   QFile inouput(filename);
if(!inouput.open(QIODevice::WriteOnly|QIODevice::Text))
       return;
QTextStream out(&inouput);
for(int i=0;i<obquestionlist.count();++i)
 {
    out<<"obid ";
    out<<obquestionlist.at(i)->getOb_id()<<"\n";
    out<<"title ";
    out<<obquestionlist.at(i)->getTitle()<<"\n";
    out<<"answer ";
    out<<obquestionlist.at(i)->getAnswer()<<"\n";

}

inouput.close();
   }
//以上为obquestions表写入文件


//以下为obquestions表读取文件
QList<Ob_questions*> IOManager::inputOb(QString path)
{
       QList<Ob_questions*> oblist;

QFile inouput(path);
if(!inouput.open(QIODevice::ReadOnly|QIODevice::Text))
    return oblist;
QTextStream in(&inouput);
QString temp;

while(!in.atEnd())
{
    Ob_questions* obquestions=new Ob_questions;
    temp=in.readLine();
    temp=temp.mid(temp.indexOf(" ")+1);
    obquestions->setOb_id(temp.toInt());

    temp=in.readLine();
    temp=temp.mid(temp.indexOf(" ")+1);
    obquestions->setTitle(temp);

    temp=in.readLine();
    temp=temp.mid(temp.indexOf(" ")+1);
    obquestions->setAnswer(temp);
    oblist.append(obquestions);
}
inouput.close();

return oblist;

}

//以上为obquestions表读取文件

//以下为subquestions表写入文件
void IOManager::outputSub(QList<Sub_questions*> subquestionlist)
{
    QString filename;
    filename.append(QString("data/主观题信息_"));
    filename.append(QDate::currentDate().toString());
    filename.append(".txt");
   QFile inouput(filename);
if(!inouput.open(QIODevice::WriteOnly|QIODevice::Text))
       return ;
QTextStream out(&inouput);
for(int i=0;i<subquestionlist.count();++i)
 {
    out<<"subid ";
    out<<subquestionlist.at(i)->getSub_id()<<"\n";
    out<<"title ";
    out<<subquestionlist.at(i)->getTitle()<<"\n";

 }
inouput.close();
}
//以上为subquestions表写入文件

//以下为subquestions表读取文件
QList<Sub_questions*> IOManager::inputSub(QString path)
{
       QList<Sub_questions*> sublist;

QFile inouput(path);
if(!inouput.open(QIODevice::ReadOnly|QIODevice::Text))
    return sublist;
QTextStream in(&inouput);
QString temp;

while(!in.atEnd())
{
    Sub_questions* subquestions=new Sub_questions;
    temp=in.readLine();
    temp=temp.mid(temp.indexOf(" ")+1);
    subquestions->setSub_id(temp.toInt());

temp=in.readLine();
temp=temp.mid(temp.indexOf(" ")+1);
subquestions->setTitle(temp);


sublist.append(subquestions);
}
inouput.close();
return sublist;
}
//以上为subquestions表读取文件



















