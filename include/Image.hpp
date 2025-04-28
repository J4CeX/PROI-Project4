#pragma once
#include "Element.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Text.hpp"
#include <vector>
#include <memory>

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
            Image(Image&& secImage) noexcept = default;
            int getWidth() const { return width; }
            int getHeight() const { return height; }
            int getSize() const { return elements.size(); }
            void addElement(std::unique_ptr<Element> newElement);
            // void removeElement(const Element& rmElement);
            std::string print();
            Image& operator=(const Image& secImage);
            Image& operator=(Image&& secImage) noexcept = default;
            ~Image() = default;

            // class Iterator {
            //     private:
            //         std::vector<std::unique_ptr<Element>>::iterator current;
            //     public:
            //         Iterator(std::vector<std::unique_ptr<Element>>::iterator it) : current(it) {}
            //         Element& operator*() const { return *(*current); }
            //         Iterator& operator++() {
            //             ++current;
            //             return *this;
            //         }
            //         bool operator!=(const Iterator& secIterator) const { return current != secIterator.current; }
            //         std::vector<std::unique_ptr<Element>>::iterator getCurrent() const { return current; }
            //     };
            // Iterator begin() { return Iterator(elements.begin()); }
            // Iterator end() { return Iterator(elements.end()); }
    };
}