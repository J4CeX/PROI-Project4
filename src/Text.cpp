#include "Text.hpp"

using Element::Text;

std::string Text::getFileOutput() const {
    std::string fileOutput = "";
    fileOutput += "<text x=\"" + getX();
    fileOutput += "\" y=\"" + getY();
    fileOutput += "\" font-size=\"" + getFontSize();
    fileOutput += "\" text-anchor=\"" + getTextAnchor() + "\""
    + getFillAndStrokeToFile() + ">" + getContent() + "</text>";
    return fileOutput;
}