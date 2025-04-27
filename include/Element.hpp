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
            Element(Element&& secElement) noexcept;
            int getX() const { return x; }
            int getY() const { return y; }
            int getWidth() const { return width; }
            int getHeight() const { return height; }
            std::string getFill() const { return fill; }
            std::string getStroke() const { return stroke; }
            std::string getFillAndStrokeToFile() const;
            virtual std::string getFileOutput() const;
            virtual Element operator+(const Element& secElement) const;
            virtual Element& operator=(const Element& secElement);
            virtual Element& operator=(Element&& secElement) noexcept;
            friend std::ofstream& operator<<(std::ofstream& ofile, const Element& element);
            virtual ~Element() = default;
    };
    std::ofstream& operator<<(std::ofstream& ofile, const Element& element);
}