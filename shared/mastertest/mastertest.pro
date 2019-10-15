QT += network quick gui gamepad testlib

release: DESTDIR = build/release
debug:   DESTDIR = build/debug

OBJECTS_DIR = $$DESTDIR/.obj
MOC_DIR = $$DESTDIR/.moc
RCC_DIR = $$DESTDIR/.qrc
UI_DIR = $$DESTDIR/.ui

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

DEPENDPATH += $$PWD/../masterlib
#Directory where the library headers are
INCLUDEPATH += $$PWD/../masterlib
#Directory where the .lib file is
#LIBS += -L../../build-rov-Desktop_Qt_5_12_3_MinGW_32_bit-Debug/masterlib/debug -lmasterlib
#LIBS += -L../build-masterlib-Desktop_Qt_5_12_2_MinGW_32_bit-Debug/debug -lmasterlib
LIBS += -L$$OUT_PWD/../masterlib/build/debug -lmasterlib
