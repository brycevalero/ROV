#!/bin/sh
#===================================================================================
# USAGE: source ./exports.sh
#
# DESCRIPTION: Adds environment variables for application to run
#===================================================================================


HOME=/home/debian/Projects/Qt
LIB_PATHS=$(find $HOME -name "libmasterlib.so")

export LD_LIBRARY_PATH=$(dirname $LIB_PATHS)
#export QT_PLUGIN_PATH=`pwd`/plugins
export QML2_IMPORT_PATH=$HOME/ROV/shared/masterqml

echo "CURRENT LD_LIBRARY_PATH: $LD_LIBRARY_PATH"
echo "CURRENT QML2_IMPORT_PATH: $QML2_IMPORT_PATH"
