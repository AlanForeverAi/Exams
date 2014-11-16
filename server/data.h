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
    int _socketDescriptor; //socket文件描述符

};
Q_DECLARE_METATYPE(Student)

//管理员。。。通过用户ID判断是否管理员。。。。
class USER{
public:
    USER();
    void setId(int);
    void setName(QString);
    void setPassword(QString);
    void setType(int);
    int getType();
    int getId();
    QString getName();
    QString getPassword();
    static USER& GetInstance();
private:
    int _id;
    QString _name;
    QString _password;
    int _type; //根据Type判断用户为管理员还是老师（还要判断老师类型）
};

/*
 * 参考设计模式，修改？设置问题基类，方便以后添加新的题型。。。。。但是如何解决判断题目的类型。。。设计模式。。。
  */
/*
//问题基类。。。。
class Questions{
public:
    Questions();
    void setId(int);
    void setType(QString);
    void setTitle(QString);
    void setAnswer(QString);
    int getId();
    QString getType();
    QString getTitle();
    QString getAnswer();
private:
    int _id;
    QString _subject; //科目

    int _type;  //结合老师的类型（科目）来判断题目类型（科目）。。。

    QString _title;
    QString _answer;
};

class ObQuestions : public Questions {
  // 暂时还没考虑具体子类的结构。。。。
};

class SubQuestions : public Questions {
  // 暂时还没考虑具体子类的结构。。。。
};
*/


//客观题
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

//主观题，添加参考答案？
class SubQuestions
{
    friend QDataStream &operator <<(QDataStream &,const SubQuestions &);
    friend QDataStream &operator >>(QDataStream &,SubQuestions &);
public:
    SubQuestions();
    void setSubId(int);
    void setType(QString);
    void setTitle(QString);
    int getsubId();
    QString getType();
    QString getTitle();
private:
    int _subId;
    QString _type;
    QString _title;
};

/*
//答案基类
class Answers{
public:
    Answers();
    ~Answers();
    void setanswerId(int id);
    void setpaperId(int);
    void setstudentId(int);
    int getanswerId();
    int getpaperId();
    QString getstrudentId();

private:
    int AnswerId;
    int PaperId;
    QString StudentId;
};

class SubAnswers : public Answers{
public:
    void setsubAnswerslist(QVector<QString>);
    QVector<QString>getsubAnswerslist();
private:
    QVector<QString> SubAnswerslist;
};

class ObAnswers : public Answers{
public:
    void setobAnswer(QString);
    QString getobAnswer();
private:
    QString ObAnswer;
};
*/

//主观题答案。。。。
class SubAnswers
{
    friend QDataStream &operator <<(QDataStream &,const SubAnswers &);
    friend QDataStream &operator >>(QDataStream &,SubAnswers &);
public:
    SubAnswers();
    void setSuAnId(int);
    void setPaperId(int);
    void setStudentId(QString);
    void setSubanslist(QVector<QString>);
    int getSuAnId();
    int getPaperId();
    QString getStudentId();
    QVector<QString> getSubanslist();
private:
    int _suAnId;
    int _paperId;
    QString _studentId;
    QVector<QString> _subansList;

};

//客观题答案
class ObAnswers   //作答的答案
{
    friend QDataStream &operator <<(QDataStream &,const ObAnswers &);
    friend QDataStream &operator >>(QDataStream &,ObAnswers &);
public:
    ObAnswers();
    void setObAnId(int);
    void setPaperId(int);
    void setStudent_id(QString);
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
    int getPaperId();
    QString getObQuIds();
    QString getSubQuIds();
    QString getDescription();
    int     getTotalMark();
    int     getPercent();
    int     getTime();
    QString getDate();
    //一下两个list看着好不顺眼。。。。
    QList<ObQuestions> obList;
    QList<SubQuestions> subList;

    /*
     QList<Questions *> questionList; //试卷的题目列表。。。。
    */
private:
    int _paperId;
    QString _obQuIds;
    QString _subQuIds;

    /*
      QString questionsID;
     */
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
    //下面的东西又又做死了。。。。
    void setObanswer(ObAnswers);
    void setSubanswer(SubAnswers);

    /*
        void setAnswer(Answers *); //设置答案
    */
    void setPaperid(int);
    void setUserid(QString);

    //下面的东西又又写死了
    ObAnswers getObanswer();
    SubAnswers getSubanswer();

    /*
         Answers* getAnswer(); //获取答案
    */
    int getPaperid();
    QString getUserid();
private:
    //改进。。。。
    ObAnswers _obanswer;
    SubAnswers _subanswer;

     /*
         Answers * answer; //答案。。。
     */
    int _paperid;
    QString _userid;
};
Q_DECLARE_METATYPE(AllAnswers)


//有必要包括所有属性么？
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
