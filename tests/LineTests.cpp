#include <gtest/gtest.h>
#include "Line.hpp"

using SVG::Line;

TEST(LineTests, LineConstructor) {
    Line line(1, 2, 3, 4, 5, "red");
    ASSERT_EQ(line.getX(), 1);
    ASSERT_EQ(line.getY(), 2);
    ASSERT_EQ(line.getX2(), 3);
    ASSERT_EQ(line.getY2(), 4);
    ASSERT_EQ(line.getWidth(), 5);
    ASSERT_EQ(line.getStroke(), "red");
}

TEST(LineTests, LineDefaultValuesConstructor) {
    Line line(1, 2, 3, 4, 5);
    ASSERT_EQ(line.getX(), 1);
    ASSERT_EQ(line.getY(), 2);
    ASSERT_EQ(line.getX2(), 3);
    ASSERT_EQ(line.getY2(), 4);
    ASSERT_EQ(line.getWidth(), 5);
    ASSERT_EQ(line.getStroke(), "none");
}

TEST(LineTests, LineCopy) {
    Line line(1, 2, 3, 4, 5, "red");
    Line secLine(10, 20, 30, 40, 50, "green");
    line = secLine;
    ASSERT_EQ(line.getX(), 10);
    ASSERT_EQ(line.getY(), 20);
    ASSERT_EQ(line.getX2(), 30);
    ASSERT_EQ(line.getY2(), 40);
    ASSERT_EQ(line.getWidth(), 50);
    ASSERT_EQ(line.getStroke(), "green");
    Line thLine = secLine;
    ASSERT_EQ(line.getX(), 10);
    ASSERT_EQ(line.getY(), 20);
    ASSERT_EQ(line.getX2(), 30);
    ASSERT_EQ(line.getY2(), 40);
    ASSERT_EQ(line.getWidth(), 50);
    ASSERT_EQ(line.getStroke(), "green");
}

TEST(LineTests, LinePrint) {
    Line line(1, 2, 3, 4, 5, "red");
    std::string expectedLine = "<line x1=\"1\" y1=\"2\" x2=\"3\" y2=\"4\" stroke-width=\"5\" fill=\"none\" stroke=\"red\" />";
    ASSERT_EQ(line.print(), expectedLine);
}

TEST(LineTests, LineSetters) {
    Line line(1, 2, 3, 4, 5, "red");
    ASSERT_EQ(line.getX(), 1);
    ASSERT_EQ(line.getY(), 2);
    ASSERT_EQ(line.getX2(), 3);
    ASSERT_EQ(line.getY2(), 4);
    ASSERT_EQ(line.getWidth(), 5);
    ASSERT_EQ(line.getStroke(), "red");
    line.setX(10);
    line.setY(20);
    line.setX2(30);
    line.setY2(40);
    line.setWidth(50);
    line.setStroke("green");
    ASSERT_EQ(line.getX(), 10);
    ASSERT_EQ(line.getY(), 20);
    ASSERT_EQ(line.getX2(), 30);
    ASSERT_EQ(line.getY2(), 40);
    ASSERT_EQ(line.getWidth(), 50);
    ASSERT_EQ(line.getStroke(), "green");
}

TEST(LineTests, LineComparison) {
    Line firstLine(1, 2, 3, 4, 5, "red");
    Line secondLine(10, 20, 30, 40, 50, "green");
    ASSERT_TRUE(firstLine != secondLine);
    ASSERT_FALSE(firstLine == secondLine);
    firstLine = secondLine;
    ASSERT_TRUE(firstLine == secondLine);
    ASSERT_FALSE(firstLine != secondLine);
}