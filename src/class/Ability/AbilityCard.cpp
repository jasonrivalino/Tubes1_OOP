#include "AbilityCard.hpp"

#include <iostream>
using namespace std;

ReRoll::ReRoll() : Card("ReRoll",false){
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

void ReRoll::ReRollEffect(Player &p,SetGame &s){
    p.removeBackCard();
    p.removeBackCard();
    p.addCard(*s.getCards()[s.getSizeCards()-1]);
    p.addCard(*s.getCards()[s.getSizeCards()-2]);

    cout << "Melakukan pembuangan kartu yang sedang dimiliki" << endl;
    cout << "Kamu mendapatkan 2 kartu baru yaitu:" << endl;
    cout << "1." << s.getCards()[s.getSizeCards()-1]->getNameCard() <<" "<< s.getCards()[s.getSizeCards()-1]->getNumberCard() << endl;
    cout << "2." << s.getCards()[s.getSizeCards()-2]->getNameCard() <<" "<< s.getCards()[s.getSizeCards()-2]->getNumberCard() << endl;

    s.removeBackCard();
    s.removeBackCard();



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

Quadruple::Quadruple() : Card("Quadruple",false){
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

void Quadruple::QuadrupleEffect(Player &player, SetGame &s){
    cout<<"Player P-"<<player.getTurn()<<" melakukan QUADRUPLE!"<<endl;
    cout<<"poin hadiah naik dari "<<s.getPointGame();
    s.setPoint(s.getPointGame()*4);
    cout<<"menjadi "<<s.getPointGame()<<endl;


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

Quarter::Quarter() : Card("Quarter",false){
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

void Quarter::QuarterEffect(Player &player, SetGame &s){
    cout<<"Player P-"<<player.getTurn()<<" melakukan QUARTER!"<<endl;
    cout<<"poin hadiah turun dari "<<s.getPointGame();
    s.setPoint(s.getPointGame()/4);
    cout<<"menjadi "<<s.getPointGame()<<endl;

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

ReverseDirection::ReverseDirection() : Card("ReverseDirection",false){
}

ReverseDirection::~ReverseDirection(){
    //dtor
}

void ReverseDirection::setReverseDirection(bool adaCard){
    this ->setIsCardUsed(adaCard);
}

bool ReverseDirection::getReverseDirection(){
    return this -> getIsCardUsed();
}


void ReverseDirection::ReverseDirectionEffect(SetGame &PlayerTurn){
    // reversing player turn
    reverse(PlayerTurn.getPlayers().begin(), PlayerTurn.getPlayers().end());
}


SwapCard::SwapCard() : Card("swap_card", false){
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

void SwapCard::SwapCardEffect(Player &pHaveCard,Player &p1,Player &p2,int cardChoose1,int cardChoose2,SetGame &s){
    int idxP1=0;
    int idxP2=0;
    int idxPHave=0;

    for(int i=0;i<s.getPlayers().size();i++){
        if(s.getPlayers()[i]->getTurn()==pHaveCard.getTurn()) idxPHave=i;
        if(s.getPlayers()[i]->getTurn()==p1.getTurn()) idxP1=i;
        if(s.getPlayers()[i]->getTurn()==p2.getTurn()) idxP2=i;
    }

    Card *pHaveCard1=s.getPlayers()[idxPHave]->getCardsPlayer()[cardChoose1];
    Card *pHaveCard2=s.getPlayers()[idxPHave]->getCardsPlayer()[cardChoose2];
    Card *p1Card1=s.getPlayers()[idxP1]->getCardsPlayer()[cardChoose1];
    Card *p2Card1=s.getPlayers()[idxP2]->getCardsPlayer()[cardChoose2];

    s.getPlayers()[idxPHave]->getCardsPlayer().erase(s.getPlayers()[idxPHave]->getCardsPlayer().begin()+cardChoose1);
    s.getPlayers()[idxPHave]->getCardsPlayer().erase(s.getPlayers()[idxPHave]->getCardsPlayer().begin()+cardChoose2);
    s.getPlayers()[idxPHave]->getCardsPlayer().push_back(p1Card1);
    s.getPlayers()[idxPHave]->getCardsPlayer().push_back(p2Card1);

    s.getPlayers()[idxP1]->getCardsPlayer().erase(s.getPlayers()[idxP1]->getCardsPlayer().begin()+cardChoose1);
    s.getPlayers()[idxP1]->getCardsPlayer().push_back(pHaveCard1);

    s.getPlayers()[idxP2]->getCardsPlayer().erase(s.getPlayers()[idxP2]->getCardsPlayer().begin()+cardChoose2);
    s.getPlayers()[idxP2]->getCardsPlayer().push_back(pHaveCard2);


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

Switch::Switch() : Card("switch",false){
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

void Switch::SwitchEffect(Player &p1, Player &Target, SetGame &s){
    int idxPlayer=0;

    for(int i=0;i<s.getPlayers().size();i++){
        if(s.getPlayers()[i]->getTurn()==p1.getTurn()){
            idxPlayer=i;
            s.getPlayers()[i]->getCardsPlayer().pop_back();
            s.getPlayers()[i]->getCardsPlayer().pop_back();
            s.getPlayers()[i]->addCard(*Target.getCardsPlayer()[0]);
            s.getPlayers()[i]->addCard(*Target.getCardsPlayer()[1]);
        }
        if(s.getPlayers()[i]->getTurn()==Target.getTurn()){
            s.getPlayers()[i]->getCardsPlayer().pop_back();
            s.getPlayers()[i]->getCardsPlayer().pop_back();
            s.getPlayers()[i]->addCard(*p1.getCardsPlayer()[0]);
            s.getPlayers()[i]->addCard(*p1.getCardsPlayer()[1]);
        }
    }

    cout<<"Kedua kartu pemain-"<<p1.getTurn()<<" telah ditukar dengan pemain-"<<Target.getTurn()<<endl;
    cout<<"Kartumu sekarang adalah"<<Target.getCardsPlayer()[0]->getNameCard()<<""<<Target.getCardsPlayer()[0]->getNumberCard()<<" "<<Target.getCardsPlayer()[1]->getNameCard()<<""<<Target.getCardsPlayer()[1]->getNumberCard()<<endl;


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

Abilityless::Abilityless() : Card("abilityless", false){
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

// void Abilityless::AbilitylessEffect(Player &abilityPlayer, vector<Player*> p){
//     int idxIsNoUsedAbility;
//     vector<int> collect;
//     vector<Card> nameCardRegular = {*new ReRoll,*new Switch,*new SwapCard,*new ReverseDirection,*new Quarter,*new Quadruple};

//    for(int i=0;i<p.size();i++){
//        if(p[i].getTurn()!=abilityPlayer.getTurn()){
//            for(Card name:nameCardRegular){
//                auto it = find_if(p[i].getCardsPlayer().begin(),p[i].getCardsPlayer().end(),[=](const Card &obj){
//                    return obj.getNameCard()==name;
//                });
//            }
//        }
//    }
// }

void Abilityless::AbilitylessEffect(SetGame &s, Player &abilityPlayer, Player &Target){
//    bool isAllAbilityUsed = true;
//
//    for(int i=0; i<s.getPlayers().size(); i++){
//        for(int j=0;j<s.getPlayers()[i]->getSizeCardsPlayer();j++){
//            if(s.getPlayers()[i]->getTurn()!=abilityPlayer.getTurn()) {
//                bool itIs =
//                        s.getPlayers()[i]->getCardsPlayer()[j]->getNameCard() != "K" &&
//                        s.getPlayers()[i]->getCardsPlayer()[j]->getNameCard() != "M" &&
//                        s.getPlayers()[i]->getCardsPlayer()[j]->getNameCard() != "B" &&
//                        s.getPlayers()[i]->getCardsPlayer()[j]->getNameCard() != "H";
//                if (itIs) {
//                    if (s.getPlayers()[i]->getCardsPlayer()[j]->getIsCardUsed()) {
//                        isAllAbilityUsed = false;
//                        break;
//                    }
//                }
//            }
//        }
//    }
//
//    if(isAllAbilityUsed){
//        cout << "Yah, kamu menjadi abilityless. Yah, penggunaan kartu ini sia-sia 😞 " << endl;
//    }
//
//    else{
//        cout << "Silahkan pilih pemain yang kartu abilitynya ingin dimatikan:" << endl;
//        for(int i=0; i<s.getPlayers().size();i++){
//            cout << i+1 << ". Pemain " << s.getPlayers()[i]->getTurn()  << endl;
//        }
//        cout<<">>";
//        int choose;
//        cin >> choose;
//        while (choose < 1 || choose > s.getPlayers().size()){
//            cout << "Pilihan tidak valid silakan pilih kembali" << endl;
//            cout<<">>";
//            cin>>choose;
//        }
//
//        for(int i=0;s.getPlayers()[choose-1])
//
//        if(s.getPlayers()[choose-1]->getCardsPlayer()[2]->getIsCardUsed()==true){
//            cout << "Kartu ability " << s.getPlayers()[choose-1]->getTurn() << " telah dipakai sebelumnya. Yah, sayang penggunaan kartu ini sia-sia 🙁" << endl;
//        }
//
//        else{
//            s.getPlayers()[choose-1]->getCardsPlayer()[2]->setIsCardUsed(true);
//            cout << "Kartu ability " << s.getPlayers()[choose-1]->getTurn() << " telah dimatikan." << endl;
//        }
//    }

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
        if(abilityP2){
            s.getPlayers()[idxTarget]->getCardsPlayer()[i]->setIsCardUsed(true);
        }
    }



    setAbilityless(true);
}
