//
// Created by lenovo on 14/03/2023.
//

#include "NextAct.hpp"

NextAct::NextAct(Player &p, SetGame &s): Action() {
    this->p=&p;
    this->s=&s;
}

void NextAct::Act() {
    cout << "Giliran dilanjut ke pemain berikutnya" << endl;
    this->s->nextTurn();
}