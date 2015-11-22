TEMPLATE = subdirs

app.depends = lib
qt_test.depends = lib

SUBDIRS += \
    app \
    lib \
    qt_tests \
    oop
