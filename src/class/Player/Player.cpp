#include "Player.hpp"

int Player::currentTurn=0;


Player::Player(string playerName):turn(currentTurn+1){
    this->playerName = playerName;
    this->point=0;
    currentTurn++;
}

int Player::getTurn() const{
    return turn;
}

void Player::addCard(Card c){
    cards.push_back(c);
}

Player::~Player(){
    cards.clear();
}

void Player::removeSpecificCard(Card c){
    for(int i = 0; i < cards.size();i++){
        if(cards[i].getNumberCard() == c.getNumberCard()){
            cards.erase(cards.begin() + i);
        }
    }
}

void Player::removeTopCard(Card c){
    cards.pop_back();
}

void Player::printCards(){
    if (cards.size() == 0){
        cout << "No cards" << endl;
    }
    else{
        for(int i = 0; i < cards.size();i++){
        cout << cards[i].getNameCard() << " " << cards[i].getNumberCard() << endl;
    }
    }
}
void Player::setPoin(int point) { this->point=point;}
int Player::getPoint() {return this->point;}