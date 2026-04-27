#include "Point.h"
#include <iostream>

using namespace std;

// ---------------- CONSTRUCTORS ----------------

Point::Point() : x(0), y(0), z(0) {}

Point::Point(int x, int y, int z) : x(x), y(y), z(z) {}

// ---------------- GETTERS ----------------

int Point::getX() const { return x; }
int Point::getY() const { return y; }
int Point::getZ() const { return z; }

// ---------------- SETTERS ----------------

void Point::setX(int value) { x = value; }
void Point::setY(int value) { y = value; }
void Point::setZ(int value) { z = value; }

// ---------------- OUTPUT ----------------

void Point::print() const {
    cout << "Point: (" << x << ", " << y << ", " << z << ")" << endl;
}