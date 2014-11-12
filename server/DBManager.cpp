#include"DBManager.h"
#include <QMessageBox>
//构造函数，连接数据库
DBManager::DBManager(QString name, QString user, QString pw)
{
    db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");    //主机名
    db.setDatabaseName("qtdb");     //数据库名
    db.setUserName("root");             //用户名
    db.setPassword("allen");                 //密码

    if(!db.open())
    {
      QMessageBox msg;
      msg.setText(QString("连接数据库失败！"));
      msg.exec();
    }
}
DBManager::~DBManager()
{

}

//////////////////////////////////////////////////////////////////
//查询user表的所有数据
QSqlQuery DBManager::SelectUser()
{

    QSqlQuery query;
    if( query.exec("SELECT * FROM user"))
        return query;
    else
    {
       // return NULL;
        qDebug()<<query.lastError();
     }
}

QSqlQuery DBManager::SelectUserId(QString a)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM user WHERE userid = (?)");
    query.addBindValue(a);
    query.exec();

    qDebug()<<query.lastError();
    return query;

}

QSqlQuery DBManager::SelectUserGc(int a, int b)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM user WHERE grade = (?) AND class = (?)");
    query.addBindValue(a);
    query.addBindValue(b);
    query.exec();

    qDebug()<<query.lastError();
    return query;
}

//插入用户
void DBManager::InsertUser(QString a, QString b, int c, int d, QString e)
{
    QSqlQuery query;

    query.prepare("INSERT INTO user (userid, name, grade, class,password) "
                  "VALUES (?,?,?,?,?)");
    query.addBindValue(a);
    query.addBindValue(b);
    query.addBindValue(c);
    query.addBindValue(d);
    query.addBindValue(e);
    query.exec();
    qDebug()<<query.lastError();
}

void DBManager::ModifyUser(QString id, QString name, int grade, int clas, QString PW)
{
    QSqlQuery query;
    QString s="UPDATE user set name='%1',grade=%2,class=%3,password='%4' WHERE userid='%5'";

    query.exec(s.arg(name).arg(grade).arg(clas).arg(PW).arg(id));

    qDebug()<<query.lastError();
}

//根据id删除用户
void DBManager::DeleteUserId(QString a)
{
    QSqlQuery query;
    query.prepare("DELETE FROM user WHERE userid = (?)");
    query.addBindValue(a);
    if(!query.isValid())

    query.exec();
}
//根据name删除用户
void DBManager::DeleteUserName(QString a)
{
    QSqlQuery query;
    query.prepare("DELETE FROM user WHERE name = (?)");
    query.addBindValue(a);
    if(!query.isValid())

    query.exec();
}

/*
 *改用serveruser数据库。。。
 */
QSqlQuery DBManager::SelectManager()
{
    QSqlQuery query;
    if( query.exec("SELECT userid,name,password,type FROM serveruser"))
        return query;
    else
        return query;
}
void DBManager::InsertManager(int a,QString b,QString c)
{
    QSqlQuery query;
    query.prepare("INSERT INTO serveruser (userid, name,password) "
                  "VALUES (:teacherid, :name, :password)");
    query.bindValue(":teacherid", a);
    query.bindValue(":name", b);
    query.bindValue(":password",c);
    query.exec();
    qDebug()<<query.lastError();
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
    qDebug()<<query.lastError();
}
*/

void DBManager::DeleteManagerId(int a)
{
    QSqlQuery query;
    query.prepare("DELETE FROM serveruser WHERE userid = (?)");
    query.addBindValue(a);
    if(!query.isValid())

    query.exec();
}

void DBManager::DeleteManagerName(QString a)
{
    QSqlQuery query;
    query.prepare("DELETE FROM serveruser WHERE name = (?)");
    query.addBindValue(a);
    if(!query.isValid())

    query.exec();
}

///////////////////////////////////////////////
//查询manager表的所有数据
/*
QSqlQuery DBManager::SelectManager()
{
    QSqlQuery query;
    if( query.exec("SELECT * FROM manager"))
        return query;
    else
        return query;
}

void DBManager::InsertManager(int a,QString b,QString c)
{
    QSqlQuery query;
    query.prepare("INSERT INTO manager (teacherid, name,password) "
                  "VALUES (:teacherid, :name, :password)");
    query.bindValue(":teacherid", a);
    query.bindValue(":name", b);
    query.bindValue(":password",c);
    query.exec();
    qDebug()<<query.lastError();
}

void DBManager::DeleteManagerId(int a)
{
    QSqlQuery query;
    query.prepare("DELETE FROM manager WHERE teacherid = (?)");
    query.addBindValue(a);
    if(!query.isValid())

    query.exec();
}

void DBManager::DeleteManagerName(QString a)
{
    QSqlQuery query;
    query.prepare("DELETE FROM manager WHERE name = (?)");
    query.addBindValue(a);
    if(!query.isValid())

    query.exec();
}
*/

