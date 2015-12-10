TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    tableApp.cpp \
    matrixapp.cpp

HEADERS += \
    tableApp.h \
    matrixapp.h

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
