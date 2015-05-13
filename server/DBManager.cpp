#include "dbmanager.h"
#include <QMessageBox>
DBManager::DBManager()
{

}

DBManager::~DBManager()
{

}

void DBManager::setConfig(QString name, QString user, QString password)
{
     _db = QSqlDatabase::addDatabase("QMYSQL");
     _db.setHostName("localhost");
     _db.setDatabaseName(name);
     _db.setUserName(user);
     _db.setPassword(password);

     if(!_db.open()){
         QMessageBox msg;
         msg.setText(QStringLiteral("连接数据库失败！"));
         msg.exec();
     }
}

QSqlQuery DBManager::selectType()
{
    QSqlQuery query;
    if(query.exec("select * from serveridtype"))
        return query;
    else
    {
        qDebug() << "selectType] " << query.lastError();
    }
}

QSqlQuery DBManager::selectSubject()
{
    QSqlQuery query;
    QString s = "select * from serveridtype where type not in (select type from serveridtype where type = '%1')";
    if(query.exec(s.arg(QStringLiteral("管理员"))))
        return query;
    else
    {
        qDebug() << "selectSubject] " << query.lastError();
    }
}

QSqlQuery DBManager::selectUserTypeBySubject(QString subject)
{
    QSqlQuery query;
    QString s = "select id from serveridtype where type = '%1'";
    if(query.exec(s.arg(subject))){
        return query;
    }
    else{
        qDebug() << "selectUserTypeBySubject] " << query.lastError();
    }
}

void DBManager::insertType(int id, QString type)
{
    QSqlQuery query;
    query.prepare("insert into serveridtype (id, type) values (?, ?)");
    query.addBindValue(id);
    query.addBindValue(type);
    query.exec();
    qDebug() << "insertType] " << query.lastError();
}

void DBManager::deleteType(int id)
{
    QSqlQuery query;
    query.prepare("delete from serveridtype where id = ?");
    query.addBindValue(id);
    query.exec();
    qDebug() << "deleteType] " << query.lastError();
}

void DBManager::updateType(int id, QString type)
{
    QSqlQuery query;
    QString s = "update serveridtype set type = '%1' where id = %2";
    query.exec(s.arg(type).arg(id));

    qDebug() << "updateType] " << query.lastError();
}

QSqlQuery DBManager::selectStudent()
{
    QSqlQuery query;
    if( query.exec("select * from student"))
        return query;
    else
    {
        qDebug() << "selectStudent] " << query.lastError();
    }
}

QSqlQuery DBManager::selectStudentByID(QString a)
{
    QSqlQuery query;
    query.prepare("select * from student where userid  =  (?)");
    query.addBindValue(a);
    query.exec();
    qDebug() << "selectStudentById] " << query.lastError();
    return query;
}

QSqlQuery DBManager::selectStudentByGC(int a, int b)
{
    QSqlQuery query;
    query.prepare("select * from student where grade  =  (?) AND class =  (?)");
    query.addBindValue(a);
    query.addBindValue(b);
    query.exec();

    qDebug() << "selectStudentByGC]" << query.lastError();
    return query;
}

void DBManager::insertStudent(QString a, QString b, int c, int d, QString e)
{
    QSqlQuery query;

    query.prepare("insert into student (userid, name, grade, class,password) "
                  "values (?,?,?,?,?)");
    query.addBindValue(a);
    query.addBindValue(b);
    query.addBindValue(c);
    query.addBindValue(d);
    query.addBindValue(e);
    query.exec();
    qDebug() << "insetStudent] " << query.lastError();
}

void DBManager::updateStudent(QString id, QString name, int grade, int clas, QString passowrd)
{
    QSqlQuery query;
    QString s = "update student set name = '%1', grade = %2, class = %3, password = '%4' where userid = '%5'";

    query.exec(s.arg(name).arg(grade).arg(clas).arg(passowrd).arg(id));

    qDebug() << "updateStudent] " << query.lastError();
}

void DBManager::updateServerUser(QString id, QString name, QString password, int type)
{
    QSqlQuery query;
    QString s = "update serveruser set name = '%1', password = '%2', type = %3 where userid = '%4'";

    query.exec(s.arg(name).arg(password).arg(type).arg(id));

    qDebug() << "updateTeacher] " << query.lastError();
}

