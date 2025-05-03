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
            void setRadius(const int& newRadius) { radius = newRadius; }
            bool operator==(const Element& secElement) const override;
            bool operator!=(const Element& secElement) const override { return !(*this == secElement); }
            std::string print() const override;
            void edit() override;
            std::unique_ptr<Element> clone() const override { return std::make_unique<Circle>(*this); }
    };
}