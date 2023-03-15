#include "StraightFlush.hpp"



int count=0;
    int idx=99;
    vector <Card*> ret;

    int sizeCardTable=tableCard.getCards().size();
    for(int i=0;i<player.getCardsPlayer().size();i++){
        count=0;
        for(int j=0;j<sizeCardTable;j++){


            if(player.getCardsPlayer()[i]->getNameCard()==tableCard.getCards()[j]->getNameCard()){
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

        vector <Card*> temp;
        vector<int> forSort;

        int countpcard = 1;

        for(int i = 0; i < tableCard.getCards().size(); i++){
            if (player.getCardsPlayer()[idx]->getNameCard() == tableCard.getCards()[i]->getNameCard()){
                temp.push_back(tableCard.getCards()[i]);
            }
        }

        for (int i = 0; i < temp.size(); i++) allCard.push_back(temp[i]);
        allCard.push_back(player.getCardsPlayer()[idx]);

        if(idx == 0 && player.getCardsPlayer()[idx]->getNameCard() == player.getCardsPlayer()[idx+1]->getNameCard()) {
            allCard.push_back(player.getCardsPlayer()[idx+1]);
            countpcard ++;
        }

        for(int i=0;i<allCard.size();i++) forSort.push_back(allCard[i]->getNumberCard());
        sort(forSort.begin(),forSort.end());

        int cek;
        bool pcard;
        

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
                        (forSort[j] == player.getCardsPlayer()[idx]->getNumberCard() ||
                        forSort[j-1] == player.getCardsPlayer()[idx]->getNumberCard() )){
                            pcard = true;
                    }
                    else if (countpcard == 2 &&
                        (forSort[j] == player.getCardsPlayer()[0]->getNumberCard() ||
                        forSort[j-1] == player.getCardsPlayer()[0]->getNumberCard() ||
                        forSort[j] == player.getCardsPlayer()[1]->getNumberCard() ||
                        forSort[j-1] == player.getCardsPlayer()[1]->getNumberCard()) ){
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