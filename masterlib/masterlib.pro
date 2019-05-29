#-------------------------------------------------
#
# Project created by QtCreator 2017-10-01T07:52:30
#
#-------------------------------------------------
QT += network quick gui gamepad

TARGET = masterlib
TEMPLATE = lib

DEFINES += MASTERLIB_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

Release:DESTDIR = release
Release:OBJECTS_DIR = release/.obj
Release:MOC_DIR = release/.moc
Release:RCC_DIR = release/.rcc
Release:UI_DIR = release/.ui

Debug:DESTDIR = debug
Debug:OBJECTS_DIR = debug/.obj
Debug:MOC_DIR = debug/.moc
Debug:RCC_DIR = debug/.rcc
Debug:UI_DIR = debug/.ui

SOURCES += \
    master/masterlib.cpp \
    master/ipc/socket/xhostaddress.cpp \
    master/ipc/socket/xudpsocket.cpp \
    master/ipc/socket/xtcpserver.cpp \
    master/ipc/socket/xtcpclient.cpp \
    master/peripheral/gamepad/xgamepad.cpp \
    master/peripheral/keyboard/xkeyhandler.cpp \
    master/peripheral/keyboard/xkeyeventfilter.cpp \
    master/peripheral/keyboard/xkeyprotocol.cpp \
    master/controls/xnavigation.cpp \
    master/peripheral/keyboard/xkeyeventgenerator.cpp \
    master/controls/xkeymap.cpp \
    master/config/ini/xkeysettings.cpp \
    master/config/ini/xsettings.cpp \
    master/ipc/sharedmem/xsharedmemory.cpp

HEADERS += \
    master/masterlib.h \
    master/masterlib_global.h \
    master/ipc/socket/xhostaddress.h \
    master/ipc/socket/xudpsocket.h \
    master/ipc/socket/xtcpserver.h \
    master/ipc/socket/xtcpclient.h \
    master/peripheral/gamepad/xgamepad.h \
    master/peripheral/keyboard/xkeyhandler.h \
    master/peripheral/keyboard/xkeyeventfilter.h \
    master/peripheral/keyboard/xkeyprotocol.h \
    master/controls/xnavigation.h \
    master/peripheral/keyboard/xkeyeventgenerator.h \
    master/controls/xkeymap.h \
    master/config/ini/xkeysettings.h \
    master/config/ini/xsettings.h \
    master/ipc/sharedmem/xsharedmemory.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
