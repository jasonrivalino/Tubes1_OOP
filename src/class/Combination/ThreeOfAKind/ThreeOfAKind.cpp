#include "ThreeOfAKind.hpp"

ThreeOfAKind::ThreeOfAKind(Player &p, Table &t): Combination(){
    this->p = &p;
    this->t = &t;
}

ThreeOfAKind::~ThreeOfAKind(){
    delete p;
    delete t;
}

vector<Card*> ThreeOfAKind::comb(){
    vector<Card*> allCard;
    vector<Card*> ret;
    vector<int> forSort;
    bool pcard = false;
 
    for (int i = 0; i < tableCard.getCards().size(); i++) {
        allCard.push_back(tableCard.getCards()[i]);
    }
    for (int i = 0; i < player.getCardsPlayer().size(); i++) {
        allCard.push_back(player.getCardsPlayer()[i]);
    }
 
    for (int i = 0; i < allCard.size(); i ++) forSort.push_back(allCard[i]->getNumberCard());
    sort(forSort.begin(), forSort.end());
 
    int counter = 1;
    for (int i=0; i < allCard.size() - 1; i++) {
        if (forSort[i] == forSort[i + 1]) {
            counter ++ ;
            if (counter == 3) {
                for(int j = 0; j < player.getCardsPlayer().size(); j++) {
                    if(player.getCardsPlayer()[j]->getNumberCard() == forSort[i]){
                        if(ret.size() == 0){
                            ret.push_back(player.getCardsPlayer()[j]);
                        }
                        else{
                            if(ret[0]->getNameCard() == "K"){
                                if(player.getCardsPlayer()[j]->getNameCard() == "M"){
                                    ret.clear();
                                    ret.push_back(player.getCardsPlayer()[j]);
                                }
                            }
                            else if(ret[0]->getNameCard() == "B"){
                                if(player.getCardsPlayer()[j]->getNameCard() == "M" or player.getCardsPlayer()[j]->getNameCard() == "K"){
                                    ret.clear();
                                    ret.push_back(player.getCardsPlayer()[j]);
                                }
                            }
                            else if(ret[0]->getNameCard() == "H"){
                                if(player.getCardsPlayer()[j]->getNameCard() == "M" or player.getCardsPlayer()[j]->getNameCard() == "K" or player.getCardsPlayer()[j]->getNameCard() == "B"){
                                    ret.clear();
                                    ret.push_back(player.getCardsPlayer()[j]);
                                }
                            }
                        }
                    }
                }
                return ret;
            }
        }
        else counter = 1;
    }
    ret.clear();
    return ret;
}