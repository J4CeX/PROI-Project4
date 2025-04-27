#pragma once
#include <vector>
#include "Element.hpp"

namespace SVG {
    class Image {
        private:
            std::vector<Element> elements;
        public:
            Image();
            Image(Image&& secImage) noexcept;
            Image& operator=(const Image& secImage) noexcept;
            ~Image();
    };
}