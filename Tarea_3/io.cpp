#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

#include "chess.h"
#include "player.h"
using namespace std;

int Y_Coordenate(string coord) {
    int Y;
    Y=coord[1]-'0';
    if (Y > 8 || Y < 0) {
        return -1;
    }
    return 8-Y;
}

int X_Coordenate(string coord) {
    string XPos="abcdefgh";
    for (int i = 0; i < 8; i++) {
        if (XPos[i]==coord[0]) {
            return i;
        }
    }
    return -1;
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
    cout << " " << XPos;
}

bool IsWhite(string board[8][8], int X, int Y) {
    if (board[Y][X][1]=='W') {
        return true;
    }
    return false;
}

int Read_Move(string Initial, string Final, string board[8][8], int ID){
    int x0 = X_Coordenate(Initial);
    int y0 = Y_Coordenate(Initial);
    int number;
    if (board[y0][x0][0] == 'P')
        number = Validate_Move_Pawn(Initial, Final, board, ID);
    else if (board[y0][x0][0] == 'T')
        number = Validate_Move_Tower(Initial, Final, board, ID);
    else if (board[y0][x0][0] == 'N')
        number = Validate_Move_Horse(Initial, Final, board, ID);
    else if (board[y0][x0][0] == 'B')
        number = Validate_Move_Bishop(Initial, Final, board, ID);
    else if (board[y0][x0][0] == 'Q')
        number = Validate_Move_Queen(Initial, Final, board, ID);
    else if (board[y0][x0][0] == 'K')
        number = Validate_Move_King(Initial, Final, board, ID);

    return number;
}


int flag(string b[3]) {
	int j=1;
	for (j=1;j<3;j++) {
        if (b[j] == "-t") {
            return 1;
        }
    }
    return 0;
}

string File_Name(string b[3]) {
	int j=1;
	for (j=1;j<3;j++) {
        if (b[j] == "-t") {
            return b[j+1];
        }
    }
    return NULL;
}

void Move(string Initial, string Final, string board[8][8]) {
    int x0 = X_Coordenate(Initial);
    int y0 = Y_Coordenate(Initial);

    int x1 = X_Coordenate(Final);
    int y1 = Y_Coordenate(Final);
    board[y1][x1] = board[y0][x0];
    board[y0][x0] = "  ";

}

int Winner(string board[8][8]) {
    int sumWhite = 0;
    int sumDark = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if(board[i][j] == "KD"){
                sumDark++;
            }
            else if (board[i][j] == "KW") {
                sumWhite++;
            }
        }
    }
    if (sumWhite == 0) {
        return 0;
    }
    else if (sumDark == 0) {
        return 1;
    }
    return 2;
}

string splitX(string Move) {
    string Initial;
    for (int i = 0; i < 2; i++) {
        Initial+=Move[i];
    }
    return Initial;
}

string splitY(string Move) {
    string Final;
    for (int i = 3; i < 5; i++) {
        Final+=Move[i];
    }
    return Final;
}
