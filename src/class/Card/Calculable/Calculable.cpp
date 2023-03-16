#include "Calculable.hpp"
using namespace std;


Cards::Cards(vector<Card*> v) {
    this->cards = v;
}


double Cards::valueCards() {
    return this->value;
}


HighCard :: HighCard(vector<Card*> &v) : Cards(cards) {
    map <string,int> mp;
    mp["H"] = 0;
    mp["B"] = 1;
    mp["K"] = 2;
    mp["M"] = 3;

    this -> value = v[0]->getNumberCard() * 0.1 + mp[v[0]->getNameCard()] * 0.03;
}

double HighCard :: valueCards() {
    return this -> value;
}

OnePair :: OnePair(vector<Card*> &v) : Cards(cards) {
    map <string,int> mp;
    mp["H"] = 0;
    mp["B"] = 1;
    mp["K"] = 2;
    mp["M"] = 3;

    double maxHigh = 1.39;
    double ret = maxHigh;
    ret += v[0]->getNumberCard() * 0.1;
    if(mp[v[0]->getNameCard()] > mp[v[1]->getNameCard()]){
        ret += mp[v[0]->getNameCard()] * 0.03 + mp[v[1]->getNameCard()] * 0.003;
    }
    else {
        ret += mp[v[1]->getNameCard()] * 0.03 + mp[v[0]->getNameCard()] * 0.003;
    }
    this -> value = ret;
}
double OnePair :: valueCards(){
    return this -> value;
}

TwoPair :: TwoPair(vector<Card*> &v) : Cards(cards) {
    map <string,int> mp;
    mp["H"] = 0;
    mp["B"] = 1;
    mp["K"] = 2;
    mp["M"] = 3;
    
    double maxPair = 2.786;
    double ret = maxPair;
    if(v[0]->getNumberCard() > v[3]->getNumberCard()){
        ret += v[0]->getNumberCard() * 0.1;
        if(mp[v[0]->getNameCard()] > mp[v[1]->getNameCard()]){
            ret += mp[v[0]->getNameCard()] * 0.03 + mp[v[1]->getNameCard()] * 0.003;
        }
        else{
            ret += mp[v[1]->getNameCard()] * 0.03 + mp[v[0]->getNameCard()] * 0.003;
        }

        ret += v[2]->getNumberCard() * 0.0001;
        if(mp[v[2]->getNameCard()] > mp[v[3]->getNameCard()]){
            ret += mp[v[2]->getNameCard()] * 0.00003 + mp[v[3]->getNameCard()] * 0.000003;
        }
        else{
            ret += mp[v[3]->getNameCard()] * 0.00003 + mp[v[2]->getNameCard()] * 0.000003;
        }
    }

    else{
        ret += v[3]->getNumberCard() * 0.1;
        if(mp[v[2]->getNameCard()] > mp[v[3]->getNameCard()]){
            ret += mp[v[2]->getNameCard()] * 0.03 + mp[v[3]->getNameCard()] * 0.003;
        }
        else{
            ret += mp[v[3]->getNameCard()] * 0.03 + mp[v[2]->getNameCard()] * 0.003;
        }

        ret += v[0]->getNumberCard() * 0.0001;
        if(mp[v[0]->getNameCard()] > mp[v[1]->getNameCard()]){
            ret += mp[v[0]->getNameCard()] * 0.00003 + mp[v[1]->getNameCard()] * 0.000003;
        }
        else{
            ret += mp[v[1]->getNameCard()] * 0.00003 + mp[v[0]->getNameCard()] * 0.000003;
        }
    }
    this -> value = ret;
}
double TwoPair :: valueCards() {
    return this -> value;
}

ThreeOfAKind :: ThreeOfAKind(vector<Card*> &v) : Cards(cards) {
    map <string,int> mp;
    mp["H"] = 0;
    mp["B"] = 1;
    mp["K"] = 2;
    mp["M"] = 3;

    double maxTwoPair = 4.182226;
    double ret = maxTwoPair;
    ret += v[0]->getNumberCard() * 0.1 + mp[v[0]->getNameCard()] * 0.03;
    this -> value = ret;
}
double ThreeOfAKind :: valueCards() {
    return this -> value;
}

Straight :: Straight(vector<Card*> &v) : Cards(cards) {
    map <string,int> mp;
    mp["H"] = 0;
    mp["B"] = 1;
    mp["K"] = 2;
    mp["M"] = 3;
    
    double maxThreeKind = 5.572226;
    double ret = maxThreeKind;

    for(int i = 0; i < 5 ; i ++){
        ret += (v[i]->getNumberCard() * pow(10,-1-(3*i))) + (mp[v[i]->getNameCard()] * 0.3 * pow(10,-1-(3*i)));
    }
    this -> value = ret;
}
double Straight :: valueCards() {
    return this -> value;
}

Flush :: Flush(vector<Card*> &v) : Cards(cards) {
    map <string,int> mp;
    mp["H"] = 0;
    mp["B"] = 1;
    mp["K"] = 2;
    mp["M"] = 3;


    double maxStraight = 6.9635171910909;
    double ret = maxStraight;
    for(int i = 0 ; i < 5; i ++){
        ret += v[i]->getNumberCard() * pow(10,-1-i);
    }
    this -> value = ret;
}
double Flush :: valueCards() {
    return this -> value;
}

FullHouse :: FullHouse(vector<Card*> &v) : Cards(cards) {
    map <string,int> mp;
    mp["H"] = 0;
    mp["B"] = 1;
    mp["K"] = 2;
    mp["M"] = 3;

    double maxFlush = 8.395607191 ;
    double ret = maxFlush ;
    ret += v[0]->getNumberCard() * 0.1;
    ret += v[4]->getNumberCard() * 0.001;
    if(mp[v[3]->getNameCard()] > mp[v[4]->getNameCard()]){
        ret += mp[v[3]->getNameCard()] * 0.0003; 
        ret += mp[v[4]->getNameCard()] * 0.00003;
    }
    else{
        ret += mp[v[4]->getNameCard()] * 0.0003; 
        ret += mp[v[3]->getNameCard()] * 0.00003;
    }
    this -> value = ret;
}
double FullHouse :: valueCards() {
    return this -> value;
}

FourOfAKind :: FourOfAKind(vector<Card*> &v) : Cards(cards) {
    map<string,int> mp;
    mp["H"] = 0;
    mp["B"] = 1;
    mp["K"] = 2;
    mp["M"] = 3;

    double maxFullHouse = 9.709567191;
    double ret = maxFullHouse;
    ret += v[0]->getNumberCard() * 0.1;

    this -> value = ret;
}
double FourOfAKind :: valueCards() {
    return this -> value;
}

StraightFlush :: StraightFlush(vector<Card*> &v) : Cards(cards) {
    map<string,int> mp;
    mp["H"] = 0;
    mp["B"] = 1;
    mp["K"] = 2;
    mp["M"] = 3;

    double maxFourOfAKind = 11.009567191;
    double ret = maxFourOfAKind;

    vector<int> forSort;

    for(int i = 0 ; i < 5; i ++){
        forSort.push_back(v[i]->getNumberCard()); 
    }
    sort(forSort.begin(), forSort.end());

    for(int i = 4; i >= 0; i--){
        ret += forSort[i] * pow(10, -1-i);
    }
    this -> value = ret;
}
double StraightFlush :: valueCards() {
    return this -> value;
}