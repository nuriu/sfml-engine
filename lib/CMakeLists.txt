### IMGUI

list(APPEND LIB_IMGUI_DIR imgui/)
list(APPEND LIB_IMGUI_INCLUDE_DIR ${LIB_IMGUI_DIR})

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

list(APPEND LIB_IMGUI_LIBRARIES)

add_library(imgui STATIC ${LIB_IMGUI_SOURCES} ${LIB_IMGUI_HEADERS})
target_include_directories(imgui PRIVATE ${LIB_IMGUI_INCLUDE_DIR})
target_link_libraries(imgui PUBLIC ${LIB_IMGUI_LIBRARIES})

### IMGUI-SFML

find_package(OpenGL REQUIRED)

list(APPEND LIB_IMGUI_SFML_DIR imgui-sfml/)
list(APPEND LIB_IMGUI_SFML_INCLUDE_DIR ${LIB_IMGUI_INCLUDE_DIR} ${LIB_IMGUI_SFML_DIR})

list(APPEND LIB_IMGUI_SFML_HEADERS
        "${LIB_IMGUI_SFML_DIR}/imgui-SFML.h")

list(APPEND LIB_IMGUI_SFML_SOURCES
        "${LIB_IMGUI_SFML_DIR}/imgui-SFML.cpp")

list(APPEND LIB_IMGUI_SFML_LIBRARIES ${OPENGL_LIBRARY} imgui)

add_library(imgui-sfml STATIC ${LIB_IMGUI_SFML_SOURCES} ${LIB_IMGUI_SFML_HEADERS})
target_include_directories(imgui-sfml PRIVATE ${LIB_IMGUI_INCLUDE_DIR})
target_link_libraries(imgui-sfml PUBLIC ${LIB_IMGUI_SFML_LIBRARIES})
