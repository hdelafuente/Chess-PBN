#ifndef IO_H
#define IO

#include <string>
#include <sstream>
#include <cmath>

#include "chess.h"
#include "player.h"

using namespace std;
//Reads the input and returns an (x,y) coordenate
int Y_Coordenate(string coord);
int X_Coordenate(string coord);

//reads and prints the board
void Print_Board(string board[8][8]);

//read the tile and verify if it is white
bool IsWhite(string board[8][8], int X, int Y);

//read the coordenates and return the validation of the move
int Read_Move(string Initial, string Final, string board[8][8], int ID);

//read flags and return file name
int flag(string b[3]);
string File_Name(string b[3]);

//makes the move
void Move(string Initial, string Final, string board[8][8]);

int Winner(string board[8][8]);

string splitX(string Move);
string splitY(string Move);
#endif
