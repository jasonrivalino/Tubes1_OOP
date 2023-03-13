//
// Created by lenovo on 03/03/2023.
//

#include "Table.hpp"

Table::Table() {}

Table::~Table() {
    this->cards.clear();
}

void Table::addCard(Card &c) {
    this->cards.push_back(&c);
}

void Table::removeBackCard() {
    this->cards.pop_back();
}

void Table::endRound() {
    for(int i=0;i< this->cards.size();i++) removeBackCard();
}

void Table::showTable() {}

vector<Card*> Table::getCards() {return this->cards;}