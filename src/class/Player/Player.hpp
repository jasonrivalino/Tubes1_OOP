#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>

#include "../Card/Card.hpp"

using namespace std;
class Player{
protected:
    static int currentTurn;
    const int turn;
    int point;
    string playerName; 
    vector <Card> cards;
public:
    /*
     memanggil class dengan mengatur nama dari sang player dan giliran player
     */
    Player(string playerName);
    // dcctor
    ~Player();

    // untuk mendapatkan giliran dari player yang dipilih
    int getTurn() const;

    //untuk mendapatkan poin dari player yang dipilih
    int getPoint();

    //untuk mendapatkan seluruh kartu yang dimiliki oleh player
    vector<Card> getCardsPlayer();

    // mendapatkan banyaknya kartu yang player punya
    int getSizeCardsPlayer();

    // menambahkan kartu palyer
    void addCard(Card c);

    // menampilkan seluruh kartu yang player punya
    void printCards();

    // menghapus kartu yang dimiliki palayer secara spesifik
    void removeSpecificCard(Card c);

    // menghapus kartu player dari yang terbawah
    void removeBackCard();

    // men-setting poin player
    void setPoint(int);

};

#endif