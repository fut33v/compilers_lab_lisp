TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    lab01/token.cpp \
    lab01/stringscanner.cpp \
    lab01/parenthesisscanner.cpp \
    lab01/operationscanner.cpp \
    lab01/numberscanner.cpp \
    lab01/identificatorscanner.cpp \
    lab01/flowoftokens.cpp \
    lab01/code.cpp \
    lab02/parser.cpp \
    lab02/production.cpp

HEADERS += \
    lab01/token.h \
    lab01/stringscanner.h \
    lab01/parenthesisscanner.h \
    lab01/operationscanner.h \
    lab01/numberscanner.h \
    lab01/identificatorscanner.h \
    lab01/flowoftokens.h \
    lab01/code.h \
    lab01/classes.h \
    lab01/ascii.h \
    lab02/parser.h \
    lab02/production.h

QMAKE_CXXFLAGS += -std=c++11

