#include "Element.hpp"
#include <fstream>

namespace Element {
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
            friend std::ofstream& operator<<(std::ofstream& oflie, const Circle& circle);
    };
    std::ofstream& operator<<(std::ofstream& oflie, const Circle& circle);
}