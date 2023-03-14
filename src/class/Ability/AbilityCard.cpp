#include "AbilityCard.hpp"

#include <iostream>
using namespace std;

ReRoll::ReRoll(): Ability("ReRoll", false, false){
    this->name= "ReRoll";
    this->isUsed= false;
    this->isDeath= false;

}

ReRoll::~ReRoll(){
    //dtor
}

void ReRoll::setIsCardDeath(bool d) {this->isDeath=d;}
void ReRoll::setIsCardUsed(bool u) { this->isUsed=u;}

bool ReRoll::getIsCardDeath() const {return this->isDeath;}
bool ReRoll::getIsCardUsed() const {return this->isUsed;}

string ReRoll::getNameCard() const {
    return this->name;
}

void ReRoll::effect(Player &p,SetGame &s){
    p.removeFirstCard();
    p.removeFirstCard();
    p.addCardSpesPos(*s.getCards()[s.getSizeCards()-1],0);
    p.addCardSpesPos(*s.getCards()[s.getSizeCards()-2],1);

    cout << "Melakukan pembuangan kartu yang sedang dimiliki" << endl;
    cout << "Kamu mendapatkan 2 kartu baru yaitu:" << endl;
    cout << "1." << s.getCards()[s.getSizeCards()-1]->getNameCard() <<" "<< s.getCards()[s.getSizeCards()-1]->getNumberCard() << endl;
    cout << "2." << s.getCards()[s.getSizeCards()-2]->getNameCard() <<" "<< s.getCards()[s.getSizeCards()-2]->getNumberCard() << endl;

    s.removeBackCard();
    s.removeBackCard();



    int idxPlayer=0;

    for(int i=0;i<s.getPlayers().size();i++){
        if(*s.getPlayers()[i]==p) idxPlayer=i;
    }


    s.getPlayers()[idxPlayer]->getAbility()[0]->setIsCardUsed(true);


}

Quadruple::Quadruple(): Ability("Quadruple", false, false){
    this->name="Quadruple";
    this->isUsed= false;
    this->isDeath= false;
}

Quadruple::~Quadruple(){
    //dtor
}

void Quadruple::setIsCardDeath(bool d) {this->isDeath=d;}
void Quadruple::setIsCardUsed(bool u) { this->isUsed=u;}

bool Quadruple::getIsCardDeath() const {return this->isDeath;}
bool Quadruple::getIsCardUsed() const {return this->isUsed;}


string Quadruple::getNameCard() const {
    return this->name;
}

void Quadruple::effect(Player &p, SetGame &s){
    cout<<"Player P-"<<p.getTurn()<<" melakukan QUADRUPLE!"<<endl;
    cout<<"poin hadiah naik dari "<<s.getPointGame();
    s.setPoint(s.getPointGame()*4);
    cout<<"menjadi "<<s.getPointGame()<<endl;


    int idxPlayer=0;

    for(int i=0;i<s.getPlayers().size();i++){
        if(*s.getPlayers()[i]==p) idxPlayer=i;
    }


    s.getPlayers()[idxPlayer]->getAbility()[0]->setIsCardUsed(true);


}

Quarter::Quarter(): Ability("Quarter", false, false){
    this->name= "Quarter";
    this->isUsed= false;
    this->isDeath= false;
}

Quarter::~Quarter(){
    //dtor
}

void Quarter::setIsCardDeath(bool d) {this->isDeath=d;}
void Quarter::setIsCardUsed(bool u) { this->isUsed=u;}

bool Quarter::getIsCardDeath() const {return this->isDeath;}
bool Quarter::getIsCardUsed() const {return this->isUsed;}


string Quarter::getNameCard()const {
    return this->name;
}

void Quarter::effect(Player &player, SetGame &s){
    if(!(s.getPointGame()/4<1)) {
        cout << "Player P-" << player.getTurn() << " melakukan QUARTER!" << endl;
        cout << "poin hadiah turun dari " << s.getPointGame();
        s.setPoint(s.getPointGame() / 4);
        cout << "menjadi " << s.getPointGame() << endl;
    }

    int idxPlayer=0;

    for(int i=0;i<s.getPlayers().size();i++){
        if(s.getPlayers()[i]->getTurn()==player.getTurn()) idxPlayer=i;
    }

    s.getPlayers()[idxPlayer]->getAbility()[0]->setIsCardUsed(true);
}

