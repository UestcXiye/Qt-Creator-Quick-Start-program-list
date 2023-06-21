QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mythread
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    mythread.cpp

HEADERS  += dialog.h \
    mythread.h

FORMS    += dialog.ui
