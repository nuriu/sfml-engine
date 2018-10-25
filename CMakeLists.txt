cmake_minimum_required(VERSION 3.1)
project(game)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "$ENV{SFML_ROOT}/lib/cmake/SFML")


find_package(SFML 2.5.1 COMPONENTS graphics network audio REQUIRED)

add_executable(game src/main.cpp)

target_link_libraries(game sfml-graphics sfml-network sfml-audio)