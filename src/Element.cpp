#include "Element.hpp"

namespace Element {
    Element::Element(Element&& secElement) {

    }

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

    Element& Element::operator=(Element&& secElement) {

    }

    std::string Element::getFillAndStrokeToFile() const {
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
}