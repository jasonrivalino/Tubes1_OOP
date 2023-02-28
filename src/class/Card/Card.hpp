//
// Created by lenovo on 27/02/2023.
//

#ifndef TUBES1_OOP_CARD_HPP
#define TUBES1_OOP_CARD_HPP


#include <iostream>

using namespace std;

class Card {
private:
    string nama;
    int nomorKartu;
public:
    Card(string nama);
    Card(string nama,int number);

    string getNameCard();
    int getNumberCard();
};


#endif //TUBES1_OOP_CARD_H
