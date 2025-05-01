#include "Image.hpp"

namespace SVG {
    using std::to_string;

    Image::Image() {
        width = 0;
        height = 0;
        std::vector<std::unique_ptr<Element>> emptyElements = {};
        elements = std::move(emptyElements);
    }

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

    void Image::removeElement(SVG::Element* element) {
        auto it = std::find_if(begin(), end(), [=](SVG::Element* el) {
            return el == element;
        });
        if (it != end()) {
            elements.erase(it.base());
        }
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

    Element* Image::operator[](int index) const {
        if (index >= 0 && index < elements.size())
            return elements[index].get();
        else
            throw std::out_of_range("Index out of range!");
    }

    std::ostream& operator<<(std::ostream& os, const Image& image) {
        os << image.print();
        return os;
    }
}