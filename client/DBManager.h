#ifndef DBMANAGER_H
#define DBMANAGER_H
#include<QtSql>


class DBManager
{

public:
    DBManager();
    QSqlQuery SelectUser();

};
#endif // DBMANAGER_H
