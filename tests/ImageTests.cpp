#include <gtest/gtest.h>
#include "Image.hpp"

using namespace SVG;

TEST(ImageTests, ImageConstructor) {
    Image image(100, 200);
    ASSERT_EQ(image.getWidth(), 100);
    ASSERT_EQ(image.getHeight(), 200);
    ASSERT_EQ(image.getSize(), 0);
}

TEST(ImageTests, ImageSetters) {
    Image image(100, 200);
    ASSERT_EQ(image.getWidth(), 100);
    ASSERT_EQ(image.getHeight(), 200);
    ASSERT_EQ(image.getSize(), 0);
    image.setWidth(300);
    image.setHeight(400);
    ASSERT_EQ(image.getWidth(), 300);
    ASSERT_EQ(image.getHeight(), 400);
}

TEST(ImageTests, ImageAddElementAndPrint) {
    Image image(100, 200);
    Circle circle(1, 2, 3, "red", "blue");
    Rectangle rectangle(1, 2, 3, 4, "yellow", "orange");
    Text text("some text", 1, 2, 3, "middle", "white", "black");
    image.addElement<Circle>(circle);
    image.addElement<Rectangle>(rectangle);
    image.addElement<Text>(text);
    std::string expectedResult = "<svg version=\"1.1\"\n\twidth=\"100\" height=\"200\"\n\txmlns=\"http://www.w3.org/2000/svg\">\n";
    expectedResult += "\t<circle cx=\"2\" cy=\"3\" r=\"1\" fill=\"red\" stroke=\"blue\" />\n";
    expectedResult += "\t<rect x=\"3\" y=\"4\" width=\"1\" height=\"2\" fill=\"yellow\" stroke=\"orange\" />\n";
    expectedResult += "\t<text x=\"1\" y=\"2\" font-size=\"3\" text-anchor=\"middle\" fill=\"white\" stroke=\"black\">some text</text>\n";
    expectedResult += "</svg>\n";
    ASSERT_EQ(image.print(), expectedResult);
    ASSERT_EQ(image.getSize(), 3);
}

TEST(ImageTests, ImageAddElementAndRemove) {
    Image image(100, 200);
    Circle circle(1, 2, 3, "red", "blue");
    Rectangle rectangle(1, 2, 3, 4, "yellow", "orange");
    Text text("some text", 1, 2, 3, "middle", "white", "black");
    image.addElement<Circle>(circle);
    image.addElement<Rectangle>(rectangle);
    image.addElement<Text>(text);
    Image secondImage(100, 200);
    secondImage = image;
    ASSERT_EQ(image.getSize(), 3);
    ASSERT_TRUE(*image[0] == *secondImage[0]);
    ASSERT_TRUE(*image[1] == *secondImage[1]);
    ASSERT_TRUE(*image[2] == *secondImage[2]);
    image.removeElement(image[1]);
    ASSERT_EQ(image.getSize(), 2);
    ASSERT_TRUE(*image[0] == *secondImage[0]);
    ASSERT_FALSE(*image[1] == *secondImage[1]);
    ASSERT_TRUE(*image[1] == *secondImage[2]);
}