#include "Image.hpp"

using namespace SVG;

Image::Image(const Image& secImage) {
    size = secImage.size;
    elements = secImage.elements;
}

Image::Image(Image&& secImage) noexcept {
    size = secImage.size;
    elements = std::move(secImage.elements);
}

void Image::addElement(const Element& newElement) {
    elements.push_back(newElement);
    size++;
}

void Image::removeElement(const Element& rmElement) {
    for (Image::Iterator it = begin(); it != end(); ++it) {
        if (*it == rmElement) {
            elements.erase(it.getCurrent());
            size--;
            break;
        }
    }
}

Element& Image::operator[](const int& index) {
    if (index < size && index >= 0) {
        return elements[index];
    }
    else {
        throw std::out_of_range("Index out of range");
    }
}

Image& Image::operator=(const Image& secImage) {
    if (this != &secImage) {
        size = secImage.size;
        elements = secImage.elements;
    }
    return *this;
}

Image& Image::operator=(const Image&& secImage) noexcept {
    if (this != &secImage) {
        size = secImage.size;
        elements = std::move(secImage.elements);
    }
    return *this;
}
