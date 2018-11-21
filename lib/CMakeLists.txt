### IMGUI

list(APPEND LIB_IMGUI_DIR imgui/)

list(APPEND LIB_IMGUI_HEADERS
        "${LIB_IMGUI_DIR}/imgui_internal.h"
        "${LIB_IMGUI_DIR}/imconfig.h"
        "${LIB_IMGUI_DIR}/imgui.h"
        "${LIB_IMGUI_DIR}/misc/cpp/imgui_stdlib.h"
        "${LIB_IMGUI_DIR}/imstb_rectpack.h"
        "${LIB_IMGUI_DIR}/imstb_textedit.h"
        "${LIB_IMGUI_DIR}/imstb_truetype.h")

list(APPEND LIB_IMGUI_SOURCES
        "${LIB_IMGUI_DIR}/misc/cpp/imgui_stdlib.cpp"
        "${LIB_IMGUI_DIR}/imgui.cpp"
        "${LIB_IMGUI_DIR}/imgui_draw.cpp"
        "${LIB_IMGUI_DIR}/imgui_widgets.cpp")

add_library(imgui STATIC ${LIB_IMGUI_SOURCES} ${LIB_IMGUI_HEADERS})
target_include_directories(imgui PRIVATE ${LIB_IMGUI_DIR})

### IMGUI-SFML

find_package(OpenGL REQUIRED)

list(APPEND LIB_IMGUI_SFML_DIR imgui-sfml/)

list(APPEND LIB_IMGUI_SFML_HEADERS
        "${LIB_IMGUI_SFML_DIR}/imgui-SFML.h")

list(APPEND LIB_IMGUI_SFML_SOURCES
        "${LIB_IMGUI_SFML_DIR}/imgui-SFML.cpp")

list(APPEND LIB_IMGUI_SFML_LIBRARIES ${OPENGL_LIBRARY} imgui)

add_library(imgui-sfml STATIC ${LIB_IMGUI_SFML_SOURCES} ${LIB_IMGUI_SFML_HEADERS})
target_include_directories(imgui-sfml PRIVATE ${LIB_IMGUI_SFML_DIR} ${LIB_IMGUI_DIR})
target_link_libraries(imgui-sfml PRIVATE ${LIB_IMGUI_SFML_LIBRARIES})

### TMXLITE

list(APPEND LIB_TMXLITE_DIR tmxlite/tmxlite/)
list(APPEND LIB_TMXLITE_INCLUDE_DIR ${LIB_TMXLITE_DIR}/include/)

list(APPEND LIB_TMXLITE_SOURCES
        ${LIB_TMXLITE_DIR}/src/detail/pugixml.cpp
        ${LIB_TMXLITE_DIR}/src/FreeFuncs.cpp
        ${LIB_TMXLITE_DIR}/src/ImageLayer.cpp
        ${LIB_TMXLITE_DIR}/src/Map.cpp
        ${LIB_TMXLITE_DIR}/src/miniz.c
        ${LIB_TMXLITE_DIR}/src/Object.cpp
        ${LIB_TMXLITE_DIR}/src/ObjectGroup.cpp
        ${LIB_TMXLITE_DIR}/src/Property.cpp
        ${LIB_TMXLITE_DIR}/src/TileLayer.cpp
        ${LIB_TMXLITE_DIR}/src/Tileset.cpp)

add_library(tmxlite STATIC ${LIB_TMXLITE_SOURCES})
target_include_directories(tmxlite PRIVATE ${LIB_TMXLITE_INCLUDE_DIR})
