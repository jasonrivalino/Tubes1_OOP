//
// Created by lenovo on 14/03/2023.
//

#include "HalfAct.hpp"


HalfAct::HalfAct(Player &p, SetGame &s): Action() {
    this->p=&p;
    this->s=&s;
}

void HalfAct::Act() {
    long pointBeforeAction = this->s->getPointGame();
    if (pointBeforeAction != 1) {
        this->s->setPoint(this->s->getPointGame()/2);
        cout << this->p << "melakukan HALF!" << "Poin hadiah turun dari " << pointBeforeAction << " menjadi " << this->s->getPointGame() << endl;
    }
}