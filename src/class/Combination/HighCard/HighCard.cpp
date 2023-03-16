#include "HighCard.hpp"

HighCard :: HighCard(Player &p, Table &t): Combination() {
    this->p = &p;
    this->t = &t;
}

HighCard :: ~HighCard() {
    delete p;
    delete t;
}

vector<Card*> HighCard :: combHighCard() {
    map <string, int> mp;
    mp["M"] = 4;
    mp["K"] = 3;
    mp["B"] = 2;
    mp["H"] = 1;

    vector<Card*> ret;
    if(p->getCardsPlayer()[0]->getNumberCard() > p->getCardsPlayer()[1]->getNumberCard()){
        ret.push_back(p->getCardsPlayer()[0]);
        return ret;
    }
    else if (p->getCardsPlayer()[0]->getNumberCard() < p->getCardsPlayer()[1]->getNumberCard()){
        ret.push_back(p->getCardsPlayer()[1]);
        return ret;
    }
    else{
        if(mp[p->getCardsPlayer()[0]->getNameCard()] > mp[p->getCardsPlayer()[1]->getNameCard()]){
            ret.push_back(p->getCardsPlayer()[0]);
            return ret;
        }
        else{
            ret.push_back(p->getCardsPlayer()[1]);
            return ret;
        }
    }
}