QT += core gui

TEMPLATE = lib
TARGET = qtcurl
DESTDIR = ../lib

HEADERS += src/QtCUrl.h
SOURCES += src/QtCUrl.cpp

LIBS += -lcurl
