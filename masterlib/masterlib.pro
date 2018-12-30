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

SOURCES += \
    master/masterlib.cpp \
    master/socket/xhostaddress.cpp \
    master/socket/xudpsocket.cpp \
    master/socket/xtcpserver.cpp \
    master/socket/xtcpclient.cpp \
    master/peripheral/gamepad/xgamepad.cpp \
    master/peripheral/keyboard/xkeyhandler.cpp \
    master/peripheral/keyboard/xkeyeventfilter.cpp \
    master/peripheral/keyboard/xkeyprotocol.cpp \
    master/controls/xnavigation.cpp \
    master/peripheral/keyboard/xkeyeventgenerator.cpp \
    master/controls/xkeymap.cpp \
    master/config/ini/xkeysettings.cpp

HEADERS += \
    master/masterlib.h \
    master/masterlib_global.h \
    master/socket/xhostaddress.h \
    master/socket/xudpsocket.h \
    master/socket/xtcpserver.h \
    master/socket/xtcpclient.h \
    master/peripheral/gamepad/xgamepad.h \
    master/peripheral/keyboard/xkeyhandler.h \
    master/peripheral/keyboard/xkeyeventfilter.h \
    master/peripheral/keyboard/xkeyprotocol.h \
    master/controls/xnavigation.h \
    master/peripheral/keyboard/xkeyeventgenerator.h \
    master/controls/xkeymap.h \
    master/config/ini/xkeysettings.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
