#include "Text.hpp"

using namespace Element;

std::ofstream& Element::operator<<(std::ofstream& ofile, const Text& text) {
    ofile << "<text x=\"" << text.getX() << "\" y=\"" << text.getY()
        << "\" font-size=\"" << text.getFontSize()
        << "\" text-anchor=\"" << text.getTextAnchor() << "\""
        << text.getFillAndStrokeToFile() << ">"
        << text.getContent() << "</text>" << std::endl;
}