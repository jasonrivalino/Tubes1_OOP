#ifndef PLAYERACTION_H
#define PLAYERaCTION_H

#include "../../Ability/AbilityCard.hpp" 
#include "../Player.hpp"
#include "../../SetGame/SetGame.hpp"
#include "../../Exception/Exception.hpp"

using namespace std;
#include <iostream>

class PlayerAction
{
public:
    PlayerAction();
    ~PlayerAction();
    void halfAct(Player &player, SetGame &pointGame);
    void doubleAct( Player &player, SetGame &pointGame);
    void nextCard();
    void reRoll(Player &p,SetGame &s);
    void quadrupleCard(Player &player, SetGame &pointGame);
    void quarterCard(Player &player, SetGame &pointGame);
    void reverseCard(Player&,SetGame&);
};


#endif