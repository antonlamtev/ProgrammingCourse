TEMPLATE = app
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CFLAGS += -std=c11

SOURCES += \
    main.c \
    menu.c \
    exchange_ui.c \
    help_ui.c \
    lines_symmetrization_ui.c \
    matrix_ui.c \
    queens_ui.c \
    quotient_ui.c

HEADERS += \
    ../main.h \
    main.h


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../lib_c/release/ -llib_c
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../lib_c/debug/ -llib_c
else:unix: LIBS += -L$$OUT_PWD/../lib_c/ -llib_c

INCLUDEPATH += $$PWD/../lib_c
DEPENDPATH += $$PWD/../lib_c

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../lib_c/release/liblib_c.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../lib_c/debug/liblib_c.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../lib_c/release/lib_c.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../lib_c/debug/lib_c.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../lib_c/liblib_c.a
