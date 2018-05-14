#include <iostream>
#include <string>
#include <sstream>
#include "io.h"
using namespace std;
bool Validate_Move_Pawn(string Initial, string Final, string board[8][8]) {
    int x0=X_Coordenate(Initial);
    int y0=Y_Coordenate(Initial);

    int x1=X_Coordenate(Final);
    int y1=Y_Coordenate(Final);

    if (x0-x1 != 0) {
        return false;
    }

    else if (IsWhite(board, x0, y0)) {
        if (y0-y1 > 0 && y0-y1 < 2) {
            return true;
        }
        return false;
    }
    else if (!IsWhite(board, x0, y0)) {
        if (y1-y0 > 0 && y1-y0 < 2) {
            return true;
        }
        return false;
    }
}
