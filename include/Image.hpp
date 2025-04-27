#pragma once
#include "Element.hpp"
#include <vector>

namespace SVG {
    class Image {
        private:
            std::vector<Element> elements;
            int size;
        public:
            Image() = delete;
            Image(std::vector<Element> elements)
                : elements(elements), size(elements.size()) {}
            Image(const Image& secImage);
            Image(Image&& secImage) noexcept;
            int getSize() const { return size; }
            void addElement(const Element& newElement);
            void removeElement(const Element& rmElement);
            Element& operator[](const int& index);
            Image& operator=(const Image& secImage);
            Image& operator=(const Image&& secImage) noexcept;
            ~Image() {};

            class Iterator {
                private:
                    std::vector<Element>::iterator current;
                public:
                    Iterator(std::vector<Element>::iterator it): current(it) {}
                    Element operator*() const { return *current; }
                    Iterator& operator++() {
                        ++current;
                        return *this;
                    }
                    bool operator!=(const Iterator& secIterator) const { return current != secIterator.current; }
                    std::vector<Element>::iterator getCurrent() const { return current; }
                };
            Iterator begin() { return Iterator(elements.begin()); }
            Iterator end() { return Iterator(elements.end()); }
    };
}