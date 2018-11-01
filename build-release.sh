# CREATE BUILD AND RELEASE FOLDERS
mkdir -p build/release
cd build/release

# BUILD
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release ../../

# COMPILE & LINK
make -f Makefile
