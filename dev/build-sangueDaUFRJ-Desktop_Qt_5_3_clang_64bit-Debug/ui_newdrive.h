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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewDrive
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QLabel *label;
    QDateTimeEdit *dateTimeEdit;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QDateTimeEdit *dateTimeEdit_2;
    QCheckBox *checkBox_3;
    QDateTimeEdit *dateTimeEdit_3;
    QCheckBox *checkBox_4;
    QDateTimeEdit *dateTimeEdit_4;
    QCheckBox *checkBox_5;
    QDateTimeEdit *dateTimeEdit_5;
    QCheckBox *checkBox_6;
    QDateTimeEdit *dateTimeEdit_6;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
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
        label->setStyleSheet(QStringLiteral("background:transparent;"));
        dateTimeEdit = new QDateTimeEdit(centralwidget);
        dateTimeEdit->setObjectName(QStringLiteral("dateTimeEdit"));
        dateTimeEdit->setGeometry(QRect(120, 100, 141, 24));
        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(290, 100, 89, 20));
        checkBox->setStyleSheet(QStringLiteral("background:transparent;"));
        checkBox_2 = new QCheckBox(centralwidget);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(290, 150, 89, 20));
        checkBox_2->setStyleSheet(QStringLiteral("background:transparent;"));
        dateTimeEdit_2 = new QDateTimeEdit(centralwidget);
        dateTimeEdit_2->setObjectName(QStringLiteral("dateTimeEdit_2"));
        dateTimeEdit_2->setGeometry(QRect(120, 150, 141, 24));
        checkBox_3 = new QCheckBox(centralwidget);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
        checkBox_3->setGeometry(QRect(290, 200, 89, 20));
        checkBox_3->setStyleSheet(QStringLiteral("background:transparent;"));
        dateTimeEdit_3 = new QDateTimeEdit(centralwidget);
        dateTimeEdit_3->setObjectName(QStringLiteral("dateTimeEdit_3"));
        dateTimeEdit_3->setGeometry(QRect(120, 200, 141, 24));
        checkBox_4 = new QCheckBox(centralwidget);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));
        checkBox_4->setGeometry(QRect(290, 250, 89, 20));
        checkBox_4->setStyleSheet(QStringLiteral("background:transparent;"));
        dateTimeEdit_4 = new QDateTimeEdit(centralwidget);
        dateTimeEdit_4->setObjectName(QStringLiteral("dateTimeEdit_4"));
        dateTimeEdit_4->setGeometry(QRect(120, 250, 141, 24));
        checkBox_5 = new QCheckBox(centralwidget);
        checkBox_5->setObjectName(QStringLiteral("checkBox_5"));
        checkBox_5->setGeometry(QRect(290, 300, 89, 20));
        checkBox_5->setStyleSheet(QStringLiteral("background:transparent;"));
        dateTimeEdit_5 = new QDateTimeEdit(centralwidget);
        dateTimeEdit_5->setObjectName(QStringLiteral("dateTimeEdit_5"));
        dateTimeEdit_5->setGeometry(QRect(120, 300, 141, 24));
        checkBox_6 = new QCheckBox(centralwidget);
        checkBox_6->setObjectName(QStringLiteral("checkBox_6"));
        checkBox_6->setGeometry(QRect(290, 350, 89, 20));
        checkBox_6->setStyleSheet(QStringLiteral("background:transparent;"));
        dateTimeEdit_6 = new QDateTimeEdit(centralwidget);
        dateTimeEdit_6->setObjectName(QStringLiteral("dateTimeEdit_6"));
        dateTimeEdit_6->setGeometry(QRect(120, 350, 141, 24));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 430, 141, 23));
        pushButton_2->setStyleSheet(QStringLiteral(""));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(320, 430, 141, 23));
        pushButton_3->setStyleSheet(QStringLiteral(""));
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
        label->setText(QApplication::translate("NewDrive", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-weight:600;\">CADASTRAR NOVA DATA DE MUTIR\303\203O</span></p></body></html>", 0));
        checkBox->setText(QApplication::translate("NewDrive", "Incluir", 0));
        checkBox_2->setText(QApplication::translate("NewDrive", "Incluir", 0));
        checkBox_3->setText(QApplication::translate("NewDrive", "Incluir", 0));
        checkBox_4->setText(QApplication::translate("NewDrive", "Incluir", 0));
        checkBox_5->setText(QApplication::translate("NewDrive", "Incluir", 0));
        checkBox_6->setText(QApplication::translate("NewDrive", "Incluir", 0));
        pushButton_2->setText(QApplication::translate("NewDrive", "Salvar e criar pr\303\263ximo", 0));
        pushButton_3->setText(QApplication::translate("NewDrive", "Salvar e finalizar", 0));
    } // retranslateUi

};

namespace Ui {
    class NewDrive: public Ui_NewDrive {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWDRIVE_H
