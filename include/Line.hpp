#pragma once
#include "Element.hpp"

namespace SVG {
    class Line : public Element {
        private:
            int x2, y2;
            double strokeDasharray;
        public:
            Line(const int& x1, const int& y1, const int& x2,
                const int& y2, const int& strokeWidth,
                const std::string& stroke = "none")
                : Element(x1, y1, strokeWidth, 0, "none", stroke),
                x2(x2), y2(y2), strokeDasharray(strokeDasharray) {};
            int getX2() const { return x2; }
            int getY2() const { return y2; }
            void setX2(const int& newX2) { x2 = newX2; }
            void setY2(const int& newY2) { y2 = newY2; }
            bool operator==(const Element& secElement) const override;
            bool operator!=(const Element& secElement) const override { return !(*this == secElement); }
            std::string print() const override;
            void edit() override;
            std::unique_ptr<Element> clone() const override { return std::make_unique<Line>(*this); }
    };
}