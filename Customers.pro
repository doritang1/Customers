#-------------------------------------------------
#
# Project created by QtCreator 2015-08-13T10:23:32
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Customers
TEMPLATE = app


SOURCES += main.cpp\
        maindialog.cpp

HEADERS  += maindialog.h \
    initdb.h

FORMS    += maindialog.ui
