#include"DBManager.h"
#include <QMessageBox>
//构造函数，连接数据库
DBManager::DBManager(QString name, QString user, QString pw)
{
    _db = QSqlDatabase::addDatabase("QMYSQL");
    _db.setHostName("localhost");    //主机名
    _db.setDatabaseName("qtdb");     //数据库名
    _db.setUserName("root");             //用户名
    _db.setPassword("allen");                 //密码

    if(!_db.open())
    {
        QMessageBox msg;
        msg.setText(QStringLiteral("连接数据库失败！"));
        msg.exec();
    }
}
DBManager::~DBManager()
{

}

//////////////////////////////////////////////////////////////////
//查询user表的所有数据
QSqlQuery DBManager::selectStudent()
{

    QSqlQuery query;
    if( query.exec("SELECT * FROM student"))
        return query;
    else
    {
        // return NULL;
        qDebug() << "selectStudent] " << query.lastError();
    }
}

QSqlQuery DBManager::selectStudentId(QString a)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM student WHERE userid  =  (?)");
    query.addBindValue(a);
    query.exec();

    qDebug() << "selectStudentId]" << query.lastError();
    return query;

}

QSqlQuery DBManager::selectStudentGC(int a, int b)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM student WHERE grade  =  (?) AND class =  (?)");
    query.addBindValue(a);
    query.addBindValue(b);
    query.exec();

    qDebug() << "selectStudentGC]" << query.lastError();
    return query;
}

//插入用户
void DBManager::insertStudent(QString a, QString b, int c, int d, QString e)
{
    QSqlQuery query;

    query.prepare("INSERT INTO student (userid, name, grade, class,password) "
                  "VALUES (?,?,?,?,?)");
    query.addBindValue(a);
    query.addBindValue(b);
    query.addBindValue(c);
    query.addBindValue(d);
    query.addBindValue(e);
    query.exec();
    qDebug() << "insetStudent] " << query.lastError();
}

void DBManager::modifyStudent(QString id, QString name, int grade, int clas, QString PW)
{
    QSqlQuery query;
    QString s = "UPDATE student set name= '%1',grade= %2,class= %3,password= '%4' WHERE userid= '%5'";

    query.exec(s.arg(name).arg(grade).arg(clas).arg(PW).arg(id));

    qDebug() << "modifyStudent] " << query.lastError();
}

//根据id删除用户
void DBManager::deleteStudentId(QString a)
{
    QSqlQuery query;
    query.prepare("DELETE FROM student WHERE userid  =  (?)");
    query.addBindValue(a);
    if(!query.isValid())

        query.exec();
}
//根据name删除用户
void DBManager::deleteStudentName(QString a)
{
    QSqlQuery query;
    query.prepare("DELETE FROM student WHERE name  =  (?)");
    query.addBindValue(a);
    if(!query.isValid())
        query.exec();
}

/*
 *改用serveruser数据库。。。
 */
QSqlQuery DBManager::selectServerUser()
{
    QSqlQuery query;
    if( query.exec("SELECT userid,name,password,type FROM serveruser"))
        return query;
    else
        return query;
}
void DBManager::insertServerUser(int a,QString b,QString c)
{
    QSqlQuery query;
    query.prepare("INSERT INTO serveruser (userid, name,password) "
                  "VALUES (:teacherid, :name, :password)");
    query.bindValue(":teacherid", a);
    query.bindValue(":name", b);
    query.bindValue(":password",c);
    query.exec();
    qDebug() << "insertServerUser] " << query.lastError();
}
//下面的插入管理员函数需要修改UI使得支持用户类型。。所以暂时使用原来不带用户类型的函数
/*
void DBManager::InsertManager(int a,QString b,QString c, int d)
{
    QSqlQuery query;
    query.prepare("INSERT INTO serveruser (userid,name,password,type) "
                  "VALUES (:userid, :name, :password, :type)");
    query.bindValue(":userid", a);
    query.bindValue(":name", b);
    query.bindValue(":password",c);
    query.bindValue(":type",d)
    query.exec();
    qDebug() << query.lastError();
}
*/

void DBManager::deleteServerUserID(int a)
{
    QSqlQuery query;
    query.prepare("DELETE FROM serveruser WHERE userid  =  (?)");
    query.addBindValue(a);
    if(!query.isValid())
        query.exec();
}

void DBManager::deleteServerUserName(QString a)
{
    QSqlQuery query;
    query.prepare("DELETE FROM serveruser WHERE name  =  (?)");
    query.addBindValue(a);
    if(!query.isValid())
        query.exec();
}

