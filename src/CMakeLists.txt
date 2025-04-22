cmake_minimum_required(VERSION 3.10)
project(Project4)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB SRC "*.cpp" "*.hpp")


# Create static library with cpp and hpp files
add_library(Menu STATIC ${SRC})
add_library(Element STATIC ${SRC})
add_library(Image STATIC ${SRC})
add_library(OutFile STATIC ${SRC})
add_library(Rectangle STATIC ${SRC})
add_library(DataBase STATIC ${SRC})


