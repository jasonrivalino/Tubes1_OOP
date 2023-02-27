//
// Created by lenovo on 27/02/2023.
//

#ifndef TUBES1_OOP_CARD_H
#define TUBES1_OOP_CARD_H


#include <iostream>

using namespace std;

class card {
private:
    string nama;
    int nomorKartu;
public:
    card(string nama);
    card(string nama,int number);

    string getNameCard();
    int getNumberCard();
};


#endif //TUBES1_OOP_CARD_H
