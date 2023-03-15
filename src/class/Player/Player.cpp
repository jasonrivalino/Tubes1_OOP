#include "Player.hpp"

int Player::currentTurn=0;

Player::Player(string playerName):turn(currentTurn+1){
    this->playerName = playerName;
    currentTurn++;
}

void Player::addCard(Card &c){
    cards.push_back(&c);
}
void Player::addCardSpesPos(Card &c, int idx) {
    this->cards.insert(this->cards.begin()+idx,&c);
}

Player::~Player(){
    cards.clear();
    abilityCard.clear();
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
void Player::removeFirstCard() {
    this->cards.erase(this->cards.begin());
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
void Player::setPoint(int point) {
    this->point = point;
}
void Player::removeAbilityCard() {
    if(this->abilityCard.size()!=0) this->abilityCard.pop_back();
}
void Player::addAbilityCard(Ability &a) {
    this->abilityCard.push_back(&a);
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

int Player::getPoint() {
    return this->point;
}
int Player::getTurn() const{
    return turn;
}
int Player::getSizeCardsPlayer() {
    return this->cards.size();
}
vector<Ability*> Player::getAbility() const {
    return this->abilityCard;
}
