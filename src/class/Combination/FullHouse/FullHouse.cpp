#include "FullHouse.hpp"

FullHouse::FullHouse(Player &p, Table &t): Combination(){
    this->p = &p;
    this->t = &t;
}

FullHouse::~FullHouse(){
    delete p;
    delete t;
}

vector<Card*> comb() {
    vector <Card*> ret;
    vector <Card*> threeKindCard;
    vector <Card*> twoKindCard;
    vector <int> forSort;
    vector<Card*> allCard;
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
}