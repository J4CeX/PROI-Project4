#include "Circle.hpp"

using SVG::Circle;
using std::to_string;

std::string Circle::print() const {
    std::string output = "";
    output += "<circle cx=\"" + to_string(getX());
    output += "\" cy=\"" + to_string(getY());
    output += "\" r=\"" + to_string(getRadius());
    output += "\"" + getFillAndStrokeToOs() + " />";
    return output;
}

bool Circle::operator==(const Circle& secCircle) const {
    bool elementComparison = Element::operator==(secCircle);
    bool circleComparison = radius == secCircle.radius;
    return elementComparison && circleComparison;
}