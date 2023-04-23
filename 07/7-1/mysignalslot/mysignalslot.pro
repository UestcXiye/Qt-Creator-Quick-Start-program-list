#-------------------------------------------------
#
# Project created by QtCreator 2023-04-13T20:31:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mysignalslot
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    mydialog.cpp

HEADERS  += widget.h \
    mydialog.h

FORMS    += widget.ui \
    mydialog.ui
