#-------------------------------------------------
#
# Project created by QtCreator 2017-01-21T19:13:16
#
#-------------------------------------------------

QT       += core gui
QT       += xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SwashUI
TEMPLATE = app


SOURCES += main.cpp\
        swashuiadmin.cpp \
    swashuicustomer.cpp \
    communication.cpp \
    garment.cpp \
    customer.cpp \
    xmlfilehandler.cpp \
    swashadmin.cpp \
    swashcustomer.cpp

HEADERS  += swashuiadmin.h \
    swashuicustomer.h \
    communication.h \
    garment.h \
    customer.h \
    xmlfilehandler.h \
    swashadmin.h \
    swashcustomer.h

FORMS    += swashuiadmin.ui \
    swashuicustomer.ui
