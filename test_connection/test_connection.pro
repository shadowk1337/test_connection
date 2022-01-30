QT       += core gui \
            network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
CONFIG += c++11
INCLUDEPATH += ../src

SOURCES += \
    ../src/main.cpp \
    ../src/testconnectionmainwindow.cpp \
    ../src/testnetworkmanager.cpp

HEADERS += \
    ../src/testconnectionmainwindow.h \
    ../src/testnetworkmanager.h

FORMS += \
    ../src/testconnectionmainwindow.ui

include(../qtcurl/qtcurl.pri)
