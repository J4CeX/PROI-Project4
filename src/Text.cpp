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
        std::cout << "Content = ";
        std::getline(std::cin, content);
    }

    bool Text::operator==(const Element& secElement) const {
        const Text* secText = dynamic_cast<const Text*>(&secElement);
        if (secText) {
            if (getX() != secText->getX()) return false;
            if (getY() != secText->getY()) return false;
            if (getWidth() != secText->getWidth()) return false;
            if (getHeight() != secText->getHeight()) return false;
            if (getFill() != secText->getFill()) return false;
            if (getStroke() != secText->getStroke()) return false;
            if (fontSize != secText->fontSize) return false;
            if (textAnchor != secText->textAnchor) return false;
            if (content != secText->content) return false;
            return true;
        }
        return false;
    }
}