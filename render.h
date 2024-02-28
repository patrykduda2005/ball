#ifndef RENDER_H
#define RENDER_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include "vector2d.h"
using namespace std;
template <typename T>
using vec = vector<T>;


class Render {
    vec<vec<char>> board;

    private:
    int setchar(V2d coords, char ch); //setchar (returns -1 when partially failed)
    public:
    Render(int x, int y);
    void display(); //render the scene
    char get_char(V2d coords);
    int draw_rectangle(V2d coords1, V2d coords2, char ch); //draws a square (returns -1 when partially failed)
    int draw_line(V2d coords1, V2d coords2, char ch); //draws a line (returns -1 when partially failed)
};

#endif

