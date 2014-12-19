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

    //Student
    QSqlQuery selectStudent();
    QSqlQuery selectStudentId(QString);
    QSqlQuery selectStudentGC(int,int);//根据年级和班别选择user
    void insertStudent(QString,QString,int,int,QString);///////////插入学生
    void deleteStudentId(QString);/////根据id删除学生
    void deleteStudentName(QString);//根据name删除学生
    void modifyStudent(QString,QString,int,int,QString);
    //ServerUser
    QSqlQuery selectServerUser();
    void insertServerUser(int,QString,QString);
    void deleteServerUserID(int);
    void deleteServerUserName(QString);

    void insertOb(int,QString,QString,QString);
    void insertSub(int,QString,QString);
    QSqlQuery selectObQuestions();//查询客观题表的所有数据
    QSqlQuery selectSubQuestions();//查询主观题表的所有数据
    void deleteObQuestions(int);//按ID找到记录把在问题表和答案表内的该记录一并删除（客观题）
    void deleteSubQuestions(int);//按ID找到记录把在问题表和答案表内的该记录一并删除（主观题）
    void alterObQuestions(int,QString,QString,QString);
    void alterSubQuestions(int,QString,QString);
    void insertPaper(QString,QString,int,int,QString,int);
    QSqlQuery selectPaperById(int);
    QSqlQuery selectPaper();
    void deletePaperById(int);
    void alterPaper(int,QString,QString,int,int,QString,int);


    void insertObAnswers(int,QString,QString);//把学生客观题答案插入客观题答案表
    void insertSubAnswers(int,QString);//把学生主观题答案插入主观题答案表
    void updateObAnswers(int,QString,QString);
    void updateSubAnswers(int,QString,int,QString);
    bool insertPaperMark(QString,QString,int,int,QString);//把学生某张试卷的成绩插入试卷成绩表
    bool deletePaperMark(int);
    QSqlQuery searchPaperMark(int , QString);
    void updatePaperMarkObmark(QString,int,QString);
    void updatePaperMarkSubmark(QString,int,QString);
    void updatePaperMarkTotalmark(int,int,QString);
    QSqlQuery queryPaperMark1(int);//按试卷ID在papermark表中查询,返回的是papermark表的记录
    QSqlQuery queryPaperMark2(QString);//按学生ID在papermark表中查询,返回的是papermark表的记录
    QSqlQuery querySubAnswers(int,QString);//按试卷ID和学生ID在subanswers表中查询
    QSqlQuery login(QString,QString);//登录功能
    QSqlQuery managerLogin(int,QString);//登录功能
    void updatePaperMarkDone(QString,int,QString);
    int deleteScore(int pid,qlonglong uid);
private:
    QSqlDatabase _db;
};
#endif // DBMANAGER_H
