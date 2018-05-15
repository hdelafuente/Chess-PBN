#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int Y_Coordenate(string coord) {
    int Y;
    Y=coord[1]-'0';
    return 8-Y;
}

int X_Coordenate(string coord) {
    string XPos="abcdefgh";
    for (int i = 0; i < 8; i++) {
        if (XPos[i]==coord[0]) {
            return i;
        }
    }
}

void Print_Board(string board[8][8]) {
    string XPos="    a    b    c    d    e    f    g    h\n"; //X-position
    string Line="  -----------------------------------------\n";
    string YPos="12345678";//Y-position
    cout << XPos;
    cout << Line;
    for (int y = 0; y < 8; y++) {
        cout << '9' - YPos[y];
        cout << " ";
        cout <<  '|';
        for (int x = 0; x < 8; x++) {
            cout << ' ' + board[y][x] + " |";
        }
        cout << " " << '9' - YPos[y];
        cout << endl;
        cout << Line;
    }
    cout << " " <<XPos;
}

bool IsWhite(string board[8][8], int X, int Y) {
    if (board[Y][X][1]=='W') {
        return true;
    }
    return false;
}
