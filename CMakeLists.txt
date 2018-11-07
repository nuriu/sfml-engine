cmake_minimum_required(VERSION 3.1)
project(game)

if (WIN32)
    set(SFML_STATIC_LIBRARIES TRUE)
    set(SFML_DIR "$ENV{SFML_ROOT}/lib/cmake/SFML")
endif (WIN32)

find_package(SFML 2.5.1 COMPONENTS graphics network audio REQUIRED)

if (WIN32)
    include_directories($ENV{SFML_ROOT}/include/ include/)
else()
    include_directories(include/)
endif (WIN32)

set(HEADERS
            include/Scenes/GameScene.hpp
            include/Scenes/Scene.hpp
            include/Managers/SceneManager.hpp
            include/Managers/InputManager.hpp
            include/Managers/AssetManager.hpp
            include/CoreComponents.hpp
            include/Game.hpp)

set(SOURCES
            src/Scenes/GameScene.cpp
            src/Managers/SceneManager.cpp
            src/Managers/InputManager.cpp
            src/Managers/AssetManager.cpp
            src/Game.cpp
            src/main.cpp)

source_group("Headers" FILES ${HEADERS})
source_group("Sources" FILES ${SOURCES})

add_executable(game ${SOURCES} ${HEADERS})

target_link_libraries(game sfml-graphics sfml-network sfml-audio)
