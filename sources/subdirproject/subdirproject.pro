TEMPLATE = subdirs
# C project
app_c.depends = lib_c
qt_test_c.depends = lib_c

# C++ project
unit_tests_cpp.depends = lib_cpp
#----------------------

SUBDIRS += \
    app_c \
    lib_c \
    qt_tests_c \
    oop \
    lib_cpp \
    unit_tests_cpp
