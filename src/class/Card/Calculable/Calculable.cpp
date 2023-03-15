#include "Calculable.hpp"
#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Class Card
Cards::Cards(string suit, float value) {
    this->suit = suit;
    this->value = value;
}

string Cards::getSuit() {
    return this -> suit;
}

float Cards::valueCards() {
    return this->value;
}

// Class Combo
Combo::Combo(vector<Cards> cards) {
    this -> suit = suit;
    this -> value = value;
}

float Combo::valueCards() {
    return this -> value;
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

OnePair::OnePair(vector<Cards> cards) : Combo(vector<Cards>(cards)) {
    float maxHigh = 1.39;
    // Cari pasangan dua kartu
    for (int i = 0; i < cards.size(); i++){
        for (int j = i+1; j < cards.size(); j++){
            if (cards[i].valueCards() == cards[j].valueCards()){
                this->value = cards[i].valueCards() + cards[j].valueCards() + maxHigh;
            }
        }
    }
}

float OnePair::valueCards(){
    return this->value;
}

TwoPair::TwoPair(vector<Cards> cards) : Combo(vector<Cards>(cards)) {
    float maxOnePair = 2.75;
    // Cari pasangan dua kartu sebanyak dua kali
    for (int i = 0; i < cards.size(); i++){
        for (int j = i+1; j < cards.size(); j++){
            if (cards[i].valueCards() == cards[j].valueCards()){
                for (int k = 0; k < cards.size(); k++){
                    for (int l = k+1; l < cards.size(); l++){
                        if (cards[k].valueCards() == cards[l].valueCards()){
                            this->value = cards[i].valueCards() + cards[j].valueCards() + cards[k].valueCards() + cards[l].valueCards() + maxOnePair;
                        }
                    }
                }
            }
        }
    }
}

float TwoPair::valueCards(){
    return this->value;
}

ThreeOfKind::ThreeOfKind(vector<Cards> cards) : Combo(vector<Cards>(cards)) {
    float maxTwoPair = 5.30;
    // Cari pasangan tiga kartu
    for (int i = 0; i < cards.size(); i++){
        for (int j = i+1; j < cards.size(); j++){
            for (int k = j+1; k < cards.size(); k++){
                if (cards[i].valueCards() == cards[j].valueCards() && cards[j].valueCards() == cards[k].valueCards()){
                    this->value = cards[i].valueCards() + cards[j].valueCards() + cards[k].valueCards() + maxTwoPair;
                }
            }
        }
    }
}

float ThreeOfKind::valueCards(){
    return this->value;
}

Straight::Straight(vector<Cards> cards) : Combo(vector<Cards>(cards)) {
    float maxThreeOfKind = 4.08;
    // Basis
    sort(cards.begin(), cards.end(), [](Cards a, Cards b) { return a.valueCards() < b.valueCards(); });
    for (int i = 0; i < cards.size(); i++){
        for (int j = 0; j < 4; j++){
            if (cards[i+1].valueCards() == cards[i].valueCards()+1){
                this->value = cards[i].valueCards() + cards[i+1].valueCards() + cards[i+2].valueCards() + cards[i+3].valueCards() + cards[i+4].valueCards() + maxThreeOfKind;
            }
        }
    }
}

float Straight::valueCards(){
    return this->value;
}

Flush::Flush(vector<Cards> cards) : Combo(vector<Cards>(cards)) {
    float maxStraight = 5.92;
    // Cari flush
    map <string, float> m;
    for (int i = 0; i < cards.size(); i++){
        m[cards[i].getSuit()]++;
    }
    for (auto i : m){
        if (i.second == 5){
            this->value = cards[0].valueCards() + cards[1].valueCards() + cards[2].valueCards() + cards[3].valueCards() + cards[4].valueCards() + maxStraight;
        }
    }
}

float Flush::valueCards(){
    return this->value;
}

FullHouse::FullHouse(vector<Cards> cards) : Combo(vector<Cards>(cards)) {
    float maxFlush = 5.85;
    // Cari pasangan tiga kartu dan dua kartu
    for (int i = 0; i < cards.size(); i++){
        for (int j = i+1; j < cards.size(); j++){
            for (int k = j+1; k < cards.size(); k++){
                if (cards[i].valueCards() == cards[j].valueCards() && cards[j].valueCards() == cards[k].valueCards()){
                    for (int l = 0; l < cards.size(); l++){
                        for (int m = l+1; m < cards.size(); m++){
                            if (cards[l].valueCards() == cards[m].valueCards()){
                                this->value = cards[i].valueCards() + cards[j].valueCards() + cards[k].valueCards() + cards[l].valueCards() + cards[m].valueCards() + maxFlush;
                            }
                        }
                    }
                }
            }
        }
    }
}

float FullHouse::valueCards(){
    return this->value;
}

FourOfKind::FourOfKind(vector<Cards> cards) : Combo(vector<Cards>(cards)) {
    float maxFullHouse = 6.63;
    // Cari pasangan empat kartu
    for (int i = 0; i < cards.size(); i++){
        for (int j = i+1; j < cards.size(); j++){
            for (int k = j+1; k < cards.size(); k++){
                for (int l = k+1; l < cards.size(); l++){
                    if (cards[i].valueCards() == cards[j].valueCards() && cards[j].valueCards() == cards[k].valueCards() && cards[k].valueCards() == cards[l].valueCards()){
                        this->value = cards[i].valueCards() + cards[j].valueCards() + cards[k].valueCards() + cards[l].valueCards() + maxFullHouse;
                    }
                }
            }
        }
    }
}

float FourOfKind::valueCards(){
    return this->value;
}

StraightFlush::StraightFlush(vector<Cards> cards) : Combo(vector<Cards>(cards)) {
    float maxFourOfKind = 5.38;
    sort(cards.begin(), cards.end(), [](Cards a, Cards b) { return a.valueCards() < b.valueCards(); });
    map <string, float> m;
    
    for (int i = 0; i < cards.size(); i++){
        m[cards[i].getSuit()]++;
    }

    for (auto i : m){
        if (i.second == 5){
            for (int j = 0; j < 4; j++){
                if (cards[j+1].valueCards() == cards[j].valueCards()+1){
                    this->value = cards[j].valueCards() + cards[j+1].valueCards() + cards[j+2].valueCards() + cards[j+3].valueCards() + cards[j+4].valueCards() + maxFourOfKind;
                }
            }
        }
    }
}

float StraightFlush::valueCards(){
    return this->value;
}