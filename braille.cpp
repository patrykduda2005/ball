#include "braille.h"
#include <codecvt>
#include <locale>

Braille::Braille(vec<vec<char>> board) {
    for (int y = 0; y < board.size(); y+=4) {
        vec<string> row;
        for (int x = 0; x < board[0].size(); x+=2) {
            vec<bool> character;
            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 4; j++) {
                    if (x+i >= board[0].size() || y+j >= board.size()) {
                        character.push_back(false);
                        continue;
                    }
                    character.push_back(board.at(y+j).at(x+i) != '.');
                }

            row.push_back(this->get_symbol(character));
        }
        this->brailles.push_back(row);
    }
}

string Braille::get_symbol(vec<bool> character) {
    wchar_t uni = L'\u2800';
    //0x1 0x2
    //0x4 0x40
    //0x8 0x10
    //0x20 0x80
    //character = {true, true, true, true, true, true, true, false};
    if (character[0]) uni+=0x01;
    if (character[1]) uni+=0x02;
    if (character[2]) uni+=0x04;
    if (character[4]) uni+=0x08;

    if (character[3]) uni+=0x40;
    if (character[5]) uni+=0x10;
    if (character[6]) uni+=0x20;
    if (character[7]) uni+=0x80;
    wstring_convert<codecvt_utf8<wchar_t>> converter;
    string utf8_str = converter.to_bytes(uni);
    return utf8_str;
}

void Braille::display() {
    for (int y = 0; y < this->brailles.size(); y++) {
        for (int x = 0; x < this->brailles[0].size(); x++) {
            cout << this->brailles[y][x];
        }
        cout << endl;
    }
}
