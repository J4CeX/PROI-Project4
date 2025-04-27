cmake_minimum_required(VERSION 3.10)
project(Project4)
set(CMAKE_CXX_STANDARD 20)
include_directories(include)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(googletest)

add_subdirectory(src)
add_subdirectory(tests)

add_executable(Project4 main.cpp)
target_link_libraries(Project4 src_lib)
