#include "Card.hpp"


Card::Card(string nama,bool isUsed) {

    this->nama=nama;
    this->isUsed=isUsed;
    this->isDeath= false;
}
Card::Card(string nama, int number) {
    this->nama=nama;
    this->nomorKartu=number;
}
string Card::getNameCard() const {
    return this->nama;
}
bool Card::getIsCardUsed() const {
    return this->isUsed;
}
void Card::setIsCardUsed(bool isUsed) {
    this->isUsed=isUsed;
}
int Card::getNumberCard() const {
    return this->nomorKartu;
}
void Card::setIsCardDeath(bool D) {
    this->isDeath=D;
}
bool Card::getIsCardDeath() const {
    return this->isDeath;
}
// float Card::valueCard() {
//     if (this -> nama == "Hijau"){
//         this -> nilaiWarna = 0;
//     }
//     if (this -> nama == "Biru"){
//         this -> nilaiWarna = 1;
//     }
//     if (this -> nama == "Kuning"){
//         this -> nilaiWarna = 2;
//     }
//     if (this -> nama == "Merah"){
//         this -> nilaiWarna = 3;
//     }
//     // if (/*High Card*/){
//     //     this -> value = this -> konstanta + this -> nilaiWarna * 0.03;
//     // }
//     // if (/*Pair*/){
//     //     this -> value = /*Pair*/ + 1.39;
//     // }
//     // if (/*Two Pair*/){
//     //     this -> value = /*Two Pair + Max_Pair;*/
//     // }
//     // if (/*Three of a Kind*/){
//     //     this -> value = /*Three of a Kind + Max_Two Pair;*/
//     // }
//     // if (/*Straight*/){
//     //     this -> value = /*Straight + Max_Three of a Kind;*/
//     // }
//     // if (/*Flush*/){
//     //     this -> value = /*Flush + Max_Straight;*/
//     // }
//     // if (/*Full House*/){
//     //     this -> value = /*Full House + Max_Flush;*/
//     // }
//     // if (/*Four of a Kind*/){
//     //     this -> value = /*Four of a Kind + Max_Full House;*/
//     // }
//     // if (/*Straight Flush*/){
//     //     this -> value = /*Straight Flush + Max_Four of a Kind;*/
//     // }
// }