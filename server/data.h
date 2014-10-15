#ifndef DATA_H
#define DATA_H
#include<QString>
#include<QDataStream>
#include<QMetaType>
#include<QVector>
class User
{
    //这个两个运算符重载，是给C/S通讯用的，可以不理
    friend QDataStream &operator <<(QDataStream &,const User &);
    friend QDataStream &operator >>(QDataStream &,User &);
public:
    User();
    void setID(QString);
    void setName(QString);
    void setGrade(int);
    void setClass(int);
    void setPassword(QString);
    void setState(QString);
    void setHostname(QString);
    void setSockDescriptor(int);
    QString getID();
    QString getName();
    int getGrade();
    int getClass();
    QString getPassword();
    QString getState();
    QString getHostname();
    int getSockDescriptor();
private:
    QString ID;
    QString Name;
    int Grade;
    int Class;
    QString Password;
    QString state;
    QString hostname;
    int socketDescriptor; //socket文件描述符

};
Q_DECLARE_METATYPE(User)

//管理员。。。这个以后需要修改。。。。权限不正确。。。。
class Manager
{
public:
    Manager();
    void setId(int);
    void setName(QString);
    void setPassword(QString);

    int getId();
    QString getName();
    QString getPassword();
private:
    int Id;
    QString Name;
    QString Password;

};

/*
 * 参考设计模式，修改？设置问题基类，方便以后添加新的题型。。。。。但是如何解决判断题目的类型。。。设计模式。。。
  */
//客观题
class Ob_questions
{
    friend QDataStream &operator <<(QDataStream &,const Ob_questions &);
    friend QDataStream &operator >>(QDataStream &,Ob_questions &);
public:
    Ob_questions();
    void setOb_id(int);
    void setType(QString);
    void setTitle(QString);
    void setAnswer(QString);
    int getOb_id();
    QString getType();
    QString getTitle();
    QString getAnswer();
private:
    int Ob_id;
    QString Type;
    QString Title;
    QString Answer;

};

//主观题，添加参考答案？
class Sub_questions
{
    friend QDataStream &operator <<(QDataStream &,const Sub_questions &);
    friend QDataStream &operator >>(QDataStream &,Sub_questions &);
public:
    Sub_questions();
    void setSub_id(int);
    void setType(QString);
    void setTitle(QString);
    int getSub_id();
    QString getType();
    QString getTitle();
private:
    int Sub_id;
    QString Type;
    QString Title;
};

//主观题答案。。。。
class Sub_answers
{
    friend QDataStream &operator <<(QDataStream &,const Sub_answers &);
    friend QDataStream &operator >>(QDataStream &,Sub_answers &);
public:
    Sub_answers();
    void setSu_an_id(int);
    void setPaper_id(int);
    void setStudent_id(QString);
    void setSubanslist(QVector<QString>);
    int getSu_an_id();
    int getPaper_id();
    QString getStudent_id();
    QVector<QString>getSubanslist();
private:
    int Su_an_id;
    int Paper_id;
    QString Student_id;
   QVector<QString> subanslist;

};

//客观题答案
class Ob_answers   //作答的答案
{
    friend QDataStream &operator <<(QDataStream &,const Ob_answers &);
    friend QDataStream &operator >>(QDataStream &,Ob_answers &);
public:
    Ob_answers();
    void setOb_an_id(int);
    void setPaper_id(int);
    void setStudent_id(QString);
    void setAnswers(QString);
    int getOb_an_id();
    int getPaper_id();
    QString getStudent_id();
    QString getAnswers();
private:
    int Ob_an_id;
    int Paper_id;
    QString Student_id;
    QString Answers;

};

//试卷。。。。坑爹的通过主观题id和客观题id来决定试卷内容。。。以后需要添加新的题型又需要修改。。。。
//可以使用vector存储题目id？QList可以存储题目父类指针。。。。方便以后修改。。。。
class Paper
{
    friend QDataStream &operator <<(QDataStream &,const Paper &);
    friend QDataStream &operator >>(QDataStream &,Paper &);
public:
    Paper();
    void setPaper_id(int);
    void setOb_qu_ids(QString);
    void setSub_qu_ids(QString);
    void setTotal_mark(int);
    void setPercent(int);
    void setDescription(QString);
    void setTime(int);
    void setDate(QString);
    int getPaper_id();
    QString getOb_qu_ids();
    QString getSub_qu_ids();
    QString getDescription();
    int     getTotal_mark();
    int     getPercent();
    int     getTime();
    QString getDate();
    //一下两个list看着好不顺眼。。。。
    QList<Ob_questions> obList;
    QList<Sub_questions> subList;
private:
    int Paper_id;
    QString Ob_qu_ids;
    QString Sub_qu_ids;
    QString Description;
    int     Total_mark;
    int     Percent;
    int     time;
    QString date;


};
Q_DECLARE_METATYPE(Paper)

class All_answers
{
    friend QDataStream &operator <<(QDataStream &,const All_answers &);
    friend QDataStream &operator >>(QDataStream &,All_answers &);
    public:
        All_answers();
        //下面的东西又又做死了。。。。
        void setObanswer(Ob_answers);
        void setSubanswer(Sub_answers);
        void setPaperid(int);
        void setUserid(QString);
        Ob_answers getObanswer();
        Sub_answers getSubanswer();
        int getPaperid();
        QString getUserid();
    private:
        Ob_answers obanswer;
        Sub_answers subanswer;
        int paperid;
        QString userid;
};
Q_DECLARE_METATYPE(All_answers)

class Combo ///用于成绩管理 包括了user paper papermark全部或者部分属性
{
    friend QDataStream &operator <<(QDataStream &,const Combo &);
    friend QDataStream &operator >>(QDataStream &,Combo &);
public:
    Combo();
    void setUser_id(QString);
    void setName(QString);
    void setGrade(int);
    void setClass(int);
    void setTime(int);
    void setPaper_id(int);
    void setPaper_mark(int);
    void setObmark(int);
    void setSubmark(int);
    void setPaperName(QString);

    QString getUser_id();
    QString getName();
    int getGrade();
    int getClass();
    int getTime();
    int getPaper_id();
    int getPaper_mark();
    int getObmark();
    int getSubMark();
    QString getPaperName();
private:
    QString User_id;
    QString Name;
    int Grade;
    int Class;
    int Time;
    int Paper_id;
    int obmark;
    int submark;
    QString paperName;
    int Paper_mark;
};
Q_DECLARE_METATYPE(Combo)
Q_DECLARE_METATYPE(QList <Combo>)
#endif // DATA_H
