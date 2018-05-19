#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include "io.h"
using namespace std;
int Validate_Move_Pawn(string Initial, string Final, string board[8][8]) {
    int x0 = X_Coordenate(Initial);
    int y0 = Y_Coordenate(Initial);

    int x1 = X_Coordenate(Final);
    int y1 = Y_Coordenate(Final);
    if (x1 == -1 || y1 == -1 || x0 == -1 || y0 == -1) {
        return 0;
    }
    if (abs(x0-x1) != 0 && abs(y0-y1) == 0) {
        return 0;
    }

    else if (IsWhite(board, x0, y0)) {
        if (y0 > y1 && abs(y0-y1) == 1 && (board[y1][x1][1] != 'W' || 'D')) {
            return 1;
        }
        else if (abs(x0-x1)==1 && abs(y0-y1) == 1 && board[y1][x1][1] == 'D') {
            return 2;
        }
        else if (y0 > y1 && abs(y0-y1) == 2 && (board[y1][x1][1] != 'W' || 'D') && y0 == 6) {
            return 1;
        }
        return 0;
    }

    else if (!IsWhite(board, x0, y0)) {
        if (y1 > y0 && abs(y1-y0) == 1 && (board[y1][x1][1] != 'W' || 'D')) {
            return 1;
        }
        else if (abs(x0-x1)==1 && abs(y0-y1) == 1 && board[y1][x1][1] == 'W') {
            return 2;
        }
        else if (y0 < y1 && abs(y0-y1) == 2 && (board[y1][x1][1] != 'W' || 'D') && y0 == 1) {
            return 1;
        }
        return 0;
    }
    return 0;
}

int Validate_Move_Tower(string Initial, string Final, string board[8][8], int Player) {
    int x0 = X_Coordenate(Initial);
    int y0 = Y_Coordenate(Initial);

    int x1 = X_Coordenate(Final);
    int y1 = Y_Coordenate(Final);

    int DeltaX = x0 - x1;
    int DeltaY = y0 - y1;
    if (DeltaX == 0 || DeltaY == 0) {
        return 0;
    }
    else if (x1 == -1 || y1 == -1 || x0 == -1 || y0 == -1) {
        return 0;
    }
    if (abs(x0-x1) != 0 && abs(y0-y1) != 0) {
        return 0;
    }

    else if (Player == 1 && IsWhite(board, x0, y0)) { //white Player
        if (y0 > y1 && abs(x0-x1) == 0) {
            int temp = 0;
            for (int y = y1; y < y0; y++) {
                if (board[y][x0][1] == 'W') {
                    return 0;
                }
                else if (board[y][x0][1] == 'D' && temp == 0) {
                    temp++;
                }
                else if (board[y][x0][1] == 'D' && temp > 0) {
                    return 0;
                }
            }
            if (temp == 1) {
                return 2;
            }
            else return 1;
        }
        else if (y1 > y0 && abs(x0-x1) == 0) {
            int temp = 0;
            for (int y = y0; y < y1; y++) {
                if (board[y][x0][1] == 'W') {
                    return 0;
                }
                else if (board[y][x0][1] == 'D' && temp == 0) {
                    temp++;
                }
                else if (board[y][x0][1] == 'D' && temp > 0) {
                    return 0;
                }
            }
            if (temp == 1) {
                return 2;
            }
            else return 1;
        }
        else if (x0 > x1 && abs(y0-y1) == 0) {
            int temp = 0;
            for (int x = x1; x < x0; x++) {
                if (board[y0][x][1] == 'W') {
                    return 0;
                }
                else if (board[y0][x][1] == 'D' && temp == 0) {
                    temp++;
                }
                else if (board[y0][x][1] == 'D' && temp > 0) {
                    return 0;
                }
            }
            if (temp == 1) {
                return 2;
            }
            else return 1;
        }
        else if (x1 > x0 && abs(y0-y1) == 0) {
            int temp = 0;
            for (int x = x0; x < x1; x++) {
                if (board[y0][x][1] == 'W') {
                    return 0;
                }
                else if (board[y0][x][1] == 'D' && temp == 0) {
                    temp++;
                }
                else if (board[y0][x][1] == 'D' && temp > 0) {
                    return 0;
                }
            }
            if (temp == 1) {
                return 2;
            }
            else return 1;
        }
    }

    else if (Player == 0 && !IsWhite(board, x0, y0)) { //Dark Players
        if (y0 > y1 && abs(x0-x1) == 0) {
            int temp = 0;
            for (int y = y1; y < y0; y++) {
                if (board[y][x0][1] == 'D') {
                    return 0;
                }
                else if (board[y][x0][1] == 'W' && temp == 0) {
                    temp++;
                }
                else if (board[y][x0][1] == 'W' && temp > 0) {
                    return 0;
                }
            }
            if (temp == 1) {
                return 2;
            }
            else return 1;
        }
        else if (y1 > y0 && abs(x0-x1) == 0) {
            int temp = 0;
            for (int y = y0; y < y1; y++) {
                if (board[y][x0][1] == 'D') {
                    return 0;
                }
                else if (board[y][x0][1] == 'W' && temp == 0) {
                    temp++;
                }
                else if (board[y][x0][1] == 'W' && temp > 0) {
                    return 0;
                }
            }
            if (temp == 1) {
                return 2;
            }
            else return 1;
        }
        else if (x0 > x1 && abs(y0-y1) == 0) {
            int temp = 0;
            for (int x = x1; x < x0; x++) {
                if (board[y0][x][1] == 'D') {
                    return 0;
                }
                else if (board[y0][x][1] == 'W' && temp == 0) {
                    temp++;
                }
                else if (board[y0][x][1] == 'W' && temp > 0) {
                    return 0;
                }
            }
            if (temp == 1) {
                return 2;
            }
            else return 1;
        }
        else if (x1 > x0 && abs(y0-y1) == 0) {
            int temp = 0;
            for (int x = x0; x < x1; x++) {
                if (board[y0][x][1] == 'D') {
                    return 0;
                }
                else if (board[y0][x][1] == 'W' && temp == 0) {
                    temp++;
                }
                else if (board[y0][x][1] == 'W' && temp > 0) {
                    return 0;
                }
            }
            if (temp == 1) {
                return 2;
            }
            else return 1;
        }
    }
    return 0;
}

