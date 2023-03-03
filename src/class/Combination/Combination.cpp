#include "Combination.hpp"
#include <algorithm>

using namespace std;

bool Combination::isStraightFlush(Player &player, Table &tableCard)
{
    int count=0;
    int idx=99;
    int sizeCardTable=tableCard.getCards().size();
    for(int i=0;i<player.getCardsPlayer().size();i++){
        count=0;
        for(int j=0;j<sizeCardTable;j++){
            if(player.getCardsPlayer()[i].getNameCard()==tableCard.getCards()[j]->getNameCard()){
                count++;
            }
        }
        
        if(count==5){
            idx=i;
            break;
        }
    }
    if(idx!=99){
        vector <Card*> temp;
        vector <Card*> allCard;
        for(int i = 0; i < tableCard.getCards().size(); i++){
            if (player.getCardsPlayer()[idx].getNameCard() == tableCard.getCards()[i]->getNameCard()){
                temp.push_back(tableCard.getCards()[i]);
            }
        }
        allCard.insert(temp.end(), player.getCardsPlayer().begin(), player.getCardsPlayer().end());
        sort(allCard.begin(), allCard.end());
        for (int i = 0; i < allCard.size(); i++){
            if (allCard[i+1]->getNumberCard() - allCard[i]->getNumberCard() != 1){
                return false;
            }
        }
    }
    else{
        return false;
    }
    return true;
}

bool Combination::isFullHouse(Player &player, Table &tableCard)
{
    int count=0;
    int count2=0;
    int sizeCardTable=tableCard.getCards().size();
    for(int i=0;i<player.getCardsPlayer().size();i++){
        count=0;
        count2=0;
        for(int j=0;j<sizeCardTable;j++){
            if(player.getCardsPlayer()[i].getNumberCard()==tableCard.getCards()[j]->getNumberCard()){
                count++;
            }
        }
        if(count==3){
            for(int k=0;k<player.getCardsPlayer().size();k++){
                if(player.getCardsPlayer()[k].getNumberCard() != player.getCardsPlayer()[i].getNumberCard()){
                    for(int l=0;l<sizeCardTable;l++){
                        if(player.getCardsPlayer()[k].getNumberCard()==tableCard.getCards()[l]->getNumberCard()){
                            count2++;
                        }
                    }
                }
            }
            if(count2==2){
                return true;
            }
        }
    }
    return false;
}
