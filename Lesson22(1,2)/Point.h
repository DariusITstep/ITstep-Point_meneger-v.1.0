#pragma once
#include <iostream>

class Point {
private:
    int x;
    int y;
    int z;

public:
    Point();
    Point(int x, int y, int z);

    void print() const;

    int getX() const;
    int getY() const;
    int getZ() const;

    void setX(int value);
    void setY(int value);
    void setZ(int value);
};