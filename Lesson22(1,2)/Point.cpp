#define _CRT_SECURE_NO_WARNINGS
#include "Point.h"
#include <cstdio>
using namespace std;

Point::Point() : x(0), y(0), z(0) {}
Point::Point(int x, int y, int z) : x(x), y(y), z(z) {}
Point::~Point() {}

// Ввід
int Point::inputInt() {

    int x;

    while (true) {

        cin >> x;

        if (cin.fail()) {
            cin.clear();              
            cin.ignore(10000, '\n');  
            cout << "Error: only integer!\n";
            continue;
        }
        if (x < -1000 || x > 1000) {
            cout << "Error range! Try again: ";
            cin.ignore(10000, '\n');
            continue;
        }
        break;
    }

    cin.ignore(10000, '\n');   
    return x;
}

// Вивід
void Point::print() const {
    cout << "Point: (" << x << ", " << y << ", " << z << ")" << endl;
}

// Геттери
int Point::getX() const { return x; }
int Point::getY() const { return y; }
int Point::getZ() const { return z; }

// Сеттери
void Point::setX(int value) { x = value; }
void Point::setY(int value) { y = value; }
void Point::setZ(int value) { z = value; }

// Збереження
bool Point::saveToFile(const char* filename) const {
    FILE* file = fopen(filename, "w");

    if (!file) return false;

    fprintf_s(file, "%d %d %d", x, y, z);

    fclose(file);
    return true;
}

// Завантаження
bool Point::loadFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");

    if (!file) return false;

    if (fscanf_s(file, "%d %d %d", &x, &y, &z) != 3) {
        fclose(file);
        return false;
    }

    fclose(file);
    return true;
}