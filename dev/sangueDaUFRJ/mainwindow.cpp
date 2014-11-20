#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setStyleSheet("background-image: url(./sangue.png);font-family : Arial, Helvetica, 'Nimbus Sans L'', 'Liberation Sans'', FreeSans, Sans-serif; font-size:13px");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked() //"Salvar e criar próximo"
{
    //Saves and opens a new sign up form
}

void MainWindow::on_pushButton_2_clicked() //"Salvar e finalizar"
{
    //Saves and opens a new sign up form
}

void MainWindow::on_pushButton_3_clicked()
{
    // volta para o form principal
    appmenu = new MainMenu();
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()-appmenu->width()) / 2;
    int y = (screenGeometry.height()-appmenu->height()) / 2;
    appmenu->move(x, y);
    appmenu->show();
    this->close();
}

void MainWindow::closeEvent(QCloseEvent *)
{
    MainWindow::on_pushButton_3_clicked();
}
