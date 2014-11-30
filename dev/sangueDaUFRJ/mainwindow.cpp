#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopWidget>
#include <QSql>
#include <QSqlDatabase>
#include <QtSql>
#include <QSqlQuery>
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

//    QSqlQueryModel * modal = new QSqlQueryModel();
//    //db must be opened -> I considered it will be opened by MainMenu. Otherwise, here is the place for "open()" method
//    QSqlQuery* qry = new QSqlQuery(mydb);  //mydb is the database
//    qry->prepare("select date from DonationTime");
//    qry->exec();
//    modal->setQuery(*qry);
//    ui->comboBox_2->setModel(modal);
//    qry->prepare("select time from DonationTime");    //I wonder if this repetition of the code works, I guess so
//    qry->exec();
//    modal->setQuery(*qry);
//    ui->comboBox_5->setModel(modal);

//    //you may close the db here if you want


    fillDays();
    ui->comboBox_2->setCurrentIndex(0); //set the first day available = “clear”
    QString myDate = ui->comboBox_2->currentText();
    prepareCombos(myDate); //prepares the hours available for the first day

/**********\magic **********/



//    QStringList testList;
//    testList << "Hello" <<"teste";
//    ui->comboBox_2->addItems(testList);
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
            ret = qry.value(0).toInt();
            return ret;
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
    QString major, name, email, phone, semester, obs, date, time, donationTimeID, donorID;
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
    qry1.prepare("INSERT INTO Donor (major,name,email,phone,semester,obs) VALUES ('"+major+"','"+name+"','"+email+"','"+phone+"','"+semester+"','"+obs+"');");
    qry1.exec();
    date = ui->comboBox_2->currentText();
    time = ui->comboBox_5->currentText();
    qry2.prepare("SELECT id FROM DonationTime WHERE scheduledDate = '"+date+"' AND scheduledTime = '"+time+"'");
    if (qry2.exec())
    {
        while (qry2.next())
        {
            donationTimeID = qry2.value(0).toString();  //ou = <<(msm duvida sempre =/)
        }
    }
    qry3.prepare("SELECT MAX (id) FROM Donor");
    if (qry3.exec()) //last Donor
    {
        while (qry3.next())
        {
            donorID = qry3.value(0).toString();
        }
    }
    qry4.prepare("INSERT INTO DonorSchedule (donationTimeID, donorID) VALUES (:donationTimeID,:donorID)");
    qry4.bindValue(":donationTimeID",donationTimeID);
    qry4.bindValue(":donorID", donorID);
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
            return true;
    }
    ui->comboBox_2->removeItem(find(date,ui->comboBox_2));
    return false;
}

int MainWindow::countPeople(QString date, QString time)
{
    QSqlQuery qry;
    qry.prepare("SELECT COUNT (*) FROM Donor WHERE scheduledDate = '"+date+"' AND scheduledTime = '"+time+"'");
    qry.exec();
    int count = 0;
    if (qry.next())
        count = qry.value(0).toInt(); //pode não funcionar (será que é = mesmo ou seria += ou <<)?
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
            max = qry.value(0).toInt();  //talves tenha que ser <<
        }
    }
    return max;
}

void MainWindow::prepareCombos(QString date)
{
    QString strTime;
    for (int time=8; time<14; time++)
    {
        strTime = QString::number(time)+":00";
        if (countPeople(date,strTime)<maxPeople(date,strTime))
            ui->comboBox_5->addItem(strTime);
    }
    checkDate(date);
    return;
}

void MainWindow::fillDays()
{
    QSqlQuery qryaux1;
    QSqlQuery qryaux2;
    QSqlQuery qryaux3;
    QSqlQuery qryaux4;
    QSqlQuery qry1;
    QSqlQuery qry2;
    QString scheduledDate;
    qryaux1.prepare("CREATE TABLE allDates (scheduledDate TEXT);");
    qryaux1.exec();
    qryaux2.prepare("INSERT INTO allDates SELECT scheduledDate FROM DonationTime WHERE bloodDriveID =:bloodDriveID ;");
    qryaux2.bindValue(":bloodDriveID",ui->comboBox_3->currentIndex());
    qryaux2.exec();
    //agora vem a parte duvidosa. Farei do jeito que eu acho que é
    int count=0;
    qryaux3.prepare("SELECT COUNT (*) FROM allDates;");
    if (qryaux3.exec())
    {
        while (qryaux3.next())
        {
            count = qryaux3.value(0).toInt();  //talvez << ou += etc (depende do real funcionamento desses métodos)
        }
    }
    while (count)
    {
        qry1.prepare("SELECT scheduledDate FROM allDates LIMIT 1;");
        qry1.exec();
        if (qry1.exec())
            scheduledDate = qry1.value(0).toInt(); //ou <<
        if (checkDate(scheduledDate))
            ui->comboBox_2->addItem(scheduledDate);
        qry2.prepare("DELETE scheduledDate FROM allDates WHERE scheduledDate = '"+scheduledDate+"'");
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
    prepareCombos(ui->comboBox_2->currentText());
}

void MainWindow::on_comboBox_2_currentIndexChanged(int index)
{
    prepareCombos(ui->comboBox_2->itemData(index).toString());  //considerando que é possivel acessar o elemento da comboBox assim. Pode ser [] etc();
}
