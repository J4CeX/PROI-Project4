#include "Element.hpp"

namespace SVG {
    Element& Element::operator=(const Element& secElement) {
        if (this != &secElement) {
            x = secElement.x;
            y = secElement.y;
            width = secElement.width;
            height = secElement.height;
            fill = secElement.fill;
            stroke = secElement.stroke;
        }
        return *this;
    }

    std::string Element::getFillAndStrokeToOs() const {
        {
            std::string fillAndStroke = "";
            if (fill != "none") {
                fillAndStroke += " fill=\"" + fill + "\"";
            }
            if (stroke != "none") {
                if (fill == "none") {
                    fillAndStroke += " fill+=\"" + fill + "\"";
                }
                fillAndStroke += " stroke=\"" + stroke + "\"";
            }
            return fillAndStroke;
        }
    }

    std::string Element::print() const {
        std::string fileOutput = "";
        fileOutput = "<rect width=\"" + getWidth();
        fileOutput += "\" height=\"" + getHeight();
        fileOutput += "\"" + getFillAndStrokeToOs() + " />";
        return fileOutput;
    }

    std::ostream& operator<<(std::ostream& os, const Element& element) {
        os << element.getFillAndStrokeToOs() << std::endl;
        return os;
    }
}