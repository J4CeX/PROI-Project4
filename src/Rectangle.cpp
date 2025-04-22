#include "Rectangle.hpp"

using namespace Element;

Rectangle::Rectangle(const int& width, const int& height,
    const int& x, const int& y,
    const std::string& fill,
    const std::string& stroke) {
    this->width = width;
    this->height = height;
    this->x = x;
    this->y = y;
    this->fill = fill;
    this->stroke = stroke;
}

std::ofstream& Element::operator<<(std::ofstream& ofile, const Rectangle& rect) {
    ofile << "<rect width=" << rect.width << " height=" << rect.height;
    if (rect.fill != "none") {
        ofile << " fill=" << rect.fill;
    }
    if (rect.stroke != "none") {
        if (rect.fill == "none") {
            ofile << " fill=" << rect.fill;
        }
        ofile << "stroke=" << rect.stroke;
    }
    ofile << "/>" << std::endl;
    system("pause");
    return ofile;
}