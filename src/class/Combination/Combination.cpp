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
    // KURANG KALO 2 KARTU WARNA SAMA
    if(idx!=99){
        vector <Card*> temp;
        vector <Card*> allCard;
        for(int i = 0; i < tableCard.getCards().size(); i++){
            if (player.getCardsPlayer()[idx].getNameCard() == tableCard.getCards()[i]->getNameCard()){
                temp.push_back(tableCard.getCards()[i]);
            }
        }

        for (int i = 0; i < temp.size(); i++) allCard.push_back(temp[i]);
        allCard.push_back(&player.getCardsPlayer()[idx]);
        // allCard.insert(temp.end(), player.getCardsPlayer().begin(), player.getCardsPlayer().end());
        sort(allCard.begin(), allCard.end());
        for (int i = 0; i < allCard.size()-1; i++){
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
    // isi y guys
}

bool Combination::isOnePair(Player &player, Table &tableCard)
{
    // isi y guys
}

bool Combination::isHighCard(Player &player, Table &tableCard)
{
    // isi y guys
}

void Combination::checkCombination(Player &player, Table &tableCard)
{
    //
}