#include "vector2d.h"
V2d::V2d(int x, int y) {
    this->x = (float)x;
    this->y = (float)y;
}
V2d::V2d(float x, float y) {
    this->x = (float)x;
    this->y = (float)y;
}

void V2d::swap() {
    std::swap(this->x, this->y);
}

V2d V2d::swapped() {
    this->swap();
    return *this;
}
