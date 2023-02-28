//
// Created by lenovo on 28/02/2023.
//

#include "SetGame.hpp"
#include <algorithm>


SetGame::SetGame() {
    string warna[4] = {"Kuning","Hijau","Merah","Biru"};
    for(int i=1;i<8;i++){
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
void SetGame::addCard(Card card) {
    this->cards.push_back(card);
}
void  SetGame::removeTopCard() {
    this->cards.pop_back();
}
void SetGame::removeAbilityCards() {
    this->ability.clear();
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