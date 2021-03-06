#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopWidget>
#include <QSql>
#include <QSqlDatabase>
#include <QtSql>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QStringList>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_2->setEnabled(false);
    ui->comboBox_2->clear();
    ui->comboBox_5->clear();

    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("sangueDB.db");
    mydb.open();

/********** magic **********/

    QSqlQuery* qry = new QSqlQuery(mydb);
    qry->prepare("SELECT name FROM BloodDrive ORDER BY id");
    if (qry->exec())
    {
        while (qry->next())
        {
            ui->comboBox_3->addItem(qry->value(0).toString());
        }
    }


    fillDays();
    ui->comboBox_2->setCurrentIndex(0); //set the first day available = “clear”
    QString myDate = ui->comboBox_2->currentText();
    prepareCombos(myDate); //prepares the hours available for the first day

/**********\magic **********/


    setStyleSheet("background-image: url(:/image/data/sangue.png);font-family : Arial, Helvetica, 'Nimbus Sans L'', 'Liberation Sans'', FreeSans, Sans-serif; font-size:13px");

}

MainWindow::~MainWindow()
{
    mydb.close();
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
    QString myDate = ui->comboBox_2->currentText(); //the last day from sign up
    checkDate(myDate);
    ui->comboBox_2->setCurrentIndex(0);
    myDate = ui->comboBox_2->currentText();
    prepareCombos(myDate);
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
int MainWindow::getMajor()  //returns the ID, but QString or int?
{
    QSqlQuery qry;
    QSqlQuery qry2;
    int ret;
    if(ui->comboBox_8->currentText()== "Outro")
    {
        qry.prepare("INSERT INTO Major (listedName,inputName) VALUES ('Outro',:outro)");
        qry.bindValue(":outro",ui->lineEdit_2->text());
        qry.exec();
        if (qry2.exec("SELECT MAX (id) FROM Major"))
        {
            ret = qry2.value(0).toInt();
            return ret;
        }
    }
    else
        qry2.prepare("SELECT id FROM Major WHERE listedName = '"+ui->comboBox_8->currentText()+"'");
        if (qry2.exec())
        {
            while (qry2.next())
            {
                ret = qry2.value(0).toInt();
                return ret;
            }
        }
    return -1;   //error case
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
void MainWindow::saveDonorInfo()
{
    QString name, email, phone, semester, obs, date, time;
    int major,donationTimeID, donorID;
    QSqlQuery qry1;
    QSqlQuery qry2;
    QSqlQuery qry3;
    QSqlQuery qry4;
    name = ui->lineEdit->text();
    email = ui->lineEdit_4->text();
    phone = ui->lineEdit_3->text();
    major = getMajor();
    semester = ui->comboBox->currentText();
    obs = ui->textEdit->toPlainText();
    qry1.prepare("INSERT INTO Donor (majorID,name,email,phone,semester,obs) VALUES ("+QString::number(major)+",'"+name+"','"+email+"','"+phone+"','"+semester+"','"+obs+"');");
    qry1.exec();
    date = ui->comboBox_2->currentText();
    time = ui->comboBox_5->currentText();
    qry2.prepare("SELECT id FROM DonationTime WHERE scheduledDate = '"+date+"' AND scheduledTime = '"+time+"'");
    if (qry2.exec())
    {
        while (qry2.next())
        {
            donationTimeID = qry2.value(0).toInt();  //ou = <<(msm duvida sempre =/)
        }
    }
    donorID=0;
    qry3.prepare("SELECT MAX (id) FROM Donor");
    if (qry3.exec()) //last Donor
    {
        while (qry3.next())
        {
            donorID = qry3.value(0).toInt();
        }
    }
    int DonorScheduleID=0;
    QSqlQuery query;
    if(query.exec("SELECT MAX (id) FROM DonorSchedule"))
    {
        while (query.next())
        {
            DonorScheduleID = query.value(0).toInt()+1;
        }
    }
    qry4.prepare("INSERT INTO DonorSchedule (id, donationTimeID, donorID) VALUES ("+QString::number(DonorScheduleID)+","+QString::number(donationTimeID)+","+QString::number(donorID)+")");
    qry4.exec();
}

//criados:

bool MainWindow::checkDate(QString date)
{
    QString strTime;
    for (int time = 8; time<14; time++)
    {
        strTime = QString::number(time) + ":00";
        if (maxPeople(date,strTime)>countPeople(date,strTime))
        {
            return true;
        }
    }
    return false;
}

int MainWindow::countPeople(QString date, QString time)
{
    QSqlQuery qry;
    int DonationTimeID;
    qry.prepare("SELECT id FROM DonationTime WHERE scheduledDate = '"+date+"' AND scheduledTime = '"+time+"'");
    int count = 0;
    if (qry.exec())
    {
        while (qry.next())
        {
            DonationTimeID = qry.value(0).toInt();
        }
    }
    if (qry.exec("SELECT COUNT (*) FROM DonorSchedule WHERE donationTimeID = "+QString::number(DonationTimeID)))
    {
        while (qry.next())
        {
            count = qry.value(0).toInt();
        }
    }
    return count;
}

int MainWindow::maxPeople(QString date, QString time)
{
    QSqlQuery qry;
    int max = 0;
    if (qry.exec("SELECT maxDonors FROM DonationTime WHERE scheduledDate = '"+date+"' AND scheduledTime = '"+time+"'"))
    {
        while(qry.next())
        {
            max = qry.value(0).toInt();
        }
    }
    return max;
}

void MainWindow::prepareCombos(QString date)
{
    ui->comboBox_5->clear();
    QString strTime;
    for (int time=8; time<14; time++)
    {
        strTime = QString::number(time)+":00";
        if (countPeople(date,strTime)<maxPeople(date,strTime))
        {
            ui->comboBox_5->addItem(strTime);
        }
    }
    checkDate(date);
    return;
}

void MainWindow::fillDays()
{
    ui->comboBox_2->clear();
    QSqlQuery qryaux1;
    QSqlQuery qryaux2;
    QSqlQuery qryaux3;
    QSqlQuery qryaux4;
    QSqlQuery qry1;
    QSqlQuery qry2;
    QString scheduledDate;
    qryaux1.prepare("CREATE TABLE allDates (scheduledDate TEXT);");
    qryaux1.exec();
    qryaux2.prepare("INSERT INTO allDates (scheduledDate) SELECT DISTINCT scheduledDate FROM DonationTime WHERE bloodDriveID = "+QString::number(ui->comboBox_3->currentIndex())+" GROUP BY scheduledDate");   //:bloodDriveID)");
    qryaux2.exec();
    int count=0;
    qryaux3.prepare("SELECT COUNT (*) FROM allDates;");
    if (qryaux3.exec())
    {
        while (qryaux3.next())
        {
            count = qryaux3.value(0).toInt();
        }
    }
    while (count)
    {
        qry1.prepare("SELECT scheduledDate FROM allDates LIMIT 1;");
        if (qry1.exec())
        {
            while (qry1.next())
            {
                scheduledDate = qry1.value(0).toString(); //ou <<
            }
        }
        if (checkDate(scheduledDate))
        {
            ui->comboBox_2->addItem(scheduledDate);
        }
        qry2.prepare("DELETE FROM allDates WHERE scheduledDate = '"+scheduledDate+"'");
        qry2.exec();
        count--;
    }
    qryaux4.exec("DROP TABLE allDates;");
}

int MainWindow::find(QString& date, QComboBox *&combo)
{
    for (int index = 0; index<combo->count();index++)
    {
        if (combo->itemData(index).toString()==date)
            return index;
    }
    return -1;  //error case
}


void MainWindow::on_comboBox_3_currentIndexChanged(int index)
{
    fillDays();
}

void MainWindow::on_comboBox_2_currentIndexChanged(int index)
{
    prepareCombos(ui->comboBox_2->itemText(index));  //considerando que é possivel acessar o elemento da comboBox assim. Pode ser [] etc();
}

void MainWindow::on_comboBox_5_currentTextChanged(const QString &arg1)
{
    if (!checkDate(ui->comboBox_2->currentText()))
    {
        ui->comboBox_2->removeItem(ui->comboBox_2->currentIndex());
    }
}
