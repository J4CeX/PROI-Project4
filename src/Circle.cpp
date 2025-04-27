#include "Circle.hpp"

using SVG::Circle;

std::string Circle::print() const {
    std::string output = "";
    output += "<circle cx=\"" + getX();
    output += "\" cy=\"" + getY();
    output += "\" r=\"" + getRadius();
    output += "\"" + getFillAndStrokeToOs() + " />";
    return output;
}

bool Circle::operator==(const Circle& secCircle) const {
    bool elementComparison = Element::operator==(secCircle);
    bool circleComparison = radius == secCircle.radius;
    return elementComparison && circleComparison;
}