#include "AbilityCard.hpp"

#include <iostream>
using namespace std;

ReRoll::ReRoll() : Card("ReRoll",false){
    this->name= "ReRoll";
}

ReRoll::~ReRoll(){
    //dtor
}

void ReRoll::setReRoll(bool adaCard){
    this ->setIsCardUsed(adaCard);
}

bool ReRoll::getReRoll(){
    return this -> getIsCardUsed();
}
string ReRoll::getNameCard() const {
    return this->name;
}

void ReRoll::ReRollEffect(Player &p,SetGame &s){
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


    for(int i=0;i<s.getPlayers()[idxPlayer]->getCardsPlayer().size();i++){
        bool abilityP1 =
                s.getPlayers()[idxPlayer]->getCardsPlayer()[i]->getNameCard()!="M"&&
                s.getPlayers()[idxPlayer]->getCardsPlayer()[i]->getNameCard()!="B"&&
                s.getPlayers()[idxPlayer]->getCardsPlayer()[i]->getNameCard()!="K"&&
                s.getPlayers()[idxPlayer]->getCardsPlayer()[i]->getNameCard()!="H";

        if(abilityP1){
            s.getPlayers()[idxPlayer]->getCardsPlayer()[i]->setIsCardUsed(true);
        }
    }
}

Quadruple::Quadruple() : Card("Quadruple",false){
    this->name="Quadruple";
}

Quadruple::~Quadruple(){
    //dtor
}

void Quadruple::setQuadruple(bool isUsed){
    this ->setIsCardUsed(isUsed);
}

bool Quadruple::getQuadruple(){
    return getIsCardUsed();
}

string Quadruple::getNameCard() const {
    return this->name;
}

void Quadruple::QuadrupleEffect(Player &p, SetGame &s){
    cout<<"Player P-"<<p.getTurn()<<" melakukan QUADRUPLE!"<<endl;
    cout<<"poin hadiah naik dari "<<s.getPointGame();
    s.setPoint(s.getPointGame()*4);
    cout<<"menjadi "<<s.getPointGame()<<endl;


    int idxPlayer=0;

    for(int i=0;i<s.getPlayers().size();i++){
        if(*s.getPlayers()[i]==p) idxPlayer=i;
    }


    for(int i=0;i<s.getPlayers()[idxPlayer]->getCardsPlayer().size();i++){
        bool abilityP1 =
                s.getPlayers()[idxPlayer]->getCardsPlayer()[i]->getNameCard()!="M"&&
                s.getPlayers()[idxPlayer]->getCardsPlayer()[i]->getNameCard()!="B"&&
                s.getPlayers()[idxPlayer]->getCardsPlayer()[i]->getNameCard()!="K"&&
                s.getPlayers()[idxPlayer]->getCardsPlayer()[i]->getNameCard()!="H";

        if(abilityP1){
            s.getPlayers()[idxPlayer]->getCardsPlayer()[i]->setIsCardUsed(true);
        }
    }
}

Quarter::Quarter() : Card("Quarter",false){
    this->name= "Quarter";
}

Quarter::~Quarter(){
    //dtor
}

void Quarter::setQuarter(bool isUsed){
    this ->setIsCardUsed(isUsed);
}

bool Quarter::getQuarter(){
    return this -> getIsCardUsed();
}
string Quarter::getNameCard()const {
    return this->name;
}

void Quarter::QuarterEffect(Player &player, SetGame &s){
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


    for(int i=0;i<s.getPlayers()[idxPlayer]->getCardsPlayer().size();i++){
        bool abilityP1 =
                s.getPlayers()[idxPlayer]->getCardsPlayer()[i]->getNameCard()!="M"&&
                s.getPlayers()[idxPlayer]->getCardsPlayer()[i]->getNameCard()!="B"&&
                s.getPlayers()[idxPlayer]->getCardsPlayer()[i]->getNameCard()!="K"&&
                s.getPlayers()[idxPlayer]->getCardsPlayer()[i]->getNameCard()!="H";

        if(abilityP1){
            s.getPlayers()[idxPlayer]->getCardsPlayer()[i]->setIsCardUsed(true);
        }
    }
}

ReverseDirection::ReverseDirection() : Card("Reverse",false){
    this->name="Reverse";
}

ReverseDirection::~ReverseDirection(){
    //dtor
}

void ReverseDirection::setReverseDirection(bool isUsed){
    this ->setIsCardUsed(isUsed);
}

bool ReverseDirection::getReverseDirection(){
    return this -> getIsCardUsed();
}

string ReverseDirection::getNameCard() const {
    return this->name;
}

void ReverseDirection::ReverseDirectionEffect(Player &p,SetGame &s){
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

    for(int i=0;i<s.getPlayers()[idxPlayer]->getCardsPlayer().size();i++){
        bool abilityP1 =
                s.getPlayers()[idxPlayer]->getCardsPlayer()[i]->getNameCard()!="M"&&
                s.getPlayers()[idxPlayer]->getCardsPlayer()[i]->getNameCard()!="B"&&
                s.getPlayers()[idxPlayer]->getCardsPlayer()[i]->getNameCard()!="K"&&
                s.getPlayers()[idxPlayer]->getCardsPlayer()[i]->getNameCard()!="H";

        if(abilityP1){
            s.getPlayers()[idxPlayer]->getCardsPlayer()[i]->setIsCardUsed(true);
        }
    }
}


