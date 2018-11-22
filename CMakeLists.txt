cmake_minimum_required(VERSION 3.12)
project(game)

list(APPEND HEADERS
        "${CMAKE_SOURCE_DIR}/include/Engine/Application.hpp"
        "${CMAKE_SOURCE_DIR}/include/Engine/Scene.hpp"
        "${CMAKE_SOURCE_DIR}/include/Engine/AssetManager.hpp"
        "${CMAKE_SOURCE_DIR}/include/Engine/InputManager.hpp"
        "${CMAKE_SOURCE_DIR}/include/Engine/SceneManager.hpp"
        "${CMAKE_SOURCE_DIR}/include/Engine/Components.hpp"
        "${CMAKE_SOURCE_DIR}/include/Game/Scenes/GameScene.hpp")

list(APPEND SOURCES
        "${CMAKE_SOURCE_DIR}/src/main.cpp"
        "${CMAKE_SOURCE_DIR}/src/Engine/Application.cpp"
        "${CMAKE_SOURCE_DIR}/src/Engine/AssetManager.cpp"
        "${CMAKE_SOURCE_DIR}/src/Engine/InputManager.cpp"
        "${CMAKE_SOURCE_DIR}/src/Engine/SceneManager.cpp"
        "${CMAKE_SOURCE_DIR}/src/Game/Scenes/GameScene.cpp")

list(APPEND GAME_INCLUDE_DIRS
        "${CMAKE_SOURCE_DIR}/include/"
        "${CMAKE_SOURCE_DIR}/lib/spdlog/include/"
        "${CMAKE_SOURCE_DIR}/lib/imgui/"
        "${CMAKE_SOURCE_DIR}/lib/imgui-sfml/"
        "${CMAKE_SOURCE_DIR}/lib/tmxlite/tmxlite/include/")

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
            "$<$<CONFIG:DEBUG>:-DDEBUG>")
endif()

add_subdirectory(lib/)

target_include_directories(game PRIVATE ${GAME_INCLUDE_DIRS})
target_link_libraries(game PRIVATE sfml-graphics sfml-network sfml-audio imgui-sfml tmxlite)

add_custom_target(clang-format COMMAND clang-format -style=file -i ${SOURCES} ${HEADERS})
add_custom_target(cppcheck COMMAND cppcheck -i${CMAKE_SOURCE_DIR}/lib/ ${SOURCES} -I ${GAME_INCLUDE_DIRS} --enable=all --inconclusive --quiet)
add_custom_target(clang-tidy COMMAND clang-tidy ${SOURCES} -export-fixes='.clang-tidy-fixes' -checks=*,-abseil*,-android*,-fuchsia-default*,-hicpp-braces-around*,-google-readability-braces-around* -- -std=c++17
        -I "${CMAKE_SOURCE_DIR}/include/"
        -I "${CMAKE_SOURCE_DIR}/lib/spdlog/include/"
        -I "${CMAKE_SOURCE_DIR}/lib/imgui/"
        -I "${CMAKE_SOURCE_DIR}/lib/imgui-sfml/"
        -I "${CMAKE_SOURCE_DIR}/lib/tmxlite/tmxlite/include/")
