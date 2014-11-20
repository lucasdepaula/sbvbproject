#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include "mainwindow.h"
#include "newdrive.h"

namespace Ui {
class MainMenu;
}

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = 0);
    ~MainMenu();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainMenu *ui;
    QMainWindow *inscricao;
    QMainWindow *mutirao;
};

#endif // MAINMENU_H
