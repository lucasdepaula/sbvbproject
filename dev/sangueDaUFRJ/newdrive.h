#ifndef NEWDRIVE_H
#define NEWDRIVE_H

#include <QMainWindow>
#include "mainwindow.h"
#include <QSqlDatabase>
//#include "mainmenu.h"

namespace Ui {
class NewDrive;
}

class NewDrive : public QMainWindow
{
    Q_OBJECT

public:
    explicit NewDrive(QWidget *parent = 0);
    ~NewDrive();


private slots:

    void on_pushButton_clicked();

    void closeEvent(QCloseEvent *);

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

//    void on_pushButton_2_clicked();

private:
    Ui::NewDrive *ui;
    QMainWindow *appmenu;
    void saveBloodDriveInfo();
    QSqlDatabase mydb;
    void sortListWidget();
};

#endif // NEWDRIVE_H
