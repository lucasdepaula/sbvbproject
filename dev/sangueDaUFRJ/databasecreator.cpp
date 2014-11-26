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
    QSqlQuery qry("CREATE TABLE "Donor" ("id" INTEGER PRIMARY KEY   AUTOINCREMENT ,major VARCHAR,"name" VARCHAR,"email" VARCHAR,"phone" VARCHAR DEFAULT (null) ,"semester" VARCHAR DEFAULT (null) ,"obs" VARCHAR DEFAULT (null) );",mydb);
}
