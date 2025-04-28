#pragma once
#include "Element.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Text.hpp"
#include <vector>
#include <memory>
#include <algorithm>

namespace SVG {
    class Image {
        private:
            std::vector<std::unique_ptr<Element>> elements;
            int width;
            int height;
        public:
            Image(const int& width, const int& height, std::vector<std::unique_ptr<Element>> elements = {})
                : width(width), height(height), elements(std::move(elements)) {}
            Image(const Image& secImage);
            Image(Image&& secImage) noexcept;
            int getWidth() const { return width; }
            int getHeight() const { return height; }
            int getSize() const { return elements.size(); }
            template<typename T, typename... Args>
            void addElement(Args&&... args) {
                elements.push_back(std::make_unique<T>(std::forward<Args>(args)...));
            }
            std::string print();
            Image& operator=(const Image& secImage);
            Image& operator=(Image&& secImage) noexcept;
            ~Image() = default;
    };
}