#pragma once
#include <iostream>
#include <limits>
#include "Rectangle.hpp"
#include <fstream>

class Menu {
    private:
        int inputInt(const std::string& communique="Option -> ");
    public:
        Menu();
        ~Menu() = default;
};