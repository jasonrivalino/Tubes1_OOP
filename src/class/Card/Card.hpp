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
    int nomorKartu;
public:

    /*
      memasukkan nama dari kartu reguler dan angkanyanay.
      nama yang dimkasud adalah nama warna dari kartu reguler yang dimasukkan
     */
    Card(string nama,int number);

    /*
     mengambil nama dari kartu
     entah nama warna maupun nama dari ability
     */
    virtual string getNameCard() const;


    /*
     untuk mengambil nomor kartu yang dipilih
     */
    int getNumberCard() const;

};


#endif //TUBES1_OOP_CARD_H
