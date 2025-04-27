add_executable(Project4_source
    Element.cpp
    Image.cpp
    Menu.cpp
    OutFile.cpp
    Rectangle.cpp
    Text.cpp
)

target_include_directories(Project4_source PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(Project4_source PRIVATE source)