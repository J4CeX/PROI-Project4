#include "Circle.hpp"

using SVG::Circle;

std::string Circle::print() const {
    std::string fileOutput = "";
    fileOutput += "<circle cx=\"" + getX();
    fileOutput += "\" cy=\"" + getY();
    fileOutput += "\" r=\"" + getRadius();
    fileOutput += "\"" + getFillAndStrokeToOs() + " />";
    return fileOutput;
}

bool Circle::operator==(const Circle& secCircle) const {
    bool elementComparison = Element::operator==(secCircle);
    bool circleComparison = radius == secCircle.radius;
    return elementComparison && circleComparison;
}