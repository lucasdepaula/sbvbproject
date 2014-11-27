#ifndef REPORT_H
#define REPORT_H

#include <QMainWindow>
#include "mainwindow.h"
#include <QSqlQuery>
#include <QSqlDatabase>

namespace Ui {
class Report;
}

class Report : public QMainWindow
{
    Q_OBJECT

public:
    explicit Report(QWidget *parent = 0);
    ~Report();


private slots:

    void on_pushButton_clicked();

    void closeEvent(QCloseEvent *);


    void on_pushButton_2_clicked();

private:
    Ui::Report *ui;
    QMainWindow *appmenu;
    QSqlDatabase mydb;
    QSqlQuery* qry;

};


#endif // REPORT_H
