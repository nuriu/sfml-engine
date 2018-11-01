# CREATE BUILD AND DEBUG FOLDERS
mkdir -p build/debug
cd build/debug

# BUILD
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug ../../

# COMPILE & LINK
make -f Makefile
