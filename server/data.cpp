#include"data.h"

Student::Student()
{
    qRegisterMetaTypeStreamOperators<Student>("User");
}
void Student::setID(QString id)
{
    _id=id;
}
void Student::setName(QString n)
{
    _name=n;
}
void Student::setGrade(int c)
{
    _grade=c;
}
void Student::setClass(int c)
{
    _class=c;
}
void Student::setPassword(QString c)
{
    _password=c;
}
void Student::setState(QString s)
{
    _state=s;
}
void Student::setHostname(QString host)
{
    _hostname=host;
}
void Student::setSockDescriptor(int descriptor)
{

    _socketDescriptor=descriptor;
}
QString Student::getID()
{
    return _id;
}
QString Student::getName()
{
    return _name;
}
int Student::getGrade()
{
    return _grade;
}
int Student::getClass()
{
    return _class;
}
QString Student::getPassword()
{
    return _password;
}
QString Student::getState()
{
    return _state;
}
QString Student::getHostname()
{
    return _hostname;
}
int Student::getSockDescriptor()
{
    return _socketDescriptor;
}
/*
int Student::getSocketDescriptor() const
{
    return _socketDescriptor;
}

void Student::setSocketDescriptor(int value)
{
    _socketDescriptor = value;
}
*/

QDataStream &operator >>(QDataStream &in,Student &user)
{
    in>>user._id>>user._name>>user._class>>user._grade>>user._password>>user._hostname;
    return in;
}
QDataStream &operator <<(QDataStream &out,const Student &user)
{
    out<<user._id<<user._name<<user._class<<user._grade<<user._password<<user._hostname;
    return out;
}

SubQuestions::SubQuestions()
{
    qRegisterMetaTypeStreamOperators<SubQuestions>("Sub_questions");
}
QDataStream &operator >>(QDataStream &in,SubQuestions &sub)
{
    in>>sub._subId>>sub._title>>sub._type;
    return in;
}
QDataStream &operator <<(QDataStream &out,const SubQuestions &sub)
{
    out<<sub._subId<<sub._title<<sub._type;
    return out;
}
void SubQuestions::setSubId(int id)
{
    _subId=id;
}
void SubQuestions::setType(QString t)
{
    _type=t;
}
void SubQuestions::setTitle(QString title)
{
    _title=title;
}
int SubQuestions::getsubId()
{
    return _subId;
}
QString SubQuestions::getType()
{
    return _type;
}
QString SubQuestions::getTitle()
{
    return _title;
}

SubAnswers::SubAnswers()
{
    qRegisterMetaTypeStreamOperators<SubAnswers>("Sub_answers");
}
void SubAnswers::setSuAnId(int id)
{
    _suAnId=id;
}
void SubAnswers::setPaperId(int id)
{
    _paperId=id;
}
void SubAnswers::setStudentId(QString id)
{
    _studentId=id;
}
void SubAnswers::setSubanslist(QVector<QString> ans)
{
    _subansList=ans;
}
int SubAnswers::getSuAnId()
{
    return _suAnId;
}
int SubAnswers::getPaperId()
{
    return _paperId;
}
QString SubAnswers::getStudentId()
{
    return _studentId;
}
QVector<QString> SubAnswers::getSubanslist()
{
    return _subansList;
}
QDataStream &operator >>(QDataStream &in,SubAnswers &sub)
{
    in>>sub._suAnId>>sub._paperId>>sub._studentId>>sub._subansList;

    return in;
}
QDataStream &operator <<(QDataStream &out,const SubAnswers &sub)
{
    out<<sub._suAnId<<sub._paperId<<sub._studentId<<sub._subansList;

    return out;
}

Paper::Paper()
{
    qRegisterMetaTypeStreamOperators<Paper>("Paper");

}
QDataStream &operator >>(QDataStream &in,Paper &p)
{
    in>>p._paperId>>p._description>>p._obQuIds>>p._subQuIds>>p.obList>>p.subList>>p._totalMark>>p._percent>>p._time;
    return in;
}
QDataStream &operator <<(QDataStream &out,const Paper &p)
{
    out<<p._paperId<<p._description<<p._obQuIds<<p._subQuIds<<p.obList<<p.subList<<p._totalMark<<p._percent<<p._time;
    return out;
}
int Paper::getPaperId()
{
    return _paperId;
}
QString Paper::getObQuIds()
{
    return _obQuIds;
}
QString Paper::getSubQuIds()
{
    return _subQuIds;
}
QString Paper::getDescription()
{
    return _description;
}
int Paper::getTotalMark()
{
    return _totalMark;
}
int Paper::getPercent()
{
    return _percent;
}
int Paper::getTime()
{
    return _time;
}
QString Paper::getDate()
{
    return _date;
}
void Paper::setPaper_id(int id )
{
    _paperId=id;
}
void Paper::setOb_qu_ids(QString id )
{
    _obQuIds=id;
}
void Paper::setSub_qu_ids(QString id )
{
    _subQuIds=id;
}
void Paper::setDescription(QString description )
{
    _description=description;
}
void Paper::setTotal_mark(int mark )
{
    _totalMark=mark;
}
void Paper::setPercent(int percent )
{
    _percent=percent;
}
void Paper::setTime(int t)
{
    _time=t;
}
void Paper::setDate(QString d)
{
    _date=d;
}

