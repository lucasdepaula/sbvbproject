#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include "mainwindow.h"
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

private:
    Ui::MainMenu *ui;
    QMainWindow *inscricao;
};

#endif // MAINMENU_H
