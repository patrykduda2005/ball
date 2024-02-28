#include "render.h"

int main() {
    Render r = Render(80, 10);
    r.draw_rectangle(V2d(1,1), V2d(30,5), '#');
    r.draw_rectangle(V2d(20,10), V2d(70,2), '%');
    r.draw_line(V2d(5, 0), V2d(8, 10), 'O');
    r.display();
    return 0;
}
