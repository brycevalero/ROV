#!/bin/sh
#===================================================================================
# USAGE: ./build.sh
#
# DESCRIPTION: Builds all the projects at once
# Requires that the qmake path is set before execution
#===================================================================================

HOME=/home/debian/Projects/Qt
PLUGIN_PATH=""
QML_PATH=$HOME/ROV/shared/masterqml
BUILD_PATH=$HOME/build-slave
LIB_PATH=$HOME/build-slave/masterlib/build
PRO_PATH=$PWD

if command -v qmake ; then

    #export PATH=$PATH:/home/debian/Qt/5.12.5/gcc_64/bin
    export LD_LIBRARY_PATH=$LIB_PATH
    export QT_PLUGIN_PATH=$PLUGIN_PATH/plugins
    export QML2_IMPORT_PATH=$QML_PATH

    mkdir $BUILD_PATH
    cd $BUILD_PATH

    qmake $PRO_PATH/slave.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug
    make 

else
    echo "ERROR: qmake is not found.  Please add to path"
fi
