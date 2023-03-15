#include "Straight.hpp"

Straight::Straight(Player &p, Table &t): Combination() {
    this->p = &p;
    this->t = &t;
}
Straight::~Straight() {
    delete p;
    delete t;
}

vector<Card*> Straight::comb(){
    vector<Card*> allCard;
    vector<int> forSort;
    vector<Card*> ret;
    bool pcard;
 
    for(int i=0; i < player.getCardsPlayer().size(); i++) allCard.push_back(player.getCardsPlayer()[i]);
    for(int i=0; i < tableCard.getCards().size(); i++) allCard.push_back(tableCard.getCards()[i]);
 
    //yang gw benerin
    //nanti panggil iStraight pas terakhir biar pas ke erase ga ngefek ke kombinasi lebih lanjut
    for(int i=0;i<allCard.size();i++){
        for(int j=0;j<allCard.size();j++){
            if(i!=j){
                if(allCard[i]->getNumberCard()==allCard[j]->getNumberCard()){
                    if(allCard[i]->getNameCard() == "M"){
                        allCard.erase(allCard.begin()+j);
                    }
 
                    else if(allCard[i]->getNameCard() == "K"){
                        if(allCard[j]->getNameCard() == "M"){
                            allCard.erase(allCard.begin() + i);
                        }
                        else{
                            allCard.erase(allCard.begin() + j);
                        }
                    }
 
                    else if(allCard[i]->getNameCard() == "B"){
                        if(allCard[j]->getNameCard() == "M" or allCard[j]->getNameCard() == "K"){
                            allCard.erase(allCard.begin() + i);
                        }
                        else{
                            allCard.erase(allCard.begin() + j);
                        }
                    }
 
                    else if(allCard[i]->getNameCard() == "H"){
                        if(allCard[j]->getNameCard() == "M" or allCard[j]->getNameCard() == "K" or allCard[j]->getNameCard() == "H"){
                            allCard.erase(allCard.begin() + i);
                        }
                        else{
                            allCard.erase(allCard.begin() + j);
                        }
                    }
                }
            }
        }
    }
    //yang gw benerin
 
 
    for(int i=0; i < allCard.size(); i++) forSort.push_back(allCard[i]->getNumberCard());
    sort(forSort.begin(), forSort.end());
 
 
    int cek;
    for (int i=0; i < allCard.size() - 4; i++){
        ret.clear();
        cek = 0;
        pcard = false;
        for(int j = allCard.size()-1; j >= allCard.size()-4-i; j--){
            if(forSort[j] - forSort[j-1] != 1) continue;
            else{
 
                for(int k = 0; k < allCard.size(); k++){
                    if(forSort[j] == allCard[k]->getNumberCard()) {
                        ret.push_back(allCard[k]);
                        if(allCard[k] == player.getCardsPlayer()[0] || allCard[k] == player.getCardsPlayer()[1]) pcard = true;
 
                        continue;
                    }
                }
                if(j == allCard.size()-4-i){
                    for(int k = 0; k < allCard.size(); k ++) {
                        if(forSort[j-1] == allCard[k]->getNumberCard()){
                            ret.push_back(allCard[k]);
                            if(allCard[k] == player.getCardsPlayer()[0] || allCard[k] == player.getCardsPlayer()[1]) pcard = true;
                            continue;
                        }
                    }
                }
                cek++;
            }
        }
        if(cek == 4 && pcard) return ret;
    }
    ret.clear();
    return ret;
}