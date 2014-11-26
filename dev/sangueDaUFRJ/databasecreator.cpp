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
    QSqlQuery qry("",mydb);
}
