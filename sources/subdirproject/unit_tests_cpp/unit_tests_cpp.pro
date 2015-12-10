#-------------------------------------------------
#
# Project created by QtCreator 2015-12-09T18:02:57
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

CONFIG +=c++11

TARGET = unit_tests_cpp
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += unit_tests_cpp.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../lib_cpp/release/ -llib_cpp
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../lib_cpp/debug/ -llib_cpp
else:unix: LIBS += -L$$OUT_PWD/../lib_cpp/ -llib_cpp

INCLUDEPATH += $$PWD/../lib_cpp
DEPENDPATH += $$PWD/../lib_cpp

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../lib_cpp/release/liblib_cpp.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../lib_cpp/debug/liblib_cpp.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../lib_cpp/release/lib_cpp.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../lib_cpp/debug/lib_cpp.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../lib_cpp/liblib_cpp.a

HEADERS +=