///////////////////////////////////////////////
//查询manager表的所有数据
//QSqlQuery DBManager::SelectManager()
//{
//    QSqlQuery query;
//    if( query.exec("SELECT * FROM manager"))
//        return query;
//    else
//        return query;
//}

//void DBManager::InsertManager(int a,QString b,QString c)
//{
//    QSqlQuery query;
//    query.prepare("INSERT INTO manager (teacherid, name,password) "
//                  "VALUES (:teacherid, :name, :password)");
//    query.bindValue(":teacherid", a);
//    query.bindValue(":name", b);
//    query.bindValue(":password",c);
//    query.exec();
//    qDebug() << query.lastError();
//}

//void DBManager::DeleteManagerId(int a)
//{
//    QSqlQuery query;
//    query.prepare("DELETE FROM manager WHERE teacherid  =  (?)");
//    query.addBindValue(a);
//    if(!query.isValid())

//    query.exec();
//}

//void DBManager::DeleteManagerName(QString a)
//{
//    QSqlQuery query;
//    query.prepare("DELETE FROM manager WHERE name  =  (?)");
//    query.addBindValue(a);
//    if(!query.isValid())

//    query.exec();
//}

//插入客观题到数据库
void DBManager::insertOb(int id,QString type,QString title,QString answer)
{
    QSqlQuery query;

    query.prepare("INSERT INTO obquestions ( obid,title,answer,type) " "VALUES ( ?,?,?,?)");
    query.addBindValue(id);
    query.addBindValue(title);
    query.addBindValue(answer);
    query.addBindValue(type);

    query.exec();
    qDebug() << "insertOb] " << query.lastError();


}

//插入主观题到数据库
void DBManager::insertSub(int id,QString type,QString title)
{

    QSqlQuery query;
    query.prepare("INSERT INTO subquestions (subid,title,type) " "VALUES ( ?,?, ?)");
    // query.prepare("INSERT INTO subquestions (subid,mark,title,type) " "VALUES ( ?,?, ?)");
    query.addBindValue(id);
    query.addBindValue(title);
    query.addBindValue(type);


    query.exec();
    qDebug() << "insertSub]" << query.lastError();


}

//查询客观题表的所有数据
QSqlQuery DBManager::selectObQuestions()
{
    QSqlQuery query;
    int type = USER::GetInstance().getType();
    if( query.exec(QString("SELECT * FROM obquestions WHERE type = %1").arg(type)))
        return query;
    else
        return query;
    ;
}


//查询主观题表的所有数据
QSqlQuery DBManager::selectSubQuestions()
{
    QSqlQuery query;
    int type = USER::GetInstance().getType();
    if( query.exec(QString("SELECT * FROM subquestions WHERE type = %1").arg(type)))
        return query;
    else
        return query;
    ;
}
//按ID找到记录把在问题表和答案表内的该记录一并删除（客观题）
void DBManager::deleteObQuestions(int id)
{

    QSqlQuery query;
    query.exec(QStringLiteral("DELETE FROM obquestions WHERE obid  =  %1").arg(id));
    //query.exec(QString("DELETE FROM obanswers WHERE obanid  =  %1").arg(id));
    query.exec();
    qDebug() << "selectSubQuestions] " << query.lastError();

}

//按ID找到记录把在问题表和答案表内的该记录一并删除（主观题）
void DBManager::deleteSubQuestions(int id)
{

    QSqlQuery query;

    query.exec(QStringLiteral("DELETE FROM subquestions WHERE subid  =  %1").arg(id));
    query.exec();
    qDebug() << "deleteSubQuestions] " << query.lastError();



}

//按ID修改客观题问题表
void DBManager::alterObQuestions(int id ,QString type,QString title ,QString answer)
{

    QSqlQuery query;
    QString s = "UPDATE obquestions set type= '%1',title= '%2',answer= '%3' WHERE obid= %4";

    query.exec(s.arg(type).arg(title).arg(answer).arg(id));
    qDebug() << "alterObQuestions] " << query.lastError();
}


//按ID修改主观题问题表
void DBManager::alterSubQuestions(int id ,QString type ,QString title)
{

    QSqlQuery query;

    query.exec(QStringLiteral("UPDATE subquestions set type = '%1',title= '%2' WHERE subid= %3").arg(type).arg(title).arg(id));
    qDebug() << "alterSubQuestions] " << query.lastError();
}

