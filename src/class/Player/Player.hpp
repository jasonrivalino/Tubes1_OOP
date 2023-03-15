#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>

#include "../Card/Card.hpp"
#include "../Card/Calculable/Calculable.hpp"

using namespace std;

class Player{
protected:
    static int currentTurn;
    const int turn;
    int point;
    string playerName; 
    vector <Card*> cards;
    // vector <vector<Card, int>> allCombo;
    // // vector <Card> highestCombo;
    Calculable *highestComboValue;
    
public:
    /*
     memanggil class dengan mengatur nama dari sang player dan giliran player
     */
    Player(string playerName);
    // dcctor
    ~Player();

    // untuk mendapatkan giliran dari player yang dipilih
    int getTurn() const;

    //untuk mendapatkan seluruh kartu yang dimiliki oleh player
    vector<Card*> getCardsPlayer();

    // mendapatkan banyaknya kartu yang player punya
    int getSizeCardsPlayer();

    // menambahkan kartu palyer
    void addCard(Card &c);

    //menambahkan kartu di posisi spesifik
    void addCardSpesPos(Card&,int);

    // menampilkan seluruh kartu yang player punya
    void printCards();

    // menghapus kartu yang dimiliki palayer secara spesifik
    void removeSpecificCard(Card c);

    // menghapus kartu player dari yang terbawah
    void removeBackCard();

    //penghapusan kartu pertama player
    void removeFirstCard();


    // men-setting poin player
    void setPoint(int);

    //untuk mendapatkan poin dari player yang dipilih
    int getPoint();

    //apakah player sama
    bool operator==(const Player&);

    //apakah player tidak sama
    bool operator!=(const Player&);

    //untuk mendapatkan combo tertinggi dari player yang dipilih
    Calculable* getHighestComboValue(vector<Card*>);

};

#endif