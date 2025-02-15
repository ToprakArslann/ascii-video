cmake_minimum_required(VERSION 3.15)
project(ascii-video)

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ascii-converter src/main.cpp)

target_link_libraries(ascii-converter ${OpenCV_LIBS})
