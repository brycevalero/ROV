TEMPLATE = subdirs
CONFIG  += ordered

SUBDIRS += shared \
           master \
           slave

QML2_IMPORT_PATH += shared/masterqml