void DBManager::deleteStudentById(QString a)
{
    QSqlQuery query;
    query.prepare("delete from student where userid  =  (?)");
    query.addBindValue(a);
    if(!query.isValid())

        query.exec();
}

void DBManager::deleteStudentByName(QString a)
{
    QSqlQuery query;
    query.prepare("delete from student where name  =  (?)");
    query.addBindValue(a);
    if(!query.isValid())
        query.exec();
}

QSqlQuery DBManager::selectManager(){
    QSqlQuery query;
    if(query.exec("select userid, name, password from serveruser where serveruser.type = 1")){
        return query;
    }
    else{
        qDebug() << "selectManager] " << query.lastError();
        return query;
    }
}


QSqlQuery DBManager::selectUser()
{
    QSqlQuery query;
    QString s = "select userid, name, password, serveridtype.type "
                "from serveruser, serveridtype "
                "where serveruser.type = serveridtype.id and"
                " serveruser.type not in (select id from serveridtype where type = '%1');";
    if( query.exec(s.arg(QStringLiteral("管理员")))){
        return query;
    }
    else
        qDebug() << "selectServerUser] " << query.lastError();
}

void DBManager::insertServerUser(QString a,QString b,QString c, int d)
{
    QSqlQuery query;
    query.prepare("insert into serveruser (userid,name,password,type) "
                  "values (:userid, :name, :password, :type)");
    query.bindValue(":userid", a);
    query.bindValue(":name", b);
    query.bindValue(":password",c);
    query.bindValue(":type",d);
    query.exec();
    qDebug() << query.lastError();
}


void DBManager::deleteServerUserByID(int a)
{
    QSqlQuery query;
    query.prepare("delete from serveruser where userid  =  (?)");
    query.addBindValue(a);
    if(!query.isValid())
        query.exec();
}

void DBManager::deleteServerUserByName(QString a)
{
    QSqlQuery query;
    query.prepare("delete from serveruser where name  =  (?)");
    query.addBindValue(a);
    if(!query.isValid())
        query.exec();
}

//插入客观题到数据库
void DBManager::insertOb(QString title, QString answer, int type)
{
    QSqlQuery query;
    QString s = "insert into obquestions (title, answer, type) values ('%1', '%2', %3)";
    query.exec(s.arg(title).arg(answer).arg(type));
    qDebug() << "insertOb] " << query.lastError();
}

//插入主观题到数据库
void DBManager::insertSub(QString title, QString type)
{
    QSqlQuery query;
    QString s = "insert into subquestions (title, type) values ('%1', %2)";
    query.exec(s.arg(title).arg(type));
    qDebug() << "insertSub]" << query.lastError();
}

//查询客观题表的所有数据
QSqlQuery DBManager::selectObQuestions()
{
    QSqlQuery query;
    int type = User::GetInstance().getType();
    if( query.exec(QString("select * from obquestions where type = %1").arg(type)))
        return query;
    else
        return query;
}

//查询主观题表的所有数据
QSqlQuery DBManager::selectSubQuestions()
{
    QSqlQuery query;
    int type = User::GetInstance().getType();
    if( query.exec(QString("select * from subquestions where type = %1").arg(type)))
        return query;
    else
        return query;
}

QSqlQuery DBManager::selectAllObQuestions()
{
    QSqlQuery query;
    if( query.exec(QString("select * from obquestions")))
        return query;
    else
        return query;
}

QSqlQuery DBManager::selectAllSubQuestions()
{
    QSqlQuery query;
    if( query.exec(QString("select * from subquestions")))
        return query;
    else
        return query;
}


//按ID找到记录把在问题表和答案表内的该记录一并删除（客观题）
void DBManager::deleteObQuestionsByID(int id)
{

    QSqlQuery query;
    query.exec(QStringLiteral("delete from obquestions where obid  =  %1").arg(id));
    query.exec();
    qDebug() << "selectSubQuestions] " << query.lastError();

}

//按ID找到记录把在问题表和答案表内的该记录一并删除（主观题）
void DBManager::deleteSubQuestionsByID(int id)
{
    QSqlQuery query;
    query.exec(QStringLiteral("delete from subquestions where subid  =  %1").arg(id));
    query.exec();
    qDebug() << "deleteSubQuestions] " << query.lastError();
}

