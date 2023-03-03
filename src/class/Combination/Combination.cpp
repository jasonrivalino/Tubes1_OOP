#include "Combination.hpp"
#include <algorithm>

using namespace std;

Combination::Combination(/* args */)
{
    //
}

Combination::~Combination()
{
    //
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

bool Combination::isFourOfAKind(Player &player, Table &tableCard)
{
    //
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
        if(count==2){
            for(int k=0;k<player.getCardsPlayer().size();k++){
                count2=0;
                if(player.getCardsPlayer()[k].getNumberCard() != player.getCardsPlayer()[i].getNumberCard()){
                    for(int l=0;l<sizeCardTable;l++){
                        if(player.getCardsPlayer()[k].getNumberCard()==tableCard.getCards()[l]->getNumberCard()){
                            count2++;
                        }
                    }
                }
                if(count2==1){
                    return true;
                }
            }


        }
    }
    return false;
}

bool Combination::isFlush(Player &player, Table &tableCard)
{
    int count=0;
    int sizeCardTable=tableCard.getCards().size();
    for(int i=0;i<player.getCardsPlayer().size();i++){
        count=0;
        for(int j=0;j<sizeCardTable;j++){
            if(player.getCardsPlayer()[i].getNameCard()==tableCard.getCards()[j]->getNameCard()){
                count++;
            }
        }
        if(count==5){
            return true;
        }
    }
}

bool Combination::isStraight(Player &player, Table &tableCard)
{
    // isi y guys
}

bool Combination::isThreeOfAKind(Player &player, Table &tableCard)
{
    // isi y guys
}

bool Combination::isTwoPair(Player &player, Table &tableCard)
{
    int count = 0;
    int count2 = 0;
    int sizeCardTable=tableCard.getCards().size();
    for (int i = 0; i < player.getCardsPlayer().size();i++){
        count = 0;
        count2 = 0;
        for (int j = 0; j < sizeCardTable; j++){
            if (player.getCardsPlayer()[i].getNumberCard() == tableCard.getCards()[j]->getNumberCard()){
                count++;
            }
        }
        if (count == 1){
            for (int k = 0; k < player.getCardsPlayer().size(); k++){
                count2 = 0;
                if (player.getCardsPlayer()[k].getNumberCard() != player.getCardsPlayer()[i].getNumberCard()){
                    for (int l = 0; l < sizeCardTable; l++){
                        if (player.getCardsPlayer()[k].getNumberCard() == tableCard.getCards()[l]->getNumberCard()){
                            count2++;
                        }
                    }
                }
                if (count2 == 1){
                    return true;
                }
            }
        }
    }
    return false;
}

bool Combination::isOnePair(Player &player, Table &tableCard)
{
    int count = 0;
    int sizeCardTable=tableCard.getCards().size();
    for (int i = 0; i < player.getCardsPlayer().size();i++){
        count = 0;
        for (int j = 0; j < sizeCardTable; j++){
            if (player.getCardsPlayer()[i].getNumberCard() == tableCard.getCards()[j]->getNumberCard()){
                count++;
            }
        }
        if (count == 1){
            return true;
        }
    }
    return false;
}

bool Combination::isHighCard(Player &player, Table &tableCard)
{
    // isi y guys
}

void Combination::checkCombination(Player &player, Table &tableCard)
{
    //
}