add_executable(Project4_tests
    testElement.cpp
    testImage.cpp
    testCircle.cpp
    testRectangle.cpp
    testText.cpp
    testOutFile.cpp
)

target_include_directories(Project4_tests PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(Project4_tests PRIVATE GTest::gtest_main source)

include(GoogleTest)
gtest_discover_tests(Project4_tests)