#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

#include "io.h"
#include "player.h"
#include "chess.h"

Player::Player(string Name, int Id) {
    name = Name;
    king_status = 1;
    id = Id;
}

string Player::GetName() const {
    return name;
}

int Player::GetKingStatus() {
    return king_status;
}

int Player::GetId() {
    return id;
}

void Player::ChangeKingStatus() {
    king_status--;
}

Player::~Player(){

}
