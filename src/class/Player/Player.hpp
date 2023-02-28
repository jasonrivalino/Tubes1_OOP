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
    int point;
    string playerName; 
    vector <Card> cards;
public:
    Player(string playerName);
    ~Player();
    int getTurn() const;
    int getPoint();
    vector<Card> getCardsPlayer();
    int getSizeCardsPlayer();
    void addCard(Card c);
    void printCards();
    void removeSpecificCard(Card c);
    void removeBackCard();
    void setPoin(int);

};

#endif