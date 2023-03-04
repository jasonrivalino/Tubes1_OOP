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
        bool ans = false;


        vector <Card*> temp;
        vector<int> forSort;

        for(int i = 0; i < tableCard.getCards().size(); i++){
            if (player.getCardsPlayer()[idx].getNameCard() == tableCard.getCards()[i]->getNameCard()){
                temp.push_back(tableCard.getCards()[i]);
            }
        }

        for (int i = 0; i < temp.size(); i++) allCard.push_back(temp[i]);
        allCard.push_back(&player.getCardsPlayer()[idx]);

        if(idx == 0 && player.getCardsPlayer()[idx].getNameCard() == player.getCardsPlayer()[idx+1].getNameCard()) {
            allCard.push_back(&player.getCardsPlayer()[idx+1]);
        }
        
        // cout << allCard.size() <<endl;

        for(int i=0;i<allCard.size();i++) forSort.push_back(allCard[i]->getNumberCard());
        sort(forSort.begin(),forSort.end());

        // for (auto x : forSort) {
        //     cout << x << endl;
        // }
        int cek;
        for (int i = 0; i < allCard.size()- 4; i++){
            cek = 0;
            for(int j = allCard.size()-1 - i; j >= allCard.size()-5-i; j-- ){
                if (forSort[i+1] - forSort[i] != 1) continue;
                else cek ++ ;
            }
            if(cek == 5){
                ans = true;
                return true;
            }
        }
        return false;
    }
    return true;
}

bool Combination::isFourOfAKind(Player& player, Table& tableCard) {
    vector<Card*> allcards;
    vector<Card*> combination;

    for (int i = 0; i < tableCard.getCards().size(); i++) {
        allcards.push_back(tableCard.getCards()[i]);
    }
    for (int i = 0; i < player.getCardsPlayer().size(); i++) {
        allcards.push_back(&player.getCardsPlayer()[i]);
    }

    sort(allcards.begin(), allcards.end(), [](Card& card1, Card& card2) {
        return card1.getNumberCard() < card2.getNumberCard();
    });

    int counter = 1;
    for (int i = 0; i < allcards.size() - 1; i++) {
        if (allcards[i]->getNumberCard() == allcards[i + 1]->getNumberCard()) {
            counter++;
            if (counter == 4) {
                combination.push_back(allcards[i]);
                break;
            }
        } else {
            counter = 1;
        }
    }

    if (combination.size() == 1) {
        return true;
    }

    return false;
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
    vector<Card*> allcards;
    vector<Card*> combination;

    for (int i = 0; i < tableCard.getCards().size(); i++) {
        allcards.push_back(tableCard.getCards()[i]);
    }
    for (int i = 0; i < player.getCardsPlayer().size(); i++) {
        allcards.push_back(&player.getCardsPlayer()[i]);
    }

    sort(allcards.begin(), allcards.end(), [](Card& card1, Card& card2) {
        return card1.getNumberCard() < card2.getNumberCard();
    });

    int counter = 1;
    for (int i = 0; i < allcards.size() - 1; i++) {
        if (allcards[i]->getNumberCard() == allcards[i + 1]->getNumberCard()) {
            counter++;
            if (counter == 3) {
                combination.push_back(allcards[i]);
                break;
            }
        } else {
            counter = 1;
        }
    }

    if (combination.size() == 1) {
        return true;
    }

    return false;
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