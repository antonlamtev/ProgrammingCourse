TEMPLATE = subdirs

app_c.depends = lib_c
qt_test_c.depends = lib_c

SUBDIRS += \
    app_c \
    lib_c \
    qt_tests_c \
    oop
