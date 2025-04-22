#include "Menu.hpp"

Menu::Menu() {
    using std::cout, std::endl;
    using namespace Element;
    while (true) {
        system("cls");
        cout << "-- Welcome to the svg image generator --" << endl
        << "1. Create new image" << endl
        << "0. Exit" << endl;
        int option;
        option = Menu::inputInt();
        if (option == 1) {
            Rectangle rect(100, 100, 10, 10, "red", "blue");
            std::ofstream ofile;
            ofile.open("test.html", std::ios::out);
            if (ofile.good()) {
                ofile << rect;
            }
            ofile.close();
        }
        else if (option == 0) {
            system("cls");
            cout << "-- Good bye --" << endl;
            system("pause");
            break;
        }
        else {
            cout << "-- Wrong option! --\a" << endl;
            system("pause");
        }

    }
}

int Menu::inputInt(const std::string& communique) {
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