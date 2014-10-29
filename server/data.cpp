#include"data.h"

Student::Student()
{
     qRegisterMetaTypeStreamOperators<Student>("User");
}
void Student::setID(QString id)
{
    ID=id;
}
void Student::setName(QString n)
{
    Name=n;
}
void Student::setGrade(int c)
{
    Grade=c;
}
void Student::setClass(int c)
{
    Class=c;
}
void Student::setPassword(QString c)
{
    Password=c;
}
void Student::setState(QString s)
{
    state=s;
}
void Student::setHostname(QString host)
{
    hostname=host;
}
void Student::setSockDescriptor(int descriptor)
{

    socketDescriptor=descriptor;
}
QString Student::getID()
{
    return ID;
}
QString Student::getName()
{
    return Name;
}
int Student::getGrade()
{
    return Grade;
}
int Student::getClass()
{
    return Class;
}
QString Student::getPassword()
{
    return Password;
}
QString Student::getState()
{
    return state;
}
QString Student::getHostname()
{
    return hostname;
}
int Student::getSockDescriptor()
{
    return socketDescriptor;
}
QDataStream &operator >>(QDataStream &in,Student &user)
{
    in>>user.ID>>user.Name>>user.Class>>user.Grade>>user.Password>>user.hostname;
    return in;
}
QDataStream &operator <<(QDataStream &out,const Student &user)
{
    out<<user.ID<<user.Name<<user.Class<<user.Grade<<user.Password<<user.hostname;
    return out;
}

Manager::Manager()
{

}
void Manager::setId(int i)
{
    Id = i;
}
void Manager::setName(QString n)
{
    Name = n;
}
void Manager::setPassword(QString p)
{
    Password = p;
}
int Manager::getId()
{
    return Id;
}
QString Manager::getName()
{
    return Name;
}
QString Manager::getPassword()
{
    return Password;
}

Manager &Manager::GetInstance()
{
    static Manager manager;
    return manager;
}

Sub_questions::Sub_questions()
{
    qRegisterMetaTypeStreamOperators<Sub_questions>("Sub_questions");
}
QDataStream &operator >>(QDataStream &in,Sub_questions &sub)
{
    in>>sub.Sub_id>>sub.Title>>sub.Type;
    return in;
}
QDataStream &operator <<(QDataStream &out,const Sub_questions &sub)
{
    out<<sub.Sub_id<<sub.Title<<sub.Type;
    return out;
}
void Sub_questions::setSub_id(int id)
{
    Sub_id=id;
}
void Sub_questions::setType(QString t)
{
    Type=t;
}
void Sub_questions::setTitle(QString title)
{
    Title=title;
}
int Sub_questions::getSub_id()
{
    return Sub_id;
}
QString Sub_questions::getType()
{
    return Type;
}
QString Sub_questions::getTitle()
{
    return Title;
}

Sub_answers::Sub_answers()
{
    qRegisterMetaTypeStreamOperators<Sub_answers>("Sub_answers");
}
void Sub_answers::setSu_an_id(int id)
{
    Su_an_id=id;
}
void Sub_answers::setPaper_id(int id)
{
    Paper_id=id;
}
void Sub_answers::setStudent_id(QString id)
{
    Student_id=id;
}
void Sub_answers::setSubanslist(QVector<QString> ans)
{
    subanslist=ans;
}
int Sub_answers::getSu_an_id()
{
    return Su_an_id;
}
int Sub_answers::getPaper_id()
{
    return Paper_id;
}
QString Sub_answers::getStudent_id()
{
    return Student_id;
}
QVector<QString> Sub_answers::getSubanslist()
{
    return subanslist;
}
QDataStream &operator >>(QDataStream &in,Sub_answers &sub)
{
    in>>sub.Su_an_id>>sub.Paper_id>>sub.Student_id>>sub.subanslist;

    return in;
}
QDataStream &operator <<(QDataStream &out,const Sub_answers &sub)
{
    out<<sub.Su_an_id<<sub.Paper_id<<sub.Student_id<<sub.subanslist;

    return out;
}

