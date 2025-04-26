#include <iostream>
#include <fstream>

namespace Element {
    class Element{
        private:
            int x, y, width, height;
            std::string fill, stroke;
        public:
            Element(const int& x, const int& y, const int& width, const int& height,
                const std::string& fill = "none", const std::string& stroke = "none")
                : x(x), y(y), width(width), height(height), fill(fill), stroke(stroke) {}
            Element(const Element& secElement) = default;
            Element(Element&& secElement);
            int getX() const { return x; }
            int getY() const { return y; }
            int getWidth() const { return width; }
            int getHeight() const { return height; }
            std::string getFill() const { return fill; }
            std::string getStroke() const { return stroke; }
            std::string getFillAndStrokeToFile() const;
            Element& operator=(const Element& secElement);
            Element& operator=(Element&& secElement);
            virtual ~Element() = default;
    };
}