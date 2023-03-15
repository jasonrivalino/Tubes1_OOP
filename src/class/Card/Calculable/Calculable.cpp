#include "Calculable.hpp"
#include <iostream>
#include <vector>
using namespace std;

// Class Card
Cards::Cards(string suit, float value) {
    this->suit = suit;
    this->value = value;
}

float Cards::valueCards() {
    return this->value;
}

// Class Combo
Combo::Combo(vector<Cards> cards) {
    this -> cards = cards;
}

float Combo::valueCards() {
    return 0.0;
}

// Class AceCard (int value selalu 1)
CardAce::CardAce(string suit, float value) : Cards(suit, value) {
    float nilai = 0.1;
    if (this -> suit == "H"){
        nilai = 0.1;
    }
    if (this -> suit == "B"){
        nilai += 0.03;
    }
    if (this -> suit == "K"){
        nilai += 0.06;
    }
    if (this -> suit == "M"){
        nilai += 0.09;
    }
    this->value = nilai;
}

float CardAce::valueCards() {
    return this->value;
}

CardTwo::CardTwo(string suit, float value) : Cards(suit, value) {
    float nilai = 0.2;
    if (this -> suit == "H"){
        nilai = 0.2;
    }
    if (this -> suit == "B"){
        nilai += 0.03;
    }
    if (this -> suit == "K"){
        nilai += 0.06;
    }
    if (this -> suit == "M"){
        nilai += 0.09;
    }
    this->value = nilai;
}

float CardTwo::valueCards() {
    return this->value;
}

CardThree::CardThree(string suit, float value) : Cards(suit, value) {
    float nilai = 0.3;
    if (this -> suit == "H"){
        nilai = 0.3;
    }
    if (this -> suit == "B"){
        nilai += 0.03;
    }
    if (this -> suit == "K"){
        nilai += 0.06;
    }
    if (this -> suit == "M"){
        nilai += 0.09;
    }
    this->value = nilai;
}

float CardThree::valueCards() {
    return this->value;
}

CardFour::CardFour(string suit, float value) : Cards(suit, value) {
    float nilai = 0.4;
    if (this -> suit == "H"){
        nilai = 0.4;
    }
    if (this -> suit == "B"){
        nilai += 0.03;
    }
    if (this -> suit == "K"){
        nilai += 0.06;
    }
    if (this -> suit == "M"){
        nilai += 0.09;
    }
    this->value = nilai;
}

float CardFour::valueCards() {
    return this->value;
}

CardFive::CardFive(string suit, float value) : Cards(suit, value) {
    float nilai = 0.5;
    if (this -> suit == "H"){
        nilai = 0.5;
    }
    if (this -> suit == "B"){
        nilai += 0.03;
    }
    if (this -> suit == "K"){
        nilai += 0.06;
    }
    if (this -> suit == "M"){
        nilai += 0.09;
    }
    this->value = nilai;
}

float CardFive::valueCards() {
    return this->value;
}

CardSix::CardSix(string suit, float value) : Cards(suit, value) {
    float nilai = 0.6;
    if (this -> suit == "H"){
        nilai = 0.6;
    }
    if (this -> suit == "B"){
        nilai += 0.03;
    }
    if (this -> suit == "K"){
        nilai += 0.06;
    }
    if (this -> suit == "M"){
        nilai += 0.09;
    }
    this->value = nilai;
}

float CardSix::valueCards() {
    return this->value;
}

CardSeven::CardSeven(string suit, float value) : Cards(suit, value) {
    float nilai = 0.7;
    if (this -> suit == "H"){
        nilai = 0.7;
    }
    if (this -> suit == "B"){
        nilai += 0.03;
    }
    if (this -> suit == "K"){
        nilai += 0.06;
    }
    if (this -> suit == "M"){
        nilai += 0.09;
    }
    this->value = nilai;
}

float CardSeven::valueCards() {
    return this->value;
}

