#include "render.h"
#include "cuboid.h"
#include "vector3d.h"
#include <cstdlib>
#include <string>

int main() {
    Render r = Render(160, 60);

    Cuboid cube = Cuboid(V3d(30, 15, 10), V3d(30, 15, 70));
    cube.draw(r);
    r.display();
    return 0;
}
