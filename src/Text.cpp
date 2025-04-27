#include "Text.hpp"

using SVG::Text;

std::string Text::print() const {
    std::string fileOutput = "";
    fileOutput += "<text x=\"" + getX();
    fileOutput += "\" y=\"" + getY();
    fileOutput += "\" font-size=\"" + getFontSize();
    fileOutput += "\" text-anchor=\"" + getTextAnchor() + "\""
    + getFillAndStrokeToOs() + ">" + getContent() + "</text>";
    return fileOutput;
}