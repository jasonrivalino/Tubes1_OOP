//
// Created by lenovo on 14/03/2023.
//

#include "ReverseAct.hpp"

ReverseAct::ReverseAct(Player &p, SetGame &s): Action(),ReverseDirection() {
    this->p=&p;
    this->s=&s;
}

void ReverseAct::Act() {
    int idxPlayer=0;
    int idxCard=0;

    for(int i=0;i<this->s->getPlayers().size();i++){
        if(this->s->getPlayers()[i]==p) idxPlayer=i;
    }

    if(!(this->s->getPlayers()[idxPlayer]->getAbility()[0]->getNameCard()=="Reverse")) throw notHaveQuarterCard();
    if(this->s->getPlayers()[idxPlayer]->getAbility()[0]->getIsCardDeath()) throw quarterIsDeath();


    this->effect(p,s);
}

