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

/*
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
*/


SubQuestions::SubQuestions()
{
    qRegisterMetaTypeStreamOperators<SubQuestions>("Sub_questions");
}
QDataStream &operator >>(QDataStream &in,SubQuestions &sub)
{
    in>>sub._questionId>>sub._questionTitle>>sub._questionType;
    return in;
}
QDataStream &operator <<(QDataStream &out,const SubQuestions &sub)
{
    out<<sub._questionId<<sub._questionTitle<<sub._questionType;
    return out;
}
void SubQuestions::setQuestionId(int id)
{
    _questionId=id;
}
void SubQuestions::setQuestionType(QString t)
{
    _questionType=t;
}
void SubQuestions::setQuestionTitle(QString title)
{
    _questionTitle=title;
}
int SubQuestions::getQuestionId()
{
    return _questionId;
}
QString SubQuestions::getQuestionType()
{
    return _questionType;
}
QString SubQuestions::getQuestionTitle()
{
    return _questionTitle;
}

SubAnswers::SubAnswers()
{
    qRegisterMetaTypeStreamOperators<SubAnswers>("SubAnswers");
}
void SubAnswers::setAnswerId(int id)
{
    _answerId=id;
}
void SubAnswers::setPaperId(int id)
{
    _paperId=id;
}
void SubAnswers::setStudentId(QString id)
{
    _studentId=id;
}
void SubAnswers::setAnswerList(QVector<QString> ans)
{
    _answerList=ans;
}
int SubAnswers::getAnswerId()
{
    return _answerId;
}
int SubAnswers::getPaperId()
{
    return _paperId;
}
QString SubAnswers::getStudentId()
{
    return _studentId;
}
QVector<QString> SubAnswers::getAnswerList()
{
    return _answerList;
}
QDataStream &operator >>(QDataStream &in,SubAnswers &sub)
{
    in>>sub._answerId>>sub._paperId>>sub._studentId>>sub._answerList;

    return in;
}
QDataStream &operator <<(QDataStream &out,const SubAnswers &sub)
{
    out<<sub._answerId<<sub._paperId<<sub._studentId<<sub._answerList;

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
void Paper::setPaperId(int id )
{
    _paperId=id;
}
void Paper::setObQuIds(QString id )
{
    _obQuIds=id;
}
void Paper::setSubQuIds(QString id )
{
    _subQuIds=id;
}
void Paper::setDescription(QString description )
{
    _description=description;
}
void Paper::setTotalMark(int mark )
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
    in>>ob._questionId>>ob._questionTitle>>ob._answer>>ob._questionType;
    return in;
}
QDataStream &operator <<(QDataStream &out,const ObQuestions &ob)
{
    out<<ob._questionId<<ob._questionTitle<<ob._answer<<ob._questionType;
    return out;
}
int ObQuestions::getQuestionId()
{
    return _questionId;
}
QString ObQuestions::getQuestionType()
{
    return _questionType;
}
QString ObQuestions::getQuestionTitle()
{
    return _questionTitle;
}
QString ObQuestions::getAnswer()
{
    return _answer;
}
void ObQuestions::setQuestionId(int id)
{
    _questionId=id;
}
void ObQuestions::setQuestionType(QString t)
{
    _questionType=t;
}
void ObQuestions::setQuestionTitle(QString title)
{
    _questionTitle=title;
}
void ObQuestions::setQuestionAnswer(QString answer)
{
    _answer=answer;
}

ObAnswers::ObAnswers()
{
    qRegisterMetaTypeStreamOperators<ObAnswers>("ObAnswers");
}
int ObAnswers::getAnswerId()
{
    return _answerd;
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
void ObAnswers::setAnswerId(int id)
{
    _answerd=id;
}
void ObAnswers::setPaperId(int id)
{
    _paperId=id;
}
void ObAnswers::setStudentId(QString id)
{
    _studentId=id;
}
void ObAnswers::setAnswers(QString answers)
{
    _answers=answers;
}
QDataStream &operator >>(QDataStream &in,ObAnswers &ob)
{
    in>>ob._answerd>>ob._paperId>>ob._studentId>>ob._answers;
    return in;
}
QDataStream &operator <<(QDataStream &out,const ObAnswers &ob)
{
    out<<ob._answerd<<ob._paperId<<ob._studentId<<ob._answers;
    return out;
}


AllAnswers::AllAnswers()
{
    qRegisterMetaTypeStreamOperators<AllAnswers>("AllAnswers");
}
void AllAnswers::setObAnswer(ObAnswers ob)
{
    _obAnswer=ob;
}
void AllAnswers::setSubAnswer(SubAnswers sub)
{
    _subAnswer=sub;
}
void AllAnswers::setPaperId(int id)
{
    _paperId=id;
    _obAnswer.setPaperId(id);
    _subAnswer.setPaperId(id);
}
void AllAnswers::setUserId(QString id)
{
    _userId=id;
    _obAnswer.setStudentId(id);
    _subAnswer.setStudentId(id);

}
ObAnswers AllAnswers::getObAnswer()
{
    return _obAnswer;
}
SubAnswers AllAnswers::getSubAnswer()
{
    return _subAnswer;
}
int AllAnswers::getPaperId()
{
    return _paperId;
}
QString AllAnswers::getUserId()
{
    return _userId;
}
QDataStream &operator >>(QDataStream &in,AllAnswers &all)
{
    in>>all._paperId>>all._userId>>all._obAnswer>>all._subAnswer;
    return in;
}
QDataStream &operator <<(QDataStream &out,const AllAnswers &all)
{
    out<<all._paperId<<all._userId<<all._obAnswer<<all._subAnswer;
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
