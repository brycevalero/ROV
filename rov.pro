TEMPLATE = subdirs
CONFIG  += ordered

SUBDIRS += masterlib \
           masterqml \
           mastertest \
           rovctrl \
           rovslave

#DEPENDPATH += masterlib
#Directory where the library headers are
#INCLUDEPATH += masterlib
#Directory where the .lib file is
#LIBS += -L../build-rov-Desktop_Qt_5_12_3_MinGW_32_bit-Debug/masterlib/debug -lmasterlib
