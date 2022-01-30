QT += core gui

TEMPLATE = lib
TARGET = qtcurl

HEADERS += src/QtCUrl.h
SOURCES += src/QtCUrl.cpp

LIBS += -lcurl
