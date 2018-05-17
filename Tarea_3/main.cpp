#include <iostream>
#include <string>
#include <sstream>
#include <cmath>


#include "io.h"
#include "chess.h"
using namespace std;
int main(int argc, char const *argv[]) {
    string board[8][8]={
        {"TD", "ND", "BD", "QD", "KD", "BD", "ND", "TD"},
        {"PD", "PD", "PD", "PD", "PD", "PD", "PD", "PD"},
        {"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "},
        {"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "},
        {"PW", "  ", "  ", "  ", "  ", "  ", "  ", "  "},
        {"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "},
        {"  ", "PW", "PW", "PW", "PW", "PW", "PW", "PW"},
        {"TW", "NW", "BW", "QW", "KW", "BW", "NW", "TW"}
    };//Initial board, positions must be accessed via board[y][x]
    Print_Board(board);
    string flags[3]; //flags are stored in this array
    for (int i = 0; i < argc; i++) {
        flags[i]=argv[i];
    }

    cout << Validate_Move_Pawn("a4", "a5", board) << endl;
    return 0;
}
