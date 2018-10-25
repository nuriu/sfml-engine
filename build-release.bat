:: CHECK BUILD AND RELEASE FOLDERS
IF NOT EXIST build/ MKDIR build
cd build
IF NOT EXIST release/ MKDIR release
cd release

:: BUILD
cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release ../../

:: COMPILE & LINK
mingw32-make -f Makefile
