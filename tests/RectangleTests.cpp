#include <gtest/gtest.h>
#include "Rectangle.hpp"

using SVG::Rectangle;

TEST(RectangleTests, RectangleConstructor) {
    Rectangle rectangle(10, 20, 30, 40, "red", "blue");
    ASSERT_EQ(rectangle.getWidth(), 10);
    ASSERT_EQ(rectangle.getHeight(), 20);
    ASSERT_EQ(rectangle.getX(), 30);
    ASSERT_EQ(rectangle.getY(), 40);
    ASSERT_EQ(rectangle.getFill(), "red");
    ASSERT_EQ(rectangle.getStroke(), "blue");
}

TEST(RectangleTests, RectangleDefaultValuesConstructor) {
    Rectangle rectangle(10, 20);
    ASSERT_EQ(rectangle.getWidth(), 10);
    ASSERT_EQ(rectangle.getHeight(), 20);
    ASSERT_EQ(rectangle.getX(), 0);
    ASSERT_EQ(rectangle.getY(), 0);
    ASSERT_EQ(rectangle.getFill(), "none");
    ASSERT_EQ(rectangle.getStroke(), "none");
}

TEST(RectangleTests, RectangleCopy) {
    Rectangle rectangle(10, 20, 30, 40, "red", "blue");
    Rectangle secRectangle(1, 2, 3, 4, "green", "yellow");
    rectangle = secRectangle;
    ASSERT_EQ(rectangle.getWidth(), 1);
    ASSERT_EQ(rectangle.getHeight(), 2);
    ASSERT_EQ(rectangle.getX(), 3);
    ASSERT_EQ(rectangle.getY(), 4);
    ASSERT_EQ(rectangle.getFill(), "green");
    ASSERT_EQ(rectangle.getStroke(), "yellow");
    Rectangle thRectangle = rectangle;
    ASSERT_EQ(thRectangle.getWidth(), 1);
    ASSERT_EQ(thRectangle.getHeight(), 2);
    ASSERT_EQ(thRectangle.getX(), 3);
    ASSERT_EQ(thRectangle.getY(), 4);
    ASSERT_EQ(thRectangle.getFill(), "green");
    ASSERT_EQ(thRectangle.getStroke(), "yellow");
}

TEST(RectangleTests, RectanglePrint) {
    Rectangle rectangle(10, 20, 30, 40, "red", "blue");
    std::string expectedResult = "<rect x=\"30\" y=\"40\" width=\"10\" height=\"20\" fill=\"red\" stroke=\"blue\" />";
    ASSERT_EQ(rectangle.print(), expectedResult);
}

TEST(RectangleTests, RectangleSetters) {
    Rectangle rectangle(10, 20, 30, 40, "red", "blue");
    ASSERT_EQ(rectangle.getX(), 30);
    ASSERT_EQ(rectangle.getY(), 40);
    ASSERT_EQ(rectangle.getWidth(), 10);
    ASSERT_EQ(rectangle.getHeight(), 20);
    ASSERT_EQ(rectangle.getFill(), "red");
    ASSERT_EQ(rectangle.getStroke(), "blue");
    rectangle.setX(1);
    rectangle.setY(2);
    rectangle.setWidth(3);
    rectangle.setHeight(4);
    rectangle.setFill("green");
    rectangle.setStroke("yellow");
    ASSERT_EQ(rectangle.getX(), 1);
    ASSERT_EQ(rectangle.getY(), 2);
    ASSERT_EQ(rectangle.getWidth(), 3);
    ASSERT_EQ(rectangle.getHeight(), 4);
    ASSERT_EQ(rectangle.getFill(), "green");
    ASSERT_EQ(rectangle.getStroke(), "yellow");
}

TEST(RectangleTests, RectangleComparison) {
    Rectangle firstRectangle(10, 20, 30, 40, "red", "blue");
    Rectangle secondRectangle(1, 2, 3, 4, "green", "white");
    ASSERT_TRUE(firstRectangle != secondRectangle);
    ASSERT_FALSE(firstRectangle == secondRectangle);
    secondRectangle = firstRectangle;
    ASSERT_TRUE(firstRectangle == secondRectangle);
    ASSERT_FALSE(firstRectangle != secondRectangle);
}