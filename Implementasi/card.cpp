

#include "../Header/card.h"


card::card(string nama) {
    this->nama=nama;
}
card::card(string nama, int number) {
    this->nama=nama;
    this->nomorKartu=number;
}
string card::getNameCard() {
    return this->nama;
}
int card::getNumberCard() {
    return this->nomorKartu;
}
