#ifndef VECTOR2D_H
#define VECTOR2D_H
#include <utility>

class V2d{
    public:
    float x;
    float y;
    V2d(float x, float y);
    V2d(int x, int y);
    void swap();
    V2d swapped();
};

#endif