//插入客观题到数据库
void DBManager::InserOb(int id,QString type,QString title,QString answer)
{
    QSqlQuery query;

    query.prepare("INSERT INTO obquestions ( obid,title,answer,type) " "VALUES ( ?,?,?,?)");
    query.addBindValue(id);
    query.addBindValue(title);
    query.addBindValue(answer);
    query.addBindValue(type);

    query.exec();
    qDebug()<<query.lastError();


}

//插入主观题到数据库
void DBManager::InserSub(int id,QString type,QString title)
{

    QSqlQuery query;
    query.prepare("INSERT INTO subquestions (subid,title,type) " "VALUES ( ?,?, ?)");
   // query.prepare("INSERT INTO subquestions (subid,mark,title,type) " "VALUES ( ?,?, ?)");
    query.addBindValue(id);
    query.addBindValue(title);
    query.addBindValue(type);


    query.exec();
    qDebug()<<query.lastError();


}

//查询客观题表的所有数据
QSqlQuery DBManager::SelectobQuestions()
{
    QSqlQuery query;
    if( query.exec("SELECT * FROM obquestions"))
        return query;
    else
        return query;
        ;
}


//查询主观题表的所有数据
QSqlQuery DBManager::SelectsubQuestions()
{
    QSqlQuery query;
    if( query.exec("SELECT * FROM subquestions"))
        return query;
    else
        return query;
        ;
}
//按ID找到记录把在问题表和答案表内的该记录一并删除（客观题）
void DBManager::DeleteobQuestions(int id)
{

    QSqlQuery query;

    query.exec(QString("DELETE FROM obquestions WHERE obid = %1").arg(id));
    //query.exec(QString("DELETE FROM obanswers WHERE obanid = %1").arg(id));
    query.exec();
    qDebug()<<query.lastError();

}

//按ID找到记录把在问题表和答案表内的该记录一并删除（主观题）
void DBManager::DeletesubQuestions(int id)
{

    QSqlQuery query;

     query.exec(QString("DELETE FROM subquestions WHERE subid = %1").arg(id));

     //query.exec(QString("DELETE FROM obanswers WHERE suanid = %1").arg(id));



    query.exec();
    qDebug()<<query.lastError();



}

//按ID修改客观题问题表
void DBManager::AlterobQuestions(int id ,QString type,QString title ,QString answer)
{

    QSqlQuery query;
    QString s="UPDATE obquestions set type='%1',title='%2',answer='%3' WHERE obid=%4";

    query.exec(s.arg(type).arg(title).arg(answer).arg(id));
    qDebug()<<query.lastError();
}


//按ID修改主观题问题表
void DBManager::AltersubQuestions(int id ,QString type ,QString title)
{

    QSqlQuery query;

    query.exec(QString("UPDATE subquestions set type='%1',title='%2' WHERE subid=%3").arg(type).arg(title).arg(id));
    qDebug()<<query.lastError();
}

void DBManager::InserPaper( QString obids, QString subids, int total, int percent, QString description,int time)
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
    qDebug()<<query.lastError();
}

QSqlQuery DBManager::SelectPaperById(int id)
{
    QSqlQuery query;
    QString s="SELECT * FROM paper WHERE paperid=%1";
    if( query.exec(s.arg(id)))
      {
          qDebug()<<query.lastError();
          return query;

      }
    else
      {
        qDebug()<<query.lastError();
        return query;
    }
}

QSqlQuery DBManager::SelectPaper()
{

    QSqlQuery query;
    if( query.exec("SELECT * FROM paper"))
        return query;
    else
        return query;
;

}

void DBManager::DeletePaperById(int id)
{
    QSqlQuery query;

    query.exec(QString("DELETE FROM paper WHERE paperid = %1").arg(id));

    query.exec();
    qDebug()<<query.lastError();
}

void DBManager::AlterPaper(int id,QString obids, QString subids, int total, int percent, QString description,int time)
{
    QSqlQuery query;
    QString s="UPDATE paper set obquids='%1',subquids='%2',totalmark=%3,percent=%4,description='%5',time='%6' WHERE paperid=%7";

    query.exec(s.arg(obids).arg(subids).arg(total).arg(percent).arg(description).arg(time).arg(id));

    qDebug()<<query.lastError();
}


