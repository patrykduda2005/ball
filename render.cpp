#include "render.h"

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

int Render::draw_rectangle(V2d coords1, V2d coords2, char ch, bool filled) {
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
                if ((x == x1 || x == x2-1 || y == y1 || y == y2-1) || filled)
                if (this->setchar(V2d(x, y), ch) == -1) {
                    errorCode = -1;
                }
        }
    }
    return errorCode;
}
//TODO: consistent from bottom to top pixel return
vec<V2d> Render::get_pix_of_line(V2d coords1, V2d coords2) {
    vec<V2d> pixels;
    int s1, s2, l1, l2; //s for shorter axis, l for longer axis
    float a;
    bool isXLonger;
    int errorCode = 0;
    if (abs(coords2.y - coords1.y) > abs(coords2.x - coords1.x)) {
        isXLonger = false;
        if (coords2.y < coords1.y) {
            swap(coords1, coords2);
        }
        s1 = (int)coords1.x;
        s2 = (int)coords2.x;
        l1 = (int)coords1.y;
        l2 = (int)coords2.y;
    } else {
        isXLonger = true;
        if (coords2.x < coords1.x) {
            swap(coords1, coords2);
        }
        s1 = (int)coords1.y;
        s2 = (int)coords2.y;
        l1 = (int)coords1.x;
        l2 = (int)coords2.x;
    }
    a = ((float)s2 - (float)s1) / ((float)l2 - (float)l1);
    int progress = 1;
    bool isEdgeCaseXd = false;
    if (isXLonger && s2 < s1) {
        a *= -1;
        progress = -1;
        swap(l1, l2);
        swap(s1, s2);
        isEdgeCaseXd = true;
    }

    float fs1 = (float)s1;
    for (; (l1 < l2 && !isEdgeCaseXd) || (l1 > l2 && isEdgeCaseXd); l1+=progress) {
        fs1 += a;
        if (isXLonger) {
            pixels.push_back(V2d(l1, (int)round(fs1)));
        } else
            pixels.push_back(V2d((int)round(fs1), l1));
    }
    return pixels;
}

int Render::draw_line(V2d coords1, V2d coords2, char ch) {
    int errorCode = 0;
    vec<V2d> pixels = get_pix_of_line(coords1, coords2);
    for (V2d pixel : pixels) {
        if (setchar(pixel, ch) == -1)
            errorCode = -1;
    }
    return errorCode;
}

int Render::draw_triangle(V2d coords1, V2d coords2, V2d coords3, char ch, bool filled) {
    int errorCode = 0;
    if (coords2.y < coords1.y) swap(coords1, coords2);
    if (coords3.y < coords1.y) swap(coords1, coords3);
    if (coords3.y < coords2.y) swap(coords2, coords3);
    draw_line(coords1, coords2, ch);
    draw_line(coords2, coords3, ch);
    draw_line(coords3, coords1, ch);
    vec<V2d> left_x = get_pix_of_line(coords1, coords3); // |
    int y = -1;
    vec<V2d> one_to_two;
    for (V2d pixel : get_pix_of_line(coords2, coords1)) {
        if (pixel.y != y) {
            y = pixel.y;
            one_to_two.push_back(pixel);
        }
    }
    one_to_two.pop_back();
    y = -1;
    vec<V2d> two_to_three;
    for (V2d pixel : get_pix_of_line(coords2, coords3)) {
        if (pixel.y != y) {
            y = pixel.y;
            two_to_three.push_back(pixel);
            cout << pixel.x << " " << pixel.y << ";";
        }
    }
    cout << endl;
    one_to_two.insert(one_to_two.end(), two_to_three.begin(), two_to_three.end());
    //if (one_to_two.size() > left_x.size()) one_to_two.pop_back();
    for (int i = 0; i < left_x.size(); i++) {
        cout << left_x[i].x << " " << left_x[i].y << "<>" << one_to_two[i].x << " " << one_to_two[i].y << ";" << endl;
        draw_line(left_x[i], one_to_two[i], ch);
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

char Render::get_char(V2d coords) {
    int x = (int)coords.x;
    int y = (int)coords.y;
    if (y < 0 || y >= this->board.size())
        return 'E';
    if (x < 0 || x >= this->board[0].size())
        return 'E';
    return board.at(y).at(x);
}
