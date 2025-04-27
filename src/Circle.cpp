#include "Circle.hpp"

using Element::Circle;

std::string Circle::getFileOutput() const {
    std::string fileOutput = "";
    fileOutput += "<circle cx=\"" + getX();
    fileOutput += "\" cy=\"" + getY();
    fileOutput += "\" r=\"" + getRadius();
    fileOutput += "\"" + getFillAndStrokeToFile() + " />";
    return fileOutput;
}