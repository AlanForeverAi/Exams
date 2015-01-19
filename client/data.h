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
    void setHostName(QString);
    void setSockDescriptor(int);
    QString getID() const;
    QString getName() const;
    int getGrade() const;
    int getClass() const;
    QString getPassword() const;
    QString getState() const;
    QString getHostname() const;
    int getSockDescriptor() const;

    static Student& GetInstance();

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

class ChoiceQuestions
{
    friend QDataStream &operator <<(QDataStream &,const ChoiceQuestions &);
    friend QDataStream &operator >>(QDataStream &,ChoiceQuestions &);
public:
    ChoiceQuestions();
    void setQuestionId(int);
    void setQuestionType(QString);
    void setQuestionTitle(QString);
    void setQuestionAnswer(QString);
    int getQuestionId();
    QString getQuestionType();
    QString getQuestionTitle();
    QString getAnswer();
    void setAnswer(QString answer);
private:
    int _questionId;
    QString _questionType;
    QString _questionTitle;
    QString _answer;

};

class EssayQuestions
{
    friend QDataStream &operator <<(QDataStream &,const EssayQuestions &);
    friend QDataStream &operator >>(QDataStream &,EssayQuestions &);
public:
    EssayQuestions();
    void setQuestionId(int);
    void setQuestionType(QString);
    void setQuestionTitle(QString);
    int getQuestionId();
    QString getQuestionType();
    QString getQuestionTitle();
private:
    int _questionId;
    QString _questionType;
    QString _questionTitle;
};

class ChoiceAnswers
{
    friend QDataStream &operator <<(QDataStream &,const ChoiceAnswers &);
    friend QDataStream &operator >>(QDataStream &,ChoiceAnswers &);
public:
    ChoiceAnswers();
    void setAnswerId(int);
    void setPaperId(int);
    void setStudentId(QString);
    void setAnswerList(QVector<QString>);
    int getAnswerId() const;
    int getPaperId() const;
    QString getStudentId() const;
    QVector<QString> getAnswerList() const;
private:
    int _answerId;
    int _paperId;
    QString _studentId;
    QVector<QString> _answerList;

};

class EssayAnswers
{
    friend QDataStream &operator <<(QDataStream &,const EssayAnswers &);
    friend QDataStream &operator >>(QDataStream &,EssayAnswers &);
public:
    EssayAnswers();
    void setAnswerId(int);
    void setPaperId(int);
    void setStudentId(QString);
    void setAnswers(QString);
    int getAnswerId() const;
    int getPaperId() const;
    QString getStudentId() const;
    QString getAnswers() const;
private:
    int _answerId;
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
    void    setPaperId(int);
    void    setObQuIds(QString);
    void    setSubQuIds(QString);
    void    setTotalMark(int);
    void    setPercent(int);
    void    setDescription(QString);
    void    setTime(int);
    void    setDate(QString);
    int     getPaperId();
    QString getObQuIds();
    QString getSubQuIds();
    QString getDescription();
    int     getTotalMark();
    int     getPercent();
    int     getTime();
    QString getDate();
    QList<ChoiceQuestions> obList;
    QList<EssayQuestions> subList;
private:
    int     _paperId;
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
    void setObanswer(EssayAnswers);
    void setSubanswer(ChoiceAnswers);
    void setPaperId(int);
    void setUserId(QString);
    EssayAnswers getObanswer();
    ChoiceAnswers getSubanswer();
    int getPaperId();
    QString getUserId();
private:
    EssayAnswers _obAnswer;
    ChoiceAnswers _subAnswer;
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
