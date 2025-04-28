add_executable(RectangleTests RectangleTests.cpp )
add_executable(TextTests TextTests.cpp)

target_link_libraries(RectangleTests gtest_main src_lib)
target_link_libraries(TextTests gtest_main src_lib)

include(GoogleTest)
gtest_discover_tests(RectangleTests)
gtest_discover_tests(TextTests)