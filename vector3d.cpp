#include "vector3d.h"

int viewportDistanceFromCamera = 100;

V3d::V3d(int x, int y, int z) {
    this->x = (float)x;
    this->y = (float)y;
    this->z = (float)z;
}
V3d::V3d(float x, float y, float z) {
    this->x = (float)x;
    this->y = (float)y;
    this->z = (float)z;
}

V2d V3d::toV2d(int rWidth, int rHeight) {
    float xPrim = (this->x * viewportDistanceFromCamera) / this->z;
    float yPrim = (this->y * viewportDistanceFromCamera) / this->z;
    float canvasX = (xPrim * rWidth) / (rWidth * 1.2);
    float canvasY = (yPrim * rHeight) / (rHeight * 1.2);
    return V2d(canvasX, canvasY);
//    float verticalFromEdgeDistance = this->y;
//    float horizontalFromEdgeDistance = this->x;
//    if (this->x > ((float)rWidth / 2))
//        horizontalFromEdgeDistance = (float)rWidth - this->x;
//    if (this->y > ((float)rHeight / 2))
//        verticalFromEdgeDistance = (float)rHeight - this->y;
//    return V2d(this->x + (this->z * horizontalFromEdgeDistance/100),
//            this->y + (this->z * verticalFromEdgeDistance/100));
}
