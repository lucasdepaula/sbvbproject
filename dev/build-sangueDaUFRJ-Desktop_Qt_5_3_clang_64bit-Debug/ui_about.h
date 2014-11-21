/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_About
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_5;

    void setupUi(QWidget *About)
    {
        if (About->objectName().isEmpty())
            About->setObjectName(QStringLiteral("About"));
        About->resize(480, 485);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(About->sizePolicy().hasHeightForWidth());
        About->setSizePolicy(sizePolicy);
        About->setMinimumSize(QSize(480, 485));
        About->setMaximumSize(QSize(480, 485));
        pushButton = new QPushButton(About);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(205, 430, 70, 23));
        pushButton->setMinimumSize(QSize(0, 0));
        label = new QLabel(About);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 30, 361, 31));
        label->setAutoFillBackground(false);
        label->setStyleSheet(QStringLiteral("background:transparent;"));
        label_5 = new QLabel(About);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(60, 80, 361, 351));
        label_5->setStyleSheet(QStringLiteral("background:transparent;"));
        label_5->setWordWrap(true);

        retranslateUi(About);

        QMetaObject::connectSlotsByName(About);
    } // setupUi

    void retranslateUi(QWidget *About)
    {
        About->setWindowTitle(QApplication::translate("About", "Sobre - SangueUFRJ", 0));
        pushButton->setText(QApplication::translate("About", "Voltar", 0));
        label->setText(QApplication::translate("About", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-weight:600;\">SOBRE</span></p></body></html>", 0));
        label_5->setText(QApplication::translate("About", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">SangueUFRJ foi desenvolvido com o intuito de atingir o maior n\303\272mero de pessoas na doa\303\247\303\243o de sangue para o hospital universit\303\241rio (HUCFF), auxiliando na organiza\303\247\303\243o de mutir\303\265es pelo c\303\242mpus.<br/></span></p><p align=\"center\"><span style=\" font-size:12pt;\"><br/></span></p><p align=\"center\"><span style=\" font-size:12pt;\">Alunos Envolvidos @ECI</span></p><p align=\"center\"><span style=\" font-size:12pt;\">Igor Rocha, Lucas Cabral, Lucas Santos, Rafael Damasceno, Thiago Maia</span></p><p align=\"center\"><span style=\" font-size:12pt;\"><br/><br/></span></p><p align=\"center\"><span style=\" font-size:12pt;\">vers\303\243o 1.0.0</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class About: public Ui_About {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
