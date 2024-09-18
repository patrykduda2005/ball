#include "cuboid.h"

Cuboid::Cuboid(V3d corner1, V3d corner2) {
    vec<V3d> corners;
    float x1 = corner1.x;
    float y1 = corner1.y;
    float z1 = corner1.z;
    float x2 = corner2.x;
    float y2 = corner2.y;
    float z2 = corner2.z;
    corners.push_back(corner1);
    corners.push_back(V3d(x2,y1,z1));
    corners.push_back(V3d(x2,y1,z2));
    corners.push_back(V3d(x1,y1,z2));

    corners.push_back(V3d(x1,y2,z1));
    corners.push_back(V3d(x2,y2,z1));
    corners.push_back(corner2);
    corners.push_back(V3d(x1,y2,z2));
    this->corners = corners;
}

void Cuboid::draw(Render &r) {
    r.draw_line(this->corners[0].toV2d(r.width, r.height), this->corners[1].toV2d(r.width, r.height));
    r.draw_line(this->corners[1].toV2d(r.width, r.height), this->corners[2].toV2d(r.width, r.height));
    r.draw_line(this->corners[2].toV2d(r.width, r.height), this->corners[3].toV2d(r.width, r.height));
    r.draw_line(this->corners[3].toV2d(r.width, r.height), this->corners[0].toV2d(r.width, r.height));

    r.draw_line(this->corners[0].toV2d(r.width, r.height), this->corners[4].toV2d(r.width, r.height));
    r.draw_line(this->corners[1].toV2d(r.width, r.height), this->corners[5].toV2d(r.width, r.height));
    r.draw_line(this->corners[2].toV2d(r.width, r.height), this->corners[6].toV2d(r.width, r.height));
    r.draw_line(this->corners[3].toV2d(r.width, r.height), this->corners[7].toV2d(r.width, r.height));

    r.draw_line(this->corners[4].toV2d(r.width, r.height), this->corners[5].toV2d(r.width, r.height));
    r.draw_line(this->corners[5].toV2d(r.width, r.height), this->corners[6].toV2d(r.width, r.height));
    r.draw_line(this->corners[6].toV2d(r.width, r.height), this->corners[7].toV2d(r.width, r.height));
    r.draw_line(this->corners[7].toV2d(r.width, r.height), this->corners[4].toV2d(r.width, r.height));
}
