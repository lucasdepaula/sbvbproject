#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "mainwindow.h"
#include <QDesktopWidget>
#include <QtSql>
#include <QSql>

MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    setStyleSheet("background: url(:/image/data/sangue.png) top 100%;font-family : Arial, Helvetica, 'Nimbus Sans L'', 'Liberation Sans'', FreeSans, Sans-serif; font-size:13px;");

}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_pushButton_clicked()
{
    //add code here to open the main window at the center of the screen
    signup = new MainWindow();

    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()-signup->width()) / 2;
    int y = (screenGeometry.height()-signup->height()) / 2;
    signup->move(x, y);
    signup->show();
    this->close();
}

void MainMenu::on_pushButton_2_clicked()
{
    bloodDrive = new NewDrive();
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()-bloodDrive->width()) / 2;
    int y = (screenGeometry.height()-bloodDrive->height()) / 2;
    bloodDrive->move(x, y);
    bloodDrive->show();
    this->close();
}

void MainMenu::on_pushButton_3_clicked()
{
    report = new Report();
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()-report->width()) / 2;
    int y = (screenGeometry.height()-report->height()) / 2;
    report->move(x, y);
    report->show();
    this->close();
}

void MainMenu::on_pushButton_4_clicked()
{
    about = new About();
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()-about->width()) / 2;
    int y = (screenGeometry.height()-about->height()) / 2;
    about->move(x, y);
    about->show();
    this->close();
}
