//
// Created by lenovo on 28/02/2023.
//

#ifndef TUBES1_OOP_SETGAME_H
#define TUBES1_OOP_SETGAME_H

#include "../Player/Player.hpp"
#include "../Card/Card.hpp"
#include "../Ability/AbilityCard.hpp"
#include "../Table/Table.hpp"
#include "../Card/Calculable/Calculable.hpp"


using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

class Player;
class Ability;

class SetGame {
private:
    vector<Card*> cards;
    vector<Player*> players;
    vector<Ability*> ability;
    int round;
    int turn;
    long int pointGame;
public:

    SetGame(int,int);
    ~SetGame();

    void addCard(Card card);
    void removeBackCard();
    void removeFirstCard();
    void removeAbilityCards();
    void shareCardToPlayer(int shareCard);
    void shareCardToTable(Table&);
    void shareAbilityCard();
    void endRound(Table&);
    void setPoint(long);
    void reverseTurn();
    void showAllPoint();
    void printCards();
    void nextTurn();
    void setTurn(int);


    vector<Ability*> getAbilityCards() const;
    vector<Card*> getCards() const;
    vector<Player*> getPlayers() const;
    Player* playerTurn() const;
    int getSizeCards() const;
    int getTurn() const;
    int getRound() const;
    int getHighPointPlayer() const;
    long int getPointGame() const;
};


#endif //TUBES1_OOP_SETGAME_H
