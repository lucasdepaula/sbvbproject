/********************************************************************************
** Form generated from reading UI file 'report.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORT_H
#define UI_REPORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Report
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QPushButton *pushButton_2;
    QComboBox *comboBox_8;
    QLabel *label_3;
    QComboBox *comboBox_9;

    void setupUi(QWidget *Report)
    {
        if (Report->objectName().isEmpty())
            Report->setObjectName(QStringLiteral("Report"));
        Report->resize(480, 485);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Report->sizePolicy().hasHeightForWidth());
        Report->setSizePolicy(sizePolicy);
        Report->setMinimumSize(QSize(480, 485));
        Report->setMaximumSize(QSize(480, 485));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/data/icon_sangue.ico"), QSize(), QIcon::Normal, QIcon::Off);
        Report->setWindowIcon(icon);
        pushButton = new QPushButton(Report);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(205, 430, 70, 23));
        pushButton->setMinimumSize(QSize(0, 0));
        label = new QLabel(Report);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(35, 30, 410, 31));
        label->setAutoFillBackground(false);
        label->setStyleSheet(QStringLiteral("background:transparent;"));
        pushButton_2 = new QPushButton(Report);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(205, 210, 70, 23));
        comboBox_8 = new QComboBox(Report);
        comboBox_8->setObjectName(QStringLiteral("comboBox_8"));
        comboBox_8->setGeometry(QRect(30, 160, 301, 20));
        QFont font;
        font.setFamily(QStringLiteral("Helvetica Neue"));
        font.setPointSize(13);
        font.setBold(false);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(50);
        comboBox_8->setFont(font);
        comboBox_8->setStyleSheet(QStringLiteral(""));
        label_3 = new QLabel(Report);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 110, 141, 16));
        label_3->setStyleSheet(QStringLiteral("background:transparent;"));
        comboBox_9 = new QComboBox(Report);
        comboBox_9->setObjectName(QStringLiteral("comboBox_9"));
        comboBox_9->setGeometry(QRect(340, 160, 111, 21));

        retranslateUi(Report);

        QMetaObject::connectSlotsByName(Report);
    } // setupUi

    void retranslateUi(QWidget *Report)
    {
        Report->setWindowTitle(QApplication::translate("Report", "Gerar Relat\303\263rio - SangueUFRJ", 0));
        pushButton->setText(QApplication::translate("Report", "Voltar", 0));
        label->setText(QApplication::translate("Report", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-weight:600;\">GERAR RELAT\303\223RIO DE MUTIR\303\203O</span></p></body></html>", 0));
        pushButton_2->setText(QApplication::translate("Report", "Salvar", 0));
        comboBox_8->clear();
        comboBox_8->insertItems(0, QStringList()
         << QApplication::translate("Report", "Engenharia de Computa\303\247\303\243o e Informa\303\247\303\243o", 0)
        );
        label_3->setText(QApplication::translate("Report", "<html><head/><body><p><span style=\" font-size:12pt;\">Nome do mutir\303\243o:</span></p></body></html>", 0));
        comboBox_9->clear();
        comboBox_9->insertItems(0, QStringList()
         << QApplication::translate("Report", "01/01/2015", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class Report: public Ui_Report {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORT_H
