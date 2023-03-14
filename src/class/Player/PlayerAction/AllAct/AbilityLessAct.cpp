//
// Created by lenovo on 14/03/2023.
//

#include "AbilityLessAct.hpp"

AbilityLessAct::AbilityLessAct(Player &p, SetGame &s): Action(),Abilityless() {
    this->p=&p;
    this->s=&s;
}

void AbilityLessAct::Act() {
    int idxPlayer=0;
    int idxCard=0;

    for(int i=0;i<s->getPlayers().size();i++){
        if(s->getPlayers()[i]==p) idxPlayer=i;
    }


    for(int i=0;i<s->getPlayers()[idxPlayer]->getCardsPlayer().size();i++){
        bool abilityP1 =
                s->getPlayers()[idxPlayer]->getCardsPlayer()[i]->getNameCard()!="M"&&
                s->getPlayers()[idxPlayer]->getCardsPlayer()[i]->getNameCard()!="B"&&
                s->getPlayers()[idxPlayer]->getCardsPlayer()[i]->getNameCard()!="K"&&
                s->getPlayers()[idxPlayer]->getCardsPlayer()[i]->getNameCard()!="H";

        if(abilityP1){
            idxCard=i;
        }
    }

    if(!(s->getPlayers()[idxPlayer]->getCardsPlayer()[idxCard]->getNameCard()=="AbilityLess")) throw notHaveAbilityCard();


    bool isAllUsed= true;
    for(int j=0;j< s->getPlayers().size();j++) {
        if(s->getPlayers()[j]!=p) {
            for (int i = 0; i < s->getPlayers()[j]->getCardsPlayer().size(); i++) {
                bool abilityP1 =
                        s->getPlayers()[j]->getCardsPlayer()[i]->getNameCard() != "M" &&
                        s->getPlayers()[j]->getCardsPlayer()[i]->getNameCard() != "B" &&
                        s->getPlayers()[j]->getCardsPlayer()[i]->getNameCard() != "K" &&
                        s->getPlayers()[j]->getCardsPlayer()[i]->getNameCard() != "H";

                if (abilityP1) {
                    if((!s->getPlayers()[j]->getCardsPlayer()[i]->getIsCardUsed())) {
                        isAllUsed = false;
                    }
                }
            }
        }
    }


    if(isAllUsed){
        throw allCardUsed();
    }else{
        cout<<"Player "<<p->getTurn()<<" melakukan AbilityLess"<<endl;
        cout<<"silakan pilih pemain yang ingin dimatikan ability card-nya"<<endl;
        vector<Player*> allPlayers;
        int idxFirstPlayer;

        for(int i=0;i<s->getPlayers().size();i++){
            if(s->getPlayers()[i]!=p){
                allPlayers.push_back(s->getPlayers()[i]);
            }
        }


        for(int i=0;i<allPlayers.size();i++) cout<<i+1<<" Player "<<allPlayers[i]->getTurn()<<endl;

        cout<<">>";
        cin>>idxFirstPlayer;
        while(idxFirstPlayer>allPlayers.size()||idxFirstPlayer<1){
            cout<<"input anda salah"<<endl;
            cout<<">>";
            cin>>idxFirstPlayer;
        }

        Player *p1 = allPlayers[idxFirstPlayer-1];

        try {
            this->effect(*s, *p, *p1);
        }catch (playerCardUsed e){
            cout<<e.what()<<endl;
        }
    }
}