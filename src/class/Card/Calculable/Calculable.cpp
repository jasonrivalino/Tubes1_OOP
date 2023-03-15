#include "Calculable.hpp"
#include <iostream>
using namespace std;

// Class Card
Cards::Cards(int value, char suit) {
    this->value = value;
    this->suit = suit;
    this->cards.push_back(*this);
}

float Cards::valueCards() {
    return this->value;
}

// Class Combo
Combo::Combo(vector<Cards> cards) {
    this->cards = cards;
}

float Combo::valueCards() {
    return 0.0;
}

// Class OnePair
OnePair::OnePair(vector<int> cards) {
}

float OnePair::valueCards() {    
}

// Class StraightFlush
StraightFlush::StraightFlush(vector<int> cards) {
}

float StraightFlush::valueCards() {
}

// Class TwoPair
TwoPair::TwoPair(vector<int> cards) {
}

float TwoPair::valueCards() {
}

// Class FullHouse
FullHouse::FullHouse(vector<int> cards) {
}

float FullHouse::valueCards() {
}

// Class FourOfKind
FourOfKind::FourOfKind(vector<int> cards) {
}

float FourOfKind::valueCards() {
}

// Class ThreeOfKind
ThreeOfKind::ThreeOfKind(vector<int> cards) {
}

float ThreeOfKind::valueCards() {
}

// Class Straight
Straight::Straight(vector<int> cards) {
}

float Straight::valueCards() {
}

// Class Flush
Flush::Flush(vector<int> cards) {
}

float Flush::valueCards() {
}

// Class HighCard
HighCard::HighCard(vector<int> cards) {
}

float HighCard::valueCards() {
}