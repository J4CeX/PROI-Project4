#include "Text.hpp"

using std::to_string;

namespace SVG {
    std::string Text::print() const {
        std::string output = "";
        output += "<text x=\"" + to_string(getX());
        output += "\" y=\"" + to_string(getY());
        output += "\" font-size=\"" + to_string(getFontSize());
        output += "\" text-anchor=\"" + getTextAnchor();
        output += "\"" + getFillAndStrokeToOs() + ">" + getContent() + "</text>";
        return output;
    }


    void Text::edit() {
        setY(inputInt("X = "));
        setX(inputInt("Y = "));
        setFontSize(inputInt("Font-size = "));
        std::string newTextAnchor = inputSingleString("Text-anchor = ");
        if (newTextAnchor == "") setTextAnchor("none");
        else setTextAnchor(newTextAnchor);
        std::string newFill = inputSingleString("Fill = ");
        if (newFill == "") setFill("none");
        else setFill(newFill);
        std::string newStroke = inputSingleString("Stroke = ");
        if (newStroke == "") setStroke("none");
        else setStroke(newStroke);
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
}