SwapCard::SwapCard() : Card("Swap", false){
    this->name="Swap";
}

SwapCard::~SwapCard(){
    // dtor
}

void SwapCard::setSwapCard(bool adaCard){
    setIsCardUsed(adaCard);
}

bool SwapCard::getSwapCard(){
    return this -> getIsCardUsed();
}

string SwapCard::getNameCard() const {
    return this->name;
}

void SwapCard::SwapCardEffect(Player &pHaveCard, Player &p1, Player &p2, int cardChoose1, int cardChoose2, SetGame &s){
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


    for(int i=0;i<s.getPlayers()[idxPHave]->getCardsPlayer().size();i++){
        bool abilityP1 =
                s.getPlayers()[idxPHave]->getCardsPlayer()[i]->getNameCard()!="M"&&
                s.getPlayers()[idxPHave]->getCardsPlayer()[i]->getNameCard()!="B"&&
                s.getPlayers()[idxPHave]->getCardsPlayer()[i]->getNameCard()!="K"&&
                s.getPlayers()[idxPHave]->getCardsPlayer()[i]->getNameCard()!="H";

        if(abilityP1){
            s.getPlayers()[idxPHave]->getCardsPlayer()[i]->setIsCardUsed(true);
        }
    }
}

Switch::Switch() : Card("Switch",false){
    this->name="Switch";
}

Switch::~Switch(){
    // dtor
}

void Switch::setSwitch(bool adaCard){
    setIsCardUsed(adaCard);
}

bool Switch::getSwitch(){
    return this -> getIsCardUsed();
}

string Switch::getNameCard() const {
    return this->name;
}

void Switch::SwitchEffect(Player &p1, Player &Target, SetGame &s){
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


    for(int i=0;i<s.getPlayers()[idxPlayer]->getCardsPlayer().size();i++){
        bool abilityP1 =
                s.getPlayers()[idxPlayer]->getCardsPlayer()[i]->getNameCard()!="M"&&
                s.getPlayers()[idxPlayer]->getCardsPlayer()[i]->getNameCard()!="B"&&
                s.getPlayers()[idxPlayer]->getCardsPlayer()[i]->getNameCard()!="K"&&
                s.getPlayers()[idxPlayer]->getCardsPlayer()[i]->getNameCard()!="H";

        if(abilityP1){
            s.getPlayers()[idxPlayer]->getCardsPlayer()[i]->setIsCardUsed(true);
        }
    }
}

Abilityless::Abilityless() : Card("AbilityLess", false){
    this->name="AbilityLess";
}

Abilityless::~Abilityless(){
    // dtor
}

void Abilityless::setAbilityless(bool adaCard){
    this ->setIsCardUsed(adaCard);
}

bool Abilityless::getAbilityless(){
    return this -> getIsCardUsed();
}

string Abilityless::getNameCard() const {
    return this->name;
}

void Abilityless::AbilitylessEffect(SetGame &s, Player &abilityPlayer, Player &Target){


    int idxAbPlayer=0;
    int idxTarget=0;
    for(int i=0;i<s.getPlayers().size();i++){
        if(s.getPlayers()[i]->getTurn()==abilityPlayer.getTurn()){
            idxAbPlayer=i;
        }
        if(s.getPlayers()[i]->getTurn()==Target.getTurn()){
            idxTarget=i;
        }
    }

    for(int i=0;i<s.getPlayers()[idxAbPlayer]->getSizeCardsPlayer();i++){
        bool abilityP1 =
                s.getPlayers()[idxAbPlayer]->getCardsPlayer()[i]->getNameCard()!="M"&&
                s.getPlayers()[idxAbPlayer]->getCardsPlayer()[i]->getNameCard()!="B"&&
                s.getPlayers()[idxAbPlayer]->getCardsPlayer()[i]->getNameCard()!="K"&&
                s.getPlayers()[idxAbPlayer]->getCardsPlayer()[i]->getNameCard()!="H";
        bool abilityP2 =
                s.getPlayers()[idxTarget]->getCardsPlayer()[i]->getNameCard()!="M"&&
                s.getPlayers()[idxTarget]->getCardsPlayer()[i]->getNameCard()!="B"&&
                s.getPlayers()[idxTarget]->getCardsPlayer()[i]->getNameCard()!="K"&&
                s.getPlayers()[idxTarget]->getCardsPlayer()[i]->getNameCard()!="H";

        if(abilityP1){
            s.getPlayers()[idxAbPlayer]->getCardsPlayer()[i]->setIsCardUsed(true);
        }
        if(abilityP2&&!(s.getPlayers()[idxTarget]->getCardsPlayer()[i]->getIsCardUsed())){
            s.getPlayers()[idxTarget]->getCardsPlayer()[i]->setIsCardDeath(true);
        }if(abilityP2&&(s.getPlayers()[idxTarget]->getCardsPlayer()[i]->getIsCardUsed())){
            throw playerCardUsed();
        }

    }

}
