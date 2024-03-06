#include "render.h"
#include <cstdlib>

int main() {
    //Render r = Render(128, 100);
    Render r = Render(80, 15);
    //r.draw_rectangle(V2d(1,1), V2d(30,5), '#');
    //r.draw_rectangle(V2d(20,10), V2d(70,2), '%', false);
    //r.draw_line(V2d(5, 0), V2d(8, 10), 'O');
    vec<int> xs;
    for (int i = 0; i < 3; i++)
        xs.push_back((rand()%38)*2);
    vec<int> ys;
    for (int i = 0; i < 3; i++)
        ys.push_back(rand()%14);
    r.draw_triangle(V2d(xs[0],ys[0]), V2d(xs[1],ys[1]), V2d(xs[2],ys[2]), '&');
    r.display();
    return 0;
}
