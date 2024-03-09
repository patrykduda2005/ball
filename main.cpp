#include "render.h"
#include <cstdlib>
#include <string>

int main() {
    //Render r = Render(128, 100);
    Render r = Render(80, 10);
    //r.draw_rectangle(V2d(1,1), V2d(30,5), '#');
    //r.draw_rectangle(V2d(20,10), V2d(70,2), '%', false);
    //r.draw_line(V2d(0, 0), V2d(15, 8), 'O');
    vec<int> xs;
    vec<int> ys;
    srand(42);
    string a = "0";
    while (true) {
        srand(stoi(a));
        for (int i = 0; i < 3; i++)
            xs.push_back((rand()%80));
        for (int i = 0; i < 3; i++)
            ys.push_back(rand()%10);
        r.draw_triangle(V2d(xs[0],ys[0]), V2d(xs[1],ys[1]), V2d(xs[2],ys[2]), '&');
        r.display();
        cin >> a;
        xs.clear();
        ys.clear();
        r.clear();
    }
    
    return 0;
}
