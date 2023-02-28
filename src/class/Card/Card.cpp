#include "Card.hpp"


Card::Card(string nama,bool isUsed) {

    this->nama=nama;
    this->isUsed=isUsed;
}
Card::Card(string nama, int number) {
    this->nama=nama;
    this->nomorKartu=number;
}
string Card::getNameCard() {
    return this->nama;
}
bool Card::getIsCardUsed() {
    return this->isUsed;
}
void Card::setIsCardUsed(bool isUsed) {
    this->isUsed=isUsed;
}
int Card::getNumberCard() {
    return this->nomorKartu;
}

