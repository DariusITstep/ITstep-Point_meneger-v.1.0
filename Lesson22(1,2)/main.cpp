#include "Point.h"
#include <iostream>
#include <ctime>

using namespace std;

int randInt();

int main() {

    Point p1;
    srand(time(0));

    while (true) {

        cout << "\nYour current point:\n";
        p1.print();
        cout << endl;

        cout << "Select operation:\n"
            << "1. Set X\n"
            << "2. Set Y\n"
            << "3. Set Z\n"
            << "4. Random point position\n"
            << "5. Save Point\n"
            << "6. Load save point\n"
            << "0. Exit\n"
            << "Choice: ";

        int choice;
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input!\n";
            continue;
        }

        if (choice == 0) break;

        Point p2;
        switch (choice) {
        case 1:
            cout << "Enter X (max 1000): ";
            p1.setX(p1.inputInt());
            break;

        case 2:
            cout << "Enter Y (max 1000): ";
            p1.setY(p1.inputInt());
            break;

        case 3:
            cout << "Enter Z (max 1000): ";
            p1.setZ(p1.inputInt());
            break;

        case 4:
            p1.setX(randInt());
            p1.setY(randInt());
            p1.setZ(randInt());
            break;

        case 5:
            if (p1.saveToFile("point.txt")) {
                cout << "\nSaved to file!\n";
            }
            else {
                cout << "\nError saving file!\n";
            }
            break;

        case 6:
            if (p2.loadFromFile("point.txt")) {
                cout << "\nLoaded point complete!\n";
                p1 = p2;
            }
            else {
                cout << "\nError loading file!\n";
            }
            break;

        default:
            cout << "Wrong input!\n";
            break;
        }
    }
    return 0;
}

int randInt() {
    return rand() % 1000 + 1;
}