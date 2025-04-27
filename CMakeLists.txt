cmake_minimum_required(VERSION 3.14)
project(Project4)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output/lib)

add_subdirectory(src)

add_executable(Project4 main.cpp)

target_include_directories(Project4 PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(Project4 PRIVATE Menu)

include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(my_tests tests/sample_test.cpp)
target_link_libraries(my_tests gtest gtest_main)

include(GoogleTest)
gtest_discover_tests(my_tests)

