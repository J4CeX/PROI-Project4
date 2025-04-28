#include "Text.hpp"

using SVG::Text;
using std::to_string;

std::string Text::print() const {
    std::string output = "";
    output += "<text x=\"" + to_string(getX());
    output += "\" y=\"" + to_string(getY());
    output += "\" font-size=\"" + to_string(getFontSize());
    output += "\" text-anchor=\"" + getTextAnchor();
    output += "\"" + getFillAndStrokeToOs() + ">" + getContent() + "</text>";
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