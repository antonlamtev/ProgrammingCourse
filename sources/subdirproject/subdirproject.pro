TEMPLATE = subdirs
# C project
app_c.depends = lib_c
qt_test_c.depends = lib_c

# C++ project
testcpp.depends = lib_cpp
#----------------------

SUBDIRS += \
    app_c \
    lib_c \
    qt_tests_c \
    lib_cpp \
    testcpp \
    app_cpp
