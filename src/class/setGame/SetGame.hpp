//
// Created by lenovo on 28/02/2023.
//

#ifndef TUBES1_OOP_SETGAME_H
#define TUBES1_OOP_SETGAME_H

#include "../Player/Player.hpp"
#include "../Card/Card.hpp"
#include "../Ability/ability_card.hpp"

using namespace std;
#include <iostream>
#include <vector>


class SetGame {
private:
    vector<Card> cards;
    vector<Player> players;
    vector<Card> ability;
public:
    /*
     untuk melakukan setting awal pada kartu, kartu ability, dan player
     yang dimana mengacak kartu, kartu ability agar mudah dibagi ke pada para pemain
     */
    SetGame();

    /*
      Untuk melakukan penambahan kartu
      dibuat untuk pemain yang melakukan swap
    */
    void addCard(Card card);

    /*
      Untuk melakukan pengurangan kartu
      dibuat untuk pemain yang melakukan swap
    */
    void removeTopCard();

    /*
     Untuk menghapus seluruh ability card
     digunakan pada ronde ke 2 setelah ability card dibagi bagi
     setelah dibagi ability card akan terhabus semua karena seluruh ability card sudah ada pada pemain
     */
    void removeAbilityCards();

    /*
     Untuk melihat kartu ability card
    */
    vector<Card> getAbilityCards();

    /*
     Untuk melihat kartu card
    */
    vector<Card> getCards();

    /*
     Untuk melihat player
    */
    vector<Player> getPlayers();
};


#endif //TUBES1_OOP_SETGAME_H
