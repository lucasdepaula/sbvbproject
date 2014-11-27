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
    QLabel *label_6;

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
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/data/icon_sangue.ico"), QSize(), QIcon::Normal, QIcon::Off);
        About->setWindowIcon(icon);
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
        label_5->setGeometry(QRect(80, 180, 321, 251));
        label_5->setStyleSheet(QStringLiteral("background:transparent;"));
        label_5->setWordWrap(true);
        label_6 = new QLabel(About);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(90, 80, 301, 151));
        label_6->setStyleSheet(QStringLiteral("background:transparent;"));
        label_6->setWordWrap(true);

        retranslateUi(About);

        QMetaObject::connectSlotsByName(About);
    } // setupUi

    void retranslateUi(QWidget *About)
    {
        About->setWindowTitle(QApplication::translate("About", "Sobre - SangueUFRJ", 0));
        pushButton->setText(QApplication::translate("About", "Voltar", 0));
        label->setText(QApplication::translate("About", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-weight:600;\">SOBRE</span></p></body></html>", 0));
        label_5->setText(QApplication::translate("About", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt;\">Trabalho desenvolvido na disciplina: </span></p><p align=\"center\"><span style=\" font-size:11pt;\">EEL 670 \342\200\223 Lingugens de Programa\303\247\303\243o</span></p><p align=\"center\"><span style=\" font-size:11pt;\">UFRJ \342\200\223 DEL -Departamento de Engenharia Eletr\303\264nica e de Computa\303\247\303\243o</span></p><p align=\"center\"><span style=\" font-size:11pt;\">Professor: Sergio Barbosa Villas-Boas (sbVB) www.sbvb.com.br</span></p><p align=\"center\"><span style=\" font-size:11pt;\">vers\303\243o 1.0.0</span></p></body></html>", 0));
        label_6->setText(QApplication::translate("About", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt;\">Alunos desenvolvedores:<br/>(Engenharia de Computa\303\247\303\243o e Informa\303\247\303\243o)</span></p><p align=\"center\"><span style=\" font-size:11pt;\">Igor Rocha, Lucas Cabral, Lucas Santos, Rafael Damasceno, Thiago Maia</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class About: public Ui_About {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
