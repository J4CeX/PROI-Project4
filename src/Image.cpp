#include "Image.hpp"

using SVG::Image;
using SVG::Element;
using std::to_string;

Image::Image(const Image& other) {
    for (const auto& elem : other.elements) {
        elements.push_back(elem->clone());
    }
}

// Image::Image(Image&& secImage) noexcept {
//     width = secImage.width;
//     height = secImage.height;
//     elements = std::move(secImage.elements);
// }

void Image::addElement(std::unique_ptr<Element> newElement) {
    elements.push_back(std::move(newElement));
}

// void Image::removeElement(const Element& rmElement) {
//     for (Image::Iterator it = begin(); it != end(); ++it) {
//         if (*it == rmElement) {
//             elements.erase(it.getCurrent());
//             break;
//         }
//     }
// }

std::string Image::print() {
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


// Image& Image::operator=(Image&& secImage) noexcept {
//     if (this != &secImage) {
//         width = secImage.width;
//         height = secImage.height;
//         elements = std::move(secImage.elements);
//     }
//     return *this;
// }