int Validate_Move_Bishop(string Initial, string Final, string board[8][8], int Player) {
    int x0 = X_Coordenate(Initial);
    int y0 = Y_Coordenate(Initial);

    int x1 = X_Coordenate(Final);
    int y1 = Y_Coordenate(Final);
    if (x1 == -1 || y1 == -1 || x0 == -1 || y0 == -1) {
        return 0;
    }
    if ( abs(x0-x1) == 0 || abs(y0-y1) == 0) {
        return 0;
    }

    if (Player == 1 && IsWhite(board, x0, y0)) {
        if (x0 > x1 && y0 > y1) {
            int x = x0-1, y = y0-1, temp = 0;
            while(x > x1 && y > y1) {
                if (board[y][x][1]=='W') {
                    return 0;
                }
                else if (board[y][x][1]=='D' && temp == 0) {
                    temp++;
                }
                else if (board[y][x][1]=='D' && temp > 0) {
                    return 0;
                }
                x--;
                y--;
            }
            if (temp == 1) {
                return 2;
            }
            else return 1;
        }
        else if (x0 > x1 && y0 < y1) {
            int x = x0-1, y = y0+1, temp = 0;
            while(x > x1 && y < y1) {
                if (board[y][x][1]=='W') {
                    return 0;
                }
                else if (board[y][x][1]=='D' && temp == 0) {
                    temp++;
                }
                else if (board[y][x][1]=='D' && temp > 0) {
                    return 0;
                }
                x--;
                y++;
            }
            if (temp == 1) {
                return 2;
            }
            else return 1;
        }
        else if (x0 < x1 && y0 > y1) {
            int x = x0+1, y = y0-1, temp = 0;
            while(x < x1 && y > y1) {
                if (board[y][x][1]=='W') {
                    return 0;
                }
                else if (board[y][x][1]=='D' && temp == 0) {
                    temp++;
                }
                else if (board[y][x][1]=='D' && temp > 0) {
                    return 0;
                }
                x++;
                y--;
            }
            if (temp == 1) {
                return 2;
            }
            else return 1;
        }
        else if (x0 < x1 && y0 < y1) {
            int x = x0+1, y = y0+1, temp = 0;
            while(x < x1 && y < y1) {
                if (board[y][x][1]=='W') {
                    return 0;
                }
                else if (board[y][x][1]=='D' && temp == 0) {
                    temp++;
                }
                else if (board[y][x][1]=='D' && temp > 0) {
                    return 0;
                }
                x++;
                y++;
            }
            if (temp == 1) {
                return 2;
            }
            else return 1;
        }
    }
    else if (Player == 0 && !IsWhite(board, x0, y0)) {
        if (x0 > x1 && y0 > y1) {
            int x = x0-1, y = y0-1, temp = 0;
            while(x > x1 && y > y1) {
                if (board[y][x][1]=='D') {
                    return 0;
                }
                else if (board[y][x][1]=='W' && temp == 0) {
                    temp++;
                }
                else if (board[y][x][1]=='W' && temp > 0) {
                    return 0;
                }
                x--;
                y--;
            }
            if (temp == 1) {
                return 2;
            }
            else return 1;
        }
        else if (x0 > x1 && y0 < y1) {
            int x = x0-1, y = y0+1, temp = 0;
            while(x > x1 && y < y1) {
                if (board[y][x][1]=='D') {
                    return 0;
                }
                else if (board[y][x][1]=='W' && temp == 0) {
                    temp++;
                }
                else if (board[y][x][1]=='W' && temp > 0) {
                    return 0;
                }
                x--;
                y++;
            }
            if (temp == 1) {
                return 2;
            }
            else return 1;
        }
        else if (x0 < x1 && y0 > y1) {
            int x = x0+1, y = y0-1, temp = 0;
            while(x < x1 && y > y1) {
                if (board[y][x][1]=='D') {
                    return 0;
                }
                else if (board[y][x][1]=='W' && temp == 0) {
                    temp++;
                }
                else if (board[y][x][1]=='W' && temp > 0) {
                    return 0;
                }
                x++;
                y--;
            }
            if (temp == 1) {
                return 2;
            }
            else return 1;
        }
        else if (x0 < x1 && y0 < y1) {
            int x = x0+1, y = y0+1, temp = 0;
            while(x < x1 && y < y1) {
                if (board[y][x][1]=='D') {
                    return 0;
                }
                else if (board[y][x][1]=='W' && temp == 0) {
                    temp++;
                }
                else if (board[y][x][1]=='W' && temp > 0) {
                    return 0;
                }
                x++;
                y++;
            }
            if (temp == 1) {
                return 2;
            }
            else return 1;
        }
    }
    return 0;
}

