#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "mainwindow.h"
#include <QDesktopWidget>


MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    setStyleSheet("background: url(:/image/data/sangue.png) top 100%;font-family : Arial, Helvetica, 'Nimbus Sans L'', 'Liberation Sans'', FreeSans, Sans-serif; font-size:13px;");
    if(!(QFile::exists("sangueDB.db")))
    {
        MainMenu::createDatabase();
    }
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

void MainMenu::createDatabase(){
    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("sangueDB.db");
    QSqlQuery qry1("CREATE TABLE Donor (id INTEGER PRIMARY KEY AUTOINCREMENT ,majorID INTEGER,name TEXT,email TEXT,phone TEXT DEFAULT (null) ,semester TEXT DEFAULT (null) ,obs TEXT DEFAULT (null) );",mydb);
    QSqlQuery qry2("CREATE TABLE BloodDrive (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, startDate TEXT);",mydb);
    QSqlQuery qry3("CREATE TABLE DonationTime (id INTEGER AUTOINCREMENT, date TEXT NOT NULL, time TEXT NOT NULL, maxDonors INTEGER DEFAULT (0), PRIMARY KEY (id, date, time));",mydb);
    QSqlQuery qry4("CREATE TABLE BloodDriveDonor (id INTEGER AUTOINCREMENT, bloodDriveID INTEGER NOT NULL, donorID INTEGER NOT NULL, PRIMARY KEY (id, bloodDriveID, donorID));",mydb);
    QSqlQuery qry5("CREATE TABLE Major (id INTEGER AUTOINCREMENT, listedName TEXT NOT NULL, inputName TEXT, PRIMARY KEY(id));",mydb);
}
