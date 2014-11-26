#include "databasecreator.h"
#include <QtSql>
#include <QSql>
#include <QSqlQuery>

databaseCreator::databaseCreator()
{
    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("sangueDB.db");
}

void databaseCreator::createDatabase(){
    QSqlQuery qry("CREATE TABLE Donor (id INTEGER PRIMARY KEY   AUTOINCREMENT ,major VARCHAR,name TEXT,email TEXT,phone TEXT DEFAULT (null) ,semester TEXT DEFAULT (null) ,obs TEXT DEFAULT (null) );",mydb);
}
