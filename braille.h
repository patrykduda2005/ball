#ifndef BRAILLE_H
#define BRAILLE_H

#include "vector2d.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;
template <typename T>
using vec = vector<T>;

class Braille {
    vec<vec<string>> brailles;
    string get_symbol(vec<bool> character);
    public:
    Braille(vec<vec<char>> board);
    void display();
};

#endif
