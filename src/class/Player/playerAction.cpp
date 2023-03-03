#include "playerAction.hpp"

using namespace std;

void playerAction::halfCard(Player &player, SetGame pointGame, string action){
    if (action == "HALF"){
        this->currentPoint = pointGame.getPointGame()/2;
    cout << &player << "melakukan HALF!" << "Poin hadiah turun dari " << currentPoint << " menjadi " << this->currentPoint << endl;
    }
}

void playerAction::doubleCard(Player &player, SetGame pointGame, string action){
    if (action == "DOUBLE"){
        this->currentPoint = pointGame.getPointGame()*2;
        cout << &player << "melakukan DOUBLE!" << "Poin hadiah naik dari " << currentPoint << " menjadi " << this->currentPoint << endl;
    }
}

void playerAction::nextCard(Player &player, SetGame pointGame, string action){
    if (action == "NEXT"){
        this->currentPoint = pointGame.getPointGame();
        cout << "Giliran dilanjut ke pemain berikutnya" << endl;
    }
}
