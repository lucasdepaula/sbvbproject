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
#include <QtWidgets/QHeaderView>
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
        NewDrive->setCentralWidget(centralwidget);
        menubar = new QMenuBar(NewDrive);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 480, 25));
        NewDrive->setMenuBar(menubar);

        retranslateUi(NewDrive);

        QMetaObject::connectSlotsByName(NewDrive);
    } // setupUi

    void retranslateUi(QMainWindow *NewDrive)
    {
        NewDrive->setWindowTitle(QApplication::translate("NewDrive", "Novo Mutir\303\243o - Sangue UFRJ", 0));
        pushButton->setText(QApplication::translate("NewDrive", "Voltar", 0));
    } // retranslateUi

};

namespace Ui {
    class NewDrive: public Ui_NewDrive {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWDRIVE_H