Paper::Paper()
{
    qRegisterMetaTypeStreamOperators<Paper>("Paper");

}
QDataStream &operator >>(QDataStream &in,Paper &p)
{
    in>>p.Paper_id>>p.Description>>p.Ob_qu_ids>>p.Sub_qu_ids>>p.obList>>p.subList>>p.Total_mark>>p.Percent>>p.time;
    return in;
}
QDataStream &operator <<(QDataStream &out,const Paper &p)
{
    out<<p.Paper_id<<p.Description<<p.Ob_qu_ids<<p.Sub_qu_ids<<p.obList<<p.subList<<p.Total_mark<<p.Percent<<p.time;
    return out;
}
int Paper::getPaper_id()
{
 return Paper_id;
}
QString Paper::getOb_qu_ids()
{
 return Ob_qu_ids;
}
QString Paper::getSub_qu_ids()
{
 return Sub_qu_ids;
}
QString Paper::getDescription()
{
 return Description;
}
int Paper::getTotal_mark()
{
 return Total_mark;
}
int Paper::getPercent()
{
 return Percent;
}
int Paper::getTime()
{
    return time;
}
QString Paper::getDate()
{
    return date;
}
void Paper::setPaper_id(int id )
{
   Paper_id=id;
}
void Paper::setOb_qu_ids(QString id )
{
   Ob_qu_ids=id;
}
void Paper::setSub_qu_ids(QString id )
{
   Sub_qu_ids=id;
}
void Paper::setDescription(QString description )
{
   Description=description;
}
void Paper::setTotal_mark(int mark )
{
   Total_mark=mark;
}
void Paper::setPercent(int percent )
{
   Percent=percent;
}
void Paper::setTime(int t)
{
    time=t;
}
void Paper::setDate(QString d)
{
    date=d;
}

Ob_questions::Ob_questions()
{
    qRegisterMetaTypeStreamOperators<Ob_questions>("Ob_questions");
}
QDataStream &operator >>(QDataStream &in,Ob_questions &ob)
{
    in>>ob.Ob_id>>ob.Title>>ob.Answer>>ob.Type;
    return in;
}
QDataStream &operator <<(QDataStream &out,const Ob_questions &ob)
{
    out<<ob.Ob_id<<ob.Title<<ob.Answer<<ob.Type;
    return out;
}
int Ob_questions::getOb_id()
{
 return Ob_id;
}
QString Ob_questions::getType()
{
 return Type;
}
QString Ob_questions::getTitle()
{
 return Title;
}
QString Ob_questions::getAnswer()
{
 return Answer;
}
void Ob_questions::setOb_id(int id)
{
 Ob_id=id;
}
void Ob_questions::setType(QString t)
{
    Type=t;
}
void Ob_questions::setTitle(QString title)
{
 Title=title;
}
void Ob_questions::setAnswer(QString answer)
{
 Answer=answer;
}

Ob_answers::Ob_answers()
{
    qRegisterMetaTypeStreamOperators<Ob_answers>("Ob_answers");
}
int Ob_answers::getOb_an_id()
{
 return Ob_an_id;
}
int Ob_answers::getPaper_id()
{
 return Paper_id;
}
QString Ob_answers::getStudent_id()
{
 return Student_id;
}
QString Ob_answers::getAnswers()
{
 return Answers;
}
void Ob_answers::setOb_an_id(int id)
{
 Ob_an_id=id;
}
void Ob_answers::setPaper_id(int id)
{
 Paper_id=id;
}
void Ob_answers::setStudent_id(QString id)
{
 Student_id=id;
}
void Ob_answers::setAnswers(QString answers)
{
 Answers=answers;
}
QDataStream &operator >>(QDataStream &in,Ob_answers &ob)
{
    in>>ob.Ob_an_id>>ob.Paper_id>>ob.Student_id>>ob.Answers;
    return in;
}
QDataStream &operator <<(QDataStream &out,const Ob_answers &ob)
{
    out<<ob.Ob_an_id<<ob.Paper_id<<ob.Student_id<<ob.Answers;
    return out;
}