CardEight::CardEight(string suit, float value) : Cards(suit, value) {
    float nilai = 0.8;
    if (this -> suit == "H"){
        nilai = 0.8;
    }
    if (this -> suit == "B"){
        nilai += 0.03;
    }
    if (this -> suit == "K"){
        nilai += 0.06;
    }
    if (this -> suit == "M"){
        nilai += 0.09;
    }
    this->value = nilai;
}

float CardEight::valueCards() {
    return this->value;
}

CardNine::CardNine(string suit, float value) : Cards(suit, value) {
    float nilai = 0.9;
    if (this -> suit == "H"){
        nilai = 0.9;
    }
    if (this -> suit == "B"){
        nilai += 0.03;
    }
    if (this -> suit == "K"){
        nilai += 0.06;
    }
    if (this -> suit == "M"){
        nilai += 0.09;
    }
    this->value = nilai;
}

float CardNine::valueCards() {
    return this->value;
}

CardTen::CardTen(string suit, float value) : Cards(suit, value) {
    float nilai = 1;
    if (this -> suit == "H"){
        nilai = 1;
    }
    if (this -> suit == "B"){
        nilai += 0.03;
    }
    if (this -> suit == "K"){
        nilai += 0.06;
    }
    if (this -> suit == "M"){
        nilai += 0.09;
    }
    this->value = nilai;
}

float CardTen::valueCards() {
    return this->value;
}

CardJack::CardJack(string suit, float value) : Cards(suit, value) {
    float nilai = 1.1;
    if (this -> suit == "H"){
        nilai = 1.1;
    }
    if (this -> suit == "B"){
        nilai += 0.03;
    }
    if (this -> suit == "K"){
        nilai += 0.06;
    }
    if (this -> suit == "M"){
        nilai += 0.09;
    }
    this->value = nilai;
}

float CardJack::valueCards() {
    return this->value;
}

CardQueen::CardQueen(string suit, float value) : Cards(suit, value) {
    float nilai = 1.2;
    if (this -> suit == "H"){
        nilai = 1.2;
    }
    if (this -> suit == "B"){
        nilai += 0.03;
    }
    if (this -> suit == "K"){
        nilai += 0.06;
    }
    if (this -> suit == "M"){
        nilai += 0.09;
    }
    this->value = nilai;
}

float CardQueen::valueCards() {
    return this->value;
}

CardKing::CardKing(string suit, float value) : Cards(suit, value) {
    float nilai = 1.3;
    if (this -> suit == "H"){
        nilai = 1.3;
    }
    if (this -> suit == "B"){
        nilai += 0.03;
    }
    if (this -> suit == "K"){
        nilai += 0.06;
    }
    if (this -> suit == "M"){
        nilai += 0.09;
    }
    this->value = nilai;
}

float CardKing::valueCards() {
    return this->value;
}

// OnePair::OnePair(vector<Cards> cards) : Combo(vector<Cards>(cards)) {

// }

// float OnePair::valueCards(){

// }

// TwoPair::TwoPair(vector<Cards> cards) : Combo(vector<Cards>(cards)) {

// }

// float TwoPair::valueCards(){

// }

// ThreeOfKind::ThreeOfKind(vector<Cards> cards) : Combo(vector<Cards>(cards)) {

// }

// float ThreeOfKind::valueCards(){

// }

// Straight::Straight(vector<Cards> cards) : Combo(vector<Cards>(cards)) {

// }

// float Straight::valueCards(){

// }

// Flush::Flush(vector<Cards> cards) : Combo(vector<Cards>(cards)) {

// }

// float Flush::valueCards(){

// }

// FullHouse::FullHouse(vector<Cards> cards) : Combo(vector<Cards>(cards)) {

// }

// float FullHouse::valueCards(){

// }

// FourOfKind::FourOfKind(vector<Cards> cards) : Combo(vector<Cards>(cards)) {

// }

// float FourOfKind::valueCards(){

// }

// StraightFlush::StraightFlush(vector<Cards> cards) : Combo(vector<Cards>(cards)) {

// }

// float StraightFlush::valueCards(){

// }