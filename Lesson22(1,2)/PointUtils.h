#pragma once
#include "Point.h"

class Input {
public:
    static int readInt(int min, int max);
};

class Random {
public:
    static int randInt(int min, int max);
};

class PointFile {
public:
    static bool save(const Point& p, const char* filename);
    static bool load(Point& p, const char* filename);
};