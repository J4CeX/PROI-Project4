#include "Element.hpp"
#include <fstream>

namespace Element {
    class Rectangle: public Element {
        public:
            Rectangle(const int& width, const int& height,
                const int& x = 0, const int& y = 0,
                const std::string& fill = "none",
                const std::string& stroke = "none");
            friend std::ofstream& operator<<(std::ofstream& ofile, const Rectangle& rect);
    };
}