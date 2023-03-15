//
// Created by lenovo on 14/03/2023.
//

#include "DoubleAct.hpp"


DoubleAct::DoubleAct(Player &p, SetGame &s): Action() {
    this->p=&p;
    this->s=&s;
}

void DoubleAct::Act() {
    long pointBeforeAction = this->s->getPointGame();
    this->s->setPoint(this->s->getPointGame()*2);
    cout <<"Player-"<< this->p->getTurn() << " melakukan DOUBLE!" << "Poin hadiah naik dari " << pointBeforeAction << " menjadi " << this->s->getPointGame() << endl;
}