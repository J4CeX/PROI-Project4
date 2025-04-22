cmake_minimum_required(VERSION 3.10)
project(Project4)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB SRC_FILES "*.cpp")

add_library(Menu STATIC ${SRC_FILES})

target_include_directories(Menu PUBLIC ${CMAKE_SOURCE_DIR}/include)