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
    int _socketDescriptor; //socket文件描述符

};
Q_DECLARE_METATYPE(Student)

class User{
public:
    User();
    void setID(QString);
//    void setID(int);
    void setName(QString);
    void setPassword(QString);
    void setType(int);
    void setSubject(QString);
    int getType() const;
//    int getID() const;
    QString getID() const;
    QString getName() const;
    QString getPassword() const;
    QString getSubject() const;
    static User& GetInstance();
private:
//    int _id;
    QString _id;
    int _type; //根据Type判断用户为管理员还是老师（还要判断老师类型）
    QString _name;
    QString _password;
    QString _subject;
};

/*
 * 参考设计模式，修改？设置问题基类，方便以后添加新的题型。。。。。但是如何解决判断题目的类型。。。设计模式。。。
  */
////问题基类。。。。
//class Questions{
//public:
//    Questions();
//    void setId(int);
//    void setSubject(QString);
//    void setTitle(QString);
//    void setAnswer(QString);
//    void setMark(int);
//    int getId();
//    int getMark();
//    QString getSubject();
//    QString getTitle();
//    QString getAnswer();

//private:
//    int _questionId;
//    //QString _subject; //科目
//    QString _title;
//    QString _answer;
//    int _mark;
//};

//class ObQuestions : public Questions {
//  // 暂时还没考虑具体子类的结构。。。。
//};

//class SubQuestions : public Questions {
//  // 暂时还没考虑具体子类的结构。。。。
//};


//class showAnswerBehavior {
//public:
//    showAnswerBehavior();
//    virtual QString getAnswer() = 0;
//    virtual void setAnswer(QString) = 0;

//protected:
//    QString _answer;
//};

//class showNoAnswer : public showAnswerBehavior {
//public:
//    virtual QString getAnswer();
//    virtual void setAnswer(QString);
//};

//class showWithAnswer : public showAnswerBehavior {
//public:
//    virtual QString getAnswer();
//    virtual void setAnswer(QString);
//};


//class Questions{
//public:
//    Questions();

//    int getQuestionId() const;
//    void setQuestionId(int getQuestionId);

//    QString getQuestionType() const;
//    void setQuestionType(const QString &getQuestionType);

//    QString getQuestionTitle() const;
//    void setQuestionTitle(const QString &getQuestionTitle);

//private:
//    int _questionId;
//    QString _questionType;
//    QString _questionTitle;

//protected:
//    showAnswerBehavior *showAnswer;
//};


//class ObQuestionsTest : public Questions {
//    friend QDataStream &operator <<(QDataStream &,const ObQuestionsTest &);
//    friend QDataStream &operator >>(QDataStream &,ObQuestionsTest &);

//public:
//    ObQuestionsTest();
//};



//class SubQuestionsTest : public Questions {
//    friend QDataStream &operator <<(QDataStream &,const SubQuestionsTest &);
//    friend QDataStream &operator >>(QDataStream &,SubQuestionsTest &);

//public:
//    SubQuestionsTest();
//};

//question基类
//class Questions{
//public:
//    Questions();
//    ~Questions();
//    int getQuestionId() const;
//    void setQuestionId(int questionId);

//    int getSubjectId() const;
//    void setSubjectId(int subjectId);

//    int getQuestionType() const;
//    void setQuestionType(int questionType);

//    int getMark() const;
//    void setMark(int mark);

//    QString getQuestionTitle() const;
//    void setQuestionTitle(const QString &questionTitle);

//    QString getAnswer() const;
//    void setAnswer(const QString &getAnswer);

//private:
//    int _questionId;
//    int _subjectId;
//    int _questionType;
//    int _mark;
//    QString _questionTitle;
//    QString _answer;
//};

class ObjectQuestions{
public:
    ObjectQuestions();
    virtual void setQuestionId(int);
//    virtual void
//    virtual void
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


////答案基类
//class Answers{
//public:
//    Answers();
//    ~Answers();
//    void setanswerId(int id);
//    void setpaperId(int);
//    void setstudentId(int);
//    int getanswerId();
//    int getpaperId();
//    QString getstrudentId();

//private:
//    int AnswerId;
//    int PaperId;
//    QString StudentId;
//};

//class SubAnswers : public Answers{
//public:
//    void setsubAnswerslist(QVector<QString>);
//    QVector<QString>getsubAnswerslist();
//private:
//    QVector<QString> SubAnswerslist;
//};

//class ObAnswers : public Answers{
//public:
//    void setobAnswer(QString);
//    QString getobAnswer();
//private:
//    QString ObAnswer;
//};


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
    int getAnswerId();
    int getPaperId();
    QString getStudentId();
    QVector<QString> getAnswerList();
private:
    int _answerId;
    int _paperId;
    QString _studentId;
    QVector<QString> _answerList;

};

//问答题答案
class EssayAnswers   //作答的答案
{
    friend QDataStream &operator <<(QDataStream &,const EssayAnswers &);
    friend QDataStream &operator >>(QDataStream &,EssayAnswers &);
public:
    EssayAnswers();
    void setAnswerId(int);
    void setPaperId(int);
    void setStudentId(QString);
    void setAnswers(QString);
    int getAnswerId();
    int getPaperId();
    QString getStudentId();
    QString getAnswers();
private:
    int _answerId;
    int _paperId;
    QString _studentId;
    QString _answers;
};

//试卷。。。。坑爹的通过主观题id和客观题id来决定试卷内容。。。以后需要添加新的题型又需要修改。。。。
//可以使用vector存储题目id？QList可以存储题目父类指针。。。。方便以后修改。。。。
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
    int getSubject();
    int getPaperId();
    QString getObQuIds();
    QString getSubQuIds();
    QString getDescription();
    int     getTotalMark();
    int     getPercent();
    int     getTime();
    QString getDate();
    QList<ChoiceQuestions> choiceQuestionList;
    QList<EssayQuestions> essayQuestionbList;
private:
    int     _paperId;
    QString _obQuIds;
    QString _subQuIds;
    QString _description;
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
    //下面的东西又又做死了。。。。
    void setObanswer(EssayAnswers);
    void setSubanswer(ChoiceAnswers);

    /*
        void setAnswer(Answers *); //设置答案
    */
    void setPaperid(int);
    void setUserid(QString);

    //下面的东西又又写死了
    EssayAnswers getObanswer();
    ChoiceAnswers getSubanswer();

    /*
         Answers* getAnswer(); //获取答案
    */
    int getPaperid();
    QString getUserid();
private:
    //改进。。。。
    EssayAnswers _obAnswer;
    ChoiceAnswers _subAnswer;

     /*
         Answers * answer; //答案。。。
     */
    int _paperId;
    QString _userId;
};
Q_DECLARE_METATYPE(AllAnswers)


//有必要包括所有属性么？
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
