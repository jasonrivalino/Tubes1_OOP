//
// Created by lenovo on 03/03/2023.
//

#include "Table.hpp"

Table::Table() {}

Table::~Table() {
    this->cards.clear();
}

void Table::addCard(Card c) {
    this->cards.push_back(&c);
}

void Table::showTable() {}

vector<Card*> Table::getCards() {return this->cards;}