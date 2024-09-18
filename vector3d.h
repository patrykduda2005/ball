#ifndef VECTOR3D_H
#define VECTOR3D_H
#include "vector2d.h"


class V3d{
    public:
    float x;
    float y;
    float z;
    V3d(float x, float y, float z);
    V3d(int x, int y, int z);
    V2d toV2d(int rWidth, int rHeight); 
};

#endif
