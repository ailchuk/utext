set(SOURCES mainwindow.cpp actions.cpp utils.cpp clicks.cpp myfind.cpp searchhighlight.cpp highlighter.cpp openFile.cpp themes.cpp)

set(HEADERS mainwindow.h myfind.h searchhighlight.h highlighter.h openFile.h)

set(UI mainwindow.ui myfind.ui)

add_library(src ${SOURCES} ${HEADERS} ${UI})

target_link_libraries(src PRIVATE Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Gui
)
