#include <gtest/gtest.h>
#include "Image.hpp"

using namespace SVG;

TEST(ImageTests, ImageConstructor) {
    Image image(100, 200);
    image.addElement(std::make_unique<Circle>(1, 2, 3, "red", "blue"));
    image.addElement(std::make_unique<Rectangle>(1, 2, 3, 4, "yellow", "orange"));
    image.addElement(std::make_unique<Text>("some text", 1, 2, 3, "middle", "white", "black"));
    std::string expectedResult = "<svg version=\"1.1\"\n\twidth=\"100\" height=\"200\"\n\txmlns=\"http://www.w3.org/2000/svg\">\n";
    expectedResult += "\t<circle cx=\"2\" cy=\"3\" r=\"1\" fill=\"red\" stroke=\"blue\" />\n";
    expectedResult += "\t<rect x=\"3\" y=\"4\" width=\"1\" height=\"2\" fill=\"yellow\" stroke=\"orange\" />\n";
    expectedResult += "\t<text x=\"1\" y=\"2\" font-size=\"3\" text-anchor=\"middle\" fill=\"white\" stroke=\"black\">some text</text>\n";
    expectedResult += "</svg>\n";
    ASSERT_EQ(image.print(), expectedResult);
}