#!/bin/sh
#===================================================================================
# USAGE: ./run.sh
#
# DESCRIPTION: Runs the server and client applications
#===================================================================================

#export PATH=$PATH:/home/debian/Qt/5.12.5/gcc_64/bin
export LD_LIBRARY_PATH=../build-rov/masterlib/build/debug
#export QT_PLUGIN_PATH=`pwd`/plugins
export QML2_IMPORT_PATH=./masterqml

../build-rov/rovctrl/build/debug/rovctrl
