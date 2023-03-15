#include "HighCard.hpp"

HighCard :: HighCard(Player &p, Table &t): Combination() {
    this->p = &p;
    this->t = &t;
}

HighCard :: ~HighCard() {
    delete p;
    delete t;
}

vector<Card*> HighCard :: comb() {
    map <string, int> mp;
    mp["M"] = 4;
    mp["K"] = 3;
    mp["B"] = 2;
    mp["H"] = 1;

    vector<Card*> ret;
    if(player.getCardsPlayer()[0]->getNumberCard() > player.getCardsPlayer()[1]->getNumberCard()){
        ret.push_back(player.getCardsPlayer()[0]);
        return ret;
    }
    else if (player.getCardsPlayer()[0]->getNumberCard() < player.getCardsPlayer()[1]->getNumberCard()){
        ret.push_back(player.getCardsPlayer()[1]);
        return ret;
    }
    else{
        if(mp[player.getCardsPlayer()[0]->getNameCard()] > mp[player.getCardsPlayer()[1]->getNameCard()]){
            ret.push_back(player.getCardsPlayer()[0]);
            return ret;
        }
        else{
            ret.push_back(player.getCardsPlayer()[1]);
            return ret;
        }
    }
}