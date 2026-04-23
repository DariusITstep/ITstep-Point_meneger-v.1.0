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
    ~Point();

    int inputInt();
    void print() const;

    int getX() const;
    int getY() const;
    int getZ() const;

    void setX(int value);
    void setY(int value);
    void setZ(int value);

    bool saveToFile(const char* filename) const;
    bool loadFromFile(const char* filename);
};