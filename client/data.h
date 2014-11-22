#ifndef DATA_H
#define DATA_H
#include<QString>
#include<QDataStream>
#include<QMetaType>
#include<QVector>
class Student
{
    //这个两个运算符重载，是给C/S通讯用的，可以不理
    friend QDataStream &operator <<(QDataStream &,const Student &);
    friend QDataStream &operator >>(QDataStream &,Student &);
public:
    Student();
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
    QString _id;
    QString _name;
    int _grade;
    int _class;
    QString _password;
    QString _state;
    QString _hostname;
    int _socketDescriptor;

};
Q_DECLARE_METATYPE(Student)

/*
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
*/

class ObQuestions
{
    friend QDataStream &operator <<(QDataStream &,const ObQuestions &);
    friend QDataStream &operator >>(QDataStream &,ObQuestions &);
public:
    ObQuestions();
    void setObId(int);
    void setType(QString);
    void setTitle(QString);
    void setAnswer(QString);
    int getObId();
    QString getType();
    QString getTitle();
    QString getAnswer();
private:
    int _obId;
    QString _type;
    QString _title;
    QString _answer;

};

class SubQuestions
{
    friend QDataStream &operator <<(QDataStream &,const SubQuestions &);
    friend QDataStream &operator >>(QDataStream &,SubQuestions &);
public:
    SubQuestions();
    void setSubId(int);
    void setType(QString);
    void setTitle(QString);
    int getSubId();
    QString getType();
    QString getTitle();
private:
    int _subId;
    QString _type;
    QString _title;
};

class SubAnswers
{
    friend QDataStream &operator <<(QDataStream &,const SubAnswers &);
    friend QDataStream &operator >>(QDataStream &,SubAnswers &);
public:
    SubAnswers();
    void setSuAnId(int);
    void setPaperId(int);
    void setStudentId(QString);
    void setSubansList(QVector<QString>);
    int getSuAnId();
    int getPaperId();
    QString getStudentId();
    QVector<QString> getSubansList();
private:
    int _suAnId;
    int _paperId;
    QString _studentId;
    QVector<QString> _subansList;

};

class ObAnswers
{
    friend QDataStream &operator <<(QDataStream &,const ObAnswers &);
    friend QDataStream &operator >>(QDataStream &,ObAnswers &);
public:
    ObAnswers();
    void setObAnId(int);
    void setPaperId(int);
    void setStudentId(QString);
    void setAnswers(QString);
    int getObAnId();
    int getPaperId();
    QString getStudentId();
    QString getAnswers();
private:
    int _obAnId;
    int _paperId;
    QString _studentId;
    QString _answers;

};

class Paper
{
    friend QDataStream &operator <<(QDataStream &,const Paper &);
    friend QDataStream &operator >>(QDataStream &,Paper &);
public:
    Paper();
    void setPaperId(int);
    void setObQuIds(QString);
    void setSubQuIds(QString);
    void setTotalMark(int);
    void setPercent(int);
    void setDescription(QString);
    void setTime(int);
    void setDate(QString);
    int getPaperId();
    QString getObQuIds();
    QString getSubQuIds();
    QString getDescription();
    int     getTotalMark();
    int     getPercent();
    int     getTime();
    QString getDate();
    QList<ObQuestions> obList;
    QList<SubQuestions> subList;
private:
    int _paperId;
    QString _obQuIds;
    QString _subQuIds;
    QString _description;
    int     _totalMark;
    int     _percent;
    int     _time;
    QString _date;


};
Q_DECLARE_METATYPE(Paper)

class AllAnswers
{
    friend QDataStream &operator <<(QDataStream &,const AllAnswers &);
    friend QDataStream &operator >>(QDataStream &,AllAnswers &);
public:
    AllAnswers();
    void setObAnswer(ObAnswers);
    void setSubAnswer(SubAnswers);
    void setPaperId(int);
    void setUserId(QString);
    ObAnswers getObAnswer();
    SubAnswers getSubAnswer();
    int getPaperId();
    QString getUserId();
private:
    ObAnswers _obAnswer;
    SubAnswers _subAnswer;
    int _paperId;
    QString _userId;
};
Q_DECLARE_METATYPE(AllAnswers)

class Combo ///用于成绩管理 包括了user paper papermark全部或者部分属性
{
    friend QDataStream &operator <<(QDataStream &,const Combo &);
    friend QDataStream &operator >>(QDataStream &,Combo &);
public:
    Combo();
    void setUserId(QString);
    void setName(QString);
    void setGrade(int);
    void setClass(int);
    void setTime(int);
    void setPaperId(int);
    void setPaperMark(int);
    void setObmark(int);
    void setSubmark(int);
    void setPaperName(QString);

    QString getUserId();
    QString getName();
    int getGrade();
    int getClass();
    int getTime();
    int getPaperId();
    int getPaperMark();
    int getObmark();
    int getSubMark();
    QString getPaperName();
private:
    QString _userId;
    QString _name;
    int _grade;
    int _class;
    int _time;
    int _paperId;
    int _obmark;
    int _submark;
    QString _paperName;
    int _paperMark;
};
Q_DECLARE_METATYPE(Combo)
Q_DECLARE_METATYPE(QList <Combo>)
#endif // DATA_H
