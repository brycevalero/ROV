mkdir build
cd build
qmake ../masterlib.pro -spec win32-g++ "CONFIG+=debug" "CONFIG+=qml_debug"
mingw32-make.exe -j8