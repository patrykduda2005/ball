#ifndef CUBOID_H
#define CUBOID_H

#include "vector3d.h"
#include "render.h"
#include <vector>
using namespace std;
template <typename T>
using vec = vector<T>;

class Cuboid {
    vec<V3d> corners;
    public:
    Cuboid(V3d corner1, V3d corner2);
    void draw(Render &r); 
};

#endif
