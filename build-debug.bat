:: CHECK BUILD AND DEBUG FOLDERS
IF NOT EXIST build/ MKDIR build
cd build
IF NOT EXIST debug/ MKDIR debug
cd debug

:: BUILD
cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Debug ../../

:: COMPILE & LINK
mingw32-make -f Makefile
