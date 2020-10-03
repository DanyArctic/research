include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG += qt

HEADERS += \
    tst_calculations.h\
    ../engine.h

SOURCES += \
        main.cpp\
        ../engine.cpp
