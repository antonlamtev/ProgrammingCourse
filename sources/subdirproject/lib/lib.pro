#-------------------------------------------------
#
# Project created by QtCreator 2015-11-05T14:57:34
#
#-------------------------------------------------

QT       -= core gui

TARGET = lib
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    queens_result.c \
    queens_out.c \
    queens_in.c \
    matrix_algorithms.c \
    queens_check_for_beating.c \
    exchange_change.c \
    exchange_out.c \
    quotient_math.c

HEADERS += \
    queens_result.h \
    queens_out.h \
    queens_in.h \
    exchange_change.h \
    matrix_algorithms.h \
    queens_check_for_beating.h \
    exchange_out.h \
    quotient_math.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
