#pragma once
#include <iostream>
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
            Image();
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
            void removeElement(SVG::Element* element);
            std::string print() const;
            Image& operator=(const Image& secImage);
            Image& operator=(Image&& secImage) noexcept;
            Element* operator[](int index) const;
            friend std::ostream& operator<<(std::ostream& os, const Image& image);
            ~Image() = default;
            class Iterator {
                private:
                    using VecIter = std::vector<std::unique_ptr<Element>>::iterator;
                    VecIter iter;
                public:
                    Iterator(VecIter it) : iter(it) {}

                    Iterator& operator++() { ++iter; return *this; }
                    bool operator!=(const Iterator& other) const { return iter != other.iter; }
                    SVG::Element* operator*() const { return iter->get(); }
                    VecIter base() const { return iter; }
                };

                Iterator begin() { return Iterator(elements.begin()); }
                Iterator end() { return Iterator(elements.end()); }

    };
    std::ostream& operator<<(std::ostream& os, const Image& image);
}