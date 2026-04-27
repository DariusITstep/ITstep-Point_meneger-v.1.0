#include "PointUtils.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

// ---------------- INPUT ----------------

int Input::readInt(int min, int max) {

    int x;

    while (true) {

        cin >> x;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error: only integer!\n";
            continue;
        }

        if (x < min || x > max) {
            cout << "Error range! Try again: ";
            cin.ignore(10000, '\n');
            continue;
        }

        cin.ignore(10000, '\n');
        return x;
    }
}

// ---------------- RANDOM ----------------

int Random::randInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// ---------------- FILE SAVE ----------------

bool PointFile::save(const Point& p, const char* filename) {

    FILE* file = fopen(filename, "w");
    if (!file) return false;

    fprintf_s(file, "%d %d %d",
        p.getX(),
        p.getY(),
        p.getZ()
    );

    fclose(file);
    return true;
}

// ---------------- FILE LOAD ----------------

bool PointFile::load(Point& p, const char* filename) {

    FILE* file = fopen(filename, "r");
    if (!file) return false;

    int x, y, z;

    if (fscanf_s(file, "%d %d %d", &x, &y, &z) != 3) {
        fclose(file);
        return false;
    }

    fclose(file);

    p.setX(x);
    p.setY(y);
    p.setZ(z);

    return true;
}