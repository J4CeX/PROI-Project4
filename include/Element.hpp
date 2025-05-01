#pragma once
#include <iostream>
#include <memory>
#include <cstring>
#include "globalCommands.hpp"

namespace SVG {
    class Element{
        private:
            int x, y, width, height;
            std::string fill, stroke;
        public:
            Element() = default;
            Element(const int& x, const int& y, const int& width, const int& height,
                const std::string& fill = "none", const std::string& stroke = "none")
                : x(x), y(y), width(width), height(height), fill(fill), stroke(stroke) {}
            Element(const Element& secElement) = default;
            int getX() const { return x; }
            int getY() const { return y; }
            int getWidth() const { return width; }
            int getHeight() const { return height; }
            std::string getFill() const { return fill; }
            std::string getStroke() const { return stroke; }
            std::string getFillAndStrokeToOs() const;
            void setX(const int& newX) { x = newX; }
            void setY(const int& newY) { y = newY; }
            void setWidtth(const int& newWidth) { width = newWidth; }
            void setHeight(const int& newHeight) { height = newHeight; }
            void setFill(const std::string& newFill) { fill = newFill; }
            void setStroke(const std::string& newStroke) { stroke = newStroke; }
            virtual std::string print() const = 0;
            virtual void edit() = 0;
            Element& operator=(const Element& secElement);
            std::string operator+(const Element& secElement) const;
            std::string operator+(const std::string& secString) const;
            void operator+=(std::string& secString) const;
            virtual bool operator==(const Element& secElement) const;
            virtual bool operator!=(const Element& secElement) const { return !(*this == secElement); }
            friend std::ostream& operator<<(std::ostream& os, const Element& element);
            friend std::istream& operator>>(std::istream& is, Element& element);
            virtual ~Element() = default;
            virtual std::unique_ptr<Element> clone() const = 0;
    };
    std::ostream& operator<<(std::ostream& os, const Element& element);
    std::istream& operator>>(std::istream& is, Element& element);
}