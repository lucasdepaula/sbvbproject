#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "mainwindow.h"
#include <QDesktopWidget>
#include <QtSql/QSql>

MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    setStyleSheet("background: url(./sangue.png) top 100%;font-family : Arial, Helvetica, 'Nimbus Sans L'', 'Liberation Sans'', FreeSans, Sans-serif; font-size:13px;");
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_pushButton_clicked()
{
    //add code here to open the main window at the center of the screen
    inscricao = new MainWindow();

    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()-inscricao->width()) / 2;
    int y = (screenGeometry.height()-inscricao->height()) / 2;
    inscricao->move(x, y);
    inscricao->show();
    this->close();
}

void MainMenu::on_pushButton_2_clicked()
{
    mutirao = new NewDrive();
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()-mutirao->width()) / 2;
    int y = (screenGeometry.height()-mutirao->height()) / 2;
    mutirao->move(x, y);
    mutirao->show();
    this->close();
}

void MainMenu::on_pushButton_3_clicked()
{
    relatorio = new Report();
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()-relatorio->width()) / 2;
    int y = (screenGeometry.height()-relatorio->height()) / 2;
    relatorio->move(x, y);
    relatorio->show();
    this->close();
}

void MainMenu::on_pushButton_4_clicked()
{
    sobre = new About();
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()-sobre->width()) / 2;
    int y = (screenGeometry.height()-sobre->height()) / 2;
    sobre->move(x, y);
    sobre->show();
    this->close();
}
