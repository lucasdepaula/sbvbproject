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
    qry->prepare("CREATE TABLE BufferTable (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, scheduledDate TEXT NOT NULL, maxDonors"TIME1" INTEGER DEFAULT(0),maxDonors"TIME2" INTEGER DEFAULT(0),maxDonors"TIME3" INTEGER DEFAULT(0),maxDonors"TIME4" INTEGER DEFAULT(0),maxDonors"TIME5" INTEGER DEFAULT(0),maxDonors"TIME6" INTEGER DEFAULT(0));");
    qry->exec();
    //qDebug() << qry->executedQuery();
}

NewDrive::~NewDrive()
{
    delete ui;
}

//"Voltar"
void NewDrive::on_pushButton_clicked()
{
    this->close();
}

void NewDrive::closeEvent(QCloseEvent *)
{
    QSqlQuery qryDestroy("DROP TABLE BufferTable;");
    qDebug() << qryDestroy.executedQuery();
    mydb.close();
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
    char buffer1[100];
    char buffer2[100];
    char buffer3[100];
    char buffer4[100];
    char buffer5[100];
    char buffer6[100];
    itoa(ui->spinBox->value(),buffer1,10);
    itoa(ui->spinBox_2->value(),buffer2,10);
    itoa(ui->spinBox_3->value(),buffer3,10);
    itoa(ui->spinBox_4->value(),buffer4,10);
    itoa(ui->spinBox_5->value(),buffer5,10);
    itoa(ui->spinBox_6->value(),buffer6,10);
    qry->prepare("INSERT INTO BufferTable (name,scheduledDate,maxDonors"TIME1",maxDonors"TIME2",maxDonors"TIME3",maxDonors"TIME4",maxDonors"TIME5",maxDonors"TIME6") VALUES ('"TEMP"','"+date+"','"+buffer1+"','"+buffer2+"','"+buffer3+"','"+buffer4+"','"+buffer5+"','"+buffer6+"');");
    qry->exec();
    qDebug() << qry->executedQuery();
}

//saves blood drive information to database
void NewDrive::saveBloodDriveInfo(){
    qry = new QSqlQuery(mydb);
    QString name;
    name = ui->lineEdit->text();
    qry->prepare("INSERT INTO BloodDrive (name) VALUES ('"+name+"');");
    qry->exec();
    QSqlQuery getID("SELECT id FROM BloodDrive WHERE name = '"+name+"'",mydb);
    getID.next();
    qDebug() << getID.executedQuery();
    qDebug() <<getID.value(0).toString();
    QSqlQuery getCount1("SELECT COUNT(*) FROM DonationTime");
    getCount1.next();
    int currentDonationTimeID = 0;
    if(getCount1.value(0).toInt()!=0){
        QSqlQuery getMaxID("SELECT MAX(id) as max_id FROM DonationTime");
        getMaxID.next();
        qDebug() << getMaxID.executedQuery();
        qDebug() <<getMaxID.value(0).toString();
        currentDonationTimeID = getMaxID.value(0).toInt();
    }
    QSqlQuery getCount2("SELECT COUNT(*) FROM BufferTable");
    getCount2.next();
    qDebug() << getCount2.executedQuery();
    qDebug() <<getCount2.value(0).toString();
    QString bloodDriveID = getID.value(0).toString();
    int numberOfRowsToAdd = getCount2.value(0).toInt();
    for (int i = 1; i<=numberOfRowsToAdd; i++){

        for(int j = atoi(TIME1);j<=atoi(TIME6);j++){
            currentDonationTimeID++;
            QString strid = QString::number(currentDonationTimeID);
            qry->prepare("INSERT INTO DonationTime (id, bloodDriveID) VALUES ("+strid+","+bloodDriveID+")");
            qry->exec();
            qDebug() << qry->executedQuery();
            qry->prepare("UPDATE DonationTime SET scheduledDate = (SELECT scheduledDate FROM BufferTable WHERE id = "+QString::number(i)+"), scheduledTime = '"+QString::number(j)+":00', maxDonors = (SELECT maxDonors"+QString::number(j)+" FROM BufferTable WHERE id = "+QString::number(i)+") WHERE id = "+strid+"");
            qry->exec();
            qDebug() << qry->executedQuery();
        }
    }

}

//saves and goes back to mainmenu
void NewDrive::on_pushButton_3_clicked() //"Salvar e finalizar"
{
    ui->pushButton_3->setText("Salvando...");
    QApplication::processEvents(QEventLoop::AllEvents);
    this->setDisabled(true);
    QApplication::processEvents(QEventLoop::AllEvents);
    saveBloodDriveInfo();
    this->close();
}
