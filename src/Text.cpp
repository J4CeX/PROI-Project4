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

bool Text::operator==(const Text& secText) const {
    bool elementComparison = Element::operator==(secText);
    bool textComparison = true;
    if (fontSize != secText.fontSize) textComparison = false;
    if (textAnchor != secText.textAnchor) textComparison = false;
    if (content != secText.content) textComparison = false;
    return elementComparison && textComparison;
}

bool Text::operator!=(const Text& secText) const {
    return !(*this == secText);
}