#-------------------------------------------------
#
# Project created by QtCreator 2015-10-23T09:29:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Calculator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    lexicalanalyzer.cpp \
    postfixnotation.cpp \
    controller.cpp

HEADERS  += mainwindow.h \
    lexicalanalyzer.h \
    postfixnotation.h \
    controller.h

FORMS    += mainwindow.ui