void DBManager::updateChoiceQuestions(int id, QString title, QString answer)
{
    QSqlQuery query;
    QString s = "update obquestions set title= '%1',answer= '%2' where obid= %3";
    query.exec(s.arg(title).arg(answer).arg(id));
    qDebug() << "alterObQuestions] " << query.lastError();
}

void DBManager::updateEssayQuestions(int id, QString title)
{
    QSqlQuery query;
    QString s = "update subquestions set title= '%1' where subid= %2";
    query.exec(s.arg(title).arg(id));
    qDebug() << "alterSubQuestions] " << query.lastError();
}

void DBManager::insertPaper( QString obids, QString subids, int total, int percent, QString description,int time)
{
    QSqlQuery query;
    query.prepare("insert into paper (obquids,subquids,totalmark,percent,description,time,subject) " "values (?,?,?,?,?,?,?)");
    query.addBindValue(obids);
    query.addBindValue(subids);
    query.addBindValue(total);
    query.addBindValue(percent);
    query.addBindValue(description);
    query.addBindValue(time);
    query.addBindValue(User::GetInstance().getType());
    query.exec();
    qDebug() << "insertPaper] " << query.lastError();
}

void DBManager::insertPaper(QString obids, QString subids, int totalmark, int percent, QString description, int time, int subject, QString obmarks, QString submarks)
{
    QSqlQuery query;
    QString s = "insert into paper (obquids, subquids, totalmark, percent, description, time, subject, obmarks, submarks)"
            "values('%1', '%2', %3, %4, '%5', %6, %7, '%8', '%9')";
    query.exec(s.arg(obids).arg(subids).arg(totalmark).arg(percent).arg(description).arg(time).arg(subject).arg(obmarks).arg(submarks));
    qDebug() << "insertPaper] " << query.lastError();
}

QSqlQuery DBManager::selectPaperById(int id)
{
    QSqlQuery query;
    QString s = "select * from paper where paperid = %1";
    if( query.exec(s.arg(id)))
    {
//        qDebug() << "selectPaperById] " << query.lastError();
        return query;

    }
    else
    {
        qDebug() << "selectPaperById] " << query.lastError();
        return query;
    }
}

QSqlQuery DBManager::selectPaper()
{
    QSqlQuery query;
    int subject = User::GetInstance().getType();
    if( query.exec(QString("select * from paper where subject = %1").arg(subject)))
        return query;
    else
        return query;
}

QSqlQuery DBManager::selectAllPaper()
{
    QSqlQuery query;
    if(query.exec(QString("select * from paper")))
        return query;
    else
        return query;
}

//删除试卷的时候需要不存放该试卷id的数据先删除，否则会因为外键的原因导致删除失败。该函数需要进一步优化，尽量简洁。。。。。
void DBManager::deletePaperById(int id)
{
    QSqlQuery query;
    query.exec(QStringLiteral("delete from subanswers where fpaperid = %1").arg(id));
    qDebug() << "deletePaperById] " << query.lastError();
    query.exec(QStringLiteral("delete from obanswers where fpaperid = %1").arg(id));
    qDebug() << "deletePaperById] " << query.lastError();
    query.exec(QStringLiteral("delete from papermark where fpaperid = %1").arg(id));
    qDebug() << "deletePaperById] " << query.lastError();
    query.exec(QStringLiteral("delete from paper where paperid = %1").arg(id));
    qDebug() << "deletePaperById] " << query.lastError();
}

void DBManager::alterPaper(int id,QString obids, QString subids, int total, int percent, QString description,int time)
{
    QSqlQuery query;
    QString s = "update paper set obquids= '%1',subquids= '%2',totalmark= %3,percent= %4,description= '%5',time= '%6' where paperid= %7";
    query.exec(s.arg(obids).arg(subids).arg(total).arg(percent).arg(description).arg(time).arg(id));
    qDebug() << "alterPaper] " << query.lastError();
}

void DBManager::updatePaper(int id, QString objectIds, QString subjectIds, int totalMark, int percent, QString description, int time, QString objectMarks, QString subjectMarks)
{
    QSqlQuery query;
    QString s = "update paper set obquids = '%1', subquids = '%2', totalmark = %3, description = '%4', time = %5, obmarks = '%6', submarks = '%7' where paperid = %8";
    query.exec(s.arg(objectIds).arg(subjectIds).arg(totalMark).arg(description).arg(time).arg(objectMarks).arg(subjectMarks).arg(id));
    qDebug() << "updatePaper] " << query.lastError();
}

