cmake_minimum_required(VERSION 3.10)
project(irl2ascii VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(OpenCV 4 REQUIRED)

include_directories(include)

file(GLOB SOURCES src/*.cpp)

add_executable(irl2ascii ${SOURCES})

target_link_libraries(irl2ascii ${OpenCV_LIBS})
