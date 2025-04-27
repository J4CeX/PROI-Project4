set(TEST_SOURCES
    CircleTests.cpp
    ElementTests.cpp
    ImageTests.cpp
    OutFileTests.cpp
    RectangleTests.cpp
    TextTests.cpp
)

add_executable(ElementTests ${TEST_SOURCES})
add_executable(ImageTests ${TEST_SOURCES})
target_link_libraries(ElementTests src_lib gtest gtest_main)
target_link_libraries(ImageTests src_lib gtest gtest_main)

enable_testing()
add_test(NAME ElementTests COMMAND ElementTests)
add_test(NAME ImageTests COMMAND ImageTests)