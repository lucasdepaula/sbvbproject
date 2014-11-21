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
        pushButton = new QPushButton(Report);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(205, 430, 70, 23));
        pushButton->setMinimumSize(QSize(0, 0));
        label = new QLabel(Report);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(35, 30, 410, 31));
        label->setAutoFillBackground(false);
        label->setStyleSheet(QStringLiteral("background:transparent;"));

        retranslateUi(Report);

        QMetaObject::connectSlotsByName(Report);
    } // setupUi

    void retranslateUi(QWidget *Report)
    {
        Report->setWindowTitle(QApplication::translate("Report", "Gerar Relat\303\263rio - SangueUFRJ", 0));
        pushButton->setText(QApplication::translate("Report", "Voltar", 0));
        label->setText(QApplication::translate("Report", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-weight:600;\">GERAR RELAT\303\223RIO DE MUTIR\303\203O</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class Report: public Ui_Report {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORT_H
