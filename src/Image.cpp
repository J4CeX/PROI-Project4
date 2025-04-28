#include "Image.hpp"

using SVG::Image;
using SVG::Element;

Image::Image(const Image& secImage) {
    width = secImage.width;
    height = secImage.height;
}

Image::Image(Image&& secImage) noexcept {
    width = secImage.width;
    height = secImage.height;
    elements = std::move(secImage.elements);
}

// void Image::addElement(std::unique_ptr<Element> newElement) {
//     elements.push_back(std::move(newElement));
// }

// void Image::removeElement(const Element& rmElement) {
//     for (Image::Iterator it = begin(); it != end(); ++it) {
//         if (*it == rmElement) {
//             elements.erase(it.getCurrent());
//             break;
//         }
//     }
// }

// std::string Image::print() {
//     std::string output = "";
//     output += "<svg version=\"1.1\"";
//     output += "\n\twidth=\"" + getWidth();
//     output += "\" height=\"" + getHeight();
//     output += "\"\nxmlns=\"http://www.w3.org/2000/svg\">\n";
//     for (Image::Iterator it = begin(); it != end(); ++it) {
//         output += *it + "\n";
//     }
//     output += "<svg>\n";
//     return output;
// }

Image& Image::operator=(const Image& secImage) {
    if (this != &secImage) {
        width = secImage.width;
        height = secImage.height;
    }
    return *this;
}

Image& Image::operator=(const Image&& secImage) noexcept {
    if (this != &secImage) {
        width = secImage.width;
        height = secImage.height;
    }
    return *this;
}
