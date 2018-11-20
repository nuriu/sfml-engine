cmake_minimum_required(VERSION 3.12)
project(game)

set(HEADERS
        include/Game.hpp
        include/CoreComponents.hpp
        include/Managers/AssetManager.hpp
        include/Managers/InputManager.hpp
        include/Managers/SceneManager.hpp
        include/Scenes/Scene.hpp
        include/Scenes/GameScene.hpp
        )

set(SOURCES
        src/main.cpp
        src/Game.cpp
        src/Managers/AssetManager.cpp
        src/Managers/InputManager.cpp
        src/Managers/SceneManager.cpp
        src/Scenes/GameScene.cpp
        )

source_group("Headers" FILES ${HEADERS})
source_group("Sources" FILES ${SOURCES})

if (WIN32)
    set(SFML_STATIC_LIBRARIES TRUE)
    set(SFML_DIR "$ENV{SFML_ROOT}/lib/cmake/SFML")
endif (WIN32)

find_package(SFML COMPONENTS graphics network audio REQUIRED)

add_executable(game ${SOURCES} ${HEADERS})

if(MSVC)
    target_compile_options(game PRIVATE /W4)
else()
    target_compile_options(game PRIVATE
            -Wall
            -Wextra # reasonable and standard
            -Wshadow # warn the user if a variable declaration shadows one from a parent context
            -Wnon-virtual-dtor # warn the user if a class with virtual functions has a non-virtual destructor. This helps catch hard to track down memory errors
            -Wold-style-cast # warn for c-style casts
            -Wcast-align # warn for potential performance problem casts
            -Wunused # warn on anything being unused
            -Woverloaded-virtual # warn if you overload (not override) a virtual function
            -Wpedantic # warn if non-standard C++ is used
            -Wconversion # warn on type conversions that may lose data
            -Wsign-conversion # warn on sign conversions
            -Wmisleading-indentation # warn if identation implies blocks where blocks do not exist
            -Wduplicated-cond # warn if if / else chain has duplicated conditions
            -Wduplicated-branches # warn if if / else branches have duplicated code
            -Wlogical-op # warn about logical operations being used where bitwise were probably wanted
            -Wnull-dereference # warn if a null dereference is detected
            -Wuseless-cast # warn if you perform a cast to the same type
            -Wdouble-promotion # warn if float is implicit promoted to double
            -Wformat=2 # warn on security issues around functions that format output (ie printf)
            -std=c++17
            )
endif()

add_subdirectory(lib/)

target_include_directories(game PRIVATE include/ lib/)
target_link_libraries(game PRIVATE sfml-graphics sfml-network sfml-audio imgui-sfml)
