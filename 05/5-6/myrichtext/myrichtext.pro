#-------------------------------------------------
#
# Project created by QtCreator 2023-03-30T20:12:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = myrichtext
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mysyntaxhighlighter.cpp

HEADERS  += mainwindow.h \
    mysyntaxhighlighter.h

FORMS    += mainwindow.ui
