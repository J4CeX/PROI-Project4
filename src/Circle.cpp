#include "Circle.hpp"

using std::to_string;

namespace SVG {
    std::string Circle::print() const {
        std::string output = "";
        output += "<circle cx=\"" + to_string(getX());
        output += "\" cy=\"" + to_string(getY());
        output += "\" r=\"" + to_string(getRadius());
        output += "\"" + getFillAndStrokeToOs() + " />";
        return output;
    }

    void Circle::edit() {
        setX(inputInt("X = "));
        setY(inputInt("Y = "));
        setRadius(inputInt("Radius = "));
        std::string newFill = inputSingleString("Fill = ");
        if (newFill == "") setFill("none");
        else setFill(newFill);
        std::string newStroke = inputSingleString("Stroke = ");
        if (newStroke == "") setStroke("none");
        else setStroke(newStroke);
    }

    bool Circle::operator==(const Element& secElement) const {
        const Circle* secCircle = dynamic_cast<const Circle*>(&secElement);
        if (secCircle) {
            if (getX() != secCircle->getX()) return false;
            if (getY() != secCircle->getY()) return false;
            if (getWidth() != secCircle->getWidth()) return false;
            if (getHeight() != secCircle->getHeight()) return false;
            if (getFill() != secCircle->getFill()) return false;
            if (getStroke() != secCircle->getStroke()) return false;
            if (radius != secCircle->radius) return false;
            return true;
        }
        return false;
    }
}