QT += core

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

SOURCES += \
    client2.cpp

win32 {
    LIBS += -lws2_32
}