void DBManager::insertPaper( QString obids, QString subids, int total, int percent, QString description,int time)
{
    QSqlQuery query;

    query.prepare("INSERT INTO paper (obquids,subquids,totalmark,percent,description,time) " "VALUES (?,?,?,?,?,?)");

    query.addBindValue(obids);
    query.addBindValue(subids);
    query.addBindValue(total);
    query.addBindValue(percent);
    query.addBindValue(description);
    query.addBindValue(time);

    query.exec();
    query.lastQuery();
    qDebug() << "insertPaper] " << query.lastError();
}

QSqlQuery DBManager::selectPaperById(int id)
{
    QSqlQuery query;
    QString s = "SELECT * FROM paper WHERE paperid= %1";
    if( query.exec(s.arg(id)))
    {
        qDebug() << "selectPaperById] " << query.lastError();
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
    if( query.exec("SELECT * FROM paper"))
        return query;
    else
        return query;
    ;

}

void DBManager::deletePaperById(int id)
{
    QSqlQuery query;

    query.exec(QStringLiteral("DELETE FROM paper WHERE paperid  =  %1").arg(id));

    query.exec();
    qDebug() << "deletePaperById" << query.lastError();
}

void DBManager::alterPaper(int id,QString obids, QString subids, int total, int percent, QString description,int time)
{
    QSqlQuery query;
    QString s = "UPDATE paper set obquids= '%1',subquids= '%2',totalmark= %3,percent= %4,description= '%5',time= '%6' WHERE paperid= %7";

    query.exec(s.arg(obids).arg(subids).arg(total).arg(percent).arg(description).arg(time).arg(id));

    qDebug() << "alterPaper] " << query.lastError();
}


//把学生客观题答案插入客观题答案表
void DBManager::insertObAnswers(int fpaperid,QString studentid,QString answers)
{
    QSqlQuery query;
    query.prepare("INSERT INTO obanswers (fpaperid,studentid,answers) " "VALUES (?,?,?)");
    query.addBindValue(fpaperid);
    query.addBindValue(studentid);
    query.addBindValue(answers);
    query.exec();

    qDebug() << "insertObAnswers] " << query.lastError();
}

void DBManager::updateObAnswers(int pid, QString uid, QString ans)
{
    QString s = "UPDATE obanswers set answers= '%1' WHERE fpaperid= %2 and studentid= %3";
    QSqlQuery query;
    query.exec(s.arg(ans).arg(pid).arg(uid));

    qDebug() << "updateObAnswers] " <<  query.lastError();

}

//把学生主观题答案插入主观题答案表
void DBManager::insertSubAnswers(int fpaperid,QString studentid)
{

    QSqlQuery query;

    query.prepare("INSERT INTO subanswers(fpaperid,studentid)" "values(?,?)");

    query.addBindValue(fpaperid);
    query.addBindValue(studentid);
    query.exec();
    qDebug() << "insertSubAnswers] " << query.lastError();

}
void DBManager::updateSubAnswers(int pid, QString uid, int index, QString answer)
{
    QString s = "UPDATE subanswers set answer%1= '%2' WHERE fpaperid= %3 and studentid= %4";
    QSqlQuery query;
    query.exec(s.arg(index).arg(answer).arg(pid).arg(uid));

    qDebug() << "updateSubAnswers] " <<  query.lastError();
}

//把学生某张试卷的成绩插入试卷成绩表
bool DBManager::insertPaperMark(QString obqumark,QString subqumark,int totalmark,int fpaperid,QString fuserid)
{
    QSqlQuery query;

    query.prepare("INSERT INTO papermark (obqumark,subqumark,totalmark,fpaperid,fuserid,done) " "VALUES (?,?,?,?,?,?)");


    query.addBindValue(obqumark);
    query.addBindValue(subqumark);
    query.addBindValue(totalmark);
    query.addBindValue(fpaperid);
    query.addBindValue(fuserid);
    query.addBindValue(QStringLiteral("未完成"));

    query.exec();
    if (query.numRowsAffected()>0)
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

    query.exec(QStringLiteral("DELETE FROM papermark WHERE fpaperid =  %1 and done= '%2'").arg(pid).arg(QString("未完成")));
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
    QString s = "SELECT * FROM papermark WHERE fpaperid= %1 and fuserid= %2 ";

    if( query.exec(s.arg(pid).arg(uid)))
    {
        qDebug() << query.lastQuery();
        qDebug() << "searchPaperMark] " << query.lastError();
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
    QString s = "SELECT * FROM papermark inner join student on student.userid= papermark.fuserid WHERE fpaperid= %1";
    if( query.exec(s.arg(id)))
    {
        qDebug() << "queryPaperMark1] " << query.lastError();
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
    QString s = "SELECT * FROM papermark WHERE fuserid= %1";
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

//按试卷ID和学生ID在subanswers表中查询
QSqlQuery DBManager::querySubAnswers(int fpaperid,QString studentid)
{

    QSqlQuery query;
    query.exec(QStringLiteral("SELECT * FROM subanswers WHERE fpaperid = %1 and studentid= '%2' ").arg(fpaperid).arg(studentid));
    qDebug() << query.lastQuery();
    qDebug() << "querySubAnswers] " << query.lastError();

    return query;



}

//登录功能，账号密码正确返回true 否则返回false
QSqlQuery DBManager::login(QString id ,QString password)
{
    QSqlQuery query;
    QString s = "SELECT * FROM student WHERE userid= %1 and password= '%2' ";

    if( query.exec(s.arg(id).arg(password)))
    {
        std::cout << "!!!!!!" << std::endl;
        qDebug() << "login] " << query.lastError();
        return query;
    }
    else
    {
        qDebug() << "login] " << query.lastError();
        return query;
    }

}

//serveruser登录
//转成serveruser数据库。。。验证成功的时候顺便把用户的设置用户的type。。。方便以后可以获得当前用户的信息。
QSqlQuery DBManager::managerLogin(int id ,QString password)
{
    QSqlQuery query;
    QString s = "SELECT userid, name, type FROM serveruser WHERE userid= %1 and password= \'%2\' ";
    if( query.exec(s.arg(id).arg(password)))
    {
        query.first(); //QSqlQuery使用value()需要调用该函数
        USER::GetInstance().setType(query.value(2).toInt());
        qDebug() << "managerLogin] " << query.lastError();
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
    QString s = "UPDATE papermark set obqumark= '%1' WHERE fpaperid= %2 and fuserid= %3";

    query.exec(s.arg(obmark).arg(pid).arg(uid));

    qDebug() << "updatePaperMarkObmark] " << query.lastError();
}

void DBManager::updatePaperMarkSubmark(QString submark,int pid,QString uid)
{
    QSqlQuery query;
    QString s = "UPDATE papermark set subqumark= '%1' WHERE fpaperid= %2 and fuserid= %3";

    query.exec(s.arg(submark).arg(pid).arg(uid));

    qDebug() << "updatePaperMarkSubmark] " << query.lastError();
}

void DBManager::updatePaperMarkTotalmark(int totalmark,int pid,QString uid)
{
    QSqlQuery query;
    QString s = "UPDATE papermark set totalmark= '%1',finish= '%2' WHERE fpaperid= %3 and fuserid= %4";

    query.exec(s.arg(totalmark).arg(QString("已批改")).arg(pid).arg(uid));

    qDebug() << "updatePaperMarkTotalmark] " << query.lastError();
}



void DBManager::updatePaperMarkDone(QString date,int pid,QString uid)
{
    QSqlQuery query;
    QString s = "UPDATE papermark set date= '%1',done= '%2',finish= '%3' WHERE fpaperid= %4 and fuserid= %5";

    query.exec(s.arg(date).arg(QStringLiteral("已完成")).arg(QStringLiteral("未批改")).arg(pid).arg(uid));
    qDebug() << query.lastQuery();
    qDebug() << "updatePaperMarkDone] " << query.lastError();
}





int DBManager::deleteScore(int pid,qlonglong uid)
{
    QSqlQuery query;
    int rowsaffected = 0;
    QString s = "DELETE FROM papermark WHERE fpaperid= '%1' and fuserid= '%2'";
    query.exec(s.arg(pid).arg(uid));
    //qDebug() << s << pid << "\t" << uid;
    qDebug() << query.lastQuery();
    qDebug() << "deleteScore] " << query.lastError();
    qDebug() << "rowsaffected:" << query.numRowsAffected();
    rowsaffected = query.numRowsAffected()+ rowsaffected;
    QString r = "DELETE FROM obanswers WHERE fpaperid= '%1' and studentid= '%2'";
    query.exec(r.arg(pid).arg(uid));
    //qDebug() << r;
    qDebug() << query.lastQuery();
    qDebug() << "deleteScore] " << query.lastError();
    qDebug() << "rowsaffected:" << query.numRowsAffected();
    rowsaffected = query.numRowsAffected()+ rowsaffected;
    QString t = "DELETE FROM subanswers WHERE fpaperid= '%1' and studentid= '%2'";
    query.exec(t.arg(pid).arg(uid));
    rowsaffected = query.numRowsAffected()+ rowsaffected;
    // qDebug() << t;
    qDebug() << query.lastQuery();
    qDebug() << query.lastError();
    qDebug() << "rowsaffected:" << query.numRowsAffected() << rowsaffected;
    return rowsaffected;
}









