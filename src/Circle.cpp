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