//把学生客观题答案插入客观题答案表
void DBManager::insertObAnswers(int fpaperid,QString studentid,QString answers)
{
    QSqlQuery query;
    query.prepare("insert into obanswers (fpaperid,studentid,answers) " "values (?,?,?)");
    query.addBindValue(fpaperid);
    query.addBindValue(studentid);
    query.addBindValue(answers);
    query.exec();
    qDebug() << "insertObAnswers] " << query.lastError();
}

void DBManager::updateObAnswers(int pid, QString uid, QString ans)
{
    QString s = "update obanswers set answers= '%1' where fpaperid= %2 and studentid= '%3'";
    QSqlQuery query;
    query.exec(s.arg(ans).arg(pid).arg(uid));
    qDebug() << "updateObAnswers] " <<  query.lastError();

}

//把学生主观题答案插入主观题答案表
void DBManager::insertSubAnswers(int fpaperid,QString studentid)
{

    QSqlQuery query;
    query.prepare("insert into subanswers(fpaperid,studentid)" "values(?,?)");
    query.addBindValue(fpaperid);
    query.addBindValue(studentid);
    query.exec();
    qDebug() << "insertSubAnswers] " << query.lastError();

}
void DBManager::updateSubAnswers(int pid, QString uid, int index, QString answer)
{
    QString s = "update subanswers set answer%1= '%2' where fpaperid= %3 and studentid= '%4'";
    QSqlQuery query;
    query.exec(s.arg(index).arg(answer).arg(pid).arg(uid));
    qDebug() << "updateSubAnswers] " <<  query.lastError();
}

