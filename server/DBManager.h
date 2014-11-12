#ifndef DBMANAGER_H
#define DBMANAGER_H
#include<QtSql>
#include <iostream>
#include "data.h"


class DBManager:public QObject
{
Q_OBJECT
public:
    DBManager(QString,QString,QString);
    ~DBManager();


    QSqlQuery SelectUser();
    QSqlQuery SelectUserId(QString);
    QSqlQuery SelectUserGc(int,int);//根据年级和班别选择user
    void InsertUser(QString,QString,int,int,QString);///////////插入学生
    void DeleteUserId(QString);/////根据id删除学生
    void DeleteUserName(QString);//根据name删除学生
    void ModifyUser(QString,QString,int,int,QString);
    //manager
    QSqlQuery SelectManager();
    void InsertManager(int,QString,QString);
    void DeleteManagerId(int);
    void DeleteManagerName(QString);

    void InserOb(int,QString,QString,QString);
    void InserSub(int,QString,QString);
    QSqlQuery SelectobQuestions();//查询客观题表的所有数据
    QSqlQuery SelectsubQuestions();//查询主观题表的所有数据
    void DeleteobQuestions(int);//按ID找到记录把在问题表和答案表内的该记录一并删除（客观题）
    void DeletesubQuestions(int);//按ID找到记录把在问题表和答案表内的该记录一并删除（主观题）
    void AlterobQuestions(int,QString,QString,QString);
    void AltersubQuestions(int,QString,QString);
    void InserPaper(QString,QString,int,int,QString,int);
    QSqlQuery SelectPaperById(int);
    QSqlQuery SelectPaper();
    void DeletePaperById(int);
    void AlterPaper(int,QString,QString,int,int,QString,int);


    void InserobAnswers(int,QString,QString);//把学生客观题答案插入客观题答案表
    void InsersubAnswers(int,QString);//把学生主观题答案插入主观题答案表
    void UpdateobAnswers(int,QString,QString);
    void UpdatesubAnswers(int,QString,int,QString);
    bool InserpaperMark(QString,QString,int,int,QString);//把学生某张试卷的成绩插入试卷成绩表
    bool DeletePapermark(int);
    QSqlQuery SearchpaperMark(int , QString);
    void UpdatepaperMarkObmark(QString,int,QString);
    void UpdatepaperMarkSubmark(QString,int,QString);
    void UpdatepaperMarkTotalmark(int,int,QString);
    QSqlQuery QueryPapermark1(int);//按试卷ID在papermark表中查询,返回的是papermark表的记录
    QSqlQuery QueryPapermark2(QString);//按学生ID在papermark表中查询,返回的是papermark表的记录
    QSqlQuery QuerysubAnswers(int,QString);//按试卷ID和学生ID在subanswers表中查询
    QSqlQuery Login(QString,QString);//登录功能
    QSqlQuery ManagerLogin(int,QString);//登录功能
    void UpdatepapermarkDone(QString,int,QString);
    int DeleteScore(int pid,qlonglong uid);
private:
    QSqlDatabase db;
};
#endif // DBMANAGER_H