ObQuestions::ObQuestions()
{
    qRegisterMetaTypeStreamOperators<ObQuestions>("Ob_questions");
}
QDataStream &operator >>(QDataStream &in,ObQuestions &ob)
{
    in>>ob._obId>>ob._title>>ob._answer>>ob._type;
    return in;
}
QDataStream &operator <<(QDataStream &out,const ObQuestions &ob)
{
    out<<ob._obId<<ob._title<<ob._answer<<ob._type;
    return out;
}
int ObQuestions::getObId()
{
    return _obId;
}
QString ObQuestions::getType()
{
    return _type;
}
QString ObQuestions::getTitle()
{
    return _title;
}
QString ObQuestions::getAnswer()
{
    return _answer;
}
void ObQuestions::setObId(int id)
{
    _obId=id;
}
void ObQuestions::setType(QString t)
{
    _type=t;
}
void ObQuestions::setTitle(QString title)
{
    _title=title;
}
void ObQuestions::setAnswer(QString answer)
{
    _answer=answer;
}

ObAnswers::ObAnswers()
{
    qRegisterMetaTypeStreamOperators<ObAnswers>("Ob_answers");
}
int ObAnswers::getObAnId()
{
    return _obAnId;
}
int ObAnswers::getPaperId()
{
    return _paperId;
}
QString ObAnswers::getStudentId()
{
    return _studentId;
}
QString ObAnswers::getAnswers()
{
    return _answers;
}
void ObAnswers::setObAnId(int id)
{
    _obAnId=id;
}
void ObAnswers::setPaperId(int id)
{
    _paperId=id;
}
void ObAnswers::setStudent_id(QString id)
{
    _studentId=id;
}
void ObAnswers::setAnswers(QString answers)
{
    _answers=answers;
}
QDataStream &operator >>(QDataStream &in,ObAnswers &ob)
{
    in>>ob._obAnId>>ob._paperId>>ob._studentId>>ob._answers;
    return in;
}
QDataStream &operator <<(QDataStream &out,const ObAnswers &ob)
{
    out<<ob._obAnId<<ob._paperId<<ob._studentId<<ob._answers;
    return out;
}


AllAnswers::AllAnswers()
{
    qRegisterMetaTypeStreamOperators<AllAnswers>("All_answers");
}
void AllAnswers::setObanswer(ObAnswers ob)
{
    _obanswer=ob;
}
void AllAnswers::setSubanswer(SubAnswers sub)
{
    _subanswer=sub;
}
void AllAnswers::setPaperid(int id)
{
    _paperid=id;
}
void AllAnswers::setUserid(QString id)
{
    _userid=id;
}
ObAnswers AllAnswers::getObanswer()
{
    return _obanswer;
}
SubAnswers AllAnswers::getSubanswer()
{
    return _subanswer;
}
int AllAnswers::getPaperid()
{
    return _paperid;
}
QString AllAnswers::getUserid()
{
    return _userid;
}
QDataStream &operator >>(QDataStream &in,AllAnswers &all)
{
    in>>all._paperid>>all._userid>>all._obanswer>>all._subanswer;
    return in;
}
QDataStream &operator <<(QDataStream &out,const AllAnswers &all)
{
    out<<all._paperid<<all._userid<<all._obanswer<<all._subanswer;
    return out;
}

Combo::Combo()
{
    qRegisterMetaTypeStreamOperators<Combo>("Combo");
}

void Combo::setUserId(QString a)
{
    _userId = a;
}
void Combo::setName(QString s)
{
    _name = s;
}
void Combo::setGrade(int a)
{
    _grade = a;
}
void Combo::setClass(int b)
{
    _class = b;
}
void Combo::setTime(int t)
{
    _time = t;
}
void Combo::setPaperId(int d)
{
    _paperId = d;
}
void Combo::setPaperMark(int m)
{
    _paperMark = m;
}
void Combo::setObmark(int m)
{
    _obmark=m;
}
void Combo::setSubmark(int m)
{
    _submark=m;
}
void Combo::setPaperName(QString n)
{
    _paperName=n;
}

QString Combo::getUserId()
{
    return _userId;
}
QString Combo::getName()
{
    return _name;
}
int Combo::getGrade()
{
    return _grade;
}
int Combo::getClass()
{
    return _class;
}
int Combo::getTime()
{
    return _time;
}
int Combo::getPaperId()
{
    return _paperId;
}
int Combo::getPaperMark()
{
    return _paperMark;
}
int Combo::getObmark()
{
    return _obmark;
}
int Combo::getSubMark()
{
    return _submark;
}
QString Combo::getPaperName()
{
    return _paperName;
}
QDataStream &operator >>(QDataStream &in,Combo &c)
{
    in>>c._paperName>>c._obmark>>c._submark>>c._paperMark;
    return in;
}
QDataStream &operator <<(QDataStream &out,const Combo &c)
{
    out<<c._paperName<<c._obmark<<c._submark<<c._paperMark;
    return out;
}

/*
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

void Answers::setstudentId(int id)
{
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
*/

USER::USER()
{

}

void USER::setId(int id)
{
    _id = id;
}

void USER::setName(QString name)
{
    _name = name;
}

void USER::setPassword(QString password)
{
    _password = password;
}

void USER::setType(int type)
{
    _type = type;
}

int USER::getType()
{
    return _type;
}

int USER::getId()
{
    return _id;
}

QString USER::getName()
{
    return _name;
}

QString USER::getPassword()
{
    return _password;
}

USER &USER::GetInstance()
{
    static USER user;
    return user;
}
