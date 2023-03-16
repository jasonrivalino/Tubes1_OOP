#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>

#include "../Card/Card.hpp"
#include "../Ability/AbilityCard.hpp"

class Ability;
#include "../Card/Calculable/Calculable.hpp"

using namespace std;
class Player{
protected:
    static int currentTurn;
    const int turn;
    int point;
    string playerName;
    vector<Ability*> abilityCard;
    vector <Card*> cards;
    Calculable *highestComboValue;

public:

    Player(string playerName);
    ~Player();


    int getTurn() const;
    vector<Card*> getCardsPlayer();
    int getSizeCardsPlayer();
    int getPoint();
    bool operator==(const Player&);
    bool operator!=(const Player&);
    Calculable* getHighestComboValue(vector<Card*>);


    void addCard(Card &c);
    void addAbilityCard(Ability&);
    void addCardSpesPos(Card&,int);
    void printCards();
    void removeSpecificCard(Card c);
    void removeBackCard();
    void removeFirstCard();
    void removeAbilityCard();
    void setPoint(int);
    vector<Ability*> getAbility() const;





};

#endif