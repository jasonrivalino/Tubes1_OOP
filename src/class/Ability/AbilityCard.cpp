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
    s.removeBackCard();
    s.removeBackCard();
    setReRoll(true);
}

Quadruple::Quadruple() : Card("Quadruple",false){
}

Quadruple::~Quadruple(){
    //dtor
}

void Quadruple::setQuadruple(bool adaCard){
    this ->setIsCardUsed(adaCard);
}

bool Quadruple::getQuadruple(){
    return getIsCardUsed();
}

void Quadruple::QuadrupleEffect(){
    // Masukin efeknya
}

Quarter::Quarter() : Card("Quarter",false){
}

Quarter::~Quarter(){
    //dtor
}

void Quarter::setQuarter(bool adaCard){
    this ->setIsCardUsed(adaCard);
}

bool Quarter::getQuarter(){
    return this -> getIsCardUsed();
}

void Quarter::QuarterEffect(){
    // Masukin efeknya
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

void ReverseDirection::ReverseDirectionEffect(){
    // Masukin efeknya
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

void SwapCard::SwapCardEffect(Player &p1,Player &p2){
    int rand2 = ::rand()%p2.getSizeCardsPlayer();
    Card c1 = p1.getCardsPlayer()[p1.getSizeCardsPlayer()-1];
    Card c2 = p2.getCardsPlayer()[rand2];
    p1.removeBackCard();
    p2.removeBackCard();
    p1.addCard(c2);
    p2.addCard(c1);
    setSwapCard(true);
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

void Switch::SwitchEffect(Player &p1, Player &p2){
    Card c1_p1 = p1.getCardsPlayer()[p1.getSizeCardsPlayer()-1];
    Card c2_p1 = p1.getCardsPlayer()[p1.getSizeCardsPlayer()-2];
    Card c1_p2 = p2.getCardsPlayer()[p2.getSizeCardsPlayer()-1];
    Card c2_p2 = p2.getCardsPlayer()[p2.getSizeCardsPlayer()-2];

    p1.removeBackCard();
    p1.removeBackCard();
    p2.removeBackCard();
    p2.removeBackCard();

    p1.addCard(c1_p2);
    p1.addCard(c2_p2);
    p2.addCard(c1_p1);
    p2.addCard(c2_p1);
    setSwitch(true);
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

void Abilityless::AbilitylessEffect(SetGame &s, Player &abilityPlayer){
    bool isAllAbilityUsed = true;

    for(int i=0; i<s.getPlayers().size(); i++){
        if(s.getPlayers()[i]->getCardsPlayer()[2].getIsCardUsed()==false){
            isAllAbilityUsed = false;
        }      
    }

    if(isAllAbilityUsed){
        cout << "Yah, kamu menjadi abilityless. Yah, penggunaan kartu ini sia-sia 😞 " << endl;
    }

    else{
        cout << "Silahkan pilih pemain yang kartu abilitynya ingin dimatikan:" << endl;
        for(int i=0; i<s.getPlayers().size();i++){
            cout << i+1 << ". Pemain " << s.getPlayers()[i]->getTurn()  << endl;
        }

        int choose;
        cin >> choose;
        if(choose < 1 || choose > s.getPlayers().size()){
            cout << "Pilihan tidak valid" << endl;
        }

        else{
            if(s.getPlayers()[choose-1]->getCardsPlayer()[2].getIsCardUsed()==true){
                cout << "Kartu ability " << s.getPlayers()[choose-1]->getTurn() << " telah dipakai sebelumnya. Yah, sayang penggunaan kartu ini sia-sia 🙁" << endl;
            }

            else{
                s.getPlayers()[choose-1]->getCardsPlayer()[2].setIsCardUsed(true);
                cout << "Kartu ability " << s.getPlayers()[choose-1]->getTurn() << " telah dimatikan." << endl;
            }
        }
    }


    // jika tidak ada pemain yang bisa dimatikan ability-nya
    // if (collect.size() == 0) {
    //     abilityPlayer.setAbilityLess(true);
    //     cout << "Yah, kamu menjadi abilityless. Yah, penggunaan kartu ini sia-sia 😞" << endl;
    // }
    // else {
    //     cout << "Silahkan pilih pemain yang kartu abilitynya ingin dimatikan:" << endl;
    //     for (int i = 0; i < collect.size(); i++) {
    //         cout << i+1 << ". " << p[collect[i]]-><< endl;
    //     }
    //     // meminta input pemain yang dipilih
    //     int choose;
    //     cin >> choose;
    //     if (choose < 1 || choose > collect.size()) {
    //         cout << "Pilihan tidak valid" << endl;
    //         return;
    //     }
    //     else {
    //         idxIsNoUsedAbility = collect[choose-1];
    //         // jika pemain yang dipilih sudah mati ability-nya
    //         if (p[idxIsNoUsedAbility]->getIsAbilityUsed() == true) {
    //             cout << "Kartu ability " << p[idxIsNoUsedAbility]->getNamePlayer() << " telah dipakai sebelumnya. Yah, sayang penggunaan kartu ini sia-sia 🙁" << endl;
    //         }
    //         // mematikan ability pemain yang dipilih
    //         else {
    //             p[idxIsNoUsedAbility]->setIsAbilityUsed(true);
    //             cout << "Kartu ability " << p[idxIsNoUsedAbility]->getNamePlayer() << " telah dimatikan." << endl;
    //         }
    //     }
    // }
}
