#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>
#include <cstdlib>

#include "io.h"
#include "chess.h"
#include "player.h"
using namespace std;
void split(string Line, string Initial, string Final) {
    vector<string> list;
    size_t found;
    found = Line.find(" ");
    list.push_back(Line.substr(0,found));
    list.push_back(Line.substr(found+1, Line.size()));
    Initial = list[0];
    Final = list[1];
}


//int argc, char const *argv[]
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

    string flags[3]; //flags are stored in this array
    for (int i = 0; i < argc; i++) {
        flags[i]=argv[i];
    }
    int t_flag = flag(flags);

    //Players
    Player White ("White Player", 1);
    Player Dark ("Dark Player", 0);
    int Actual_Player=1;

    
    if (t_flag == 0) {
        while(White.GetKingStatus() == 1 && Dark.GetKingStatus() == 1) {
            int win = Winner(board);
            Print_Board(board);
            if (win == 0) {
                cout << "Dark player Wins" << endl;
                White.ChangeKingStatus();
                continue;
            }
            else if (win == 1) {
                cout << "White player Wins" << endl;
                Dark.ChangeKingStatus();
            }

            if (Actual_Player == 1) {
                cout << "White Playing" << endl;
                string Line;
                cout << "Make your move: ";
                getline(cin, Line);
                string Initial = splitX(Line);
                string Final = splitY(Line);
                int move = Read_Move(Initial, Final, board, Actual_Player);
                if(move == 0) {
                    cout << "Invalid move" << endl;
                    continue;
                }
                else {
                    Move(Initial, Final, board);
                    Actual_Player--;
                    continue;
                }
            }
            else if (Actual_Player == 0) {
                cout << "Dark Playing" << endl;
                string Line;
                cout << "Make your move: ";
                getline(cin, Line);
                string Initial = splitX(Line);
                string Final = splitY(Line);
                int move = Read_Move(Initial, Final, board, Actual_Player);
                if(move == 0) {
                    cout << "Invalid move" << endl;
                    continue;
                }
                else {
                    Move(Initial, Final, board);
                    Actual_Player++;
                    continue;
                }
            }
        }
    }
    else if (t_flag == 1) {
        string file_name = File_Name(flags);
        cout << file_name << endl;
    }

    return 0;
}
