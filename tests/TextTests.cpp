#include <gtest/gtest.h>
#include "Text.hpp"

using SVG::Text;

TEST(TextTests, TextConstructor) {
    Text text("some text", 10, 20, 30, "middle", "red", "blue");
    ASSERT_EQ(text.getContent(), "some text");
    ASSERT_EQ(text.getX(), 10);
    ASSERT_EQ(text.getY(), 20);
    ASSERT_EQ(text.getFontSize(), 30);
    ASSERT_EQ(text.getFill(), "red");
    ASSERT_EQ(text.getStroke(), "blue");
}

TEST(TextTests, TextDefaultValuesConstructor) {
    Text text("some text");
    ASSERT_EQ(text.getContent(), "some text");
    ASSERT_EQ(text.getX(), 0);
    ASSERT_EQ(text.getY(), 0);
    ASSERT_EQ(text.getFontSize(), 16);
    ASSERT_EQ(text.getFill(), "none");
    ASSERT_EQ(text.getStroke(), "none");
}

TEST(TextTests, TextCopy) {
    Text text("some text", 10, 20, 30, "middle", "red", "blue");
    Text secText("second some text", 1, 2, 3, "end", "green", "yellow");
    text = secText;
    ASSERT_EQ(text.getContent(), "second some text");
    ASSERT_EQ(text.getX(), 1);
    ASSERT_EQ(text.getY(), 2);
    ASSERT_EQ(text.getFontSize(), 3);
    ASSERT_EQ(text.getFill(), "green");
    ASSERT_EQ(text.getStroke(), "yellow");
    Text thText = text;
    ASSERT_EQ(thText.getContent(), "second some text");
    ASSERT_EQ(thText.getX(), 1);
    ASSERT_EQ(thText.getY(), 2);
    ASSERT_EQ(thText.getFontSize(), 3);
    ASSERT_EQ(thText.getFill(), "green");
    ASSERT_EQ(thText.getStroke(), "yellow");
}

TEST(TextTests, TextPrint) {
    Text text("some text", 10, 20, 30, "middle", "red", "blue");
    std::string expectedResult = "<text x=\"10\" y=\"20\" font-size=\"30\" text-anchor=\"middle\" fill=\"red\" stroke=\"blue\">some text</text>";
    ASSERT_EQ(text.print(), expectedResult);
}