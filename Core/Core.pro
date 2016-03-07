TEMPLATE = lib
QT = core

INCLUDEPATH += \
    ..

DESTDIR = ../bin
TARGET = DmCore

HEADERS += \
    private/component_si.h \
    component.h \
    dmglobal.h \
    shareddefs.h

SOURCES += \
    component.cpp

DEFINES += DM_CORE_LIB
