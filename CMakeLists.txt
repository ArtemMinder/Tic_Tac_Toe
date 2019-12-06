cmake_minimum_required(VERSION 3.10)
project (Tic_Tac_Toe)
if (CMAKE_VERSION VERSION_GREATER 3.11)
cmake_policy(SET CMP0074 NEW)
endif()

set(SOURCES Tic_Tac_Toe.cpp Tic_Tac_Toe.h main.cpp)

find_package(Boost 1.71.0)
include_directories(${Boost_INCLUDE_DIR})
set(CORELIBS ${Boost_LIBRARIES})
add_executable(${PROJECT_NAME} ${Boost_LIBRARIES} Tic_Tac_Toe.cpp Tic_Tac_Toe.h main.cpp)
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
