#ifndef DBMANAGER_H
#define DBMANAGER_H
#include <QtSql>
#include <iostream>
#include "data.h"


class DBManager:public QObject
{
Q_OBJECT
public:
    DBManager();
    ~DBManager();

    void setConfig(QString, QString, QString);

    QSqlQuery selectType();
    QSqlQuery selectSubject();
    QSqlQuery selectUserTypeBySubject(QString);

    void insertType(int, QString);
    void deleteType(int);
    void updateType(int, QString);

    //Student
    QSqlQuery selectStudent();
    QSqlQuery selectStudentByID(QString);
    QSqlQuery selectStudentByGC(int,int);
    void insertStudent(QString,QString,int,int,QString);
    void deleteStudentById(QString);
    void deleteStudentByName(QString);
    void updateStudent(QString,QString,int,int,QString);
    //ServerUser
    void updateServerUser(QString, QString, QString, int);
    QSqlQuery selectManager();
    QSqlQuery selectUser();
    void insertServerUser(QString, QString, QString, int);
    void deleteServerUserByID(int);
    void deleteServerUserByName(QString);

    void insertOb(QString, QString, int);
    void insertSub(QString, QString);
    QSqlQuery selectObQuestions();//查询客观题表的所有数据
    QSqlQuery selectSubQuestions();//查询主观题表的所有数据
    void deleteObQuestionsByID(int);//按ID找到记录把在问题表和答案表内的该记录一并删除（客观题）
    void deleteSubQuestionsByID(int);//按ID找到记录把在问题表和答案表内的该记录一并删除（主观题）
    void updateChoiceQuestions(int, QString, QString);
    void updateEssayQuestions(int, QString);
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
    QSqlQuery studentLogin(QString,QString);
    QSqlQuery managerLogin(QString,QString);//登录功能
    void updatePaperMarkDone(QString,int,QString);
    int deleteScore(int pid,qlonglong uid);
private:
    QSqlDatabase _db;
};
#endif // DBMANAGER_H
