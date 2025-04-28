#include "Menu.hpp"

using SVG::Menu;
using std::cout, std::cin, std::endl;

Menu::Menu() {
    using std::cout, std::endl;
    while (true) {
        system("cls");
        cout << "-- Welcome to the svg image generator --" << endl
        << "1. Create new image" << endl
        << "2. Add new element" << endl
        << "3. Show image" << endl
        << "4. Export image" << endl
        << "0. Exit" << endl;
        int option;
        option = Menu::inputInt();
        if (option == 1) {
            createNewImage();
        }
        else if (option == 2) {
            addNewElement();
        }
        else if (option == 3) {
            showImage();
        }
        else if (option == 4) {
            exportImage();
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

std::string Menu::inputSingleString(const std::string& communique) {
    std::string singleString = "", stringStream;
    std::cout << communique;
    std::getline(cin, stringStream);
    for(int i = 0; i < stringStream.length(); i++) {
        if (stringStream[i] == '\n') break;
        singleString += stringStream[i];
    }
    return singleString;
}

void Menu::createNewImage() {
    system("cls");
    cout << "-- Creating new image --" << endl;
    int width = inputInt("Width = ");
    int height = inputInt("Height = ");
    image = Image(width, height);
}

void Menu::createNewRectangle() {
    system("cls");
    cout << "-- Creating new rectangle --" << endl;
    int width = inputInt("Width = ");
    int height = inputInt("Height = ");
    int x = inputInt("X = ");
    int y = inputInt("Y = ");
    std::string fill = inputSingleString("Fill = ");
    if (fill == "") fill = "none";
    std::string stroke = inputSingleString("Stroke = ");
    if (stroke == "") stroke = "none";
    Rectangle newRectangle(width, height, x, y, fill, stroke);
    system("cls");
    cout << "-- Created rectangle --" << endl << endl
        << newRectangle << endl << endl;
    image.addElement<Rectangle>(newRectangle);
    system("pause");
}

void Menu::createNewText() {
    system("cls");
    cout << "-- Creating new text --" << endl;
    int x = inputInt("X = ");
    int y = inputInt("Y = ");
    int fontSize = inputInt("Font-size = ");
    std::string textAnchor = inputSingleString("Text-anchor = ");
    std::string fill = inputSingleString("Fill = ");
    if (fill == "") fill = "none";
    std::string stroke = inputSingleString("Stroke = ");
    if (stroke == "") stroke = "none";
    std::string content;
    cout << "Content = ";
    std::getline(cin, content);
    Text newText(content, x, y, fontSize, textAnchor, fill, stroke);
    system("cls");
    cout << "-- Created text --" << endl << endl
        << newText << endl << endl;
    image.addElement<Text>(newText);
    system("pause");
}

void Menu::createNewCircle() {
    system("cls");
    cout << "-- Creating new circle --" << endl;
    int radius = inputInt("Radius = ");
    int cx = inputInt("CX = ");
    int cy = inputInt("CY = ");
    std::string fill = inputSingleString("Fill = ");
    if (fill == "") fill = "none";
    std::string stroke = inputSingleString("Stroke = ");
    if (stroke == "") stroke = "none";
    Circle newCircle(radius, cx, cy, fill, stroke);
    system("cls");
    cout << "-- Created cricle --" << endl << endl
        << newCircle << endl << endl;
    image.addElement<Circle>(newCircle);
    system("pause");
}

void Menu::addNewElement() {
    if (image.getWidth() && image.getHeight()) {
        while (true) {
            system("cls");
            cout << "-- Adding new element --" << endl
                << "1. Creat new rectangle" << endl
                << "2. Creat new circle" << endl
                << "3. Creat new text" << endl
                << "0. Cancel" << endl;
            int option = inputInt();
            if (option == 1) {
                createNewRectangle();
            }
            else if (option == 2) {
                createNewCircle();
            }
            else if (option == 3) {
                createNewText();
            }
            else if (option == 0) {
                system("cls");
                cout << "-- Adding abonded --" << endl;
                system("pause");
                break;
            }
            else {
                cout << "-- Wrong option! --\a" << endl;
                system("pause");
            }
        }
    }
    else {
        system("cls");
        cout << "-- There is not created image --" << endl;
        system("pause");
    }
}

void Menu::exportImage() const {
    OutFile outFile("image.html");

    system("cls");
    if (image.getWidth() && image.getHeight() && image.getSize()) {
        outFile.saveFile(image);
        cout << "-- Image saved --" << endl << endl
            << image << endl << endl;
    }
    else {
        cout << "-- There is not created image --" << endl;
    }
    system("pause");
}

void Menu::showImage() const {
    system("cls");
    if (image.getWidth() && image.getHeight()) {
        cout << "-- Showing image --" << endl << endl
            << image << endl << endl;
    }
    else {
        cout << "-- There is not created image --" << endl;
    }
    system("pause");
}