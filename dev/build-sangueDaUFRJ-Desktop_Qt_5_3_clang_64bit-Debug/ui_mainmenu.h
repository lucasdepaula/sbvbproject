/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenu
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName(QStringLiteral("MainMenu"));
        MainMenu->resize(480, 485);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainMenu->sizePolicy().hasHeightForWidth());
        MainMenu->setSizePolicy(sizePolicy);
        MainMenu->setMinimumSize(QSize(480, 485));
        MainMenu->setMaximumSize(QSize(480, 485));
        centralwidget = new QWidget(MainMenu);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(90, 30, 301, 21));
        label->setAutoFillBackground(false);
        label->setStyleSheet(QStringLiteral("background:transparent;"));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(140, 110, 200, 41));
        pushButton_4->setStyleSheet(QStringLiteral("font: 15pt \"Helvetica Neue\";"));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(140, 190, 200, 41));
        pushButton_5->setStyleSheet(QStringLiteral("font: 15pt \"Helvetica Neue\";"));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(140, 270, 200, 41));
        pushButton_6->setStyleSheet(QStringLiteral("font: 15pt \"Helvetica Neue\";"));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(140, 350, 200, 41));
        pushButton_7->setStyleSheet(QStringLiteral("font: 15pt \"Helvetica Neue\";"));
        MainMenu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainMenu);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 480, 22));
        MainMenu->setMenuBar(menubar);

        retranslateUi(MainMenu);

        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QMainWindow *MainMenu)
    {
        MainMenu->setWindowTitle(QApplication::translate("MainMenu", "MainWindow", 0));
        label->setText(QApplication::translate("MainMenu", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-weight:600;\">SANGUE UFRJ</span></p></body></html>", 0));
        pushButton_4->setText(QApplication::translate("MainMenu", "Criar Nova Inscri\303\247\303\243o", 0));
        pushButton_5->setText(QApplication::translate("MainMenu", "Criar Novo Multir\303\243o", 0));
        pushButton_6->setText(QApplication::translate("MainMenu", "Gerar Relat\303\263rios", 0));
        pushButton_7->setText(QApplication::translate("MainMenu", "Sobre", 0));
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
