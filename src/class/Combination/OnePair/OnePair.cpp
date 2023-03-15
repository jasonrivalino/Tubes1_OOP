#include "OnePair.hpp"

OnePair :: OnePair(Player &p, Table &t) {
    this->p = &p;
    this->t = &t;
}

OnePair :: ~OnePair() {
    delete p;
    delete t;
}

vector<Card*> OnePair :: combOnePair() {
    vector<Card*> ret;
    vector<int> forSort;
    vector<int> intPair;
    vector<Card*> allCard;

    int countpair = 0;
 
    for (int i = 0; i < t->getCards().size(); i++) {
        allCard.push_back(t->getCards()[i]);
    }
    for (int i = 0; i < p->getCardsPlayer().size(); i++) {
        allCard.push_back(p->getCardsPlayer()[i]);
    }
    for (int i = 0; i < allCard.size(); i++) forSort.push_back(allCard[i]->getNumberCard());
    sort(forSort.begin(), forSort.end());
 
    for (int i = allCard.size()-1; i >= 1; i--){
        if(countpair == 3){
            break;
        }
        else{
            if(forSort[i] == forSort[i-1]){
                if(countpair == 0){
                    countpair++;
                    intPair.push_back(forSort[i]);
                }
                else{
                    if(intPair[countpair - 1] != forSort[i]){
                        countpair++;
                        intPair.push_back(forSort[i]);
                    }
                }
            }
        }
    }
    if(countpair < 1) return ret;
    else{
        int idxplayercard;
        bool cek = false;
        for(int i = 0 ; i < p->getCardsPlayer().size(); i++){
            for(int j = intPair.size() - 1 ; j >= 0; j--){
                if(p->getCardsPlayer()[i]->getNumberCard() == intPair[j]){
                    idxplayercard = j;
                    cek = true;
                }
            }
            if(cek) break;
        }
 
        if(!cek) return ret;
        else{
            vector<Card*> pair1;
            for(int i = 0; i < allCard.size(); i++){
                if(allCard[i]->getNumberCard() == intPair[idxplayercard]){
                    pair1.push_back(allCard[i]);
                }
            }
            intPair.erase(intPair.begin() + idxplayercard);
 
            if(pair1.size() == 3){
                vector <int> nonpcard;
                for(int i = 0; i < pair1.size(); i++){
                    if(pair1[i] != p->getCardsPlayer()[0] and pair1[i] != p->getCardsPlayer()[1]){
                        nonpcard.push_back(i);
                    }
                }
                if(pair1[nonpcard[0]]->getNameCard() == "H"){
                    pair1.erase(pair1.begin() + nonpcard[0]);
                }
                else if(pair1[nonpcard[0]]->getNameCard() == "B"){
                    if(pair1[nonpcard[1]]->getNameCard() == "H"){
                        pair1.erase(pair1.begin() + nonpcard[1]);
                    }
                    else{
                        pair1.erase(pair1.begin() +nonpcard[0]);
                    }
                }
                else if(pair1[nonpcard[0]]->getNameCard() == "K"){
                    if(pair1[nonpcard[1]]->getNameCard() == "H" or pair1[nonpcard[1]]->getNameCard() == "B"){
                        pair1.erase(pair1.begin() + nonpcard[1]);
                    }
                    else{
                        pair1.erase(pair1.begin() +nonpcard[0]);
                    }
                }
                else if(pair1[nonpcard[0]]->getNameCard() == "M"){
                    if(pair1[nonpcard[1]]->getNameCard() == "H" or pair1[nonpcard[1]]->getNameCard() == "B" or pair1[nonpcard[1]]->getNameCard() == "K"){
                        pair1.erase(pair1.begin() + nonpcard[1]);
                    }
                    else{
                        pair1.erase(pair1.begin() +nonpcard[0]);
                    }
                }
            }
 
            else if(pair1.size() == 4){
                bool pcardmerah = false;
                int idxpcard;
                for(int i = 0 ; i < pair1.size(); i++){
                    if((pair1[i] == p->getCardsPlayer()[0] or pair1[i] == p->getCardsPlayer()[1])){
                        if(pair1[i]->getNameCard() == "M") pcardmerah = true;
                        else idxpcard = i;
                        break;  
                    }
                }
                if(pcardmerah){
                    for(int i = 0; i < pair1.size(); i ++){
                        if(pair1[i]->getNameCard() == "B" or pair1[i]->getNameCard() == "H"){
                            pair1.erase(pair1.begin() + i);
                        }
                    }
                }
                else{
                    for(int i = 0 ; i < pair1.size(); i ++){
                        if(i != idxpcard){
                            if(pair1[i]->getNameCard() != "M"){
                                pair1.erase(pair1.begin() + i);
                            }
                        }
                    }
                }
            }
            ret = pair1;
            return ret;
        }
    }
}