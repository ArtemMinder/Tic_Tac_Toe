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
find_package(Qt5Widgets REQUIRED)

list(APPEND THIRD_PARTY_LIBS Qt5::Widgets Qt5::Core Qt5::Gui)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Tic_Tac_toe.cpp Tic_Tac_toe.h  Congratultion.cpp
    Congratultion.h Congratultion.ui Mainwindow.cpp
    Mainwindow.h Mainwindow.ui Settingwindow.cpp Settingwindow.h
    Settingwindow.ui Gameplaywindow.h Gameplaywindow.cpp Gameplaywindow.ui
    resources.qrc)
add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${Boost_LIBRARIES})

target_link_libraries(${PROJECT_NAME}
        Qt5::Core
        Qt5::Widgets
        Qt5::Gui
        )
