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
                void edit() override;
                bool operator==(const Element& secElement) const override;
                bool operator!=(const Element& secElement) const override { return !(*this == secElement); }
                std::unique_ptr<Element> clone() const override { return std::make_unique<Rectangle>(*this); }
    };
}