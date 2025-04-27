#include "Text.hpp"

using SVG::Text;

std::string Text::print() const {
    std::string output = "";
    output += "<text x=\"" + getX();
    output += "\" y=\"" + getY();
    output += "\" font-size=\"" + getFontSize();
    output += "\" text-anchor=\"" + getTextAnchor() + "\""
    + getFillAndStrokeToOs() + ">" + getContent() + "</text>";
    return output;
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