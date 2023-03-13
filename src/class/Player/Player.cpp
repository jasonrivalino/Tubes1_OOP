#include "Player.hpp"

int Player::currentTurn=0;

Player::Player(string playerName):turn(currentTurn+1){
    this->playerName = playerName;
    currentTurn++;
}

int Player::getTurn() const{
    return turn;
}

void Player::addCard(Card &c){
    cards.push_back(&c);
}

Player::~Player(){
    cards.clear();
}

void Player::removeSpecificCard(Card c){
    for(int i = 0; i < cards.size();i++){
        if(cards[i]->getNumberCard() == c.getNumberCard()){
            cards.erase(cards.begin() + i);
        }
    }
}

void Player::removeBackCard(){
    cards.pop_back();
}
int Player::getSizeCardsPlayer() {
    return this->cards.size();
}
void Player::printCards(){
    if (cards.size() == 0){
        cout << "No cards" << endl;
    }
    else{
        for(int i = 0; i < cards.size();i++){
        cout << cards[i]->getNameCard() << " " << cards[i]->getNumberCard() << endl;
    }
    }
}

vector<Card*> Player::getCardsPlayer() {
    return this->cards;
}

bool Player::operator==(const Player &p) {
    return this->getTurn()==p.getTurn();
}
bool Player::operator!=(const Player &p) {
    return this->getTurn()!=p.getTurn();
}

void Player::setPoint(int point) {
    this->point = point;
}

int Player::getPoint() {
    return this->point;
}

