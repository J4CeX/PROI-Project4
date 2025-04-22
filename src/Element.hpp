#include <iostream>
#include <fstream>

namespace Element {
    class Element{
        public:
            Element() = default;
            int x;
            int y;
            int width;
            int height;
            std::string fill;
            std::string stroke;
            virtual ~Element() = default;
            // virtual friend std::ofstream& operator<<(std::ofstream&, const Element&) {};
    };
}