#include "Combination.hpp"
#include <algorithm>
#include <map>

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
                for (int j=0; j < player.getCardsPlayer().size(); j++) {
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

int Combination::isFullHouse(Player &player, Table &tableCard)
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

vector<Card*> Combination::isFlush(Player &player, Table &tableCard)
{
    vector<Card*> ret;
    vector<int> forSort;
    
    for(int i=0; i < allCard.size(); i++) forSort.push_back(allCard[i]->getNumberCard());
    sort(forSort.begin(), forSort.end());

    bool pcard = false;
    string color;

    for (int i=0; i < player.getCardsPlayer().size(); i++){
        allCard.push_back(player.getCardsPlayer()[i]);
        for(int j=0; j < tableCard.getCards().size(); j++){
            if(player.getCardsPlayer()[i]->getNameCard() == tableCard.getCards()[j]->getNameCard()){
                allCard.push_back(tableCard.getCards()[j]);
            }
        }
        if(allCard.size() < 5) continue;
        else if (allCard.size() == 5) return allCard;
        else{
            for(int j=0; j < allCard.size(); j++) forSort.push_back(allCard[j]->getNumberCard());
            sort(forSort.begin(), forSort.end());

            for(int j = allCard.size() - 1; j >= allCard.size() - 5; j--){
                for(int k = 0; k < allCard.size(); k++){
                    if(forSort[j] == allCard[k]->getNumberCard()){
                        ret.push_back(allCard[k]);
                        if(allCard[k] == player.getCardsPlayer()[i]) pcard = true;
                    }
                }
            }
            if(pcard) return ret;
            else{
                ret.pop_back();
                for(int j = 0; j < allCard.size(); j++) {
                    if(allCard[j]->getNumberCard() == forSort[i]){
                        ret.push_back(allCard[j]);
                    }
                }
                return ret;
            }
        }
    }
    ret.clear();
    return ret;
}

vector<Card*> Combination::isStraight(Player &player, Table &tableCard)
{
    vector<int> forSort;
    vector<Card*> ret;
    bool pcard;

    for(int i=0; i < player.getCardsPlayer().size(); i++) allCard.push_back(player.getCardsPlayer()[i]);
    for(int i=0; i < tableCard.getCards().size(); i++) allCard.push_back(tableCard.getCards()[i]);

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

vector<Card*> Combination::isThreeOfAKind(Player &player, Table &tableCard)
{
    vector<Card*> ret;
    vector<int> forSort;
    bool pcard = false;

    for (int i = 0; i < tableCard.getCards().size(); i++) {
        allCard.push_back(tableCard.getCards()[i]);
    }
    for (int i = 0; i < player.getCardsPlayer().size(); i++) {
        allCard.push_back(player.getCardsPlayer()[i]);
    }

    for (int i = 0; i < allCard.size(); i ++) forSort.push_back(allCard[i]->getNumberCard());
    sort(forSort.begin(), forSort.end());

    int counter = 1;
    for (int i=0; i < allCard.size() - 1; i++) {
        if (forSort[i] == forSort[i + 1]) {
            counter ++ ;
            if (counter == 3) {
                for(int j = 0; j < player.getCardsPlayer().size(); j++) {
                    if(player.getCardsPlayer()[j]->getNumberCard() == forSort[i]){
                        ret.push_back(player.getCardsPlayer()[j]);
                        return ret;
                    }
                }
            }
        }
        else counter = 1;
    }
    ret.clear();
    return ret;
}

vector<Card*> Combination::isTwoPair(Player &player, Table &tableCard)
{
    vector<Card*> ret;
    int dipilih;
    int count = 0;
    
    int idxpair1;

    for(int i = 0; i < tableCard.getCards().size(); i ++) {
        if(player.getCardsPlayer()[0]->getNumberCard() == tableCard.getCards()[i]->getNumberCard()){
            dipilih = player.getCardsPlayer()[0]->getNumberCard();
            idxpair1 = i;
            count++;
            continue;
        }
    }

    if(count == 1){
        for(int i = 0; i < tableCard.getCards().size(); i++){
            if(player.getCardsPlayer()[1]->getNumberCard() == tableCard.getCards()[i]->getNumberCard()){
                if(dipilih > player.getCardsPlayer()[1]->getNumberCard()){
                    ret.push_back(player.getCardsPlayer()[0]);
                    ret.push_back(tableCard.getCards()[idxpair1]);
                    return ret;
                }
                else{
                    ret.push_back(player.getCardsPlayer()[1]);
                    ret.push_back(tableCard.getCards()[i]);
                    return ret;
                }
            }
        }
    }
    else return ret;
}

vector<Card*> Combination::isOnePair(Player &player, Table &tableCard)
{
    vector<Card*> ret;
    int sizeCardTable=tableCard.getCards().size();
    for (int i = 0; i < player.getCardsPlayer().size();i++){
        for (int j = 0; j < sizeCardTable; j++){
            if(player.getCardsPlayer()[i]->getNumberCard() == tableCard.getCards()[j]->getNumberCard()){
                ret.push_back(player.getCardsPlayer()[i]);
                ret.push_back(tableCard.getCards()[j]);
                return ret;
            }
        }
    }
    return ret;
}

vector<Card*> Combination::isHighCard(Player &player, Table &tableCard)
{
    map <string, int> mp;
    mp["M"] = 4;
    mp["K"] = 3;
    mp["B"] = 2;
    mp["H"] = 1;

    vector<Card*> ret;
    if(player.getCardsPlayer()[0]->getNumberCard() > player.getCardsPlayer()[1]->getNumberCard()){
        ret.push_back(player.getCardsPlayer()[0]);
        return ret;
    }
    else if (player.getCardsPlayer()[0]->getNumberCard() < player.getCardsPlayer()[1]->getNumberCard()){
        ret.push_back(player.getCardsPlayer()[1]);
        return ret;
    }
    else{
        if(mp[player.getCardsPlayer()[0]->getNameCard()] > mp[player.getCardsPlayer()[1]->getNameCard()]){
            ret.push_back(player.getCardsPlayer()[0]);
            return ret;
        }
        else{
            ret.push_back(player.getCardsPlayer()[1]);
            return ret;
        }
    }
}