All_answers::All_answers()
{
    qRegisterMetaTypeStreamOperators<All_answers>("All_answers");
}
void All_answers::setObanswer(Ob_answers ob)
{
    obanswer=ob;
}
void All_answers::setSubanswer(Sub_answers sub)
{
    subanswer=sub;
}
void All_answers::setPaperid(int id)
{
    paperid=id;
}
void All_answers::setUserid(QString id)
{
    userid=id;
}
Ob_answers All_answers::getObanswer()
{
    return obanswer;
}
Sub_answers All_answers::getSubanswer()
{
    return subanswer;
}
int All_answers::getPaperid()
{
    return paperid;
}
QString All_answers::getUserid()
{
    return userid;
}
QDataStream &operator >>(QDataStream &in,All_answers &all)
{
    in>>all.paperid>>all.userid>>all.obanswer>>all.subanswer;
    return in;
}
QDataStream &operator <<(QDataStream &out,const All_answers &all)
{
    out<<all.paperid<<all.userid<<all.obanswer<<all.subanswer;
    return out;
}

Combo::Combo()
{
    qRegisterMetaTypeStreamOperators<Combo>("Combo");
}

void Combo::setUser_id(QString a)
{
    User_id = a;
}
void Combo::setName(QString s)
{
    Name = s;
}
void Combo::setGrade(int a)
{
    Grade = a;
}
void Combo::setClass(int b)
{
    Class = b;
}
void Combo::setTime(int t)
{
    Time = t;
}
void Combo::setPaper_id(int d)
{
    Paper_id = d;
}
void Combo::setPaper_mark(int m)
{
    Paper_mark = m;
}
void Combo::setObmark(int m)
{
    obmark=m;
}
void Combo::setSubmark(int m)
{
    submark=m;
}
void Combo::setPaperName(QString n)
{
    paperName=n;
}

QString Combo::getUser_id()
{
    return User_id;
}
QString Combo::getName()
{
    return Name;
}
int Combo::getGrade()
{
    return Grade;
}
int Combo::getClass()
{
    return Class;
}
int Combo::getTime()
{
    return Time;
}
int Combo::getPaper_id()
{
    return Paper_id;
}
int Combo::getPaper_mark()
{
    return Paper_mark;
}
int Combo::getObmark()
{
    return obmark;
}
int Combo::getSubMark()
{
    return submark;
}
QString Combo::getPaperName()
{
    return paperName;
}
QDataStream &operator >>(QDataStream &in,Combo &c)
{
    in>>c.paperName>>c.obmark>>c.submark>>c.Paper_mark;
    return in;
}
QDataStream &operator <<(QDataStream &out,const Combo &c)
{
    out<<c.paperName<<c.obmark<<c.submark<<c.Paper_mark;
    return out;
}


Answers::Answers()
{

}

Answers::~Answers()
{

}

void Answers::setanswerId(int id)
{
    AnswerId = id;
}

void Answers::setpaperId(int id)
{
    PaperId = id;
}

int Answers::getanswerId()
{
    return AnswerId;
}

int Answers::getpaperId()
{
    return PaperId;
}

QString Answers::getstrudentId()
{
    return StudentId;
}

void Answers::setstudentId(int id){
    AnswerId = id;
}

void SubAnswers::setsubAnswerslist(QVector<QString> answerList)
{
    SubAnswerslist = answerList;
}

QVector<QString> SubAnswers::getsubAnswerslist()
{
    return SubAnswerslist;
}

void ObAnswers::setobAnswer(QString answer)
{
    ObAnswer = answer;
}

QString ObAnswers::getobAnswer()
{
    return ObAnswer;
}

//USER function
USER::USER()
{

}

void USER::setId(int id)
{
    Id = id;
}

void USER::setName(QString name)
{
    Name = name;
}

void USER::setPassword(QString password)
{
    Password = password;
}

int USER::getId()
{
    return Id;
}

QString USER::getName()
{
    return Name;
}

QString USER::getPassword()
{
    return Password;
}

USER &USER::GetInstance()
{
    static USER user;
    return user;
}
