#include "render.h"

Render::Render(int x, int y) {
    vec<vec<char>> board(y, vec<char>(x, '.'));
    this->board = board;
    this->width = x;
    this->height = y;
}

void Render::display(bool braille) {
    if (braille) {
        Braille b = Braille(this->board);
        b.display();
        return;
    }

    int i = 0;
    for (vec<char> c : this->board) {
        for (int x = 0; x < c.size(); x++) {
            cout << c[x];
        }
        cout << endl;
        i++;
    }
}

void Render::clear() {
    this->draw_rectangle(V2d(0,0), V2d(this->width, this->height) , '.');
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
//assumes y is longer
vec<V2d> Render::get_pix_of_line(V2d coords1, V2d coords2) {
    vec<V2d> pixels;
    //swap longer axis so its always from leasto most to most most
    if (coords2.y < coords1.y) {
        swap(coords1, coords2);
    }
    int l1 = coords1.y;
    int l2 = coords2.y;
    if (l2 - l1 == 0) return {coords1};
    float fs1 = coords1.x;
    int s2 = coords2.x;
    float a = ((float)s2 - fs1) / ((float)l2 - (float)l1);
    for (; l1 < l2 ; l1++) {
        pixels.push_back(V2d((int)round(fs1), l1));
        fs1 += a;
    }
    return pixels;
}

int Render::draw_line(V2d coords1, V2d coords2, char ch) {
    int errorCode = 0;
    //find out if y axis is longer
    bool isYLonger = true;
    if (abs(coords2.x - coords1.x) > abs(coords2.y - coords1.y)) {
        coords1.swap();
        coords2.swap();
        isYLonger = false;
    }
    
    vec<V2d> pixels = get_pix_of_line(coords1, coords2);
    for (V2d pixel : pixels) {
        if (!isYLonger) pixel.swap();
        if (setchar(pixel, ch) == -1)
            errorCode = -1;
    }
    return errorCode;
}

int Render::draw_triangle(V2d coords1, V2d coords2, V2d coords3, char ch, bool filled) {
    int errorCode = 0;
    //sort points from bottom to top
    if (coords2.y < coords1.y) swap(coords1, coords2);
    if (coords3.y < coords1.y) swap(coords1, coords3);
    if (coords3.y < coords2.y) swap(coords2, coords3);
    //draw edges
    draw_line(coords1, coords2, ch);
    draw_line(coords2, coords3, ch);
    draw_line(coords3, coords1, ch);
    if (!filled) return errorCode;

    vec<V2d> left_x = get_pix_of_line(coords1, coords3);
    vec<V2d> one_to_two = get_pix_of_line(coords1, coords2);
    vec<V2d> two_to_three = get_pix_of_line(coords2, coords3);
    if (one_to_two.size() == 1 && one_to_two[0].y == two_to_three[0].y) one_to_two.pop_back();

    vec<V2d> right_x(one_to_two.begin(), one_to_two.end());
    right_x.insert(right_x.end(), two_to_three.begin(), two_to_three.end());

    for (int i = 0; i < left_x.size(); i++) {
        draw_line(left_x[i], right_x[i], ch);
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
