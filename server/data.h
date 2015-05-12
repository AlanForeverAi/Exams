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

class User{
public:
    User();
    void setID(QString);
    void setName(QString);
    void setPassword(QString);
    void setType(int);
    void setSubject(QString);
    int getType() const;
    QString getID() const;
    QString getName() const;
    QString getPassword() const;
    QString getSubject() const;
    static User& GetInstance();
private:
    QString _id;
    int _type; //根据Type判断用户为管理员还是老师（还要判断老师类型）
    QString _name;
    QString _password;
    QString _subject;
};

class ObjectQuestions{
public:
    ObjectQuestions();
    virtual void setQuestionId(int);
private:
    int _questionID;
    int mark;
    QString _subjectID;
    QString _questionTitle;
    QString _answer;
};

//选择题
class ChoiceQuestions
{
    friend QDataStream &operator <<(QDataStream &,const ChoiceQuestions &);
    friend QDataStream &operator >>(QDataStream &,ChoiceQuestions &);
public:
    ChoiceQuestions();
    void setQuestionId(int);
    void setSubjectID(QString);
    void setQuestionTitle(QString);
    void setAnswer(QString);
    int getQuestionId() const;
    QString getSubjectID() const;
    QString getQuestionTitle() const;
    QString getAnswer() const;
private:
    int _questionId;
    QString _subjectID;
    QString _questionTitle;
    QString _answer;

};

//问答题
class EssayQuestions
{
    friend QDataStream &operator <<(QDataStream &,const EssayQuestions &);
    friend QDataStream &operator >>(QDataStream &,EssayQuestions &);
public:
    EssayQuestions();
    void setQuestionId(int);
    void setSubjectID(QString);
    void setQuestionTitle(QString);
    int getQuestionId() const;
    QString getSubjectID() const;
    QString getQuestionTitle() const;
private:
    int _questionId;
    QString _questionType;
    QString _questionTitle;
};

//选择题答案。。。。
class ChoiceAnswers
{
    friend QDataStream &operator <<(QDataStream &,const ChoiceAnswers &);
    friend QDataStream &operator >>(QDataStream &,ChoiceAnswers &);
public:
    ChoiceAnswers();
    void setAnswerId(int);
    void setPaperId(int);
    void setStudentId(QString);
    void setAnswerList(QVector<QString> answer);
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

//问答题答案
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
    void setPaperId(int);
    void setObQuIds(QString);
    void setSubQuIds(QString);
    void setTotalMark(int);
    void setPercent(int);
    void setDescription(QString);
    void setTime(int);
    void setDate(QString);
    void setSubject(int);
    void setObjectMark(QString mark);
    void setSubjectMark(QString mark);
    QString getObjectMark() const;
    QString getSubjectMark() const;
    int getSubject() const;
    int getPaperId() const;
    QString getObQuIds() const;
    QString getSubQuIds() const;
    QString getDescription() const;
    int     getTotalMark() const;
    int     getPercent() const;
    int     getTime() const;
    QString getDate() const;
    QList<ChoiceQuestions> choiceQuestionList;
    QList<EssayQuestions> essayQuestionbList;
private:
    int     _paperId;
    QString _obQuIds;
    QString _subQuIds;
    QString _description;
    QString _objectMark;
    QString _subjectMark;
    int     _totalMark;
    int     _percent;
    int     _time;
    QString _date;
    int     _subject;
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
    void setPaperid(int);
    void setUserid(QString);
    EssayAnswers getObanswer() const;
    ChoiceAnswers getSubanswer() const;
    int getPaperid() const;
    QString getUserid() const;
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
    void setUserId(QString userId);
    void setName(QString);
    void setGrade(int grade);
    void setClass(int);
    void setTime(int);
    void setPaperId(int paperId);
    void setPaperMark(int mark);
    void setObmark(int obmark);
    void setSubmark(int submark);
    void setPaperName(QString paperName);

    QString getUserId() const;
    QString getName() const;
    int getGrade() const;
    int getClass() const;
    int getTime() const;
    int getPaperId() const;
    int getPaperMark() const;
    int getObmark() const;
    int getSubMark() const;
    QString getPaperName() const;
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
