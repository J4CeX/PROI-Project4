#include "Rectangle.hpp"

using Element::Rectangle;

std::ofstream& Element::operator<<(std::ofstream& ofile, const Rectangle& rectangle) {
    ofile << "<rect width=\"" << rectangle.getWidth()
        << "\" height=\"" << rectangle.getHeight() << "\"";
    ofile << rectangle.getFillAndStrokeToFile();
    ofile << " />" << std::endl;
    return ofile;
}