//把学生某张试卷的成绩插入试卷成绩表
bool DBManager::insertPaperMark(QString obqumark,QString subqumark,int totalmark,int fpaperid,QString fuserid)
{
    QSqlQuery query;
    query.prepare("insert into papermark (obqumark,subqumark,totalmark,fpaperid,fuserid,done) " "values (?,?,?,?,?,?)");
    query.addBindValue(obqumark);
    query.addBindValue(subqumark);
    query.addBindValue(totalmark);
    query.addBindValue(fpaperid);
    query.addBindValue(fuserid);
    query.addBindValue(QStringLiteral("未完成"));

    query.exec();
    if (query.numRowsAffected() > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
    qDebug() << "insertPaperMark] " << query.lastError();

}

bool DBManager::deletePaperMark(int pid)
{
    QSqlQuery query;

    query.exec(QStringLiteral("delete from papermark where fpaperid =  %1 and done= '%2'").arg(pid).arg(QStringLiteral("未完成")));
    if (query.numRowsAffected()>0)
    {
        return true;
    }
    else
    {
        return false;
    }
    query.exec();
    qDebug() << "deletePaperMark] " << query.lastError();
}

QSqlQuery DBManager::searchPaperMark(int pid, QString uid)
{
    QSqlQuery query;
    QString s = "select * from papermark where fpaperid= %1 and fuserid= '%2'";

    if( query.exec(s.arg(pid).arg(uid)))
    {
        return query;
    }
    else
    {
        qDebug() << "searchPaperMark] " << query.lastError();
        return query;
    }
}

//按试卷ID在papermark表中查询
QSqlQuery DBManager::queryPaperMark1(int id)
{
    QSqlQuery query;
    QString s = "select * from papermark inner join student on student.userid= papermark.fuserid where fpaperid= %1";
    if( query.exec(s.arg(id)))
    {
        return query;

    }
    else
    {
        qDebug() << "queryPaperMark1] " << query.lastError();
        return query;
    }


}

//按学生ID在papermark表中查询
QSqlQuery DBManager::queryPaperMark2(QString id)
{
    QSqlQuery query;
    QString s = "select * from papermark where fuserid= %1";
    if( query.exec(s.arg(id)))
    {
        qDebug() << "queryPaperMark2] " << query.lastError();
        return query;

    }
    else
    {
        qDebug() << "queryPaperMark2] " << query.lastError();
        return query;
    }
}

QSqlQuery DBManager::getStudentByPaperID(int id)
{
    QSqlQuery query;
    QString s = "select fuserid from papermark where fpaperid = %1";
    if(query.exec(s.arg(id))){
        return query;
    }
    else{
        qDebug() << "getStudentByPaperID] " << query.lastError();
    }
}

//按试卷ID和学生ID在subanswers表中查询
QSqlQuery DBManager::querySubAnswers(int fpaperid,QString studentid)
{

    QSqlQuery query;
    query.exec(QStringLiteral("select * from subanswers where fpaperid = %1 and studentid= '%2'").arg(fpaperid).arg(studentid));
    qDebug() << "querySubAnswers] " << query.lastError();
    return query;
}

//登录功能，账号密码正确返回true 否则返回false
QSqlQuery DBManager::studentLogin(QString id ,QString password)
{
    QSqlQuery query;
    QString s = "select * from student where userid= '%1' and password= '%2' ";

    if( query.exec(s.arg(id).arg(password)))
    {
        qDebug() << "login] " << query.lastError();
        return query;
    }
    else
    {
        qDebug() << "login] " << query.lastError();
        return query;
    }

}

QSqlQuery DBManager::managerLogin(QString id ,QString password)
{
    QSqlQuery query;
    QString s = "select userid, name, type from serveruser where userid= %1 and password= \'%2\' ";
    if( query.exec(s.arg(id).arg(password)))
    {
        query.first();
        User::GetInstance().setType(query.value(2).toInt());
        return query;
    }
    else
    {
        qDebug()  << "managerLogin] " << query.lastError();
        return query;
    }

}

void DBManager::updatePaperMarkObmark(QString obmark,int pid,QString uid)
{
    QSqlQuery query;
    QString s = "update papermark set obqumark= '%1' where fpaperid= %2 and fuserid= '%3'";

    query.exec(s.arg(obmark).arg(pid).arg(uid));

    qDebug() << "updatePaperMarkObmark] " << query.lastError();
}

void DBManager::updatePaperMarkSubmark(QString submark,int pid,QString uid)
{
    QSqlQuery query;
    QString s = "update papermark set subqumark= '%1' where fpaperid= %2 and fuserid= '%3'";

    query.exec(s.arg(submark).arg(pid).arg(uid));

    qDebug() << "updatePaperMarkSubmark] " << query.lastError();
}

void DBManager::updatePaperMarkTotalmark(int totalmark,int pid,QString uid)
{
    QSqlQuery query;
    QString s = "update papermark set totalmark= '%1',finish= '%2' where fpaperid= %3 and fuserid= '%4'";

    query.exec(s.arg(totalmark).arg(QStringLiteral("已批改")).arg(pid).arg(uid));

    qDebug() << "updatePaperMarkTotalmark] " << query.lastError();
}

void DBManager::updatePaperMarkDone(QString date,int pid,QString uid)
{
    QSqlQuery query;
    QString s = "update papermark set date= '%1',done= '%2',finish= '%3' where fpaperid= %4 and fuserid= '%5'";
    query.exec(s.arg(date).arg(QStringLiteral("已完成")).arg(QStringLiteral("未批改")).arg(pid).arg(uid));
    qDebug() << "updatePaperMarkDone] " << query.lastError();
}

int DBManager::deleteScore(int pid,qlonglong uid)
{
    QSqlQuery query;
    int rowsaffected = 0;
    QString s = "delete from papermark where fpaperid= '%1' and fuserid= '%2'";
    query.exec(s.arg(pid).arg(uid));
    qDebug() << "deleteScore] " << query.lastError();
    qDebug() << "rowsaffected:" << query.numRowsAffected();
    rowsaffected = query.numRowsAffected()+ rowsaffected;
    QString r = "delete from obanswers where fpaperid= '%1' and studentid= '%2'";
    query.exec(r.arg(pid).arg(uid));
    qDebug() << "deleteScore] " << query.lastError();
    qDebug() << "rowsaffected:" << query.numRowsAffected();
    rowsaffected = query.numRowsAffected()+ rowsaffected;
    QString t = "delete from subanswers where fpaperid= '%1' and studentid= '%2'";
    query.exec(t.arg(pid).arg(uid));
    rowsaffected = query.numRowsAffected()+ rowsaffected;
    qDebug() << "rowsaffected:" << query.numRowsAffected() << rowsaffected;
    return rowsaffected;
}
