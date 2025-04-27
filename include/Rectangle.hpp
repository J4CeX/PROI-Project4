#include "Element.hpp"
#include <fstream>

namespace Element {
    class Rectangle: public Element {
        public:
            Rectangle(int width, int height,
                int x = 0, int y = 0,
                const std::string& fill = "none",
                const std::string& stroke = "none")
                : Element(x, y, width, height, fill, stroke) {};
    };
}