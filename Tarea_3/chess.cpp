#include <iostream>
#include <string>
#include <sstream>
#include "io.h"
using namespace std;
bool Validate_Move_Pawn(string Initial, string Final, string board[8][8]) {
    int x0 = X_Coordenate(Initial);
    int y0 = Y_Coordenate(Initial);

    int x1 = X_Coordenate(Final);
    int y1 = Y_Coordenate(Final);
    if (x1 == -1 || y1 == -1 || x0 == -1 || y0 == -1) {
        return false;
    }
    if (x0-x1 != 0) {
        return false;
    }

    else if (IsWhite(board, x0, y0)) {
        if (y0-y1 > 0 && y0-y1 < 2 && (board[y1][x1][1] != 'W' || 'D')) {
            return true;
        }
        return false;
    }
    else if (!IsWhite(board, x0, y0)) {
        if (y1-y0 > 0 && y1-y0 < 2 && (board[y1][x1][1] != 'W' || 'D')) {
            return true;
        }
        return false;
    }
}
int Validate_Move_Tower(string Initial, string Final, string board[8][8], int Player) {
    int x0 = X_Coordenate(Initial);
    int y0 = Y_Coordenate(Initial);

    int x1 = X_Coordenate(Final);
    int y1 = Y_Coordenate(Final);
    if (x1 == -1 || y1 == -1 || x0 == -1 || y0 == -1) {
        return 0;
    }
    if (x0-x1 != 0 && y0-y1 != 0) {
        return 0;
    }

    else if (Player == 1) { //white Player
        if (y0 > y1 && x0-x1 == 0) {
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
        else if (y1 > y0 && x0-x1 == 0) {
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
        else if (x0 > x1 && y0-y1 == 0) {
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
        else if (x1 > x0 && y0-y1 == 0) {
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

    else if (Player == 0) { //Dark Player
        if (y0 > y1 && x0-x1 == 0) {
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
        else if (y1 > y0 && x0-x1 == 0) {
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
        else if (x0 > x1 && y0-y1 == 0) {
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
        else if (x1 > x0 && y0-y1 == 0) {
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
}
int Validate_Move_Bishop(string Initial, string Final, string board[8][8], int Player) {
    int x0 = X_Coordenate(Initial);
    int y0 = Y_Coordenate(Initial);

    int x1 = X_Coordenate(Final);
    int y1 = Y_Coordenate(Final);
    if (x1 == -1 || y1 == -1 || x0 == -1 || y0 == -1) {
        return 0;
    }
    if (x0-x1 != 0) {
        return 0;
    }

    if (Player == 1) {
        if (x0 > x1 && y0 > y1) {
            int x = x0, y = y0, temp = 0;
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
            int x = x0, y = y0, temp = 0;
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
            int x = x0, y = y0, temp = 0;
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
            int x = x0, y = y0, temp = 0;
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
    if (Player == 0) {
        if (x0 > x1 && y0 > y1) {
            int x = x0, y = y0, temp = 0;
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
            int x = x0, y = y0, temp = 0;
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
            int x = x0, y = y0, temp = 0;
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
            int x = x0, y = y0, temp = 0;
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
}
