cmake_minimum_required(VERSION 3.10)
project(Project4)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(src)

# Define the main executable
add_executable(Project4 main.cpp)

# No need to set full path in main thanks to this include
target_include_directories(Project4 PUBLIC src)

# Link the interface library to the executable
target_link_libraries(Project4 PRIVATE Menu)
