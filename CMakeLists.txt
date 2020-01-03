cmake_minimum_required(VERSION 3.14)
project(Tic_Tac_Toe)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()
find_package(Boost 1.71.0)
include_directories(${Boost_INCLUDE_DIR})
set(CORELIBS ${Boost_LIBRARIES})
find_package(Qt5Widgets CONFIG
        PATHS C:/Qt/5.12.3/mingw73_64/lib/cmake/Qt5Widgets
       NO_DEFAULT_PATH)
list(APPEND THIRD_PARTY_LIBS Qt5::Widgets Qt5::Core Qt5::Gui)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Tic_Tac_toe.cpp Tic_Tac_toe.h  congratultion.cpp
    congratultion.h congratultion.ui mainwindow.cpp
    mainwindow.h mainwindow.ui settingwindow.cpp settingwindow.h
    settingwindow.ui gameplaywindow.h gameplaywindow.cpp gameplaywindow.ui
    resources.qrc)
add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${Boost_LIBRARIES})

target_link_libraries(${PROJECT_NAME}
        Qt5::Core
        Qt5::Widgets
        Qt5::Gui
        )
