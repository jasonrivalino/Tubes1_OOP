#include "PlayerAction.hpp"

using namespace std;

PlayerAction::PlayerAction() {}
PlayerAction::~PlayerAction() {}

void PlayerAction::halfCard(Player &player, SetGame &pointGame){
    long pointBeforeAction = pointGame.getPointGame();
    if (pointBeforeAction != 1) {
    pointGame.setPoint(pointGame.getPointGame()/2);
    cout << &player << "melakukan HALF!" << "Poin hadiah turun dari " << pointBeforeAction << " menjadi " << pointGame.getPointGame() << endl;
    
    }
}

void PlayerAction::doubleCard(Player &player, SetGame &pointGame){
    long pointBeforeAction = pointGame.getPointGame();
    pointGame.setPoint(pointGame.getPointGame()*2);
    cout << &player << "melakukan DOUBLE!" << "Poin hadiah naik dari " << pointBeforeAction << " menjadi " << pointGame.getPointGame() << endl;
}

void PlayerAction::nextCard(){
    cout << "Giliran dilanjut ke pemain berikutnya" << endl;
}

void PlayerAction::reRoll(Player &p,SetGame &s){
    if (p.getCardsPlayer()[2].getNameCard() != "REROLL" || p.getCardsPlayer()[2].getIsCardUsed()){
        cout << "Ets, tidak bisa. Kamu tidak punya kartu Ability REROLL." << endl;
    }
    else{
        cout << "Melakukan pembuangan kartu yang sedang dimiliki" << endl;
        cout << "Kamu mendapatkan 2 kartu baru yaitu:" << endl;
        ReRoll reRollCard;
        reRollCard.ReRollEffect(p,s);
    }
}

void PlayerAction::quadrupleCard(Player &player, SetGame &pointGame){
    // Kondisi jika pemain tidak punya kartu quadruple
    if (player.getCardsPlayer()[2].getNameCard() != "QUADRUPLE" || player.getCardsPlayer()[2].getIsCardUsed()){
        cout << "Ets, tidak bisa. Kamu tidak punya kartu Ability QUADRUPLE." << endl;
    }
    // Kondisi jika pemain punya kartu quadruple
    else{    
        Quadruple quadrupleCard;
        long pointBeforeAction = pointGame.getPointGame();
        pointGame.setPoint(pointGame.getPointGame()*quadrupleCard.getQuadruple());
        cout << &player << "melakukan QUADRUPLE!" << "Poin hadiah naik dari " << pointBeforeAction << " menjadi " << pointGame.getPointGame() << endl;
    }
}

void PlayerAction::quarterCard(Player &player, SetGame &pointGame){
    // Kondisi jika pemain tidak punya kartu quarter
    if (player.getCardsPlayer()[2].getNameCard() != "QUARTER" || player.getCardsPlayer()[2].getIsCardUsed()){
        cout << "Ets, tidak bisa. Kamu tidak punya kartu Ability QUARTER." << endl;
    }
    else{
        Quarter quarterCard;
        long pointBeforeAction = pointGame.getPointGame();
        pointGame.setPoint(pointGame.getPointGame()/quarterCard.getQuarter());
        cout << &player << "melakukan QUARTER!" << "Poin hadiah turun dari " << pointBeforeAction << " menjadi " << pointGame.getPointGame() << endl;
    }
}

