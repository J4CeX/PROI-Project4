#pragma once
#include "Element.hpp"

namespace SVG {
    class Circle: public Element {
        private:
            int radius;
        public:
            Circle(const int& radius, const int& x = 0, const int& y = 0,
                const std::string& fill = "none",
                const std::string& stroke = "none")
                : Element(x, y, 0, 0, fill, stroke),
                radius(radius) {};
            int getRadius() const { return radius; }
            bool operator==(const Circle& secCircle) const;
            bool operator!=(const Circle& secCircle) const { return !(*this == secCircle); }
            std::string print() const override;
    };
}