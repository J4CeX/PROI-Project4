#include "Rectangle.hpp"

using SVG::Rectangle;
using std::to_string;

std::string Rectangle::print() const {
    std::string output = "";
    output = "<rect x=\"" + to_string(getX());
    output += "\" y=\"" + to_string(getY());
    output += "\" width=\"" + to_string(getWidth());
    output += "\" height=\"" + to_string(getHeight());
    output += "\"" + getFillAndStrokeToOs() + " />";
    return output;
}