#pragma once
#include "Element.hpp"

namespace SVG {
    class Rectangle: public Element {
        public:
            Rectangle(int width, int height,
                int x = 0, int y = 0,
                const std::string& fill = "none",
                const std::string& stroke = "none")
                : Element(x, y, width, height, fill, stroke) {};
                std::string print() const override;
    };
}