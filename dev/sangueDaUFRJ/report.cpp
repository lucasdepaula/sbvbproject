#include "report.h"
#include "ui_report.h"
#include <QDesktopWidget>
#include <QCloseEvent>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>

Report::Report(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Report)
{
    ui->setupUi(this);
    setStyleSheet("background-image: url(./sangue.png);font-family : Arial, Helvetica, 'Nimbus Sans L'', 'Liberation Sans'', FreeSans, Sans-serif; font-size:13px");
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
    QString filename = QFileDialog::getSaveFileName(this, "DialogTitle", "filename.csv", "CSV files (*.csv);;Zip files (*.zip, *.7z)", 0, 0); // getting the filename (full path)
    QFile data(filename);
    if(data.open(QFile::WriteOnly |QFile::Truncate))
    {
            QTextStream output(&data);
            output << "'csv';test'";
    }
}
