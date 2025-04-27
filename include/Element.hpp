#include <iostream>

namespace SVG {
    class Element{
        private:
            int x, y, width, height;
            std::string fill, stroke;
        public:
            Element() = delete;
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
            virtual std::string print() const = 0;
            Element& operator=(const Element& secElement);
            std::string operator+(const Element& secElement) const;
            std::string operator+(const std::string& secString) const;
            void operator+=(std::string& secString) const;
            virtual bool operator==(const Element& secElement) const;
            virtual bool operator!=(const Element& secElement) const { return !(*this == secElement); }
            friend std::ostream& operator<<(std::ostream& os, const Element& element);
            virtual ~Element() = default;
    };
    std::ostream& operator<<(std::ostream& os, const Element& element);
}