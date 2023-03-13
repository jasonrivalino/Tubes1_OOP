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
    bool isDeath;
    int nomorKartu;
    int nilaiWarna;
    float value;
    float konstanta;
public:
    /*
     memasukkan nama dari kartu dan apakah kartu tersebut sudah digunakan atau tidak
     default dari isUsed adalah false yang artinya kartu belum digunakan
     class ini dipanggil untuk class ability card agar mudah diketahui apakah kartu ability card sudah digunakan atau belum
     */
    Card(string nama,bool isUsed);

    /*
      memasukkan nama dari kartu reguler dan angkanyanay.
      nama yang dimkasud adalah nama warna dari kartu reguler yang dimasukkan
     */
    Card(string nama,int number);

    /*
     mengambil nama dari kartu
     entah nama warna maupun nama dari ability
     */
    string getNameCard() const;

    /*
    untuk mengetahui apakah kartu sudah digunakan atau belum
     fungsi ini digunakan untuk mengetahui apakah abilitycard sudah digunakan atau belum
     */
    bool getIsCardUsed() const;

    //apkah suda mati
    bool getIsCardDeath() const;

    /*
     digunakan untuk men-setting sudah atau belumnya kartu tersebut digunakan
     */
    void setIsCardUsed(bool);

    // set card mati atau tidak
    void setIsCardDeath(bool);

    /*
     untuk mengambil nomor kartu yang dipilih
     */
    int getNumberCard() const;

    float valueCard();
};


#endif //TUBES1_OOP_CARD_H
