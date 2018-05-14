#ifndef IO_H
#define IO

#include <string>
#include <sstream>

using namespace std;
//Reads the input and returns an (x,y) coordenate
int Y_Coordenate(string coord);
int X_Coordenate(string coord);

//reads and prints the board
void Print_Board(string board[8][8]);

//read the tile and verify if it is white
bool IsWhite(string board[8][8], int X, int Y);

#endif
