#include "report.h"
#include "ui_report.h"
#include <QDesktopWidget>
#include <QCloseEvent>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QtSql/QSql>
#include <QSqlDatabase>
#include <QDebug>

Report::Report(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Report)
{
    ui->setupUi(this);
    setStyleSheet("background-image: url(:/image/data/sangue.png);font-family : Arial, Helvetica, 'Nimbus Sans L'', 'Liberation Sans'', FreeSans, Sans-serif; font-size:13px");

    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("sangueDB.db");
    mydb.open();


    qry = new QSqlQuery(mydb);  //mydb is the database
    qry->prepare("SELECT * FROM Donor, 'Blood Drive' GROUP BY Donor.name ORDER BY Donor.name;");
    qry->exec();




}

Report::~Report()
{
    delete ui;
}

void Report::on_pushButton_clicked()
{
    this->close();
}

void Report::closeEvent(QCloseEvent *)
{
    appmenu = new MainMenu();
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()-appmenu->width()) / 2;
    int y = (screenGeometry.height()-appmenu->height()) / 2;
    appmenu->move(x, y);
    appmenu->show();
    this->close();
}

void Report::on_pushButton_2_clicked()
{

    QString name, mymajor, email, phone, bloodDrive, csv;



    QString filename = QFileDialog::getSaveFileName(this, "DialogTitle", "filename.csv", "CSV files (*.csv);;Zip files (*.zip, *.7z)", 0, 0); // getting the filename (full path)
    QFile data(filename);
    if(data.open(QFile::WriteOnly |QFile::Truncate))
    {
            QTextStream output(&data);
            output.setGenerateByteOrderMark(true);
            output << "Nome;Curso;E-mail;Telefone;" << endl;
            while (this->qry->next()) {
                name = qry->value(2).toString();
                mymajor = qry->value(1).toString();
                email = qry->value(3).toString();
                phone = qry->value(4).toString();
                //qDebug() << name << mymajor << email << phone;
                output << name + ";"+ mymajor+";"+email+";"+ phone + ";" << endl;
            }

    }
}
