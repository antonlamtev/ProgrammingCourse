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
    quotient_math.c \
    quotient_process.c \
    lines_symmetrization_algorithms.c

HEADERS += \
    queens_result.h \
    queens_out.h \
    queens_in.h \
    exchange_change.h \
    matrix_algorithms.h \
    queens_check_for_beating.h \
    quotient_math.h \
    help_further_help.h \
    quotient_process.h \
    lines_symmetrization_algorithms.h \
    exchange_structures_declaration.h \
    queens_operands_declaration.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
