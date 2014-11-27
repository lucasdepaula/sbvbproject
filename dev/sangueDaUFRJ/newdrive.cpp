#include "newdrive.h"
#include "ui_newdrive.h"
#include <QDesktopWidget>
#include <QCloseEvent>
#include <QtSql>
#include <QSqlQuery>
#include <QList>
#define TEMP "Creating"

NewDrive::NewDrive(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NewDrive)
{
    ui->setupUi(this);
    ui->dateEdit->setDate(QDate::currentDate());
    setStyleSheet("background-image: url(:/image/data/sangue.png);font-family : Arial, Helvetica, 'Nimbus Sans L'', 'Liberation Sans'', FreeSans, Sans-serif; font-size:13px");
    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("sangueDB.db");
    mydb.open();
    QSqlQuery qry("CREATE TABLE BufferTable (id INTEGER PRIMARY KEY AUTOINCREMENT, scheduledDate TEXT NOT NULL, maxDonors8 INTEGER DEFAULT(0),maxDonors9 INTEGER DEFAULT(0),maxDonors10 INTEGER DEFAULT(0),maxDonors11 INTEGER DEFAULT(0),maxDonors12 INTEGER DEFAULT(0),maxDonors13 INTEGER DEFAULT(0));",mydb);
}

NewDrive::~NewDrive()
{
    QSqlQuery qry("DROP TABLE BufferTable;");
    mydb.close();
    delete ui;
}

//"Voltar"
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

//"Adicionar"
//adds new day in the list
void NewDrive::on_pushButton_4_clicked()
{
    QString date = ui->dateEdit->text();
    ui->listWidget->addItem(date);
    ui->listWidget->sortItems();
    qry = new QSqlQuery(mydb);

    qry->prepare("INSERT INTO BufferTable (scheduledDate,maxDonors8,maxDonors9,maxDonors10,maxDonors11,maxDonors12,maxDonors13) VALUES ('"+date+"','"+ui->spinBox->value()+"','"+ui->spinBox_2->value()+"','"+ui->spinBox_3->value()+"','"+ui->spinBox_4->value()+"','"+ui->spinBox_5->value()+"','"+ui->spinBox_6->value()+"');");
    qry->exec();
}

//saves blood drive information to database --- NOT IMPLEMENTED
void NewDrive::saveBloodDriveInfo(){
    qry = new QSqlQuery(mydb);
    QString name;
    name = ui->lineEdit->text();
    qry->prepare("INSERT INTO BloodDrive (name) VALUES ('"+name+"');");
}

//saves and goes back to mainmenu
void NewDrive::on_pushButton_3_clicked() //"Salvar e finalizar"
{
    saveBloodDriveInfo();
    this->close();
}

//QSqlQuery qry1("CREATE TABLE Donor (id INTEGER PRIMARY KEY AUTOINCREMENT ,majorID INTEGER,name TEXT,email TEXT,phone TEXT DEFAULT (null) ,semester TEXT DEFAULT (null) ,obs TEXT DEFAULT (null) );",mydb);
//QSqlQuery qry2("CREATE TABLE BloodDrive (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, startDate TEXT);",mydb);
//QSqlQuery qry3("CREATE TABLE DonationTime (id INTEGER NOT NULL, scheduledDate TEXT NOT NULL, scheduledTime TEXT NOT NULL, bloodDriveId INTEGER NOT NULL, maxDonors INTEGER DEFAULT(0), PRIMARY KEY (id, scheduledDate, scheduledTime));",mydb);
//QSqlQuery qry4("CREATE TABLE BloodDriveDonor (id INTEGER NOT NULL, bloodDriveID INTEGER NOT NULL, donorID INTEGER NOT NULL, PRIMARY KEY (id, bloodDriveID, donorID));",mydb);
//QSqlQuery qry5("CREATE TABLE Major (id INTEGER PRIMARY KEY AUTOINCREMENT, listedName TEXT NOT NULL, inputName TEXT DEFAULT NULL);",mydb);

