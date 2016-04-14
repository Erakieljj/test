TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

SOURCES += \
    main.cpp \
    line.cpp \
    fresque.cpp \
    matrix.cpp \
    point.cpp \
    polygone.cpp \
    circle.cpp \
    ellipse.cpp \
    dataJSON.cpp \
    objectinterface.cpp \
    #clientgui.cpp

HEADERS += \
    line.h \
    objectinterface.h \
    fresque.h \
    matrix.h \
    point.h \
    polygone.h \
    circle.h \
    ellipse.h \
    dataJSON.h \
    #clientgui.h

DISTFILES += \
    PatchWork.pro.user

SUBDIRS += \
    PatchWorkClient.pro \
    PatchWorkServer.pro

FORMS += \
   # clientgui.ui