ReverseDirection::ReverseDirection(): Ability("Reverse", false, false){
    this->name="Reverse";
    this->isUsed= false;
    this->isDeath= false;
}

ReverseDirection::~ReverseDirection(){
    //dtor
}

void ReverseDirection::setIsCardDeath(bool d) {this->isDeath=d;}
void ReverseDirection::setIsCardUsed(bool u) { this->isUsed=u;}

bool ReverseDirection::getIsCardDeath() const {return this->isDeath;}
bool ReverseDirection::getIsCardUsed() const {return this->isUsed;}

string ReverseDirection::getNameCard() const {
    return this->name;
}

void ReverseDirection::effect(Player &p,SetGame &s){
    // reversing player turn

    cout<<"Player-"<<p.getTurn()<<" melakukan reverse turn"<<endl;
    cout<<"urutan eksekusi giliran saat ini : ";
    for(int i=0;i<s.getPlayers().size();i++) {
        if(s.getPlayers()[i]->getTurn()!=p.getTurn()) {
            cout << "<p" << s.getPlayers()[i]->getTurn() << "> ";
        }
    }
    cout<<endl;

    s.reverseTurn();

    cout<<"urutan eksekusi giliran selanjutnya : ";
    for(int i=0;i<s.getPlayers().size();i++) {
        if(s.getPlayers()[i]->getTurn()!=p.getTurn()) {
            cout << "<p" << s.getPlayers()[i]->getTurn() << "> ";
        }
    }
    cout<<endl;


    int idxPlayer=0;

    for(int i=0;i<s.getPlayers().size();i++){
        if(s.getPlayers()[i]->getTurn()==p.getTurn()) idxPlayer=i;
    }


    s.getPlayers()[idxPlayer]->getAbility()[0]->setIsCardUsed(true);


}


SwapCard::SwapCard(): Ability("Swap", false, false){
    this->name="Swap";
    this->isUsed= false;
    this->isDeath= false;
}

SwapCard::~SwapCard(){
    // dtor
}

void SwapCard::setIsCardDeath(bool d) {this->isDeath=d;}
void SwapCard::setIsCardUsed(bool u) { this->isUsed=u;}

bool SwapCard::getIsCardDeath() const {return this->isDeath;}
bool SwapCard::getIsCardUsed() const {return this->isUsed;}

string SwapCard::getNameCard() const {
    return this->name;
}

void SwapCard::effect(Player &pHaveCard, Player &p1, Player &p2, int cardChoose1, int cardChoose2, SetGame &s){
    int idxP1=0;
    int idxP2=0;
    int idxPHave=0;


    for(int i=0;i<s.getPlayers().size();i++){
        if(s.getPlayers()[i]->getTurn()==pHaveCard.getTurn()) idxPHave=i;
        if(s.getPlayers()[i]->getTurn()==p1.getTurn()) idxP1=i;
        if(s.getPlayers()[i]->getTurn()==p2.getTurn()) idxP2=i;
    }



    Card *pHaveCard1=s.getPlayers()[idxPHave]->getCardsPlayer()[0];
    Card *pHaveCard2=s.getPlayers()[idxPHave]->getCardsPlayer()[1];
    Card *p1Card1=s.getPlayers()[idxP1]->getCardsPlayer()[cardChoose1];
    Card *p2Card1=s.getPlayers()[idxP2]->getCardsPlayer()[cardChoose2];

    s.getPlayers()[idxPHave]->removeFirstCard();
    s.getPlayers()[idxPHave]->removeFirstCard();


    s.getPlayers()[idxPHave]->addCardSpesPos(*p1Card1,0);
    s.getPlayers()[idxPHave]->addCardSpesPos(*p2Card1,1);

    s.getPlayers()[idxP1]->removeSpecificCard(*p1Card1);
    s.getPlayers()[idxP1]->addCardSpesPos(*pHaveCard1,cardChoose1);

    s.getPlayers()[idxP2]->removeSpecificCard(*p2Card1);
    s.getPlayers()[idxP2]->addCardSpesPos(*pHaveCard2,cardChoose2);


    s.getPlayers()[idxPHave]->getAbility()[0]->setIsCardUsed(true);

}

