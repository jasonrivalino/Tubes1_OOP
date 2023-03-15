//
// Created by lenovo on 28/02/2023.
//

#ifndef TUBES1_OOP_SETGAME_H
#define TUBES1_OOP_SETGAME_H

#include "../Player/Player.hpp"
#include "../Card/Card.hpp"
#include "../Ability/AbilityCard.hpp"
#include "../Table/Table.hpp"


using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>

class Player;
class Ability;

class SetGame {
private:
    vector<Card*> cards;
    vector<Player*> players;
    vector<Ability*> ability;
    static int turn;
    long int pointGame;
public:

    SetGame(int jumPlayer);
    ~SetGame();

    void addCard(Card card);
    void removeBackCard();
    void removeFirstCard();
    void removeAbilityCards();
    void shareCardToPlayer(int shareCard);
    void shareAbilityCard();
    void endRound(Player &playerWin);
    void setPoint(long);
    void reverseTurn();


    vector<Ability*> getAbilityCards();
    vector<Card*> getCards();
    vector<Player*> getPlayers();
    Player* playerTurn() const;
    int getSizeCards();
    void showAllPoint();
    void printCards();
    void nextTurn();
    void setTurn(int);
    long int getPointGame();
};


#endif //TUBES1_OOP_SETGAME_H
