/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QComboBox *comboBox;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit_3;
    QLabel *label_6;
    QLineEdit *lineEdit_4;
    QLabel *label_7;
    QComboBox *comboBox_2;
    QComboBox *comboBox_5;
    QLabel *label_17;
    QTextEdit *textEdit;
    QComboBox *comboBox_8;
    QLineEdit *lineEdit_2;
    QLabel *label_18;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QPushButton *pushButton_3;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(480, 485);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(480, 485));
        MainWindow->setMaximumSize(QSize(480, 485));
        MainWindow->setAutoFillBackground(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(90, 200, 71, 20));
        comboBox->setStyleSheet(QStringLiteral(""));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 80, 46, 16));
        label_2->setStyleSheet(QStringLiteral("background:transparent;"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 120, 111, 16));
        label_3->setStyleSheet(QStringLiteral("background:transparent;"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(80, 80, 331, 20));
        lineEdit->setStyleSheet(QStringLiteral(""));
        lineEdit->setEchoMode(QLineEdit::Normal);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 200, 61, 16));
        QFont font;
        font.setFamily(QStringLiteral("Ubuntu"));
        label_4->setFont(font);
        label_4->setStyleSheet(QStringLiteral("background:transparent;"));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 240, 71, 16));
        label_5->setStyleSheet(QStringLiteral("background:transparent;"));
        lineEdit_3 = new QLineEdit(centralWidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(90, 240, 241, 20));
        lineEdit_3->setStyleSheet(QStringLiteral(""));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 280, 51, 16));
        label_6->setStyleSheet(QStringLiteral("background:transparent;"));
        lineEdit_4 = new QLineEdit(centralWidget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(90, 280, 141, 20));
        lineEdit_4->setStyleSheet(QStringLiteral(""));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 320, 141, 21));
        label_7->setStyleSheet(QStringLiteral("background:transparent;"));
        comboBox_2 = new QComboBox(centralWidget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(20, 360, 131, 20));
        comboBox_2->setStyleSheet(QStringLiteral(""));
        comboBox_5 = new QComboBox(centralWidget);
        comboBox_5->setObjectName(QStringLiteral("comboBox_5"));
        comboBox_5->setGeometry(QRect(20, 390, 131, 20));
        comboBox_5->setStyleSheet(QStringLiteral(""));
        label_17 = new QLabel(centralWidget);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(320, 320, 46, 13));
        label_17->setStyleSheet(QStringLiteral("background:transparent;"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(320, 340, 141, 81));
        textEdit->setStyleSheet(QStringLiteral(""));
        comboBox_8 = new QComboBox(centralWidget);
        comboBox_8->setObjectName(QStringLiteral("comboBox_8"));
        comboBox_8->setGeometry(QRect(130, 120, 281, 20));
        QFont font1;
        font1.setFamily(QStringLiteral("Helvetica Neue"));
        font1.setPointSize(13);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setUnderline(false);
        font1.setWeight(50);
        comboBox_8->setFont(font1);
        comboBox_8->setStyleSheet(QStringLiteral(""));
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(130, 160, 171, 20));
        lineEdit_2->setStyleSheet(QStringLiteral(""));
        label_18 = new QLabel(centralWidget);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(20, 160, 111, 21));
        label_18->setStyleSheet(QStringLiteral("background:transparent;"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 430, 141, 23));
        pushButton->setStyleSheet(QStringLiteral(""));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(320, 430, 141, 23));
        pushButton_2->setStyleSheet(QStringLiteral(""));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 30, 361, 31));
        label->setAutoFillBackground(false);
        label->setStyleSheet(QStringLiteral("background:transparent;"));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(205, 430, 70, 23));
        pushButton_3->setStyleSheet(QStringLiteral(""));
        MainWindow->setCentralWidget(centralWidget);
        comboBox->raise();
        label_2->raise();
        label_3->raise();
        lineEdit->raise();
        label_4->raise();
        label_5->raise();
        lineEdit_3->raise();
        label_6->raise();
        lineEdit_4->raise();
        label_7->raise();
        comboBox_2->raise();
        comboBox_5->raise();
        label_17->raise();
        comboBox_8->raise();
        lineEdit_2->raise();
        label_18->raise();
        textEdit->raise();
        pushButton->raise();
        pushButton_2->raise();
        label->raise();
        pushButton_3->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 480, 22));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Nova Inscri\303\247\303\243o - Sangue da UFRJ", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1\302\272", 0)
         << QApplication::translate("MainWindow", "2\302\272", 0)
         << QApplication::translate("MainWindow", "3\302\272", 0)
         << QApplication::translate("MainWindow", "4\302\272", 0)
         << QApplication::translate("MainWindow", "5\302\272", 0)
         << QApplication::translate("MainWindow", "6\302\272", 0)
         << QApplication::translate("MainWindow", "7 \302\272", 0)
         << QApplication::translate("MainWindow", "8\302\272", 0)
         << QApplication::translate("MainWindow", "9\302\272", 0)
         << QApplication::translate("MainWindow", "10\302\272", 0)
         << QApplication::translate("MainWindow", "Outro", 0)
        );
        label_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">Nome:</span></p></body></html>", 0));
        label_3->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">Curso/Fun\303\247\303\243o:</span></p></body></html>", 0));
        lineEdit->setInputMask(QString());
        lineEdit->setText(QString());
        lineEdit->setPlaceholderText(QApplication::translate("MainWindow", "Digite seu nome completo", 0));
        label_4->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">Per\303\255odo:</span></p></body></html>", 0));
        label_5->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">Telefone:</span></p></body></html>", 0));
        lineEdit_3->setText(QString());
        lineEdit_3->setPlaceholderText(QApplication::translate("MainWindow", "Usar somente n\303\272meros (DDD + n\303\272mero)", 0));
        label_6->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">E-mail:</span></p></body></html>", 0));
        lineEdit_4->setText(QString());
        lineEdit_4->setPlaceholderText(QApplication::translate("MainWindow", "UFRJ, se tiver", 0));
        label_7->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">Op\303\247\303\265es de Hor\303\241rio:</span></p></body></html>", 0));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Escolha o dia", 0)
         << QApplication::translate("MainWindow", "Dia 1", 0)
         << QApplication::translate("MainWindow", "Dia 2", 0)
         << QApplication::translate("MainWindow", "Dia 3", 0)
         << QApplication::translate("MainWindow", "Dia 4", 0)
         << QApplication::translate("MainWindow", "Dia 5", 0)
        );
        comboBox_5->clear();
        comboBox_5->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Escolha a hora", 0)
         << QApplication::translate("MainWindow", "8:00", 0)
         << QApplication::translate("MainWindow", "10:00", 0)
         << QApplication::translate("MainWindow", "12:00", 0)
        );
        label_17->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">OBS:</span></p></body></html>", 0));
        comboBox_8->clear();
        comboBox_8->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Engenharia de Computa\303\247\303\243o e Informa\303\247\303\243o", 0)
         << QApplication::translate("MainWindow", "Outro", 0)
        );
        label_18->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">Se outro, qual?</span></p></body></html>", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Salvar e criar pr\303\263ximo", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Salvar e finalizar", 0));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-weight:600;\">INSCRI\303\207\303\203O DE NOVO DOADOR</span></p></body></html>", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "Voltar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
