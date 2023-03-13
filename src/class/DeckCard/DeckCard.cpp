#include "DeckCard.hpp"

DeckCard::DeckCard() : Card("",false) {
    this->nameDeckCard="";
    this->deckCardUsed=false;
    this->numberDeckCard=0;
}

DeckCard::DeckCard(string nama, int nomor) : Card(nama, nomor) {
    this->nameDeckCard=nama;
    this->numberDeckCard=nomor;
}

void DeckCard::setNameDeckCard(string nama){
    this->nameDeckCard=nama;
    this->deckCardUsed=false;
}

string DeckCard::getNameDeckCard() {
    return this->nameDeckCard;
}

void DeckCard::setDeckCardUsed(bool isUsed) {
    this->deckCardUsed=isUsed;
}

int DeckCard::getDeckCardUsed() {
    return this->deckCardUsed;
}