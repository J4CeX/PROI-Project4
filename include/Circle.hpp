#pragma once
#include "Element.hpp"

namespace SVG {
    class Circle: public Element {
        private:
            int radius;
        public:
            Circle(int width, int height, int radius,
                int x = 0, int y = 0,
                const std::string& fill = "none",
                const std::string& stroke = "none")
                : Element(x, y, width, height, fill, stroke),
                radius(radius) {};
            int getRadius() const { return radius; }
            bool operator==(const Circle& secCircle) const;
            bool operator!=(const Circle& secCircle) const { return !(*this == secCircle); }
            std::string print() const override;
    };
}