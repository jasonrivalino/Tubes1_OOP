#include "Flush.hpp"

Flush :: Flush (Player &p, Table &t) : Combination() {
    this->p = &p;
    this->t = &t;
}

Flush :: ~Flush() {
    delete p;
    delete t;
}

vector<Card*> Flush :: combFlush() {
    vector<Card*> ret;
    vector<int> forSort;
    vector<Card*> allCard;
    
    for(int i=0; i < allCard.size(); i++) forSort.push_back(allCard[i]->getNumberCard());
    sort(forSort.begin(), forSort.end());

    bool pcard = false;
    string color;

    for (int i=0; i < p->getCardsPlayer().size(); i++){
        allCard.push_back(p->getCardsPlayer()[i]);
        for(int j=0; j < t->getCards().size(); j++){
            if(p->getCardsPlayer()[i]->getNameCard() == t->getCards()[j]->getNameCard()){
                allCard.push_back(t->getCards()[j]);
            }
        }
        if(allCard.size() < 5) continue;
        else if (allCard.size() == 5) return allCard;
        else{
            for(int j=0; j < allCard.size(); j++) forSort.push_back(allCard[j]->getNumberCard());
            sort(forSort.begin(), forSort.end());

            for(int j = allCard.size() - 1; j >= allCard.size() - 5; j--){
                for(int k = 0; k < allCard.size(); k++){
                    if(forSort[j] == allCard[k]->getNumberCard()){
                        ret.push_back(allCard[k]);
                        if(allCard[k] == p->getCardsPlayer()[i]) pcard = true;
                    }
                }
            }
            if(pcard) return ret;
            else{
                ret.pop_back();
                for(int j = 0; j < allCard.size(); j++) {
                    if(allCard[j]->getNumberCard() == forSort[i]){
                        ret.push_back(allCard[j]);
                    }
                }
                return ret;
            }
        }
    }
    ret.clear();
    return ret;
}