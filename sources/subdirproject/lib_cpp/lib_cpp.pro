#-------------------------------------------------
#
# Project created by QtCreator 2015-12-09T16:22:19
#
#-------------------------------------------------

QT       -= core gui

TARGET = lib_cpp
TEMPLATE = lib
CONFIG += staticlib

QMAKE_CXXFLAGS += -std=c++11

SOURCES += \
    table.cpp \
    queens.cpp \
    matrix.cpp \
    text.cpp \
    longDivision.cpp \
    setOfCoins.cpp

HEADERS += \
    table.h \
    queens.h \
    matrix.h \
    text.h \
    longDivision.h \
    setOfCoins.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
