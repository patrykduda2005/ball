#include "render.h"
#include <cstdlib>
#include <string>

int main() {
    //Render r = Render(128, 100);
    Render r = Render(160, 40);
    //r.draw_rectangle(V2d(0,0), V2d(80,20));
    //r.draw_rectangle(V2d(20,10), V2d(70,2), '%', false);
    //r.draw_line(V2d(0, 0), V2d(15, 8), 'O');
    vec<int> xs;
    vec<int> ys;
    srand(42);
    int a = 0;
    while (true) {
        srand(a);
        for (int i = 0; i < 3; i++)
            xs.push_back((rand()%160));
        for (int i = 0; i < 3; i++)
            ys.push_back(rand()%40);
        r.draw_triangle(V2d(xs[0],ys[0]), V2d(xs[1],ys[1]), V2d(xs[2],ys[2]), '&');
        cout << a << endl;
        r.display();
        a++;
        xs.clear();
        ys.clear();
        r.clear();
        cin.get();
    }
    r.display();
    
    return 0;
}
