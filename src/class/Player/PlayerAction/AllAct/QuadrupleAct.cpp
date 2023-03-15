//
// Created by lenovo on 14/03/2023.
//

#include "QuadrupleAct.hpp"

QuadrupleAct::QuadrupleAct(Player &p, SetGame &s): Action(),Quadruple() {
    this->p=&p;
    this->s=&s;
}

void QuadrupleAct::Act() {
    int idxPlayer=0;

    for(int i=0;i<this->s->getPlayers().size();i++){
        if(this->s->getPlayers()[i]==p) idxPlayer=i;
    }

    if(this->s->getPlayers()[idxPlayer]->getAbility()[0]->getIsCardUsed()) throw quadrupleCardIsUsed();
    if(this->s->getPlayers()[idxPlayer]->getAbility().size()==0) throw notHaveQuadrupleCard();
    if(!(this->s->getPlayers()[idxPlayer]->getAbility()[0]->getNameCard()=="Quadruple")) throw notHaveQuadrupleCard();
    if(this->s->getPlayers()[idxPlayer]->getAbility()[0]->getIsCardDeath()) throw quadrupleIsDeath();


    this->effect(*p,*s);
}