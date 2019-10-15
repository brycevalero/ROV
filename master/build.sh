#!/bin/sh
#===================================================================================
# USAGE: ./build.sh
#
# DESCRIPTION: Builds all the projects at once
# Requires that the qmake path is set before execution
#===================================================================================

if command -v qmake ; then

    #export PATH=$PATH:/home/debian/Qt/5.12.5/gcc_64/bin
    export LD_LIBRARY_PATH=../build-rov/masterlib/build/debug
    #export QT_PLUGIN_PATH=`pwd`/plugins
    export QML2_IMPORT_PATH=./masterqml

    mkdir ../build-rov
    cd ../build-rov

    qmake ../ROV/rov.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug
    make 

else
    echo "ERROR: qmake is not found.  Please add to path"
fi
