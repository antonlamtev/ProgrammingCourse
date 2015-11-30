#-------------------------------------------------
#
# Project created by QtCreator 2015-11-05T14:57:34
#
#-------------------------------------------------

QT       -= core gui

TARGET = lib_c
TEMPLATE = lib
CONFIG += staticlib

QMAKE_CFLAGS += -std=c11

SOURCES += \
    queens_check_for_beating.c \
    quotient_process.c \
    queens_result_for_output.c \
    matrix_processing.c \
    lines_symmetrization_processing.c \
    exchange_of_coins_process.c

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
