#ifndef DBMANAGER_H
#define DBMANAGER_H
#include<QtSql>


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
    QSqlQuery SelectOb_questions();//查询客观题表的所有数据
    QSqlQuery SelectSub_questions();//查询主观题表的所有数据
    void DeleteOb_questions(int);//按ID找到记录把在问题表和答案表内的该记录一并删除（客观题）
    void DeleteSub_questions(int);//按ID找到记录把在问题表和答案表内的该记录一并删除（主观题）
    void AlterOb_questions(int,QString,QString,QString);
    void AlterSub_questions(int,QString,QString);
    void InserPaper(QString,QString,int,int,QString,int);
    QSqlQuery SelectPaperById(int);
    QSqlQuery SelectPaper();
    void DeletePaperById(int);
    void AlterPaper(int,QString,QString,int,int,QString,int);


    void InserOb_answers(int,QString,QString);//把学生客观题答案插入客观题答案表
    void InserSub_answers(int,QString);//把学生主观题答案插入主观题答案表
    void updateOb_answers(int,QString,QString);
    void updateSub_answers(int,QString,int,QString);
    bool InserPaper_mark(QString,QString,int,int,QString);//把学生某张试卷的成绩插入试卷成绩表
    bool deletePapermark(int);
    QSqlQuery SearchPaper_mark(int , QString);
    void updatePaper_mark_obmark(QString,int,QString);
    void updatePaper_mark_Submark(QString,int,QString);
    void updatePaper_mark_totalmark(int,int,QString);
    QSqlQuery Query_papermark1(int);//按试卷ID在papermark表中查询,返回的是papermark表的记录
    QSqlQuery Query_papermark2(QString);//按学生ID在papermark表中查询,返回的是papermark表的记录
    QSqlQuery QuerySub_answers(int,QString);//按试卷ID和学生ID在subanswers表中查询
    QSqlQuery Login(QString,QString);//登录功能
    QSqlQuery managerLogin(int,QString);//登录功能
    void updatePapermark_done(QString,int,QString);
    int delete_score(int pid,qlonglong uid);
private:
    QSqlDatabase db;
};
#endif // DBMANAGER_H
