#include "Rectangle.hpp"

using namespace Element;

std::ofstream& Element::operator<<(std::ofstream& ofile, const Rectangle& rect) {
    ofile << "<rect width=\"" << rect.getWidth()
        << "\" height=\"" << rect.getHeight() << "\"";
    if (rect.getFill() != "none") {
        ofile << " fill=\"" << rect.getFill() << "\"";
    }
    if (rect.getStroke() != "none") {
        if (rect.getFill() == "none") {
            ofile << " fill=\"" << rect.getFill() << "\"";
        }
        ofile << " stroke=\"" << rect.getStroke() << "\"";
    }
    ofile << "/>" << std::endl;
    system("pause");
    return ofile;
}