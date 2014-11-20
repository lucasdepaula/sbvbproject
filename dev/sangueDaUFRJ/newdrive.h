#ifndef NEWDRIVE_H
#define NEWDRIVE_H

#include <QMainWindow>
#include "mainwindow.h"
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


private:
    Ui::NewDrive *ui;
    QMainWindow *appmenu;
};

#endif // NEWDRIVE_H