//把学生客观题答案插入客观题答案表
void DBManager::InserobAnswers(int fpaperid,QString studentid,QString answers)
{
    QSqlQuery query;

    query.prepare("INSERT INTO obanswers (fpaperid,studentid,answers) " "VALUES (?,?,?)");


    query.addBindValue(fpaperid);
    query.addBindValue(studentid);
    query.addBindValue(answers);



    query.exec();

    qDebug()<<query.lastError();
}

void DBManager::UpdateobAnswers(int pid, QString uid, QString ans)
{
    QString s="UPDATE obanswers set answers='%1' WHERE fpaperid=%2 and studentid=%3";
    QSqlQuery query;
    query.exec(s.arg(ans).arg(pid).arg(uid));

   qDebug()<< query.lastError();

}

//把学生主观题答案插入主观题答案表
void DBManager::InsersubAnswers(int fpaperid,QString studentid)
{

    QSqlQuery query;

    query.prepare("INSERT INTO subanswers(fpaperid,studentid)" "values(?,?)");

    query.addBindValue(fpaperid);
    query.addBindValue(studentid);
    query.exec();
    qDebug()<<query.lastError();

}
void DBManager::UpdatesubAnswers(int pid, QString uid, int index, QString answer)
{
    QString s="UPDATE subanswers set answer%1='%2' WHERE fpaperid=%3 and studentid=%4";
    QSqlQuery query;
    query.exec(s.arg(index).arg(answer).arg(pid).arg(uid));

   qDebug()<< query.lastError();
}

//把学生某张试卷的成绩插入试卷成绩表
bool DBManager::InserpaperMark(QString obqumark,QString subqumark,int totalmark,int fpaperid,QString fuserid)
{
    QSqlQuery query;

    query.prepare("INSERT INTO papermark (obqumark,subqumark,totalmark,fpaperid,fuserid,done) " "VALUES (?,?,?,?,?,?)");


    query.addBindValue(obqumark);
    query.addBindValue(subqumark);
    query.addBindValue(totalmark);
    query.addBindValue(fpaperid);
    query.addBindValue(fuserid);
    query.addBindValue(QString("未完成"));

    query.exec();
    if (query.numRowsAffected()>0)
      {return true;}else{return false;}
    qDebug()<<query.lastError();

}


bool DBManager::DeletePapermark(int pid)
{
        QSqlQuery query;

        query.exec(QString("DELETE FROM papermark WHERE fpaperid= %1 and done='%2'").arg(pid).arg(QString("未完成")));
        if (query.numRowsAffected()>0)
                              {return true;}else{return false;}
        query.exec();
        qDebug()<<query.lastError();
    }
    /*QSqlQuery query;
    query.exec(QString("SELECT * FROM papermark WHERE fpaperid=%1").arg(pid));
    query.first();
    int ok=0;
    query.first();
    while(query.isActive())
    {
    QString str=query.value(5).toString();
    if(str=="未完成"){
                   qlonglong fuserid=query.value(4).toLongLong();
                   query.exec(QString("DELETE FROM papermark WHERE fpaperid= %1 and fuserid=%2 and done='%3'").arg(pid).arg(fuserid).arg(QString("未完成")));
                   qDebug()<<fuserid;
                   qDebug()<<query.at();
                   qDebug()<<query.numRowsAffected();

                  // if (query.numRowsAffected()>0)
                    //  {return 1;}else{return 0;}}
              // else{return 0;}
} query.next();}
    query.exec();return true;}*/


QSqlQuery DBManager::SearchpaperMark(int pid, QString uid)
{
    QSqlQuery query;
    QString s="SELECT * FROM papermark WHERE fpaperid=%1 and fuserid=%2 ";

    if( query.exec(s.arg(pid).arg(uid)))
      {
          qDebug()<<query.lastQuery();
          qDebug()<<query.lastError();
          return query;
      }
    else
      {
        qDebug()<<query.lastError();
        return query;
    }
}
//按试卷ID在papermark表中查询
QSqlQuery DBManager::QueryPapermark1(int id)
{
    QSqlQuery query;
    QString s="SELECT * FROM papermark inner join user on user.userid=papermark.fuserid WHERE fpaperid=%1";
    if( query.exec(s.arg(id)))
      {
          qDebug()<<query.lastError();
          return query;

      }
    else
      {
        qDebug()<<query.lastError();
        return query;
    }


}

//按学生ID在papermark表中查询
QSqlQuery DBManager::QueryPapermark2(QString id)
{
    QSqlQuery query;
    QString s="SELECT * FROM papermark WHERE fuserid=%1";
    if( query.exec(s.arg(id)))
      {
          qDebug()<<query.lastError();
          return query;

      }
    else
      {
        qDebug()<<query.lastError();
        return query;
    }
}

