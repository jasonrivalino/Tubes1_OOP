//
// Created by lenovo on 14/03/2023.
//

#include "SwitchAct.hpp"

SwitchAct::SwitchAct(Player &p, SetGame &s): Action(),Switch() {
    this->p=&p;
    this->s=&s;
}

void SwitchAct::Act() {
    int idxPlayer=0;
    int idxCard=0;

    for(int i=0;i<this->s->getPlayers().size();i++){
        if(this->s->getPlayers()[i]==p) idxPlayer=i;
    }

    if(this->s->getPlayers()[idxPlayer]->getAbility()[0]->getIsCardUsed()) throw switchCardIsUsed();
    if(this->s->getPlayers()[idxPlayer]->getAbility().size()==0) throw notHaveSwitchCard();
    if(!(this->s->getPlayers()[idxPlayer]->getAbility()[0]->getNameCard()=="Switch")) throw notHaveSwitchCard();
    if(this->s->getPlayers()[idxPlayer]->getAbility()[0]->getIsCardDeath()) throw switchIsDeath();

    vector<Player*> allPlayers;
    int idxFirstPlayer;

    for(int i=0;i<this->s->getPlayers().size();i++){
        if(this->s->getPlayers()[i]!=p){
            allPlayers.push_back(this->s->getPlayers()[i]);
        }
    }



    cout<<"Player "<< this->p->getTurn()<<" melakukan Switch"<<endl;
    cout<<"Silahkan pilih pemain yang kartunya ingin anda tukar:"<<endl;
    for(int i=0;i<allPlayers.size();i++) cout<<i+1<<" Player "<<allPlayers[i]->getTurn()<<endl;

    cout<<">>";
    cin>>idxFirstPlayer;
    while(idxFirstPlayer>allPlayers.size()||idxFirstPlayer<1){
        cout<<"input anda salah"<<endl;
        cout<<">>";
        cin>>idxFirstPlayer;
    }

    Player *p1 = allPlayers[idxFirstPlayer-1];
    allPlayers.erase(allPlayers.begin()+(idxFirstPlayer-1));


    this->effect(*p,*p1,*s);
}