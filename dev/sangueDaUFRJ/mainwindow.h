#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mainmenu.h"
#include "qstring.h"
#include <QSqlDatabase>
#include <QComboBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void closeEvent(QCloseEvent *);

    void on_comboBox_8_currentTextChanged(const QString &arg1);

    void on_comboBox_3_currentIndexChanged(int index);

    void on_comboBox_2_currentIndexChanged(int index);

    void on_comboBox_5_currentTextChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QMainWindow *appmenu;
    int getMajor();
    QSqlDatabase mydb;
    void saveDonorInfo();
    //modificações
    bool checkDate(QString date);
    int countPeople(QString date, QString time);
    int maxPeople(QString date, QString time);
    void prepareCombos(QString date);
    void fillDays();
    int find(QString &date, QComboBox *&combo);
    //\modificações
};

#endif // MAINWINDOW_H
