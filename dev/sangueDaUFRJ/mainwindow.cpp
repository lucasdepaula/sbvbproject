#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setStyleSheet("background-image: url(./logo_sangue.png);");
//    setStyleSheet("background-color: rgba(255, 255, 255, 10);");
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
