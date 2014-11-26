#include "newdrive.h"
#include "ui_newdrive.h"
#include <QDesktopWidget>
#include <QCloseEvent>
#include <QtSql>
#include <QSqlQuery>

NewDrive::NewDrive(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NewDrive)
{
    ui->setupUi(this);
    setStyleSheet("background-image: url(:/image/data/sangue.png);font-family : Arial, Helvetica, 'Nimbus Sans L'', 'Liberation Sans'', FreeSans, Sans-serif; font-size:13px");
}

NewDrive::~NewDrive()
{
    delete ui;
}

void NewDrive::on_pushButton_clicked()
{
    this->close();
}

void NewDrive::closeEvent(QCloseEvent *)
{
    appmenu = new MainMenu();
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()-appmenu->width()) / 2;
    int y = (screenGeometry.height()-appmenu->height()) / 2;
    appmenu->move(x, y);
    appmenu->show();
    this->close();
}

void NewDrive::on_pushButton_4_clicked()
{
    //adds new day in the list
    QString date = ui->dateEdit->text();
    ui->listWidget->addItem(date);
}

//saves blood drive information to database --- NOT IMPLEMENTED
void NewDrive::saveBloodDriveInfo(){
    QString name;
    name = ui->lineEdit->text();
//    ui->listWidget->;

//    QSqlQuery qry("INSERT INTO BloodDrive (name) VALUES ('"+name+"'');",mydb);
}
