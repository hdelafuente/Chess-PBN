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
        {"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "},
        {"  ", "  ", "  ", "  ", "  ", "  ", "  ", "  "},
        {"PW", "PW", "PW", "PW", "PW", "PW", "PW", "PW"},
        {"TW", "NW", "BW", "QW", "KW", "BW", "NW", "TW"}
    };//Initial board, positions must be accessed via board[y][x]
    Print_Board(board);
    return 0;
}
