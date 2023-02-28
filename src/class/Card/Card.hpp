//
// Created by lenovo on 27/02/2023.
//

#ifndef TUBES1_OOP_CARD_HPP
#define TUBES1_OOP_CARD_HPP

#include <iostream>

using namespace std;

class Card{
private:
    string nama;
    bool isUsed;
    int nomorKartu;
public:
    Card(string nama,bool isUsed);
    Card(string nama,int number);

    string getNameCard();
    bool getIsCardUsed();
    void setIsCardUsed(bool);
    int getNumberCard();
};


#endif //TUBES1_OOP_CARD_H
