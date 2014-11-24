#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mainmenu.h"
#include "qstring.h"
//#include "newdrive.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void closeEvent(QCloseEvent *);

private:
    Ui::MainWindow *ui;
    QMainWindow *appmenu;
    QString getMajor();
};

#endif // MAINWINDOW_H
