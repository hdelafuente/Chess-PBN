#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

#include "io.h"
#include "chess.h"

class Player {
private:
    string name;
    int id;
    int king_status;
public:
    Player(string, int);
    string GetName() const;
    int GetKingStatus();
    int GetId();
    void ChangeKingStatus();
    ~Player();
};


#endif
