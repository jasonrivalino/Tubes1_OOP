//
// Created by lenovo on 14/03/2023.
//

#include "QuarterAct.hpp"

QuarterAct::QuarterAct(Player &p, SetGame &s): Action(),Quarter() {
    this->p=&p;
    this->s=&s;
}

void QuarterAct::Act() {
    int idxPlayer=0;

    for(int i=0;i<this->s->getPlayers().size();i++){
        if(this->s->getPlayers()[i]==p) idxPlayer=i;
    }

    if(this->s->getPlayers()[idxPlayer]->getAbility().size()==0) throw notHaveQuarterCard();
    if(this->s->getPlayers()[idxPlayer]->getAbility()[0]->getIsCardUsed()) throw quarterCardIsUsed();
    if(!(this->s->getPlayers()[idxPlayer]->getAbility()[0]->getNameCard()=="Quarter")) throw notHaveQuarterCard();
    if(this->s->getPlayers()[idxPlayer]->getAbility()[0]->getIsCardDeath()) throw quarterIsDeath();


    this->effect(*p,*s);
}