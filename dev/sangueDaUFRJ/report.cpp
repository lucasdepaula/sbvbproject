#include "report.h"
#include "ui_report.h"
#include <QDesktopWidget>
#include <QCloseEvent>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QtSql/QSql>
#include <QSqlDatabase>
#include <QSqlQueryModel>
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
    bdrive = new QSqlQuery(mydb);  //mydb is the database
    schtime = new QSqlQuery(mydb);  //mydb is the database

    //qry->prepare("SELECT * FROM Donor, 'Blood Drive' GROUP BY Donor.name ORDER BY Donor.name;");

    qry->prepare("SELECT name FROM BloodDrive ORDER BY startdate DESC;");
    qry->exec();

    // the code below fills the "mutirao" combobox

    modal = new QSqlQueryModel();
    modal->setQuery(*qry);
    ui->comboBox_8->setModel(modal);



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

    bdrive->prepare("SELECT id, name FROM BloodDrive WHERE name LIKE '%"+ui->comboBox_8->currentText()+"%';");
    bdrive->exec();
    bdrive->next();

    schtime->prepare("SELECT id, scheduledDate, scheduledTime FROM DonationTime WHERE Donationtime.bloodDriveId = '"+bdrive->value(0).toString()+"' AND Donationtime.scheduledDate = '"+ui->comboBox_9->currentText()+"';");
    schtime->exec();

    //schtime->next();
    QString name, email, phone;



    QString filename = QFileDialog::getSaveFileName(this, "DialogTitle", "filename.csv", "CSV files (*.csv);;Zip files (*.zip, *.7z)", 0, 0); // getting the filename (full path)
    QFile data(filename);
    if(data.open(QFile::WriteOnly |QFile::Truncate))
    {
            QTextStream output(&data);
            output.setGenerateByteOrderMark(true);
            output << "Nome do Mutirão:;" + bdrive->value(1).toString() + ";" << endl;
            while(this->schtime->next()) {
                output << "Dia/Horario:;" + schtime->value(1).toString() + ";"+ schtime->value(2).toString() + ";" << endl << endl;
                output << "Nome;E-mail;Telefone;" << endl;
                qry->prepare("SELECT Donor.id, name, email, phone FROM Donor, DonorSchedule WHERE DonorSchedule.donationTimeID = '"+schtime->value(0).toString()+"' AND DonorSchedule.donorID = Donor.id GROUP BY Donor.name;");
                qry->exec();
                qDebug() << qry->executedQuery();
                while (this->qry->next()) {
                    name = qry->value(1).toString();

                    email = qry->value(2).toString();

                    phone = qry->value(3).toString();

                    //qDebug() << name << email << phone;
                    output << name +";"+email+";"+ phone + ";" << endl;
                }
                output << endl << endl;
            }


    }
}

void Report::on_comboBox_8_currentIndexChanged(const QString &arg1)
{
    qry->prepare("SELECT scheduledDate FROM DonationTime WHERE bloodDriveID = (SELECT id FROM BloodDrive WHERE name LIKE '"+ arg1 + "' ORDER BY id DESC) GROUP BY scheduledDate;");
    qry->exec();
    modal = new QSqlQueryModel();
    modal->setQuery(*qry);
    ui->comboBox_9->setModel(modal);
}
