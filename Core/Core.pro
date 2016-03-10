TEMPLATE = lib
QT = core

INCLUDEPATH += \
    ..

DESTDIR = ../bin
TARGET = DmCore

HEADERS += \
    private/component_si.h \
    private/propertyfield_si.h \
    private/propertyschema_si.h \
    component.h \
    dmglobal.h \
    propertyfield.h \
    propertyschema.h \
    shareddefs.h

SOURCES += \
    component.cpp \
    propertyfield.cpp \
    propertyschema.cpp

DEFINES += DM_CORE_LIB
