#include "Point.h"
#include <iostream>

using namespace std;

int main() {
    Point p1;

    cout << "Enter X (max 1000): ";
    p1.setX(p1.inputInt());

    cout << "Enter Y (max 1000): ";
    p1.setY(p1.inputInt());

    cout << "Enter Z (max 1000): ";
    p1.setZ(p1.inputInt());

    cout << "\nYour current point:\n";
    p1.print();

    // Збереження
    if (p1.saveToFile("point.txt")) {
        cout << "\nSaved to file\n";
    }
    else {
        cout << "\nError saving file\n";
    }

    // Додаємо другий об'єкт
    Point p2;

    // Завантаження
    if (p2.loadFromFile("point.txt")) {
        cout << "\nLoaded point:\n";
        p2.print();
    }
    else {
        cout << "\nError loading file\n";
    }

    return 0;
}