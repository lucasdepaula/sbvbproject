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
    QSqlQuery auxQry("CREATE TABLE BufferTable (id INTEGER PRIMARY KEY AUTOINCREMENT, scheduledDate TEXT NOT NULL, scheduledTime TEXT NOT NULL, maxDonors8 INTEGER DEFAULT(0),maxDonors9 INTEGER DEFAULT(0),maxDonors10 INTEGER DEFAULT(0),maxDonors11 INTEGER DEFAULT(0),maxDonors12 INTEGER DEFAULT(0),maxDonors13 INTEGER DEFAULT(0));",mydb);
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
    QSqlQuery qry;

    qry.prepare("INSERT INTO BufferTable (scheduledDate, scheduled)")
}

//saves blood drive information to database --- NOT IMPLEMENTED
void NewDrive::saveBloodDriveInfo(){
    QSqlQuery qry;
    QString name;
    name = ui->lineEdit->text();

//  QList<QListWidgetItem> list = ui->listWidget->items();
//    for (int i=0;i<list.size();i++){
//        qry.prepare("INSERT INTO DonationTime (id, scheduledDate)");
//    }
//    ui->listWidget->;

//    QSqlQuery qry("INSERT INTO BloodDrive (name) VALUES ('"+name+"'');",mydb);
}

//saves and goes back to mainmenu
void NewDrive::on_pushButton_3_clicked() //"Salvar e finalizar"
{
    saveBloodDriveInfo();
    this->close();
}

//saves and opens a new drive window
//void NewDrive::on_pushButton_2_clicked() //"Salvar e criar próximo"
//{
//    saveBloodDriveInfo();
//    ui->lineEdit->clear();
//    ui->dateEdit->setDate(QDate::currentDate());
//    ui->spinBox->setValue(10);
//    ui->spinBox_2->setValue(0);
//    ui->spinBox_3->setValue(10);
//    ui->spinBox_4->setValue(0);
//    ui->spinBox_5->setValue(7);
//    ui->spinBox_6->setValue(0);
//    ui->listWidget->clear();
//    return;
//}

