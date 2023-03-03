

#ifndef TUBES1_OOP_TABLE_H
#define TUBES1_OOP_TABLE_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "../Card/Card.hpp"

using namespace std;


class Table {
private:
    vector<Card*> cards;
public:
    Table();
    ~Table();

    //add card
    void addCard(Card);
    void showTable();
    void removeBackCard();
    void endRound();


    //get card
    vector<Card*> getCards();

};


#endif //TUBES1_OOP_TABLE_H
