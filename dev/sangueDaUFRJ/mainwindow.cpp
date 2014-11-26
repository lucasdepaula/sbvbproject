#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopWidget>
#include <QSql>
#include <QSqlDatabase>
#include <QtSql>
#include <QSqlQuery>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_2->setEnabled(false);
    setStyleSheet("background-image: url(:/image/data/sangue.png);font-family : Arial, Helvetica, 'Nimbus Sans L'', 'Liberation Sans'', FreeSans, Sans-serif; font-size:13px");
    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("sangueDB.db");
    mydb.open();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//saves and opens a new donor signup window
void MainWindow::on_pushButton_clicked() //"Salvar e criar próximo"
{
    saveDonorInfo();
    ui->lineEdit->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_2->clear();
    ui->comboBox->setCurrentIndex(0);
    ui->comboBox_2->setCurrentIndex(0);
    ui->comboBox_5->setCurrentIndex(0);
    ui->comboBox_8->setCurrentIndex(0);
    ui->textEdit->clear();
    return;
}

//Saves and goes back to main menu
void MainWindow::on_pushButton_2_clicked() //"Salvar e finalizar"
{
    saveDonorInfo();
    this->close();
}

void MainWindow::on_pushButton_3_clicked()
{
    // returns to main menu
    this->close();

}

void MainWindow::closeEvent(QCloseEvent *)
{
    appmenu = new MainMenu();
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()-appmenu->width()) / 2;
    int y = (screenGeometry.height()-appmenu->height()) / 2;
    appmenu->move(x, y);
    appmenu->show();

}

//appropriately gets the major attribute either from the dropdown menu or from the line edit box
QString MainWindow::getMajor()
{
    if(ui->comboBox_8->currentText()== "Outro")
        return ui->lineEdit_2->text();
    else
        return ui->comboBox_8->currentText();
}

//enables line edit for entering major if it is not in the predefined list
void MainWindow::on_comboBox_8_currentTextChanged(const QString &arg1)
{
    if (arg1 == "Outro")
        ui->lineEdit_2->setEnabled(true);
    else
    {
        ui->lineEdit_2->setEnabled(false);
        ui->lineEdit_2->clear();
    }
}

//saves donor information to database
void MainWindow::saveDonorInfo(){
    QString major, name, email, phone, semester, obs;
    name = ui->lineEdit->text();
    email = ui->lineEdit_4->text();
    phone = ui->lineEdit_3->text();
    major = getMajor();
    semester = ui->comboBox->currentText();
    obs = ui->textEdit->toPlainText();
    QSqlQuery qry("INSERT INTO Donor (major,name,email,phone,semester,obs) VALUES ('"+major+"','"+name+"','"+email+"','"+phone+"','"+semester+"','"+obs+"');",mydb);
}

