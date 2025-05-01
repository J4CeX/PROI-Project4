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
        setY(inputInt("X = "));
        setX(inputInt("Y = "));
        setRadius(inputInt("Radius"));
        std::string newFill = inputSingleString("Fill = ");
        if (newFill == "") setFill("none");
        else setFill(newFill);
        std::string newStroke = inputSingleString("Stroke = ");
        if (newStroke == "") setStroke("none");
        else setStroke(newStroke);
    }

    bool Circle::operator==(const Circle& secCircle) const {
        bool elementComparison = Element::operator==(secCircle);
        bool circleComparison = radius == secCircle.radius;
        return elementComparison && circleComparison;
    }
}