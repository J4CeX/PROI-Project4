#pragma once
#include <iostream>
#include <limits>
#include "Rectangle.hpp"

class Menu {
    private:
        int inputInt(const std::string& communique="Option -> ");
        void createNewImage();
    public:
        Menu();
        ~Menu() = default;
};