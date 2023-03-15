//
// Created by lenovo on 14/03/2023.
//

#include "SwapAct.hpp"

SwapAct::SwapAct(Player &p, SetGame &s): Action(),SwapCard() {
    this->p=&p;
    this->s=&s;
}

void SwapAct::Act() {
    int idxPlayer=0;
    int rightOrLeft1,rightOrLeft2=0;

    for(int i=0;i< this->s->getPlayers().size();i++){
        if(this->s->getPlayers()[i]==p) idxPlayer=i;
    }

    if(this->s->getPlayers()[idxPlayer]->getAbility().size()==0) throw notHaveSwapCard();
    if(!(this->s->getPlayers()[idxPlayer]->getAbility()[0]->getNameCard()=="Swap")) throw notHaveSwapCard();
    if(this->s->getPlayers()[idxPlayer]->getAbility()[0]->getIsCardDeath()) throw swapIsDeath();

    vector<Player*> allPlayers;
    int idxFirstPlayer,idxSecondPlayer;

    for(int i=0;i<this->s->getPlayers().size();i++){
        if(this->s->getPlayers()[i]!=p){
            allPlayers.push_back(this->s->getPlayers()[i]);
        }
    }


    cout<<"Player "<<this->p->getTurn()<<" melakukan Swap"<<endl;
    cout<<"Silahkan pilih pemain yang kartunya ingin anda tukar:"<<endl;
    for(int i=0;i<allPlayers.size();i++) cout<<i+1<<" Player "<<allPlayers[i]->getTurn()<<endl;

    cout<<">>";
    cin>>idxFirstPlayer;
    while(idxFirstPlayer>allPlayers.size()||idxFirstPlayer<1){
        cout<<"input anda salah"<<endl;
        cout<<">>";
        cin>>idxFirstPlayer;
    }

    cout<<"Pilih kartu: \n1.kiri\n2.kanan"<<endl;
    cout<<">>";
    cin>>rightOrLeft1;
    while (rightOrLeft1>2||rightOrLeft1<1){
        cout<<"input salah"<<endl;
        cout<<">>";
        cin>>rightOrLeft1;
    }

    Player *p1 = allPlayers[idxFirstPlayer-1];
    allPlayers.erase(allPlayers.begin()+(idxFirstPlayer-1));





    cout<<"Silahkan pilih pemain yang kartunya ingin anda tukar:"<<endl;
    for(int i=0;i<allPlayers.size();i++) cout<<i+1<<" Player "<<allPlayers[i]->getTurn()<<endl;

    cout<<">>";
    cin>>idxSecondPlayer;
    while(idxSecondPlayer>allPlayers.size()||idxSecondPlayer<1){
        cout<<"input anda salah"<<endl;
        cout<<">>";
        cin>>idxSecondPlayer;
    }

    cout<<"Pilih kartu: \n1.kiri\n2.kanan"<<endl;
    cout<<">>";
    cin>>rightOrLeft2;
    while (rightOrLeft2>2||rightOrLeft2<1){
        cout<<"input salah"<<endl;
        cout<<">>";
        cin>>rightOrLeft2;
    }

    Player *p2 = allPlayers[idxSecondPlayer-1];
    allPlayers.erase(allPlayers.begin()+(idxSecondPlayer-1));

    this->effect(*p,*p1,*p2,rightOrLeft1-1,rightOrLeft2-1,*s);

}
