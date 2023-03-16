//
// Created by lenovo on 15/03/2023.
//

#include "StraightFlush.h"

StraightFlushh::StraightFlushh(Player &p, Table &t):Combination() {
    this->p=&p;
    this->t=&t;
}

vector<Card*> StraightFlushh::comb() {
    int count=0;
    int idx=99;
    vector <Card*> ret;

    int sizeCardTable=t->getCards().size();
    for(int i=0;i<p->getCardsPlayer().size();i++){
        count=0;
        for(int j=0;j<sizeCardTable;j++){


            if(p->getCardsPlayer()[i]->getNameCard()==t->getCards()[j]->getNameCard()){
                count++;
            }
        }

        if(count==5){
            idx=i;
            break;
        }
    }


    // KURANG KALO 2 KARTU WARNA SAMA
    if(idx!=99){

        vector<Card*> allCard;
        vector <Card*> temp;
        vector<int> forSort;

        int countpcard = 1;

        for(int i = 0; i < t->getCards().size(); i++){
            if (p->getCardsPlayer()[idx]->getNameCard() == t->getCards()[i]->getNameCard()){
                temp.push_back(t->getCards()[i]);
            }
        }

        for (int i = 0; i < temp.size(); i++) allCard.push_back(temp[i]);
        allCard.push_back(p->getCardsPlayer()[idx]);

        if(idx == 0 && p->getCardsPlayer()[idx]->getNameCard() == p->getCardsPlayer()[idx+1]->getNameCard()) {
            allCard.push_back(p->getCardsPlayer()[idx+1]);
            countpcard ++;
        }

        for(int i=0;i<allCard.size();i++) forSort.push_back(allCard[i]->getNumberCard());
        sort(forSort.begin(),forSort.end());

        int cek;
        bool pcard;


        for (int i = 0; i < allCard.size()- 4; i++){

            ret.clear();
            cek = 0;
            pcard = false;
            for(int j = allCard.size()-1 - i; j >= allCard.size()-4-i; j-- ){
                if (forSort[j] - forSort[j-1] != 1) continue;
                else {

                    for(int k = 0; k < allCard.size(); k++) {
                        if(forSort[j] == allCard[k]->getNumberCard()){
                            ret.push_back(allCard[k]);
                            continue;
                        }
                    }
                    if(j == allCard.size()-4-i){
                        for(int k = 0; k < allCard.size(); k++){
                            if(forSort[j-1] == allCard[k]->getNumberCard()){
                                ret.push_back(allCard[k]);
                                continue;
                            }
                        }
                    }
                    cek ++ ;
                    if  (countpcard == 1 &&
                         (forSort[j] == p->getCardsPlayer()[idx]->getNumberCard() ||
                          forSort[j-1] == p->getCardsPlayer()[idx]->getNumberCard() )){
                        pcard = true;
                    }
                    else if (countpcard == 2 &&
                             (forSort[j] == p->getCardsPlayer()[0]->getNumberCard() ||
                              forSort[j-1] == p->getCardsPlayer()[0]->getNumberCard() ||
                              forSort[j] == p->getCardsPlayer()[1]->getNumberCard() ||
                              forSort[j-1] == p->getCardsPlayer()[1]->getNumberCard()) ){
                        pcard = true;
                    }
                }
            }
            if(cek == 4 && pcard){
                return ret;
            }
        }
        return ret;
    }
    else return ret;
}
