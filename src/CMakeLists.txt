set(SOURCES
    Element.cpp
    Image.cpp
    Menu.cpp
    OutFile.cpp
    Rectangle.cpp
    Text.cpp
    Circle.cpp
    globalCommands.cpp
)

add_library(src_lib STATIC ${SOURCES})
target_include_directories(src_lib PUBLIC ${CMAKE_SOURCE_DIR}/include)