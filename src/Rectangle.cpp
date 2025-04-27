#include "Rectangle.hpp"

using SVG::Rectangle;

std::string Rectangle::print() const {
    std::string output = "";
    output = "<rect width=\"" + getWidth();
    output += "\" height=\"" + getHeight();
    output += "\"" + getFillAndStrokeToOs() + " />";
    return output;
}