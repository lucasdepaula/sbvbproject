/********************************************************************************
** Form generated from reading UI file 'newdrive.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWDRIVE_H
#define UI_NEWDRIVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewDrive
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QLabel *label;
    QPushButton *pushButton_3;
    QDateEdit *dateEdit;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QPushButton *pushButton_4;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QListWidget *listWidget;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox_3;
    QSpinBox *spinBox_4;
    QSpinBox *spinBox_5;
    QSpinBox *spinBox_6;
    QMenuBar *menubar;

    void setupUi(QMainWindow *NewDrive)
    {
        if (NewDrive->objectName().isEmpty())
            NewDrive->setObjectName(QStringLiteral("NewDrive"));
        NewDrive->resize(480, 485);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(NewDrive->sizePolicy().hasHeightForWidth());
        NewDrive->setSizePolicy(sizePolicy);
        NewDrive->setMinimumSize(QSize(480, 485));
        NewDrive->setMaximumSize(QSize(480, 485));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/data/icon_sangue.ico"), QSize(), QIcon::Normal, QIcon::Off);
        NewDrive->setWindowIcon(icon);
        NewDrive->setStyleSheet(QStringLiteral(""));
        centralwidget = new QWidget(NewDrive);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(205, 430, 70, 23));
        pushButton->setMinimumSize(QSize(0, 0));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 30, 460, 31));
        label->setAutoFillBackground(false);
        label->setStyleSheet(QStringLiteral("background: transparent;"));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(320, 430, 141, 23));
        pushButton_3->setStyleSheet(QStringLiteral(""));
        dateEdit = new QDateEdit(centralwidget);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(80, 150, 110, 22));
        dateEdit->setAutoFillBackground(false);
        dateEdit->setFrame(true);
        dateEdit->setDateTime(QDateTime(QDate(2015, 1, 1), QTime(8, 0, 0)));
        dateEdit->setCurrentSection(QDateTimeEdit::DaySection);
        dateEdit->setCalendarPopup(true);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 150, 51, 21));
        label_2->setStyleSheet(QStringLiteral("background: transparent;"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 100, 161, 21));
        label_3->setStyleSheet(QStringLiteral("background: transparent;"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(170, 100, 251, 20));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(200, 260, 71, 81));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 200, 171, 21));
        label_4->setStyleSheet(QStringLiteral("background: transparent;"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(60, 230, 61, 21));
        label_5->setStyleSheet(QStringLiteral("background: transparent;"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(60, 260, 61, 21));
        label_6->setStyleSheet(QStringLiteral("background: transparent;"));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(50, 290, 61, 21));
        label_7->setStyleSheet(QStringLiteral("background: transparent;"));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(50, 320, 61, 21));
        label_8->setStyleSheet(QStringLiteral("background: transparent;"));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(50, 350, 61, 21));
        label_9->setStyleSheet(QStringLiteral("background: transparent;"));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(50, 380, 61, 21));
        label_10->setStyleSheet(QStringLiteral("background: transparent;"));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(300, 230, 121, 171));
        listWidget->setStyleSheet(QStringLiteral("background: transparent;"));
        listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(130, 230, 42, 22));
        spinBox->setValue(10);
        spinBox_2 = new QSpinBox(centralwidget);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setGeometry(QRect(130, 260, 42, 22));
        spinBox_2->setValue(0);
        spinBox_3 = new QSpinBox(centralwidget);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));
        spinBox_3->setGeometry(QRect(130, 290, 42, 22));
        spinBox_3->setValue(10);
        spinBox_4 = new QSpinBox(centralwidget);
        spinBox_4->setObjectName(QStringLiteral("spinBox_4"));
        spinBox_4->setGeometry(QRect(130, 320, 42, 22));
        spinBox_4->setValue(0);
        spinBox_5 = new QSpinBox(centralwidget);
        spinBox_5->setObjectName(QStringLiteral("spinBox_5"));
        spinBox_5->setGeometry(QRect(130, 350, 42, 22));
        spinBox_5->setValue(7);
        spinBox_6 = new QSpinBox(centralwidget);
        spinBox_6->setObjectName(QStringLiteral("spinBox_6"));
        spinBox_6->setGeometry(QRect(130, 380, 42, 22));
        spinBox_6->setValue(0);
        NewDrive->setCentralWidget(centralwidget);
        menubar = new QMenuBar(NewDrive);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 480, 21));
        NewDrive->setMenuBar(menubar);

        retranslateUi(NewDrive);

        QMetaObject::connectSlotsByName(NewDrive);
    } // setupUi

    void retranslateUi(QMainWindow *NewDrive)
    {
        NewDrive->setWindowTitle(QApplication::translate("NewDrive", "Novo Mutir\303\243o - Sangue UFRJ", 0));
        pushButton->setText(QApplication::translate("NewDrive", "Voltar", 0));
        label->setText(QApplication::translate("NewDrive", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-weight:600;\">CADASTRAR NOVO MUTIR\303\203O</span></p></body></html>", 0));
        pushButton_3->setText(QApplication::translate("NewDrive", "Salvar e finalizar", 0));
        label_2->setText(QApplication::translate("NewDrive", "<html><head/><body><p><span style=\" font-size:12pt;\">Data:</span></p></body></html>", 0));
        label_3->setText(QApplication::translate("NewDrive", "<html><head/><body><p><span style=\" font-size:12pt;\">Nome do mutir\303\243o:</span></p></body></html>", 0));
        pushButton_4->setText(QApplication::translate("NewDrive", "Adicionar\n"
">>>", 0));
        label_4->setText(QApplication::translate("NewDrive", "<html><head/><body><p><span style=\" font-size:12pt;\">Doadores por hor\303\241rio:</span></p></body></html>", 0));
        label_5->setText(QApplication::translate("NewDrive", "<html><head/><body><p><span style=\" font-size:12pt;\">8:00 h</span></p></body></html>", 0));
        label_6->setText(QApplication::translate("NewDrive", "<html><head/><body><p><span style=\" font-size:12pt;\">9:00 h</span></p></body></html>", 0));
        label_7->setText(QApplication::translate("NewDrive", "<html><head/><body><p><span style=\" font-size:12pt;\">10:00 h</span></p></body></html>", 0));
        label_8->setText(QApplication::translate("NewDrive", "<html><head/><body><p><span style=\" font-size:12pt;\">11:00 h</span></p></body></html>", 0));
        label_9->setText(QApplication::translate("NewDrive", "<html><head/><body><p><span style=\" font-size:12pt;\">12:00 h</span></p></body></html>", 0));
        label_10->setText(QApplication::translate("NewDrive", "<html><head/><body><p><span style=\" font-size:12pt;\">13:00 h</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class NewDrive: public Ui_NewDrive {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWDRIVE_H
