//
// Created by lenovo on 28/02/2023.
//

#include "SetGame.hpp"
#include <algorithm>

int SetGame::turn=1;

SetGame::SetGame(int jumPlayer) {

    this->pointGame=64;

    string warna[4] = {"K","H","M","B"};
    for(int i=1;i<jumPlayer+1;i++){
        this->players.push_back(new Player("P"+i));
    }
    this->ability.push_back(new ReRoll);
    this->ability.push_back(new Quadruple);
    this->ability.push_back(new Quarter);
    this->ability.push_back(new ReverseDirection);
    this->ability.push_back(new SwapCard);
    this->ability.push_back(new Switch);
    this->ability.push_back(new Abilityless);


    random_shuffle(this->ability.begin(), this->ability.end());

    for(int i=0;i<52;i++){
        int numCard = i%13+1;
        int numWarna = i/13;

        this->cards.push_back(new Card(warna[numWarna],numCard));
    }

    random_shuffle(this->cards.begin(), this->cards.end());
}
SetGame::~SetGame() {
    this->ability.clear();
    this->cards.clear();
    this->players.clear();
}
int SetGame::getSizeCards() {
    return this->cards.size();
}
void SetGame::addCard(Card card) {
    this->cards.push_back(&card);
}
void  SetGame::removeBackCard() {
    this->cards.pop_back();
}
void SetGame::removeFirstCard() {
    this->cards.erase(this->cards.begin());
}
void SetGame::removeAbilityCards() {
    this->ability.clear();
}
void SetGame::setPoint(long point) {
    this->pointGame = point;
}
void SetGame::showAllPoint() {
    for(int i=0;i< this->players.size();i++) cout<<"Player "<< this->players[i]->getTurn()<<endl;
}
void SetGame::shareCardToPlayer(int shareCard) {
    for(int i=0;i< this->players.size();i++){
        for(int j=1;j<=shareCard;j++){
            this->players[i]->addCard(*this->cards[this->cards.size()-j]);
        }
        this->cards.pop_back();
        this->cards.pop_back();
    }
}
void SetGame::shareAbilityCard() {
    for(int i=0;i< this->players.size();i++) this->players[i]->addAbilityCard(*this->ability[i]);
    this->removeBackCard();
}
void SetGame::printCards() {
    for(int i=0;i< this->cards.size();i++){
        cout<< this->cards[i]->getNameCard()<<" "<< this->cards[i]->getNumberCard()<<endl;
    }
}
void SetGame::endRound(Player &playerWin) {












    this->pointGame=64;

    string warna[4] = {"K","H","M","B"};


    this->cards.clear();

    this->ability.push_back(new ReRoll);
    this->ability.push_back(new Quadruple);
    this->ability.push_back(new Quarter);
    this->ability.push_back(new ReverseDirection);
    this->ability.push_back(new SwapCard);
    this->ability.push_back(new Switch);
    this->ability.push_back(new Abilityless);
    random_shuffle(this->ability.begin(), this->ability.end());

    for(int i=0;i<52;i++){
        int numCard = i%13+1;
        int numWarna = i/13;

        this->cards.push_back(new Card(warna[numWarna],numCard));
    }
    random_shuffle(this->cards.begin(), this->cards.end());

    if(this->players[1]->getTurn()-this->players[0]->getTurn()==-1){
        reverseTurn();
    }

    int idxPlayer=0;
    for(int i=0;i< this->players.size();i++){
        if(*this->players[i]==playerWin) idxPlayer=i;
    }


    this->players[idxPlayer]->setPoint(this->players[idxPlayer]->getPoint()+this->pointGame);
    this->pointGame=64;
}
void SetGame::reverseTurn() {
    reverse(this->players.begin(), this->players.end());
}
void SetGame::nextTurn() {
    turn++;
}
void SetGame::setTurn(int t) {
    turn=t-1;
}

vector<Card*> SetGame::getCards() {
    return this->cards;
}
vector<Ability*> SetGame::getAbilityCards() {
    return this->ability;
}
vector<Player*> SetGame::getPlayers() {
    return this->players;
}
Player& SetGame::playerTurn() const {
    return *this->players[(this->turn)%7 -1];
}

long int SetGame::getPointGame() {
    return this->pointGame;
}