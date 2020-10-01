cmake_minimum_required(VERSION 3.18.2)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_compile_options(
    -Wall
    -Wextra
    -Werror
    -Wpedantic
)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(QT NAMES Qt5 COMPONENTS Widgets Core Gui REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets Core Gui REQUIRED)

include_directories(src)

add_subdirectory(src)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../../)

add_executable(${CMAKE_PROJECT_NAME} main.cpp)

target_link_libraries(
    ${CMAKE_PROJECT_NAME}
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Gui
    src
)