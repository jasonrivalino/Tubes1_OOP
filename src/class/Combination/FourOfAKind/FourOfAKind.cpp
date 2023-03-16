#include "FourOfAKind.hpp"

FourOfAKind::FourOfAKind(Player&p, Table&t): Combination(){
    this->p = &p;
    this->t = &t;
}

FourOfAKind::~FourOfAKind(){
    delete p;
    delete t;
}

int FourOfAKind :: combFourOfAKind() {
    int ret;
    vector<int> forSort;
    vector<Card*> allCard;
 
    bool pcard = false;
 
    for (int i = 0; i < t->getCards().size(); i++) {
        allCard.push_back(t->getCards()[i]);
    }
    for (int i = 0; i < p->getCardsPlayer().size(); i++) {
        allCard.push_back(p->getCardsPlayer()[i]);
    }
    for (int i = 0; i < allCard.size(); i++) forSort.push_back(allCard[i]->getNumberCard());
    sort(forSort.begin(), forSort.end());
 
    int counter = 1;
    for (int i = allCard.size() - 1; i >= 1; i--) {
        if (forSort[i] == forSort[i - 1]) {
            counter++;
            if (counter == 4) {
                ret = forSort[i];
                for (int j=0; j < p->getCardsPlayer().size(); j++) {
                    if(p->getCardsPlayer()[j]->getNumberCard() == ret) return ret;
                }
                return -99;
            }
        } 
        else {
            counter = 1;
        }
    }
    return -99;
}