int Validate_Move_Queen(string Initial, string Final, string board[8][8], int Player) {
    int x0 = X_Coordenate(Initial);
    int y0 = Y_Coordenate(Initial);

    int x1 = X_Coordenate(Final);
    int y1 = Y_Coordenate(Final);

    int DeltaX = x0 - x1;
    int DeltaY = y0 - y1;
    if (DeltaX == 0 || DeltaY == 0) {
        return 0;
    }

    else if (x1 == -1 || y1 == -1 || x0 == -1 || y0 == -1) {
        return 0;
    }
    else if(Player == 1 && IsWhite(board, x0, y0) && board[y1][x1][1] != 'W'){
        if (abs(DeltaX) == 0 && abs(DeltaY) > 0) return 1;
        else if (abs(DeltaX) > 0 && abs(DeltaY) == 0) return 1;
        else if (abs(DeltaX) == abs(DeltaY)) return 1;
        else return 0;
    }
    else if(Player == 0 && !IsWhite(board, x0, y0) && board[y1][x1][1] != 'D'){
        if (abs(DeltaX) == 0 && abs(DeltaY) > 0) return 1;
        else if (abs(DeltaX) > 0 && abs(DeltaY) == 0) return 1;
        else if (abs(DeltaX) == abs(DeltaY)) return 1;
        else return 0;
    }
    return 0;
}

int Validate_Move_King(string Initial, string Final, string board[8][8], int Player) {
    int x0 = X_Coordenate(Initial);
    int y0 = Y_Coordenate(Initial);

    int x1 = X_Coordenate(Final);
    int y1 = Y_Coordenate(Final);

    int DeltaX = x0 - x1;
    int DeltaY = y0 - y1;
    if (x1 == -1 || y1 == -1 || x0 == -1 || y0 == -1) {
        return 0;
    }
    else if (abs(DeltaX)>1 || abs(DeltaY)>1) {
        return 0;
    } //Verify that king is only moving 1 square

    if(Player == 1 && IsWhite(board, x0, y0) && board[y1][x1][1] != 'W'){
        return 1;
    }
    else if(Player == 0 && !IsWhite(board, x0, y0) && board[y1][x1][1] != 'D'){
        return 1;
    }
    return 0;
}

int Validate_Move_Horse(string Initial, string Final, string board[8][8], int Player) {
    int x0 = X_Coordenate(Initial);
    int y0 = Y_Coordenate(Initial);

    int x1 = X_Coordenate(Final);
    int y1 = Y_Coordenate(Final);
    if (x1 == -1 || y1 == -1 || x0 == -1 || y0 == -1) {
        return 0;
    }
    if (Player==1 && IsWhite(board, x0, y0)) {
        int DeltaX=(x0-x1)*(x0-x1);
        int DeltaY=(y0-y1)*(y0-y1);
        if (DeltaX + DeltaY == 5 && board[y1][x1][1] == 'D') {
            return 2;
        }
        else if (DeltaX + DeltaY == 5 && board[y1][x1][1] == 'W' ) {
            return 0;
        }
        else return 1;
    }
    else if (Player==0 && !IsWhite(board, x0, y0)) {
        int DeltaX=(x0-x1)*(x0-x1);
        int DeltaY=(y0-y1)*(y0-y1);
        if (DeltaX + DeltaY == 5 && board[y1][x1][1] == 'W') {
            return 2;
        }
        else if (DeltaX + DeltaY == 5 && board[y1][x1][1] == 'D' ) {
            return 0;
        }
        else return 1;

    }
    return 0;
}
