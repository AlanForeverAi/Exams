#include"DBManager.h"

//构造函数，连接数据库
DBManager::DBManager()
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");    //主机名
    db.setDatabaseName("test");     //数据库名
    db.setUserName("root");             //用户名
    db.setPassword("root");                 //密码

    if(!db.open())
        qDebug("can not open");
    else
        qDebug("DB open");
}
//查询user表的所有数据
QSqlQuery DBManager::SelectUser()
{
    QSqlQuery query;
    if( query.exec("select * from user"))
        return query;
    else
        return NULL;
}
