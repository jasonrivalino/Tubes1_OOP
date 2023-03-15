//
// Created by lenovo on 14/03/2023.
//

#include "ReRollAct.hpp"

ReRollAct::ReRollAct(Player &p, SetGame &s): Action(),ReRoll() {
    this->p=&p;
    this->s=&s;
}

void ReRollAct::Act() {
    int idxPlayer=0;

    for(int i=0;i<this->s->getPlayers().size();i++){
        if(this->s->getPlayers()[i]==p) idxPlayer=i;
    }

    if(!(
            this->s->getPlayers()[idxPlayer]->getAbility()[0]->getNameCard()=="ReRoll"||
            this->s->getPlayers()[idxPlayer]->getAbility().size()==0
                    )
            )
        throw notHaveReRollCard();


    if(this->s->getPlayers()[idxPlayer]->getAbility()[0]->getIsCardDeath()) throw reRollIsDeath();


    this->effect(*p,*s);
}