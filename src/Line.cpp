#include "Line.hpp"

using std::to_string;

namespace SVG {
    std::string Line::print() const {
        std::string output = "";
        output += "<line x1=\"" + to_string(getX());
        output += "\" y1=\"" + to_string(getY());
        output += "\" x2=\"" + to_string(getX2());
        output += "\" y2=\"" + to_string(getY2());
        output += "\" stroke-width=\"" + to_string(getWidth());
        output += "\"" + getFillAndStrokeToOs() + " />";
        return output;
    }

    void Line::edit() {
        setX(inputInt("X1 = "));
        setY(inputInt("Y1 = "));
        setX2(inputInt("X2 = "));
        setY2(inputInt("Y2 = "));
        setWidth(inputInt("Stoke Width = "));
        std::string newStroke = inputSingleString("Stroke = ");
        if (newStroke == "") setStroke("none");
        else setStroke(newStroke);
    }

    bool Line::operator==(const Element& secElement) const {
        const Line* secLine = dynamic_cast<const Line*>(&secElement);
        if (secLine) {
            if (getX() != secLine->getX()) return false;
            if (getY() != secLine->getY()) return false;
            if (getX2() != secLine->getX2()) return false;
            if (getY2() != secLine->getY2()) return false;
            if (getWidth() != secLine->getWidth()) return false;
            if (getStroke() != secLine->getStroke()) return false;
            return true;
        }
        return false;
    }
}