#include <gtest/gtest.h>
#include "Circle.hpp"

using SVG::Circle;

TEST(CircleTests, CircleConstructor) {
    Circle circle(10, 20, 30, "red", "blue");
    ASSERT_EQ(circle.getX(), 20);
    ASSERT_EQ(circle.getY(), 30);
    ASSERT_EQ(circle.getRadius(), 10);
    ASSERT_EQ(circle.getFill(), "red");
    ASSERT_EQ(circle.getStroke(), "blue");
}

TEST(CircleTests, CircleDefaultValuesConstructor) {
    Circle circle(10);
    ASSERT_EQ(circle.getX(), 0);
    ASSERT_EQ(circle.getY(), 0);
    ASSERT_EQ(circle.getRadius(), 10);
    ASSERT_EQ(circle.getFill(), "none");
    ASSERT_EQ(circle.getStroke(), "none");
}

TEST(CircleTests, CircleCopy) {
    Circle circle(10, 20, 30, "red", "blue");
    Circle secCircle(1, 2, 3, "green", "yellow");
    circle = secCircle;
    ASSERT_EQ(circle.getX(), 2);
    ASSERT_EQ(circle.getY(), 3);
    ASSERT_EQ(circle.getRadius(), 1);
    ASSERT_EQ(circle.getFill(), "green");
    ASSERT_EQ(circle.getStroke(), "yellow");
    Circle thCircle = secCircle;
    ASSERT_EQ(thCircle.getX(), 2);
    ASSERT_EQ(thCircle.getY(), 3);
    ASSERT_EQ(thCircle.getRadius(), 1);
    ASSERT_EQ(thCircle.getFill(), "green");
    ASSERT_EQ(thCircle.getStroke(), "yellow");
}

TEST(CircleTests, CirclePrint) {
    Circle circle(10, 20, 30, "red", "blue");
    std::string expectedResult = "<circle cx=\"20\" cy=\"30\" r=\"10\" fill=\"red\" stroke=\"blue\" />";
    ASSERT_EQ(circle.print(), expectedResult);
}