//按试卷ID和学生ID在subanswers表中查询
QSqlQuery DBManager::QuerysubAnswers(int fpaperid,QString studentid)
{

    QSqlQuery query;

    query.exec(QString("SELECT * FROM subanswers WHERE fpaperid=%1 and studentid='%2' ").arg(fpaperid).arg(studentid));
    qDebug()<<query.lastQuery();
    qDebug()<<query.lastError();

    return query;



}

//登录功能，账号密码正确返回true 否则返回false
QSqlQuery DBManager::Login(QString id ,QString password)
{
    QSqlQuery query;
    QString s="SELECT * FROM user WHERE userid=%1 and password='%2' ";

    if( query.exec(s.arg(id).arg(password)))
      {
          qDebug()<<query.lastError();
          return query;
      }
    else
      {
        qDebug()<<query.lastError();
        return query;
    }

}

//serveruser登录
//转成serveruser数据库。。。验证成功的时候顺便把用户的设置用户的type。。。方便以后可以获得当前用户的信息。
QSqlQuery DBManager::ManagerLogin(int id ,QString password)
{
    QSqlQuery query;
    QString s="SELECT userid, name, type FROM serveruser WHERE userid=%1 and password=\'%2\' ";
    if( query.exec(s.arg(id).arg(password)))
    {
        query.first(); //QSqlQuery使用value()需要调用该函数
        USER::GetInstance().setType(query.value(2).toInt());
        qDebug()<<query.lastError();
        return query;
    }
    else
    {
        qDebug()<<query.lastError();
        return query;
    }

}

void DBManager::UpdatepaperMarkObmark(QString obmark,int pid,QString uid)
{
    QSqlQuery query;
    QString s="UPDATE papermark set obqumark='%1' WHERE fpaperid=%2 and fuserid=%3";

    query.exec(s.arg(obmark).arg(pid).arg(uid));

    qDebug()<<query.lastError();
}

void DBManager::UpdatepaperMarkSubmark(QString submark,int pid,QString uid)
{
    QSqlQuery query;
    QString s="UPDATE papermark set subqumark='%1' WHERE fpaperid=%2 and fuserid=%3";

    query.exec(s.arg(submark).arg(pid).arg(uid));

    qDebug()<<query.lastError();
}

void DBManager::UpdatepaperMarkTotalmark(int totalmark,int pid,QString uid)
{
    QSqlQuery query;
    QString s="UPDATE papermark set totalmark='%1',finish='%2' WHERE fpaperid=%3 and fuserid=%4";

    query.exec(s.arg(totalmark).arg(QString("已批改")).arg(pid).arg(uid));

    qDebug()<<query.lastError();
}



void DBManager::UpdatepapermarkDone(QString date,int pid,QString uid)
{
    QSqlQuery query;
    QString s="UPDATE papermark set date='%1',done='%2',finish='%3' WHERE fpaperid=%4 and fuserid=%5";

    query.exec(s.arg(date).arg(QString("已完成")).arg(QString("未批改")).arg(pid).arg(uid));
    qDebug()<<query.lastQuery();
    qDebug()<<query.lastError();
}





int DBManager::DeleteScore(int pid,qlonglong uid)
{
   QSqlQuery query;
   int rowsaffected=0;
   QString s="delete FROM papermark WHERE fpaperid='%1' and fuserid='%2'";
   query.exec(s.arg(pid).arg(uid));
   //qDebug()<<s<<pid<<"\t"<<uid;
   qDebug()<<query.lastQuery();
   qDebug()<<query.lastError();
    qDebug()<<"rowsaffected:"<<query.numRowsAffected();
   rowsaffected=query.numRowsAffected()+ rowsaffected;
   QString r="delete FROM obanswers WHERE fpaperid='%1' and studentid='%2'";
   query.exec(r.arg(pid).arg(uid));
   //qDebug()<<r;
   qDebug()<<query.lastQuery();
   qDebug()<<query.lastError();
    qDebug()<<"rowsaffected:"<<query.numRowsAffected();
   rowsaffected=query.numRowsAffected()+ rowsaffected;
   QString t="delete FROM subanswers WHERE fpaperid='%1' and studentid='%2'";
   query.exec(t.arg(pid).arg(uid));
   rowsaffected=query.numRowsAffected()+ rowsaffected;
  // qDebug()<<t;
   qDebug()<<query.lastQuery();
   qDebug()<<query.lastError();
   qDebug()<<"rowsaffected:"<<query.numRowsAffected()<<rowsaffected;
   return rowsaffected;
}









