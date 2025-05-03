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

    std::string Element::operator+(const Element& secElement) const {
        return print() + secElement.print();
    }

    std::string Element::operator+(const std::string& secString) const {
        return secString + print();
    }

    void Element::operator+=(std::string& secString) const {
        secString += print();
    }

    std::string Element::getFillAndStrokeToOs() const {
        {
            std::string fillAndStroke = "";
            if (fill != "none") {
                fillAndStroke += " fill=\"" + fill + "\"";
            }
            if (stroke != "none") {
                if (fill == "none") {
                    fillAndStroke += " fill=\"" + fill + "\"";
                }
                fillAndStroke += " stroke=\"" + stroke + "\"";
            }
            return fillAndStroke;
        }
    }

    std::ostream& operator<<(std::ostream& os, const Element& element) {
        os << element.print() << std::endl;
        return os;
    }

    std::istream& operator>>(std::istream& is, Element& element) {
        element.edit();
        return is;
    }
}