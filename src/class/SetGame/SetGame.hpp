//
// Created by lenovo on 28/02/2023.
//

#ifndef TUBES1_OOP_SETGAME_H
#define TUBES1_OOP_SETGAME_H

#include "../Player/Player.hpp"
#include "../Card/Card.hpp"
#include "../Ability/AbilityCard.hpp"


using namespace std;
#include <iostream>
#include <vector>


class SetGame {
private:
    vector<Card*> cards;
    vector<Player*> players;
    vector<Card*> ability;
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

    /*
     Untuk menghapus seluruh ability card
     digunakan pada ronde ke 2 setelah ability card dibagi bagi
     setelah dibagi ability card akan terhabus semua karena seluruh ability card sudah ada pada pemain
     */
    void removeAbilityCards();

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
    /*
     untuk mengambil size dari card
    */
    int getSizeCards();

    /*
    untuk menampilkan point seluruh player
    */
    void showAllPoint();
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
     untuk menampilkan seluruh kartu yang masih ada pada game
     */
    void printCards();
    /*
    untuk menghentikan ronde
     dengan mereset seluruh kartu dan memberikan poin
     kepada pemain yang menang
     */
    void endRound(Player &playerWin,int point);

    /*
     untuk mengambil point pada game
     */
    long int getPointGame();

};


#endif //TUBES1_OOP_SETGAME_H
