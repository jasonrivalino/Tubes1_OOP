#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>

#include "../Card/Card.hpp"

using namespace std;
class Player{
protected:
    static int currentTurn;
    const int turn;
    string playerName; 
    vector <card> cards;
public:
    Player(string playerName);
    ~Player();
    int getTurn() const;
    void addCard(card c);
    void printCards();
    void removeSpecificCard(card c);
    void removeTopCard(card c);
};

#endif