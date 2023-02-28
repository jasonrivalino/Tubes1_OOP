#include "Card.hpp"


Card::Card(string nama) {

    this->nama=nama;
}
Card::Card(string nama, int number) {
    this->nama=nama;
    this->nomorKartu=number;
}
string Card::getNameCard() {
    return this->nama;
}
int Card::getNumberCard() {
    return this->nomorKartu;
}
