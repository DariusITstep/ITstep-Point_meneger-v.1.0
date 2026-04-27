#include "Point.h"
#include "PointUtils.h"
#include <iostream>
#include <ctime>

using namespace std;

int main() {

    Point p1;
    srand(time(0));

    while (true) {

        cout << "\nYour current point:\n";
        p1.print();

        cout << "\nSelect operation:\n"
            << "1. Set X\n"
            << "2. Set Y\n"
            << "3. Set Z\n"
            << "4. Random point\n"
            << "5. Save\n"
            << "6. Load\n"
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

        Point temp;

        switch (choice) {

        case 1:
            cout << "Enter X (-1000..1000): ";
            p1.setX(Input::readInt(-1000, 1000));
            break;

        case 2:
            cout << "Enter Y (-1000..1000): ";
            p1.setY(Input::readInt(-1000, 1000));
            break;

        case 3:
            cout << "Enter Z (-1000..1000): ";
            p1.setZ(Input::readInt(-1000, 1000));
            break;

        case 4:
            p1.setX(Random::randInt(-1000, 1000));
            p1.setY(Random::randInt(-1000, 1000));
            p1.setZ(Random::randInt(-1000, 1000));
            break;

        case 5:
            if (PointFile::save(p1, "point.txt"))
                cout << "Saved!\n";
            else
                cout << "Save error!\n";
            break;

        case 6:
            if (PointFile::load(p1, "point.txt"))
                cout << "Loaded!\n";
            else
                cout << "Load error!\n";
            break;

        default:
            cout << "Wrong choice!\n";
            break;
        }       
    }

    return 0;
}