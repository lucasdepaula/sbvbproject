#-------------------------------------------------
#
# Project created by QtCreator 2014-11-15T15:13:59
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sangueDaUFRJ
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mainmenu.cpp \
    newdrive.cpp \
    about.cpp \
    report.cpp \
    databasecreator.cpp

HEADERS  += mainwindow.h \
    mainmenu.h \
    newdrive.h \
    about.h \
    report.h \
    databasecreator.h

FORMS    += mainwindow.ui \
    mainmenu.ui \
    newdrive.ui \
    about.ui \
    report.ui

OTHER_FILES += \

RESOURCES += \
    ../Resource.qrc
