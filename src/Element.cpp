#include "Element.hpp"

namespace Element {
    Element::Element(Element&& secElement) noexcept {

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

    Element& Element::operator=(Element&& secElement) noexcept {

    }

    Element Element::operator+(const Element& secElement) const {

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

    std::string Element::getFileOutput() const {
        std::string fileOutput = "";
        fileOutput = "<rect width=\"" + getWidth();
        fileOutput += "\" height=\"" + getHeight();
        fileOutput += "\"" + getFillAndStrokeToFile() + " />";
        return fileOutput;
    }

    std::ofstream& operator<<(std::ofstream& ofile, const Element& element) {
        ofile << element.getFileOutput() << std::endl;
        return ofile;
    }
}