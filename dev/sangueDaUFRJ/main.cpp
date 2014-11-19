#include "mainwindow.h"
#include <QApplication>
// #include <QtSql> // adicionar no PRO ->   QT += sql

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
