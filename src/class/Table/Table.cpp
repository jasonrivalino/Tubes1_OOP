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

void Table::showTable() {


    cout<<"Table\n"<<endl;
    if(this->cards.size()==0){
        cout<<"kartu masih kosong"<<endl;
    }else {

        for (int i = 0; i < this->cards.size(); i++)
            cout << this->cards[i]->getNameCard() << this->cards[i]->getNumberCard() << " ";

        cout << endl;
    }

}

vector<Card*> Table::getCards() {return this->cards;}