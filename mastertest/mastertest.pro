QT += network quick gui gamepad testlib

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

SOURCES = main.cpp \
    suite.cpp \
    master/peripheral/keyboard/testkeyprotocol.cpp \
    master/socket/testhostaddress.cpp \
    master/peripheral/keyboard/testkeyhandler.cpp

HEADERS = \
    master/peripheral/keyboard/testkeyprotocol.h \
    suite.h \
    master/socket/testhostaddress.h \
    master/peripheral/keyboard/testkeyhandler.h

DEPENDPATH += . ../masterlib
#Directory where the library headers are
INCLUDEPATH += ../masterlib
#Directory where the .lib file is
LIBS += -L../build-masterlib-Desktop_Qt_5_12_3_MinGW_32_bit-Debug/debug -lmasterlib
