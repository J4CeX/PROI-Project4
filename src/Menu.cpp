#include "Menu.hpp"

using std::cout, std::cin, std::endl;

namespace SVG {
    Menu::Menu() {
        using std::cout, std::endl;
        while (true) {
            system("cls");
            cout << "-- Welcome to the svg image generator --" << endl
            << "1. Create new image" << endl
            << "2. Edit image" << endl
            << "3. Add new element" << endl
            << "4. Edit element" << endl
            << "5. Remove element" << endl
            << "6. Show image" << endl
            << "7. Export image" << endl
            << "0. Exit" << endl;
            int option;
            option = inputInt();
            if (option == 1) {
                createNewImage();
            }
            else if (option == 2) {
                editImage();
            }
            else if (option == 3) {
                addNewElement();
            }
            else if (option == 4) {
                editElement();
            }
            else if (option == 5) {
                removeElement();
            }
            else if (option == 6) {
                showImage();
            }
            else if (option == 7) {
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

    void Menu::createNewImage() {
        system("cls");
        cout << "-- Creating new image --" << endl;
        int width = inputInt("Width = ");
        int height = inputInt("Height = ");
        image = Image(width, height);
    }

    void Menu::editImage() {
        system("cls");
        if (image.getWidth() && image.getHeight()) {
            cout << "-- Image editing --" << endl
                << "Current width = " << image.getWidth() << endl
                << "Current height = " << image.getHeight() << endl;
                image.setWidth(inputInt("New width = "));
                image.setHeight(inputInt("New height = "));
                cout << "-- Editing completed --" << endl;
        }
        else {
            cout << "-- There is not created image --" << endl;
        }
        system("pause");
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

    void Menu::createNewLine() {
        system("cls");
        cout << "-- Creating new Line --" << endl;
        int x1 = inputInt("X1 = ");
        int y1 = inputInt("Y1 = ");
        int x2 = inputInt("X2 = ");
        int y2 = inputInt("Y2 = ");
        int strokeWidth = inputInt("Stroke Width = ");
        std::string stroke = inputSingleString("Stroke = ");
        if (stroke == "") stroke = "none";
        Line newLine(x1, y1, x2, y2, strokeWidth, stroke);
        system("cls");
        cout << "-- Created cricle --" << endl << endl
            << newLine << endl << endl;
        image.addElement<Line>(newLine);
        system("pause");
    }

    void Menu::addNewElement() {
        if (image.getWidth() && image.getHeight()) {
            while (true) {
                system("cls");
                cout << "-- Adding new element --" << endl
                    << "1. Create new rectangle" << endl
                    << "2. Create new circle" << endl
                    << "3. Create new text" << endl
                    << "4. Create new line" << endl
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
                else if (option == 4) {
                    createNewLine();
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

    void Menu::removeElement() {
        if (image.getSize() > 0) {
            while(true) {
                system("cls");
                cout << "-- Element removing --" << endl;
                showElements();
                cout << endl;
                int index = inputInt("Choose element's index to remove (0 to abond) -> ");
                if (index == 0) {
                    system("cls");
                    cout << "-- Removing abonded --" << endl;
                    break;
                }
                else if (index > 0; index <= image.getSize()) {
                    system("cls");
                    cout << "-- Removing completed --" << endl;
                    cout << *image[index - 1] << endl << endl;
                    image.removeElement(image[index - 1]);
                    break;
                }
                else {
                    cout << "-- Wrong index! --" << endl;
                    system("pause");
                }
            }
        }
        else {
            system("cls");
            cout << "-- There are not any elements to edit --" << endl;
        }
        system("pause");
    }

    void Menu::editElement() {
        if (image.getSize() > 0) {
            while(true) {
                system("cls");
                cout << "-- Element editing --" << endl;
                showElements();
                cout << endl;
                int index = inputInt("Choose element's index to edit (0 to abond) -> ");
                if (index == 0) {
                    system("cls");
                    cout << "-- Editing abonded --" << endl;
                    break;
                }
                else if (index > 0; index <= image.getSize()) {
                    system("cls");
                    cout << "-- Element editing --" << endl
                        << "Current values: " << endl
                        << *image[index - 1] << endl
                        << "New values: " << endl;
                    cin >> *image[index - 1];
                    cout << "Editing completed" << endl;
                    break;
                }
                else {
                    cout << "-- Wrong index! --" << endl;
                    system("pause");
                }
            }
        }
        else {
            system("cls");
            cout << "-- There are not any elements to edit --" << endl;
        }
        system("pause");
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

    void Menu::showElements() const {
        if (image.getSize() > 0) {
            cout << endl << endl;
            for (int i = 0; i < image.getSize(); i++) {
                    cout << i + 1 << ". " << *image[i];
            }
            cout << endl;
        }
        else {
            cout << "-- There ate not any created elements --" << endl;
        }
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
}