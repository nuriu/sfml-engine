## SFML with CMake Build System

> Project template for SFML development based on CMake build system.

It supports building (via MinGW or via directly GCC on Unix) and debugging (via gdb) from VS Code (via C/C++ Extension).

Have two VS Code tasks for debug and release builds respectively.

You can find Bash and Bat script files which used for building in the root of the source tree.

Following environment variables should exist before building (Win32 only);

- SFML_ROOT should point to sfml root directory
- MinGW_LOCATION should point to mingw directory

To analyze code with clang-tidy and cppcheck on Unix platforms, just run;

> ./analyze.sh

Following line should be added to lib/imgui-sfml/imgui-SFML.cpp file before first compiling;
> #define IMGUI_USER_CONFIG "../imgui-sfml/imconfig-SFML.h"

Tested with:

- SFML 2.5.1
- GCC 7.3.0 (via MinGW on Win10)
- GCC 8.2.1 (on Manjaro 18.0.0)
- CMake 3.12.3
- VS Code 1.27.2
  - C/C++ for Visual Studio Code: 0.20.1
