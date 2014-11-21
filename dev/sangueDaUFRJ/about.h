#ifndef ABOUT_H
#define ABOUT_H

#include <QMainWindow>
#include "mainwindow.h"

namespace Ui {
class About;
}

class About : public QMainWindow
{
    Q_OBJECT

public:
    explicit About(QWidget *parent = 0);
    ~About();


private slots:

    void on_pushButton_clicked();

    void closeEvent(QCloseEvent *);


private:
    Ui::About *ui;
    QMainWindow *appmenu;
};

#endif // ABOUT_H
