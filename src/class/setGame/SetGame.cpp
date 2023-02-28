//
// Created by lenovo on 28/02/2023.
//

#include "SetGame.hpp"
#include <algorithm>


SetGame::SetGame(int jumPlayer) {
    string warna[4] = {"Kuning","Hijau","Merah","Biru"};
    for(int i=1;i<jumPlayer+1;i++){
        this->players.push_back(*new Player("P"+i));
    }
    this->ability.push_back(*new ReRoll);
    this->ability.push_back(*new Quadruple);
    this->ability.push_back(*new Quarter);
    this->ability.push_back(*new ReverseDirection);
    this->ability.push_back(*new SwapCard);
    this->ability.push_back(*new Switch);
    this->ability.push_back(*new Abilityless);


    random_shuffle(this->ability.begin(), this->ability.end());

    for(int i=0;i<52;i++){
        int numCard = i%13+1;
        int numWarna = i/13;

        this->cards.push_back(*new Card(warna[numWarna],numCard));
    }

    random_shuffle(this->cards.begin(), this->cards.end());
}
SetGame::~SetGame() {
    this->ability.clear();
    this->cards.clear();
    this->players.clear();
}
void SetGame::addCard(Card card) {
    this->cards.push_back(card);
}
void  SetGame::removeTopCard() {
    this->cards.pop_back();
}
void SetGame::removeAbilityCards() {
    this->ability.clear();
}
void SetGame::showAllPoint() {
    for(int i=0;i< this->players.size();i++) cout<<"Player "<< this->players[i].getTurn()<<endl;
}
void SetGame::shareCardToPlayer(int shareCard) {
    for(int i=0;i< this->players.size();i++){
        for(int j=1;j<=shareCard;j++){
            this->players[i].addCard(this->cards[this->cards.size()-j]);
        }
        this->cards.pop_back();
        this->cards.pop_back();
    }
}
void SetGame::shareAbilityCard() {
    for(int i=0;i< this->players.size();i++) this->players[i].addCard(this->ability[i]);
    this->removeTopCard();
}
void SetGame::printCards() {
    for(int i=0;i< this->cards.size();i++){
        cout<< this->cards[i].getNameCard()<<" "<< this->cards[i].getNumberCard()<<endl;
    }
}
vector<Card> SetGame::getCards() {
    return this->cards;
}
vector<Card> SetGame::getAbilityCards() {
    return this->ability;
}
vector<Player> SetGame::getPlayers() {
    return this->players;
}
