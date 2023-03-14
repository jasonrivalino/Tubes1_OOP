//
// Created by lenovo on 28/02/2023.
//

#ifndef TUBES1_OOP_SETGAME_H
#define TUBES1_OOP_SETGAME_H

#include "../Player/Player.hpp"
#include "../Card/Card.hpp"
#include "../Ability/AbilityCard.hpp"
#include "../Table/Table.hpp"


using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>


class SetGame {
private:
    vector<Card*> cards;
    vector<Player*> players;
    vector<Card*> ability;
    static int turn;
    long int pointGame;
public:
    /*
     untuk melakukan setting awal pada kartu, kartu ability, dan player
     yang dimana mengacak kartu, kartu ability agar mudah dibagi ke pada para pemain
     */
    SetGame(int jumPlayer);

    /*
     ddc
    */
    ~SetGame();
    /*
      Untuk melakukan penambahan kartu
      dibuat untuk pemain yang melakukan swap
    */
    void addCard(Card card);

    /*
      Untuk melakukan pengurangan kartu
      dibuat untuk pemain yang melakukan swap
    */
    void removeBackCard();

    //melakukan penghapusan kartu terdepan
    void removeFirstCard();

    /*
     Untuk menghapus seluruh ability card
     digunakan pada ronde ke 2 setelah ability card dibagi bagi
     setelah dibagi ability card akan terhabus semua karena seluruh ability card sudah ada pada pemain
     */
    void removeAbilityCards();
    /*
     share kartu ke pada player
     shareCard merupakan jumlah card yang akan dibagi ke pada player
     */
    void shareCardToPlayer(int shareCard);
    /*
    share kartu ability kepada seluruh player
     */
    void shareAbilityCard();
    /*
    untuk menghentikan ronde
     dengan mereset seluruh kartu dan memberikan poin
     kepada pemain yang menang
     */
    void endRound(Player &playerWin);

    // Untuk men-setting poin game yang dijalankan, biasanya digunakan untuk PlayerAction
    void setPoint(long);

    // untuk mereverse turn
    void reverseTurn();

    /*
     Untuk melihat kartu ability card
    */
    vector<Card*> getAbilityCards();

    /*
     Untuk melihat kartu card
    */
    vector<Card*> getCards();

    /*
     Untuk melihat player
    */
    vector<Player*> getPlayers();

    // giliran player
    Player& playerTurn() const;
    /*
     untuk mengambil size dari card
    */
    int getSizeCards();


    //untuk menampilkan point seluruh player
    void showAllPoint();
    /*
     untuk menampilkan seluruh kartu yang masih ada pada game
     */
    void printCards();

    //untuk next giliran
    void nextTurn();

    //setting turn
    void setTurn(int);


    /*
     untuk mengambil point pada game
     */
    long int getPointGame();


};


#endif //TUBES1_OOP_SETGAME_H
