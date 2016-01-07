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
    relationsideinfo.h \
    shareddefs.h \
    private/relationsideinfo_si.h

SOURCES += \
    component.cpp \
    relation.cpp \
    relationsideinfo.cpp

DEFINES += DM_CORE_LIB
