#include "Combination.hpp"
#include <algorithm>

using namespace std;

Combination::Combination(/* args */)
{
}

Combination::~Combination()
{
    this->allCard.clear();
}

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


    // KURANG KALO 2 KARTU WARNA SAMA
    if(idx!=99){
        vector <Card*> temp;
        vector<int> forSort;

        for(int i = 0; i < tableCard.getCards().size(); i++){
            if (player.getCardsPlayer()[idx].getNameCard() == tableCard.getCards()[i]->getNameCard()){
                temp.push_back(tableCard.getCards()[i]);
            }
        }

        for (int i = 0; i < temp.size(); i++) allCard.push_back(temp[i]);
        allCard.push_back(&player.getCardsPlayer()[idx]);

        for(int i=0;i<allCard.size();i++) forSort.push_back(allCard[i]->getNumberCard());
        sort(forSort.begin(),forSort.end());
        for (int i = 0; i < allCard.size()-1; i++){
            if (forSort[i+1] - forSort[i] != 1){
                return false;
            }
        }
    }
    else{
        return false;
    }
    return true;
}