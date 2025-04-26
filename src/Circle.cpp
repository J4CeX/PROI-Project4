#include "Circle.hpp"

using namespace Element;

std::ofstream& Element::operator<<(std::ofstream& ofile, const Circle& circle) {
    ofile << "<circle cx=\"" << circle.getX()
        << "\" cy=\"" << circle.getY()
        << "\" r=\"" << circle.getRadius() << "\"";
    ofile << circle.getFillAndStroke();
    ofile << "/>" << std::endl;
    return ofile;
}