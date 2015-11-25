#-------------------------------------------------
#
# Project created by QtCreator 2015-11-05T14:57:34
#
#-------------------------------------------------

QT       -= core gui

TARGET = lib_c
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    queens_result.c \
    matrix_algorithms.c \
    queens_check_for_beating.c \
    exchange_change.c \
    quotient_process.c \
    lines_symmetrization_algorithms.c

HEADERS += \
    exchange.h \
    lines_symmetrization.h \
    matrix.h \
    queens.h \
    quotient.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
