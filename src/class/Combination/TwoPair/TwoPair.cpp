#include "TwoPair.hpp"

TwoPair :: TwoPair(Player &p,Table &t): Combination() {
    this->p = &p;
    this->t = &t;
}

TwoPair :: ~TwoPair() {
    delete p;
    delete t;
}

vector<Card*> TwoPair :: combTwoPair(){
    vector<Card*> allCard;
    vector<Card*> ret;
    vector<int> forSort;
    vector<int> intPair;
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
    if(countpair < 2) return ret;
    else {
        int idxplayercard;
        bool cek = false;
        for(int i = 0; i < p->getCardsPlayer().size(); i++){
            for(int j = intPair.size() - 1 ; j >= 0; j--){
                // cout << "player card :" << p->getCardsPlayer()[i]->getNumberCard() << endl;
                // cout << "intpair : " << intPair[j] << endl;
                // cout << "idxplayercard :" << idxplayercard << endl << endl;
                if(p->getCardsPlayer()[i]->getNumberCard() == intPair[j]){
                    idxplayercard = j;
                    cek = true;
                    // break;
                }
            }
            if(cek) break;
        }
 
        if(!cek) return ret;
        else{
            vector<Card*> pair1;
            vector<Card*> pair2;
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
 
            for(int i = 0 ; i < allCard.size(); i++){
                if(allCard[i]->getNumberCard() == intPair[0]){
                    pair2.push_back(allCard[i]);
                }
            }
            if(pair2.size() == 3){
                vector <int> nonpcard;
                for(int i = 0; i < pair2.size(); i++){
                    if(pair2[i] != p->getCardsPlayer()[0] and pair2[i] != p->getCardsPlayer()[1]){
                        nonpcard.push_back(i);
                    }
                }
                if(pair2[nonpcard[0]]->getNameCard() == "H"){
                    pair2.erase(pair2.begin() + nonpcard[0]);
                }
                else if(pair2[nonpcard[0]]->getNameCard() == "B"){
                    if(pair2[nonpcard[1]]->getNameCard() == "H"){
                        pair2.erase(pair2.begin() + nonpcard[1]);
                    }
                    else{
                        pair2.erase(pair2.begin() +nonpcard[0]);
                    }
                }
                else if(pair2[nonpcard[0]]->getNameCard() == "K"){
                    if(pair2[nonpcard[1]]->getNameCard() == "H" or pair2[nonpcard[1]]->getNameCard() == "B"){
                        pair2.erase(pair2.begin() + nonpcard[1]);
                    }
                    else{
                        pair2.erase(pair2.begin() +nonpcard[0]);
                    }
                }
                else if(pair2[nonpcard[0]]->getNameCard() == "M"){
                    if(pair2[nonpcard[1]]->getNameCard() == "H" or pair2[nonpcard[1]]->getNameCard() == "B" or pair2[nonpcard[1]]->getNameCard() == "K"){
                        pair2.erase(pair2.begin() + nonpcard[1]);
                    }
                    else{
                        pair2.erase(pair2.begin() +nonpcard[0]);
                    }
                }
            }
 
            else if(pair2.size() == 4){
                bool pcardmerah = false;
                int idxpcard;
                for(int i = 0 ; i < pair2.size(); i++){
                    if((pair2[i] == p->getCardsPlayer()[0] or pair2[i] == p->getCardsPlayer()[1])){
                        if(pair2[i]->getNameCard() == "M") pcardmerah = true;
                        else idxpcard = i;
                        break;  
                    }
                }
                if(pcardmerah){
                    for(int i = 0; i < pair2.size(); i ++){
                        if(pair2[i]->getNameCard() == "B" or pair2[i]->getNameCard() == "H"){
                            pair2.erase(pair2.begin() + i);
                        }
                    }
                }
                else{
                    for(int i = 0 ; i < pair2.size(); i ++){
                        if(i != idxpcard){
                            if(pair2[i]->getNameCard() != "M"){
                                pair2.erase(pair2.begin() + i);
                            }
                        }
                    }
                }
            }
            for(int i = 0 ; i < pair1.size(); i ++) ret.push_back(pair1[i]);
            for(int i = 0 ; i < pair2.size(); i ++) ret.push_back(pair2[i]);
            return ret;
        }
    }
}