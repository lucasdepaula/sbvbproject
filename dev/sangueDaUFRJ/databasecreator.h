#ifndef DATABASECREATOR_H
#define DATABASECREATOR_H

#include "databasecreator.h"
#include <QtSql>
#include <QSql>

class databaseCreator
{
public:
    databaseCreator();

private:
    QSqlDatabase mydb;
    void createDatabase();
};

#endif // DATABASECREATOR_H
