#-------------------------------------------------
#
# Project created by QtCreator 2015-12-09T16:22:19
#
#-------------------------------------------------

QT       -= core gui

TARGET = lib_cpp
TEMPLATE = lib
CONFIG += staticlib

QMAKE_CFLAGS += -std=c++11

SOURCES += \
    exchange.cpp \
    queens.cpp \
    long_division.cpp \
    matrix.cpp \
    text.cpp

HEADERS += \
    exchange.h \
    queens.h \
    long_division.h \
    matrix.h \
    text.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
