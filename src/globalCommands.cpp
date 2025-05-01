#include "globalCommands.hpp"

namespace SVG {
    int inputInt(const std::string& communique) {
        using std::cin;
        int x;
        while (true) {
            std::cout << communique; cin >> x;
            if (!cin) {
                cin.clear();
                cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
                std::cout << "\aWrong type of value!\n";
            }
            else  if (cin.get() != '\n') {
                cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
                continue;
            }
            else {
                return x;
            }
        }
    }
    std::string inputSingleString(const std::string& communique) {
        std::string singleString = "", stringStream;
        std::cout << communique;
        std::getline(std::cin, stringStream);
        for(int i = 0; i < stringStream.length(); i++) {
            if (stringStream[i] == '\n') break;
            singleString += stringStream[i];
        }
        return singleString;
    }
}