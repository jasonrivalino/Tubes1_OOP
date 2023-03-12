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

bool Combination::isStraight(Player &player, Table &tableCard)
{
    vector<int> allCards;
    for(int i=0;i<player.getCardsPlayer().size();i++) allCards.push_back(player.getCardsPlayer()[i]->getNumberCard());
    for(int i=0;i<tableCard.getCards().size();i++) allCards.push_back(tableCard.getCards()[i]->getNumberCard());

    for(int i=0;i<allCards.size();i++){
        for(int j=0;j<allCards.size();j++){
            if(i!=j){
                if(allCards[i]==allCards[j]){
                    allCards.erase(allCards.begin()+j);
                }
            }
        }
    }



    int countCardStraight = 4;
    int countIsStraight=0;


    for(int i=0;i<allCards.size()-1;i++){
        if(allCards[i+1]-allCards[i]==1) countIsStraight++;
        if(countIsStraight==countCardStraight) return true;
    }
    return false;
//    vector<int> allPlayerCards;
//    vector<int> allTableCards;
//    for(int i=0;i<player.getCardsPlayer().size();i++) allPlayerCards.push_back(player.getCardsPlayer()[i]->getNumberCard());
//    for(int i=0;i<tableCard.getCards().size();i++) allTableCards.push_back(tableCard.getCards()[i]->getNumberCard());

//    sort(allPlayerCards.begin(),allPlayerCards.end());
//    sort(allTableCards.begin(),allTableCards.end());
//
//    int countDistancePlusOne=0;
//    int distance=1;
//
//    int idxPlusOne=0;
//    bool isOneTrue= false;
//    bool isTwoTrue= false;
//
//    vector<int> cardOne;
//    vector<int> cardTwo;
//    cardOne.push_back(player.getCardsPlayer()[0]->getNumberCard());
//    cardTwo.push_back(player.getCardsPlayer()[1]->getNumberCard());
//
//
//    for(int i=0;i<allTableCards.size();i++){ if(abs(allTableCards[i]-allPlayerCards[0])==1){
//        idxPlusOne=i;
//        isOneTrue= true;
//        break;
//        }
//        }
//    if(isOneTrue) {
//        for (int i = idxPlusOne; i < allTableCards.size(); i++) {
//            if(abs(allTableCards[i]-allPlayerCards[0])==distance){
//                cardOne.push_back(allTableCards[i]);
//                distance++;
//                countDistancePlusOne++;
//            }
//            if(countDistancePlusOne==4) return true;
//        }
//
//        distance=2;
//        if(idxPlusOne>0) {
//            for (int i = idxPlusOne-1; i >= 0; i--) {
//                if (abs(allTableCards[i] - allPlayerCards[0]) == distance) {
//                    cardOne.push_back(allTableCards[i]);
//                    distance++;
//                    countDistancePlusOne++;
//
//                }
//                if (countDistancePlusOne == 4) return true;
//            }
//            distance=1;
//            countDistancePlusOne=0;
//        }
//    }
//
//
//
//
//    for(int i=0;i<allTableCards.size();i++) if(abs(allTableCards[i]-allPlayerCards[1])==1){
//            idxPlusOne=i;
//            isTwoTrue= true;
//            break;
//        }
//    if(isTwoTrue){
//        for (int i = idxPlusOne; i < allTableCards.size(); i++) {
//            if(abs(allTableCards[i]-allPlayerCards[1])==distance){
//                cardTwo.push_back(allTableCards[i]);
//                distance++;
//                countDistancePlusOne++;
//            }
//            if(countDistancePlusOne==4) return true;
//        }
//
//        distance=2;
//
//        if(idxPlusOne>0) {
//            for (int i = idxPlusOne-1; i >= 0; i--) {
//                if (abs(allTableCards[i] - allPlayerCards[1]) == distance) {
//                    cardTwo.push_back(allTableCards[i]);
//                    distance++;
//                    countDistancePlusOne++;
//                }
//                if (countDistancePlusOne == 4) return true;
//            }
//            distance=1;
//            countDistancePlusOne=0;
//        }
//    }
//
//
//    if(isOneTrue&&isTwoTrue){
//        vector<int> allCard;
//
//        for(int i=0;i<cardOne.size();i++) allCard.push_back(cardOne[i]);
//        for(int i=0;i<cardTwo.size();i++) allCard.push_back(cardTwo[i]);
//
//
//        sort(allCard.begin(),allCard.end());
//
//
//        int countCardStraight = 4;
//        int countIsStraight=0;
//        for(int i=0;i<allCard.size()-1;i++){
//            if(allCard[i+1]-allCard[i]==1){
//                countIsStraight++;
//            }
//        }
//
//        if(countIsStraight==countCardStraight) return true;
//    }


return false;
}

// bool Combination::isThreeOfAKind(Player &player, Table &tableCard)
// {
//     vector<Card*> allCard;
//     vector<Card*> combination;
// 2 3 5 6 7
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