cmake_minimum_required(VERSION 3.2)
project(Final_Project)

set(CMAKE_CXX_STANDARD 11)

FILE(GLOB SOURCES *.cpp)
add_executable(main ${SOURCES})
