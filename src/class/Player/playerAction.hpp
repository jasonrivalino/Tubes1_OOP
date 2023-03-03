#ifndef PLAYERACTION_H
#define PLAYERaCTION_H

#include "../Player/Player.hpp"
#include "../SetGame/SetGame.hpp"

using namespace std;
#include <iostream>

class playerAction
{
private:
    string action;
    int currentPoint;
public:
    playerAction(/* args */);
    ~playerAction();
    void halfCard(Player &player, SetGame pointGame, string action);
    void doubleCard( Player &player, SetGame pointGame, string action);
    void nextCard(Player &player, SetGame pointGame, string action);
};


#endif