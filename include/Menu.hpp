#pragma once
#include <iostream>
#include "globalCommands.hpp"
#include "Image.hpp"
#include "OutFile.hpp"

namespace SVG {
    class Menu {
        private:
            Image image;
            void createNewImage();
            void editImage();
            void createNewRectangle();
            void createNewText();
            void createNewCircle();
            void addNewElement();
            void removeElement();
            void editElement();
            void exportImage() const;
            void showElements() const;
            void showImage() const;
        public:
            Menu();
            ~Menu() = default;
    };
}