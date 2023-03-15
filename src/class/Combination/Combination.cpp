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
    for (int i = allCard.size() - 1; i >= 1; i--) {
        if (forSort[i] == forSort[i - 1]) {
            counter++;
            if (counter == 4) {
                ret = forSort[i];
                for (int j=0; j < player.getCardsPlayer().size(); j++) {
                    if(player.getCardsPlayer()[j]->getNumberCard() == ret) return ret;
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

vector<Card*> Combination::isFullHouse(Player &player, Table &tableCard)
{
    vector <Card*> ret;
    vector <Card*> threeKindCard;
    vector <Card*> twoKindCard;
    vector <int> forSort;
    bool pcard = false;

    for(int i = 0 ; i < tableCard.getCards().size(); i++) allCard.push_back(tableCard.getCards()[i]);
    for(int i = 0 ; i < player.getCardsPlayer().size(); i++) allCard.push_back(player.getCardsPlayer()[i]);
    for(int i = 0 ; i < allCard.size(); i++) forSort.push_back(allCard[i]->getNumberCard());
    sort(forSort.begin(), forSort.end());

    // cout << "sort\n";
    // for(int i = 0 ; i < forSort.size(); i ++){
    //     cout << forSort[i] << " ";
    // }
    // cout << "\nallcard\n";
    // for(auto x : allCard){
    //     cout <<x->getNameCard() << "   " << x->getNumberCard() << endl;
    // }

    // nyari kartu dengan 3 angka sama dulu
    int threeKind;
    int twoKind;

    int counter = 1;
    for(int i = allCard.size() - 1; i >=1 ; i--){
        if(forSort[i] == forSort[i-1]){
            counter++;
            threeKind = forSort[i];
        }
        else{
            threeKindCard.clear();
            counter = 1;
        }
        // cout << "counter :" << counter << endl;
        if(counter == 3){
            // cout << "masuk gak\n";
            for(int j = allCard.size()-1; j >= 1; j--){
                if(allCard[j]->getNumberCard() == threeKind){
                    threeKindCard.push_back(allCard[j]);
                }
            }
            break;
        }
    }

    // cout << "size threekind : " << threeKindCard.size() << endl;

    // kalau threeKindCard gaada isinya berarti gaada yg 3 angka sama sehingga langsung return ret
    if(threeKindCard.size() == 0) return ret;
    else{
        
        // hapus kartu hijau kalau misal di threeKindCard ada 4 angka
        if(threeKindCard.size() == 4){
            for(int i = 0; i < threeKindCard.size(); i++){
                if(threeKindCard[i]->getNameCard() == "H"){
                    threeKindCard.erase(threeKindCard.begin() + i);
                    break;
                }
            }
        }

        // nyari 2 kartu dengan angka yang sama
        for(int i = 0 ; i < allCard.size(); i++){
            if(forSort[i] == forSort[i-1] && forSort[i] != threeKind){
                twoKind = forSort[i];
                for(int j = 0; j < allCard.size(); j++){
                    if(allCard[j]->getNumberCard() == forSort[i]){
                        twoKindCard.push_back(allCard[j]);
                    }
                }
                break;
            }
        }

        // kalau gaada 2 kartu yang sama angkanya(angka beda dengan threekind sebelumnya) maka return ret
        if(twoKindCard.size() == 0) return ret;
        else{
            // hapus kartu kalau misal di twoKindCard > 2 kartu
            if(twoKindCard.size() == 4){
                for(int i = 0 ; i < twoKindCard.size(); i ++){
                    if(twoKindCard[i]->getNameCard() == "H"){
                        twoKindCard.erase(twoKindCard.begin() + i);
                        break;
                    }
                }
                for(int i = 0 ; i < twoKindCard.size(); i ++){
                    if(twoKindCard[i]->getNameCard() == "B"){
                        twoKindCard.erase(twoKindCard.begin() + i);
                        break;
                    }
                }
            }

            else if(twoKindCard.size() == 3){
                for(int i = 0 ; i < twoKindCard.size(); i++){
                    if(twoKindCard[i]->getNameCard() == "H"){
                        twoKindCard.erase(twoKindCard.begin() + i);
                    }
                }
                if(twoKindCard.size() == 3){
                    for(int i = 0 ; i < twoKindCard.size(); i++){
                        if(twoKindCard[i]->getNameCard() == "B"){
                            twoKindCard.erase(twoKindCard.begin() + i);
                        }
                    }
                }
            }
            for(int i = 0 ; i < threeKindCard.size(); i++) ret.push_back(threeKindCard[i]);
            for(int i = 0 ; i < twoKindCard.size(); i++) ret.push_back(twoKindCard[i]);
            
            for(int i = 0 ; i < player.getCardsPlayer().size(); i ++){
                for(int j = 0; j < ret.size(); j ++){
                    if(player.getCardsPlayer()[i] == ret[j]){
                        pcard = true;
                        break;
                    }
                }
            }
            if(pcard) return ret;

            // kalau gaada kartu player
            else{
                bool ijo = true;
                int looooop = 0;
                int cekthree = -99, cektwo = -99;
                for(int i = 0; i < player.getCardsPlayer().size(); i ++){
                    if(player.getCardsPlayer()[i]->getNumberCard() == threeKind){
                        cekthree = i;
                        break;
                    }
                    else if(player.getCardsPlayer()[i]->getNumberCard() == twoKind){
                        if(looooop == 0){
                            if(player.getCardsPlayer()[i]->getNameCard() != "H"){
                                ijo = false;
                                cektwo = i;
                            }
                            else{
                                cektwo = i;
                            }
                        }
                        else if(looooop == 1){
                            if(ijo){
                                cektwo = i;
                            }
                        }
                    }
                }
                if(cekthree == -99 && cektwo == -99){
                    ret.clear();
                    return ret;
                }
                else if(cekthree != -99){
                    for(int i = 0 ; i < 3; i++){
                        if(ret[i]->getNameCard() == "B"){
                            ret.erase(ret.begin() + i);
                            break;
                        }
                        else if(ret[i]->getNameCard() == "K"){
                            ret.erase(ret.begin() + i);
                            break;
                        }
                        else if(ret[i]->getNameCard() == "M"){
                            ret.erase(ret.begin() + i);
                            break;
                        }
                    }
                    ret.insert(ret.begin(), player.getCardsPlayer()[cekthree]);
                }
                else if(cektwo != -99){
                    for(int i = 3 ; i < 5; i++){
                        if(ret[i]->getNameCard() == "B"){
                            ret.erase(ret.begin() + i);
                            break;
                        }
                        else if(ret[i]->getNameCard() == "K"){
                            ret.erase(ret.begin() + i);
                            break;
                        }
                        else if(ret[i]->getNameCard() == "M"){
                            ret.erase(ret.begin() + i);
                            break;
                        }
                    }
                    ret.insert(ret.begin()+3, player.getCardsPlayer()[cektwo]);
                }
                return ret;
            }
        }
    }

    // int count=0;
    // int count2=0;
    // int sizeCardTable=tableCard.getCards().size();
    // for(int i=0;i<player.getCardsPlayer().size();i++){
    //     count=0;
    //     count2=0;
    //     for(int j=0;j<sizeCardTable;j++){
    //         if(player.getCardsPlayer()[i]->getNumberCard()==tableCard.getCards()[j]->getNumberCard()){
    //             count++;
    //         }
    //     }
    //     if(count==2){
    //         for(int k=0;k<player.getCardsPlayer().size();k++){
    //             count2=0;
    //             if(player.getCardsPlayer()[k]->getNumberCard() != player.getCardsPlayer()[i]->getNumberCard()){
    //                 for(int l=0;l<sizeCardTable;l++){
    //                     if(player.getCardsPlayer()[k]->getNumberCard()==tableCard.getCards()[l]->getNumberCard()){
    //                         count2++;
    //                     }
    //                 }
    //             }
    //             if(count2==1){
    //                 return ret;
    //             }
    //         }


    //     }
    // }
    // ret.clear()
    // return ret;
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

    //yang gw benerin
    //nanti panggil iStraight pas terakhir biar pas ke erase ga ngefek ke kombinasi lebih lanjut
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
    //yang gw benerin


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
                        if(ret.size() == 0){
                            ret.push_back(player.getCardsPlayer()[j]);
                        }
                        else{
                            if(ret[0]->getNameCard() == "K"){
                                if(player.getCardsPlayer()[j]->getNameCard() == "M"){
                                    ret.clear();
                                    ret.push_back(player.getCardsPlayer()[j]);
                                }
                            }
                            else if(ret[0]->getNameCard() == "B"){
                                if(player.getCardsPlayer()[j]->getNameCard() == "M" or player.getCardsPlayer()[j]->getNameCard() == "K"){
                                    ret.clear();
                                    ret.push_back(player.getCardsPlayer()[j]);
                                }
                            }
                            else if(ret[0]->getNameCard() == "H"){
                                if(player.getCardsPlayer()[j]->getNameCard() == "M" or player.getCardsPlayer()[j]->getNameCard() == "K" or player.getCardsPlayer()[j]->getNameCard() == "B"){
                                    ret.clear();
                                    ret.push_back(player.getCardsPlayer()[j]);
                                }
                            }
                        }
                    }
                }
                return ret;
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
    vector<int> forSort;
    vector<int> intPair;
    int countpair = 0;

    for (int i = 0; i < tableCard.getCards().size(); i++) {
        allCard.push_back(tableCard.getCards()[i]);
    }
    for (int i = 0; i < player.getCardsPlayer().size(); i++) {
        allCard.push_back(player.getCardsPlayer()[i]);
    }
    for (int i = 0; i < allCard.size(); i++) forSort.push_back(allCard[i]->getNumberCard());
    sort(forSort.begin(), forSort.end());


    for (int i = allCard.size()-1; i >= 1; i--){
        if(countpair == 3){
            break;
        }
        else{
            if(forSort[i] == forSort[i-1]){
                if(countpair == 0){
                    countpair++;
                    intPair.push_back(forSort[i]);
                }
                else{
                    if(intPair[countpair - 1] != forSort[i]){
                        countpair++;
                        intPair.push_back(forSort[i]);
                    }
                }
            }
        }
    }
    if(countpair < 2) return ret;
    else {
        int idxplayercard;
        bool cek = false;
        for(int i = 0; i < player.getCardsPlayer().size(); i++){
            for(int j = intPair.size() - 1 ; j >= 0; j--){
                // cout << "player card :" << player.getCardsPlayer()[i]->getNumberCard() << endl;
                // cout << "intpair : " << intPair[j] << endl;
                // cout << "idxplayercard :" << idxplayercard << endl << endl;
                if(player.getCardsPlayer()[i]->getNumberCard() == intPair[j]){
                    idxplayercard = j;
                    cek = true;
                    // break;
                }
            }
            if(cek) break;
        }

        // for(int i = 0 ; i < intPair.size(); i ++){
        //     cout << intPair[i] << endl;
        // }
        // cout << ":::___\n";



        if(!cek) return ret;
        else{
            vector<Card*> pair1;
            vector<Card*> pair2;
            for(int i = 0; i < allCard.size(); i++){
                if(allCard[i]->getNumberCard() == intPair[idxplayercard]){
                    pair1.push_back(allCard[i]);
                }
            }
            intPair.erase(intPair.begin() + idxplayercard);

            if(pair1.size() == 3){
                vector <int> nonpcard;
                for(int i = 0; i < pair1.size(); i++){
                    if(pair1[i] != player.getCardsPlayer()[0] and pair1[i] != player.getCardsPlayer()[1]){
                        nonpcard.push_back(i);
                    }
                }
                if(pair1[nonpcard[0]]->getNameCard() == "H"){
                    pair1.erase(pair1.begin() + nonpcard[0]);
                }
                else if(pair1[nonpcard[0]]->getNameCard() == "B"){
                    if(pair1[nonpcard[1]]->getNameCard() == "H"){
                        pair1.erase(pair1.begin() + nonpcard[1]);
                    }
                    else{
                        pair1.erase(pair1.begin() +nonpcard[0]);
                    }
                }
                else if(pair1[nonpcard[0]]->getNameCard() == "K"){
                    if(pair1[nonpcard[1]]->getNameCard() == "H" or pair1[nonpcard[1]]->getNameCard() == "B"){
                        pair1.erase(pair1.begin() + nonpcard[1]);
                    }
                    else{
                        pair1.erase(pair1.begin() +nonpcard[0]);
                    }
                }
                else if(pair1[nonpcard[0]]->getNameCard() == "M"){
                    if(pair1[nonpcard[1]]->getNameCard() == "H" or pair1[nonpcard[1]]->getNameCard() == "B" or pair1[nonpcard[1]]->getNameCard() == "K"){
                        pair1.erase(pair1.begin() + nonpcard[1]);
                    }
                    else{
                        pair1.erase(pair1.begin() +nonpcard[0]);
                    }
                }
            }

            else if(pair1.size() == 4){
                bool pcardmerah = false;
                int idxpcard;
                for(int i = 0 ; i < pair1.size(); i++){
                    if((pair1[i] == player.getCardsPlayer()[0] or pair1[i] == player.getCardsPlayer()[1])){
                        if(pair1[i]->getNameCard() == "M") pcardmerah = true;
                        else idxpcard = i;
                        break;  
                    }
                }
                if(pcardmerah){
                    for(int i = 0; i < pair1.size(); i ++){
                        if(pair1[i]->getNameCard() == "B" or pair1[i]->getNameCard() == "H"){
                            pair1.erase(pair1.begin() + i);
                        }
                    }
                }
                else{
                    for(int i = 0 ; i < pair1.size(); i ++){
                        if(i != idxpcard){
                            if(pair1[i]->getNameCard() != "M"){
                                pair1.erase(pair1.begin() + i);
                            }
                        }
                    }
                }
            }

            for(int i = 0 ; i < allCard.size(); i++){
                if(allCard[i]->getNumberCard() == intPair[0]){
                    pair2.push_back(allCard[i]);
                }
            }
            if(pair2.size() == 3){
                vector <int> nonpcard;
                for(int i = 0; i < pair2.size(); i++){
                    if(pair2[i] != player.getCardsPlayer()[0] and pair2[i] != player.getCardsPlayer()[1]){
                        nonpcard.push_back(i);
                    }
                }
                if(pair2[nonpcard[0]]->getNameCard() == "H"){
                    pair2.erase(pair2.begin() + nonpcard[0]);
                }
                else if(pair2[nonpcard[0]]->getNameCard() == "B"){
                    if(pair2[nonpcard[1]]->getNameCard() == "H"){
                        pair2.erase(pair2.begin() + nonpcard[1]);
                    }
                    else{
                        pair2.erase(pair2.begin() +nonpcard[0]);
                    }
                }
                else if(pair2[nonpcard[0]]->getNameCard() == "K"){
                    if(pair2[nonpcard[1]]->getNameCard() == "H" or pair2[nonpcard[1]]->getNameCard() == "B"){
                        pair2.erase(pair2.begin() + nonpcard[1]);
                    }
                    else{
                        pair2.erase(pair2.begin() +nonpcard[0]);
                    }
                }
                else if(pair2[nonpcard[0]]->getNameCard() == "M"){
                    if(pair2[nonpcard[1]]->getNameCard() == "H" or pair2[nonpcard[1]]->getNameCard() == "B" or pair2[nonpcard[1]]->getNameCard() == "K"){
                        pair2.erase(pair2.begin() + nonpcard[1]);
                    }
                    else{
                        pair2.erase(pair2.begin() +nonpcard[0]);
                    }
                }
            }

            else if(pair2.size() == 4){
                bool pcardmerah = false;
                int idxpcard;
                for(int i = 0 ; i < pair2.size(); i++){
                    if((pair2[i] == player.getCardsPlayer()[0] or pair2[i] == player.getCardsPlayer()[1])){
                        if(pair2[i]->getNameCard() == "M") pcardmerah = true;
                        else idxpcard = i;
                        break;  
                    }
                }
                if(pcardmerah){
                    for(int i = 0; i < pair2.size(); i ++){
                        if(pair2[i]->getNameCard() == "B" or pair2[i]->getNameCard() == "H"){
                            pair2.erase(pair2.begin() + i);
                        }
                    }
                }
                else{
                    for(int i = 0 ; i < pair2.size(); i ++){
                        if(i != idxpcard){
                            if(pair2[i]->getNameCard() != "M"){
                                pair2.erase(pair2.begin() + i);
                            }
                        }
                    }
                }
            }
            for(int i = 0 ; i < pair1.size(); i ++) ret.push_back(pair1[i]);
            for(int i = 0 ; i < pair2.size(); i ++) ret.push_back(pair2[i]);
            return ret;
        }
    }



    // int dipilih;
    // int count = 0;
    
    // int idxpair1;
    // string highestwarna0, highestwarna1;

    // for(int i = 0; i < tableCard.getCards().size(); i++){
    //     if(player.getCardsPlayer()[0]->getNumberCard() == tableCard.getCards()[i]->getNumberCard()){

    //     }
    // }

    // for(int i = 0; i < tableCard.getCards().size(); i ++) {
    //     if(player.getCardsPlayer()[0]->getNumberCard() == tableCard.getCards()[i]->getNumberCard()){
    //         dipilih = player.getCardsPlayer()[0]->getNumberCard();
    //         idxpair1 = i;
    //         count++;
    //         continue;
    //     }
    // }

    // if(count == 1){
    //     for(int i = 0; i < tableCard.getCards().size(); i++){
    //         if(player.getCardsPlayer()[1]->getNumberCard() == tableCard.getCards()[i]->getNumberCard()){
    //             if(dipilih > player.getCardsPlayer()[1]->getNumberCard()){
    //                 ret.push_back(player.getCardsPlayer()[0]);
    //                 ret.push_back(tableCard.getCards()[idxpair1]);
    //                 return ret;
    //             }
    //             else{
    //                 ret.push_back(player.getCardsPlayer()[1]);
    //                 ret.push_back(tableCard.getCards()[i]);
    //                 return ret;
    //             }
    //         }
    //     }
    // }
    // else return ret;
    // ret.clear();
    // return ret;
}

vector<Card*> Combination::isOnePair(Player &player, Table &tableCard)
{
    vector<Card*> ret;
    vector<int> forSort;
    vector<int> intPair;
    int countpair = 0;

    for (int i = 0; i < tableCard.getCards().size(); i++) {
        allCard.push_back(tableCard.getCards()[i]);
    }
    for (int i = 0; i < player.getCardsPlayer().size(); i++) {
        allCard.push_back(player.getCardsPlayer()[i]);
    }
    for (int i = 0; i < allCard.size(); i++) forSort.push_back(allCard[i]->getNumberCard());
    sort(forSort.begin(), forSort.end());

    for (int i = allCard.size()-1; i >= 1; i--){
        if(countpair == 3){
            break;
        }
        else{
            if(forSort[i] == forSort[i-1]){
                if(countpair == 0){
                    countpair++;
                    intPair.push_back(forSort[i]);
                }
                else{
                    if(intPair[countpair - 1] != forSort[i]){
                        countpair++;
                        intPair.push_back(forSort[i]);
                    }
                }
            }
        }
    }
    if(countpair < 1) return ret;
    else{
        int idxplayercard;
        bool cek = false;
        for(int i = 0 ; i < player.getCardsPlayer().size(); i++){
            for(int j = intPair.size() - 1 ; j >= 0; j--){
                if(player.getCardsPlayer()[i]->getNumberCard() == intPair[j]){
                    idxplayercard = j;
                    cek = true;
                }
            }
            if(cek) break;
        }
        
        if(!cek) return ret;
        else{
            vector<Card*> pair1;
            for(int i = 0; i < allCard.size(); i++){
                if(allCard[i]->getNumberCard() == intPair[idxplayercard]){
                    pair1.push_back(allCard[i]);
                }
            }
            intPair.erase(intPair.begin() + idxplayercard);

            if(pair1.size() == 3){
                vector <int> nonpcard;
                for(int i = 0; i < pair1.size(); i++){
                    if(pair1[i] != player.getCardsPlayer()[0] and pair1[i] != player.getCardsPlayer()[1]){
                        nonpcard.push_back(i);
                    }
                }
                if(pair1[nonpcard[0]]->getNameCard() == "H"){
                    pair1.erase(pair1.begin() + nonpcard[0]);
                }
                else if(pair1[nonpcard[0]]->getNameCard() == "B"){
                    if(pair1[nonpcard[1]]->getNameCard() == "H"){
                        pair1.erase(pair1.begin() + nonpcard[1]);
                    }
                    else{
                        pair1.erase(pair1.begin() +nonpcard[0]);
                    }
                }
                else if(pair1[nonpcard[0]]->getNameCard() == "K"){
                    if(pair1[nonpcard[1]]->getNameCard() == "H" or pair1[nonpcard[1]]->getNameCard() == "B"){
                        pair1.erase(pair1.begin() + nonpcard[1]);
                    }
                    else{
                        pair1.erase(pair1.begin() +nonpcard[0]);
                    }
                }
                else if(pair1[nonpcard[0]]->getNameCard() == "M"){
                    if(pair1[nonpcard[1]]->getNameCard() == "H" or pair1[nonpcard[1]]->getNameCard() == "B" or pair1[nonpcard[1]]->getNameCard() == "K"){
                        pair1.erase(pair1.begin() + nonpcard[1]);
                    }
                    else{
                        pair1.erase(pair1.begin() +nonpcard[0]);
                    }
                }
            }

            else if(pair1.size() == 4){
                bool pcardmerah = false;
                int idxpcard;
                for(int i = 0 ; i < pair1.size(); i++){
                    if((pair1[i] == player.getCardsPlayer()[0] or pair1[i] == player.getCardsPlayer()[1])){
                        if(pair1[i]->getNameCard() == "M") pcardmerah = true;
                        else idxpcard = i;
                        break;  
                    }
                }
                if(pcardmerah){
                    for(int i = 0; i < pair1.size(); i ++){
                        if(pair1[i]->getNameCard() == "B" or pair1[i]->getNameCard() == "H"){
                            pair1.erase(pair1.begin() + i);
                        }
                    }
                }
                else{
                    for(int i = 0 ; i < pair1.size(); i ++){
                        if(i != idxpcard){
                            if(pair1[i]->getNameCard() != "M"){
                                pair1.erase(pair1.begin() + i);
                            }
                        }
                    }
                }
            }
            ret = pair1;
            return ret;
        }
    }
    








    // int sizeCardTable=tableCard.getCards().size();
    // for (int i = 0; i < player.getCardsPlayer().size();i++){
    //     for (int j = 0; j < sizeCardTable; j++){
    //         if(player.getCardsPlayer()[i]->getNumberCard() == tableCard.getCards()[j]->getNumberCard()){
    //             ret.push_back(player.getCardsPlayer()[i]);
    //             ret.push_back(tableCard.getCards()[j]);
    //             return ret;
    //         }
    //     }
    // }
    // return ret;
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