#pragma once
#include <iostream>
#include <limits>
#include <cstring>
#include "Image.hpp"
#include "OutFile.hpp"

namespace SVG {
    class Menu {
        private:
            Image image;
            int inputInt(const std::string& communique="Option -> ");
            std::string inputSingleString(const std::string& communique="Option -> ");
            void createNewImage();
            void createNewRectangle();
            void createNewText();
            void createNewCircle();
            void addNewElement();
            void exportImage() const;
            void showImage() const;
        public:
            Menu();
            ~Menu() = default;
    };
}