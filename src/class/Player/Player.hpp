#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>

#include "../Card/Card.hpp"
#include "../Ability/AbilityCard.hpp"

using namespace std;
class Player{
protected:
    static int currentTurn;
    const int turn;
    int point;
    string playerName;
    vector<Ability*> abilityCard;
    vector <Card*> cards;
public:
    /*
     memanggil class dengan mengatur nama dari sang player dan giliran player
     */
    Player(string playerName);
    // dcctor
    ~Player();

    // menambahkan kartu palyer
    void addCard(Card &c);

    //menambahkan ability card
    void addAbilityCard(Ability&);

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

    //penghapusan kartu pertama player
    void removeAbilityCard();


    // men-setting poin player
    void setPoint(int);

    //mendapatkan abilityCard
    vector<Ability*> getAbility() const;

    //untuk mendapatkan poin dari player yang dipilih
    int getPoint();

    // untuk mendapatkan giliran dari player yang dipilih
    int getTurn() const;

    //untuk mendapatkan seluruh kartu yang dimiliki oleh player
    vector<Card*> getCardsPlayer();

    // mendapatkan banyaknya kartu yang player punya
    int getSizeCardsPlayer();

    //apakah player sama
    bool operator==(const Player&);

    //apakah player tidak sama
    bool operator!=(const Player&);
};

#endif