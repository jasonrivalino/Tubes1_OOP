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
    void halfAct(Player&,SetGame&);
    void doubleAct(Player&,SetGame&);
    void nextCard();
    void reRoll(Player&,SetGame&);
    void quadrupleCard(Player&, SetGame&);
    void quarterCard(Player&, SetGame&);
    void reverseCard(Player&,SetGame&);
    void swapCard(Player&,SetGame&);
    void switchCard(Player&,SetGame&);
    void abilityLessCard(Player&,SetGame&);
};


#endif