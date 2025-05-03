#include "Rectangle.hpp"

using std::to_string;

namespace SVG {
    std::string Rectangle::print() const {
        std::string output = "";
        output = "<rect x=\"" + to_string(getX());
        output += "\" y=\"" + to_string(getY());
        output += "\" width=\"" + to_string(getWidth());
        output += "\" height=\"" + to_string(getHeight());
        output += "\"" + getFillAndStrokeToOs() + " />";
        return output;
    }

    void Rectangle::edit() {
        setWidth(inputInt("Width = "));
        setHeight(inputInt("Height = "));
        setY(inputInt("X = "));
        setX(inputInt("Y = "));
        std::string newFill = inputSingleString("Fill = ");
        if (newFill == "") setFill("none");
        else setFill(newFill);
        std::string newStroke = inputSingleString("Stroke = ");
        if (newStroke == "") setStroke("none");
        else setStroke(newStroke);
    }

    bool Rectangle::operator==(const Rectangle& secRectangle) const {
        return Element::operator==(secRectangle);
    }
}