Switch::Switch(): Ability("Switch", false, false){
    this->name="Switch";
    this->isUsed= false;
    this->isDeath= false;
}

Switch::~Switch(){
    // dtor
}

void Switch::setIsCardDeath(bool d) {this->isDeath=d;}
void Switch::setIsCardUsed(bool u) { this->isUsed=u;}

bool Switch::getIsCardDeath() const {return this->isDeath;}
bool Switch::getIsCardUsed() const {return this->isUsed;}

string Switch::getNameCard() const {
    return this->name;
}

void Switch::effect(Player &p1, Player &Target, SetGame &s){
    int idxPlayer=0;

    for(int i=0;i<s.getPlayers().size();i++){
        if(s.getPlayers()[i]->getTurn()==p1.getTurn()){
            idxPlayer=i;
            s.getPlayers()[i]->removeFirstCard();
            s.getPlayers()[i]->removeFirstCard();
            s.getPlayers()[i]->addCardSpesPos(*Target.getCardsPlayer()[0],0);
            s.getPlayers()[i]->addCardSpesPos(*Target.getCardsPlayer()[1],1);
        }
        if(s.getPlayers()[i]->getTurn()==Target.getTurn()){
            s.getPlayers()[i]->removeFirstCard();
            s.getPlayers()[i]->removeFirstCard();
            s.getPlayers()[i]->addCardSpesPos(*p1.getCardsPlayer()[0],0);
            s.getPlayers()[i]->addCardSpesPos(*p1.getCardsPlayer()[1],1);
        }
    }

    cout<<"Kedua kartu pemain-"<<p1.getTurn()<<" telah ditukar dengan pemain-"<<Target.getTurn()<<endl;
    cout<<"Kartumu sekarang adalah "<<Target.getCardsPlayer()[0]->getNameCard()<<""<<Target.getCardsPlayer()[0]->getNumberCard()<<" "<<Target.getCardsPlayer()[1]->getNameCard()<<""<<Target.getCardsPlayer()[1]->getNumberCard()<<endl;

    s.getPlayers()[idxPlayer]->getAbility()[0]->setIsCardUsed(true);

}

Abilityless::Abilityless(): Ability("AbilityLess", false, false){
    this->name="AbilityLess";
    this->isUsed= false;
    this->isDeath= false;
}

Abilityless::~Abilityless(){
    // dtor
}

void Abilityless::setIsCardDeath(bool d) {this->isDeath=d;}
void Abilityless::setIsCardUsed(bool u) { this->isUsed=u;}

bool Abilityless::getIsCardDeath() const {return this->isDeath;}
bool Abilityless::getIsCardUsed() const {return this->isUsed;}

string Abilityless::getNameCard() const {
    return this->name;
}

void Abilityless::effect(SetGame &s, Player &abilityPlayer, Player &Target){

    int idxAbPlayer=0;
    int idxTarget=0;
    for(int i=0;i<s.getPlayers().size();i++){
        if(*s.getPlayers()[i]==abilityPlayer) idxAbPlayer=i;
        if(*s.getPlayers()[i]==Target) idxTarget=i;
    }

    s.getPlayers()[idxAbPlayer]->getAbility()[0]->setIsCardUsed(true);

    if(!(s.getPlayers()[idxTarget]->getAbility()[0]->getIsCardUsed())){
        s.getPlayers()[idxTarget]->getAbility()->setIsCardDeath(true);
    }if((s.getPlayers()[idxTarget]->getAbility()[0]->getIsCardUsed())){
        throw playerCardUsed();
    }

}
