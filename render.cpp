#include "render.h"
V2d::V2d(int x, int y) {
    this->x = (float)x;
    this->y = (float)y;
}
V2d::V2d(float x, float y) {
    this->x = (float)x;
    this->y = (float)y;
}

Render::Render(int x, int y) {
    vec<vec<char>> board(y, vec<char>(x, '.'));
    this->board = board;
}

void Render::display() {
    int i = 0;
    for (vec<char> c : this->board) {
        for (int x = 0; x < c.size(); x++) {
            cout << c[x];
        }
        cout << endl;
        i++;
    }
}
int Render::draw_rectangle(V2d coords1, V2d coords2, char ch) {
    int errorCode = 0;
    int x1 = (int)coords1.x;
    int y1 = (int)coords1.y;
    int x2 = (int)coords2.x;
    int y2 = (int)coords2.y;
    if (x1 > x2) {
        int temp = x1;
        x1 = x2;
        x2 = temp;
    } 
    if (y1 > y2) {
        int temp = y1;
        y1 = y2;
        y2 = temp;
    }
    for (int y = y1; y < y2; y++) {
        for (int x = x1; x < x2; x++) {
            if (this->setchar(V2d(x, y), ch) == -1) {
                errorCode = -1;
            }
        }
    }
    return errorCode;
}

int Render::draw_line(V2d coords1, V2d coords2, char ch) {
    int s1, s2, l1, l2; //s for shorter axis, l for longer axis
    float a;
    bool isXLonger;
    int errorCode = 0;
    if (abs(coords2.y - coords1.y) > abs(coords2.x - coords1.x)) {
        isXLonger = false;
        if (coords2.y < coords1.y) {
            V2d temp = coords1;
            coords1 = coords2;
            coords2 = temp;
        }
        s1 = (int)coords1.x;
        s2 = (int)coords2.x;
        l1 = (int)coords1.y;
        l2 = (int)coords2.y;
    } else {
        isXLonger = true;
        if (coords2.x < coords1.x) {
            V2d temp = coords1;
            coords1 = coords2;
            coords2 = temp;
        }
        s1 = (int)coords1.y;
        s2 = (int)coords2.y;
        l1 = (int)coords1.x;
        l2 = (int)coords2.x;
    }
    a = ((float)s2 - (float)s1) / ((float)l2 - (float)l1);

    float fs1 = (float)s1;
    for (; l1 < l2; l1++) {
        fs1 += a;
        if (isXLonger) {
            if (setchar(V2d(l1, (int)fs1), ch) == -1)
                errorCode = -1;
        } else
            if (setchar(V2d((int)fs1, l1), ch) == -1)
                errorCode = -1;
    }
    return errorCode;
}

int Render::setchar(V2d coords, char ch) {
    int x = (int)coords.x;
    int y = (int)coords.y;
    if (y < 0 || y >= this->board.size())
        return -1;
    if (x < 0 || x >= this->board[0].size())
        return -1;
    board.at(y).at(x) = ch;
    return 0;
}
