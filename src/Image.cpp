#include "Image.hpp"

using SVG::Image;
using SVG::Element;
using std::to_string;

Image::Image(const Image& other) {
    for (const auto& elem : other.elements) {
        elements.push_back(elem->clone());
    }
}

Image::Image(Image&& secImage) noexcept {
    width = secImage.width;
    height = secImage.height;
    elements = std::move(secImage.elements);
    secImage.width = 0;
    secImage.height = 0;
}

std::string Image::print() const {
    std::string output = "";
    output += "<svg version=\"1.1\"";
    output += "\n\twidth=\"" + to_string(getWidth());
    output += "\" height=\"" + to_string(getHeight());
    output += "\"\n\txmlns=\"http://www.w3.org/2000/svg\">\n";
    for (auto& element: elements) {
        output += "\t" + element->print() + "\n";
    }
    output += "</svg>\n";
    return output;
}

Image& Image::operator=(const Image& other) {
    if (this != &other) {
        elements.clear();
        for (const auto& elem : other.elements) {
            elements.push_back(elem->clone());
        }
    }
    return *this;
}


Image& Image::operator=(Image&& secImage) noexcept {
    if (this != &secImage) {
        width = secImage.width;
        height = secImage.height;
        elements = std::move(secImage.elements);
        secImage.width = 0;
        secImage.height = 0;
    }
    return *this;
}

namespace SVG {
    std::ostream& operator<<(std::ostream& os, const Image& image) {
        os << image.print();
        return os;
    }
}