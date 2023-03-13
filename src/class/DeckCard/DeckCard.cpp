#include "DeckCard.hpp"

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