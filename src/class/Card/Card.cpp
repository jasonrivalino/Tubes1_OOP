#include "Card.hpp"



Card::Card(string nama, int number) {
    this->nama=nama;
    this->nomorKartu=number;
}
string Card::getNameCard() const {
    return this->nama;
}
int Card::getNumberCard() const {
    return this->nomorKartu;
}