#include "Combination.hpp"
#include <algorithm>

using namespace std;

Combination::Combination(/* args */)
{
    //
}



Combination::~Combination()
{
    this->allCard.clear();
    //
}

vector<Card*> Combination::isStraightFlush(Player &player, Table &tableCard)
{
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
}

int Combination::isFourOfAKind(Player &player, Table &tableCard) {
    int ret;
    vector<int> forSort;

    bool pcard = false;

    for (int i = 0; i < tableCard.getCards().size(); i++) {
        allCard.push_back(tableCard.getCards()[i]);
    }
    for (int i = 0; i < player.getCardsPlayer().size(); i++) {
        allCard.push_back(player.getCardsPlayer()[i]);
    }

    for (int i = 0; i < allCard.size(); i++) forSort.push_back(allCard[i]->getNumberCard());
    sort(forSort.begin(), forSort.end());

    int counter = 1;
    for (int i = 0; i < allCard.size() - 1; i++) {
        if (forSort[i] == forSort[i + 1]) {
            counter++;
            if (counter == 4) {
                ret = forSort[i];
                for (int i=0; i < player.getCardsPlayer().size(); i++) {
                    if(player.getCardsPlayer()[i]->getNumberCard() == ret) return ret;
                }
                return -99;
            }
        } 
        else {
            counter = 1;
        }
    }
    return -99;
}


bool Combination::isFullHouse(Player &player, Table &tableCard)
{
    vector <Card*> ret;
    bool pcard = false;

    int count=0;
    int count2=0;
    int sizeCardTable=tableCard.getCards().size();
    for(int i=0;i<player.getCardsPlayer().size();i++){
        count=0;
        count2=0;
        for(int j=0;j<sizeCardTable;j++){
            if(player.getCardsPlayer()[i]->getNumberCard()==tableCard.getCards()[j]->getNumberCard()){
                count++;
            }
        }
        if(count==2){
            for(int k=0;k<player.getCardsPlayer().size();k++){
                count2=0;
                if(player.getCardsPlayer()[k]->getNumberCard() != player.getCardsPlayer()[i]->getNumberCard()){
                    for(int l=0;l<sizeCardTable;l++){
                        if(player.getCardsPlayer()[k]->getNumberCard()==tableCard.getCards()[l]->getNumberCard()){
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
            if(player.getCardsPlayer()[i]->getNameCard()==tableCard.getCards()[j]->getNameCard()){
                count++;
            }
        }
        if(count==5){
            return true;
        }
    }
    return false;
}

// bool Combination::isStraight(Player &player, Table &tableCard)
// {
//     return true;
// }

// bool Combination::isThreeOfAKind(Player &player, Table &tableCard)
// {
//     vector<Card*> allCard;
//     vector<Card*> combination;

//     for (int i = 0; i < tableCard.getCards().size(); i++) {
//         allCard.push_back(tableCard.getCards()[i]);
//     }
//     for (int i = 0; i < player.getCardsPlayer().size(); i++) {
//         allCard.push_back(&player.getCardsPlayer()[i]);
//     }

//     sort(allCard.begin(), allCard.end(), [](Card& card1, Card& card2) {
//         return card1.getNumberCard() < card2.getNumberCard();
//     });

//     int counter = 1;
//     for (int i = 0; i < allCard.size() - 1; i++) {
//         if (allCard[i]->getNumberCard() == allCard[i + 1]->getNumberCard()) {
//             counter++;
//             if (counter == 3) {
//                 combination.push_back(allCard[i]);
//                 break;
//             }
//         } else {
//             counter = 1;
//         }
//     }

//     if (combination.size() == 1) {
//         return true;
//     }

//     return false;
// }

// bool Combination::isTwoPair(Player &player, Table &tableCard)
// {
//     int count = 0;
//     int count2 = 0;
//     int sizeCardTable=tableCard.getCards().size();
//     for (int i = 0; i < player.getCardsPlayer().size();i++){
//         count = 0;
//         count2 = 0;
//         for (int j = 0; j < sizeCardTable; j++){
//             if (player.getCardsPlayer()[i].getNumberCard() == tableCard.getCards()[j]->getNumberCard()){
//                 count++;
//             }
//         }
//         if (count == 1){
//             for (int k = 0; k < player.getCardsPlayer().size(); k++){
//                 count2 = 0;
//                 if (player.getCardsPlayer()[k].getNumberCard() != player.getCardsPlayer()[i].getNumberCard()){
//                     for (int l = 0; l < sizeCardTable; l++){
//                         if (player.getCardsPlayer()[k].getNumberCard() == tableCard.getCards()[l]->getNumberCard()){
//                             count2++;
//                         }
//                     }
//                 }
//                 if (count2 == 1){
//                     return true;
//                 }
//             }
//         }
//     }
//     return false;
// }

// bool Combination::isOnePair(Player &player, Table &tableCard)
// {
//     int count = 0;
//     int sizeCardTable=tableCard.getCards().size();
//     for (int i = 0; i < player.getCardsPlayer().size();i++){
//         count = 0;
//         for (int j = 0; j < sizeCardTable; j++){
//             if (player.getCardsPlayer()[i].getNumberCard() == tableCard.getCards()[j]->getNumberCard()){
//                 count++;
//             }
//         }
//         if (count == 1){
//             return true;
//         }
//     }
//     return false;
// }