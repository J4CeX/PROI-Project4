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

TEST(CircleTests, CircleSetters) {
    Circle circle(10, 20, 30, "red", "blue");
    ASSERT_EQ(circle.getX(), 20);
    ASSERT_EQ(circle.getY(), 30);
    ASSERT_EQ(circle.getRadius(), 10);
    ASSERT_EQ(circle.getFill(), "red");
    ASSERT_EQ(circle.getStroke(), "blue");
    circle.setRadius(1);
    circle.setX(2);
    circle.setY(3);
    circle.setFill("yellow");
    circle.setStroke("white");
    ASSERT_EQ(circle.getX(), 2);
    ASSERT_EQ(circle.getY(), 3);
    ASSERT_EQ(circle.getRadius(), 1);
    ASSERT_EQ(circle.getFill(), "yellow");
    ASSERT_EQ(circle.getStroke(), "white");
}

TEST(CircleTests, CirclesComparison) {
    Circle firstCircle(10, 20, 30, "red", "blue");
    Circle secondCircle(40, 50, 60, "yellow", "black");
    ASSERT_TRUE(firstCircle != secondCircle);
    ASSERT_FALSE(firstCircle == secondCircle);
    firstCircle = secondCircle;
    ASSERT_TRUE(firstCircle == secondCircle);
    ASSERT_FALSE(firstCircle != secondCircle);
}