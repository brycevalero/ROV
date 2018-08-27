QT += network quick gui gamepad testlib

SOURCES = main.cpp \
    suite.cpp \
    master/peripheral/keyboard/testkeyprotocol.cpp \
    master/socket/testhostaddress.cpp

HEADERS = \
    master/peripheral/keyboard/testkeyprotocol.h \
    suite.h \
    master/socket/testhostaddress.h

DEPENDPATH += . ../masterlib
#Directory where the library headers are
INCLUDEPATH += ../masterlib
#Directory where the .lib file is
LIBS += -L../build-masterlib-Desktop_Qt_5_11_1_MSVC2015_32bit-Debug/debug -lmasterlib
