TEMPLATE = lib
QT = core

INCLUDEPATH += \
    ..

DESTDIR = ../bin
TARGET = DmCore

HEADERS += \
    private/component_si.h \
    private/relation_si.h \
    component.h \
    dmglobal.h \
    relation.h \
    shareddefs.h

SOURCES += \
    component.cpp \
    relation.cpp

DEFINES += DM_CORE_LIB
