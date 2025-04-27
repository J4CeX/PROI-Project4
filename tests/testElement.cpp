#include <gtest/gtest.h>
#include "Element.hpp"

using SVG::Element;

TEST(testElement, ElementCreator) {
    Element element(10, 20, 30, 40, "red", "blue");
    ASSERT_EQ(element.getX(), 10);
    ASSERT_EQ(element.getY(), 20);
    ASSERT_EQ(element.getWidth(), 30);
    ASSERT_EQ(element.getHeight(), 40);
    ASSERT_EQ(element.getFill(), "red");
    ASSERT_EQ(element.getStroke(), "blue");
}