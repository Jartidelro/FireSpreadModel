QT += core
QT -= gui

TARGET = FireSpreadModel
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

TEMPLATE = app

SOURCES += main.cpp \
    fire.cpp \
    weather.cpp \
    output.cpp \
    parameters.cpp

HEADERS += \
    fire.h \
    weather.h \
    output.h \
    parameters.h

