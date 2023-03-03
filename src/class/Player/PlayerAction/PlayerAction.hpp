#ifndef PLAYERACTION_H
#define PLAYERaCTION_H

#include "../Player.hpp"
#include "../../SetGame/SetGame.hpp"

using namespace std;
#include <iostream>

class PlayerAction
{
public:
    PlayerAction();
    ~PlayerAction();
    void halfCard(Player &player, SetGame &pointGame);
    void doubleCard( Player &player, SetGame &pointGame);
    void nextCard();
};


#endif