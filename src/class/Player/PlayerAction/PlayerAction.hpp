#ifndef PLAYERACTION_H
#define PLAYERaCTION_H

#include "../../Ability/AbilityCard.hpp" 
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
    void reRoll(Player &p,SetGame &s);
    void quadrupleCard(Player &player, SetGame &pointGame);
    void quarterCard(Player &player, SetGame &pointGame);
};


#endif