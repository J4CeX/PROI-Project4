cmake_minimum_required(VERSION 3.10)
project(Project4)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(src)

add_executable(Project4 main.cpp)

target_include_directories(Project4 PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(Project4 PRIVATE Menu)