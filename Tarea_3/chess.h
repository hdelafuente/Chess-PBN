#ifndef CHESS_H
#define CHESS_H

#include <iostream>
#include <string>
#include <sstream>
#include "io.h"
using namespace std;

//Validate moves from each piece
bool Validate_Move_Pawn(string Initial, string Final, string board[8][8]);
//bool Validate_Move_Tower(string coord);
//bool Validate_Move_Bishop(string coord);
//bool Validate_Move_Horse(string coord);
//bool Validate_Move_Queen(string coord);
//bool Validate_Move_King(string coord);



#endif
