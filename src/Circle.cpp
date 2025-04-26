#include "Circle.hpp"

using Element::Circle;

std::ofstream& Element::operator<<(std::ofstream& ofile, const Circle& circle) {
    ofile << "<circle cx=\"" << circle.getX()
        << "\" cy=\"" << circle.getY()
        << "\" r=\"" << circle.getRadius() << "\"";
    ofile << circle.getFillAndStrokeToFile();
    ofile << " />" << std::endl;
    return ofile;
}