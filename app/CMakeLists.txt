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

qt5_add_resources(RESOURCES resources/myres.qrc)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../../)

set(APP_ICON_RESOURCE_WINDOWS "${CMAKE_CURRENT_SOURCE_DIR}/resources/app_win32.rc") #change for macos in future

add_executable(${CMAKE_PROJECT_NAME} main.cpp ${RESOURCES} ${APP_ICON_RESOURCE_WINDOWS})

target_link_libraries(
    ${CMAKE_PROJECT_NAME}
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Gui
    src
)
