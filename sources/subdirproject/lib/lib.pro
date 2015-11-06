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
    math_for_equation.c \
    check_for_beating.c \
    change.c \
    algorithms_for_matrix.c

HEADERS += \
    queens_result.h \
    queens_out.h \
    queens_in.h \
    math_for_equation.h \
    check_for_beating.h \
    change.h \
    algorithms_for_matrix.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
