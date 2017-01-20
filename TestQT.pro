#-------------------------------------------------
#
# Project created by QtCreator 2016-11-30T08:32:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TestQT
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Customer.cpp \
    Communication.cpp \
    Garment.cpp

HEADERS  += mainwindow.h \
    Customer.h \
    Communication.h \
    Garment.h

FORMS    += mainwindow.ui
