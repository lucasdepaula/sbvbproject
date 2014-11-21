#include "mainwindow.h"
#include "mainmenu.h"
#include <QApplication>
#include <QDesktopWidget>
// #include <QtSql> // adicionar no PRO ->   QT += sql

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //MainWindow w;
    MainMenu w;
    //
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()-w.width()) / 2;
    int y = (screenGeometry.height()-w.height()) / 2;
    w.move(x, y);
    w.show();
    return a.exec();
}