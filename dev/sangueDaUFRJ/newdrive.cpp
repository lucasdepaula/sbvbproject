#include "newdrive.h"
#include "ui_newdrive.h"
#include <QDesktopWidget>
#include <QCloseEvent>
#include <QtSql>
#include <QSqlQuery>
#include <QList>
#include <QDebug>
#define TEMP "Creating"
#define TIME1 "8"
#define TIME2 "9"
#define TIME3 "10"
#define TIME4 "11"
#define TIME5 "12"
#define TIME6 "13"

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
    qDebug() << "Opened DB in NewDrive.cpp";
    qry = new QSqlQuery(mydb);
    qry->prepare("CREATE TABLE BufferTable (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, scheduledDate TEXT NOT NULL, maxDonors'"TIME1"' INTEGER DEFAULT(0),maxDonors'"TIME2"' INTEGER DEFAULT(0),maxDonors'"TIME3"' INTEGER DEFAULT(0),maxDonors'"TIME4"' INTEGER DEFAULT(0),maxDonors'"TIME5"' INTEGER DEFAULT(0),maxDonors'"TIME6"' INTEGER DEFAULT(0));");
    qry->exec();
    qDebug() << "Created BufferTable";
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

    qry->prepare("INSERT INTO BufferTable (name,scheduledDate,maxDonors8,maxDonors9,maxDonors10,maxDonors11,maxDonors12,maxDonors13) VALUES ('"TEMP"','"+date+"','"+ui->spinBox->value()+"','"+ui->spinBox_2->value()+"','"+ui->spinBox_3->value()+"','"+ui->spinBox_4->value()+"','"+ui->spinBox_5->value()+"','"+ui->spinBox_6->value()+"');");
    qry->exec();
}

//saves blood drive information to database
void NewDrive::saveBloodDriveInfo(){
    qry = new QSqlQuery(mydb);
    QString name;
    name = ui->lineEdit->text();
    qry->prepare("INSERT INTO BloodDrive (name) VALUES ('"+name+"');");
    qry->exec();
    QSqlQuery getID("SELECT id FROM BloodDrive WHERE name = '"+name+"'",mydb);
    QSqlQuery getMaxID("SELECT MAX(id) as id FROM DonationTime");
    QSqlQuery getCount("SELECT COUNT(*) FROM BufferTable");
   // QSqlQuery getAll("SELECT scheduledDate,maxDonors8,maxDonors9,maxDonors10,maxDonors11,maxDonors12,maxDonors13 FROM BufferTable");
    QString bloodDriveID = getID.value(0).toString();
    int currentDonationTimeID = getMaxID.value(0).toInt();
    int numberOfRowsToAdd = getCount.value(0).toInt();
    for (int i = 1; i<=numberOfRowsToAdd; i++){
        currentDonationTimeID++;
        QString strid = QString::number(currentDonationTimeID);
        qry->prepare("INSERT INTO DonationTime (id, bloodDriveID) VALUES ('"+strid+"','"+bloodDriveID+"');");
        qry->exec();
        for(int j = atoi(TIME1);j<=atoi(TIME6);j++){
            qry->prepare("UPDATE DonationTime SET scheduledDate = (SELECT scheduledDate FROM BufferTable WHERE id = '"+QString::number(i)+"'), scheduledTime = '"+QString::number(j)+"':00, maxDonors = (SELECT maxDonors'"+QString::number(j)+"' FROM BufferTable WHERE id = '"+QString::number(i)+"') WHERE id = '"+strid+"'");
            qry->exec();
        }
    }

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

