cmake_minimum_required(VERSION 3.10)

project(imgui-sfml)

set(CMAKE_CXX_STANDARD 23)

find_package(OpenGL REQUIRED)

include_directories("${CMAKE_SOURCE_DIR}/include")

set(WHERE-IS-SFML "${CMAKE_SOURCE_DIR}/include/sfml/lib")
set(WHERE-IS-SFML-HEADERS "${CMAKE_SOURCE_DIR}/include/sfml/include")
set(WHERE-IS-GLAD "${CMAKE_SOURCE_DIR}/include/glad/src/glad.c")
set(WHERE-IS-GLAD-HEADERS "${CMAKE_SOURCE_DIR}/include/glad/include")

find_library(SFML PATHS ${WHERE-IS-SFML})
include_directories("${WHERE-IS-SFML-HEADERS}")
include_directories("${CMAKE_SOURCE_DIR}/include/imgui-sfml")

add_library("glad" ${WHERE-IS-GLAD})
include_directories("${WHERE-IS-GLAD-HEADERS}")

file(READ include/imgui-sfml/imconfig-SFML.h imconfig)
file(WRITE include/imgui/imconfig.h "${imconfig}")

# your sources
set(sources
    src/new.cpp
    src/staticinit.cpp
    src/baseactor.cpp
    src/main.cpp
    include/imgui/imconfig.h
    include/imgui/imgui.cpp
    include/imgui/imgui.h
    include/imgui/imgui_demo.cpp
    include/imgui/imgui_draw.cpp
    include/imgui/imgui_internal.h
    include/imgui/imgui_tables.cpp
    include/imgui/imgui_widgets.cpp
    include/imgui/imstb_rectpack.h
    include/imgui/imstb_textedit.h
    include/imgui/imstb_truetype.h
    include/imgui/backends/imgui_impl_opengl3.cpp
    include/imgui/backends/imgui_impl_opengl3.h
    include/imgui-sfml/imgui-SFML_export.h
    include/imgui-sfml/imgui-SFML.cpp
    include/imgui-sfml/imgui-SFML.h
)

add_executable(${CMAKE_PROJECT_NAME} ${sources})
target_link_libraries(
    ${CMAKE_PROJECT_NAME}
    "../../include/mimalloc/mimalloc-override"
    "glad"
    "../../include/sfml/lib/sfml-main"
    "../../include/sfml/lib/sfml-audio"
    "../../include/sfml/lib/sfml-graphics"
    "../../include/sfml/lib/sfml-network"
    "../../include/sfml/lib/sfml-system"
    "../../include/sfml/lib/sfml-window"    
    ${OPENGL_gl_LIBRARY}
)

# clean build/<TARGET>/bin/ directory
add_custom_command(
    TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E rm -rf ${CMAKE_CURRENT_BINARY_DIR}/bin
)

# recreate build/<TARGET>/bin/ directory
add_custom_command(
    TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}/bin
)

# copy data directory to the binary directory
add_custom_command(
    TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_SOURCE_DIR}/data/
            ${CMAKE_CURRENT_BINARY_DIR}/bin/data/
)

# copy mimalloc DLLs to the binary directory
add_custom_command(
    TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_SOURCE_DIR}/include/mimalloc/bin/
            ${CMAKE_CURRENT_BINARY_DIR}/bin/
)

# copy SFML DLLs to the binary directory
add_custom_command(
    TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_SOURCE_DIR}/include/sfml/bin/
            ${CMAKE_CURRENT_BINARY_DIR}/bin/
)

# move the executable from build directory to the binary directory
add_custom_command(
    TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E rename
            ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}.exe
            ${CMAKE_CURRENT_BINARY_DIR}/bin/${CMAKE_PROJECT_NAME}.exe
)
