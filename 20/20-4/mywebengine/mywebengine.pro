QT += core gui
QT += webenginewidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mywebengine
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    webview.cpp

HEADERS  += mainwindow.h \
    webview.h

FORMS    += mainwindow.ui
