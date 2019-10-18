QT += quick network
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

DESTDIR = build
OBJECTS_DIR = $$DESTDIR/.obj
MOC_DIR = $$DESTDIR/.moc
RCC_DIR = $$DESTDIR/.qrc
UI_DIR = $$DESTDIR/.ui

#HEADERS +=

SOURCES += main.cpp \
    src/comm/cameracomm.cpp \
    src/comm/maincomm.cpp \
    src/comm/navigationcomm.cpp \
    src/comm/sensorcomm.cpp \
    src/events/cameraeventfilter.cpp \
    src/events/navigationeventfilter.cpp \
    src/qmltyperegistrar.cpp

RESOURCES += qml/qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH += $$PWD/../../shared/masterqml
QML2_IMPORT_PATH += $$PWD/../../shared/masterqml

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH += $$PWD/../../shared/masterqml

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

BUILD_SUITE {
    message("BUILD SUITE variable set!!")
}

DEPENDPATH += $$PWD/../../shared/masterlib
#Directory where the library headers are
INCLUDEPATH += $$PWD/../../shared/masterlib
#Directory where the .lib file is
#LIBS += -L../../build-rov-Desktop_Qt_5_12_3_MinGW_32_bit-Debug/masterlib/debug -lmasterlib
#LIBS += -L../build-masterlib-Desktop_Qt_5_12_2_MinGW_32_bit-Debug/debug -lmasterlib
LIBS += -L$$OUT_PWD/../../shared/masterlib/build -lmasterlib

HEADERS += \
    src/comm/cameracomm.h \
    src/comm/maincomm.h \
    src/comm/navigationcomm.h \
    src/comm/sensorcomm.h \
    src/events/cameraeventfilter.h \
    src/events/navigationeventfilter.h \
    src/qmltyperegistrar.h
