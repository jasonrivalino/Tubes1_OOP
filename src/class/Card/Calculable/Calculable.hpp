#ifndef CALCULABLE_HPP
#define CALCULABLE_HPP

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <map>
#include "./../Card.hpp"

// #include "./../Combination.hpp"
using namespace std;

// Pure Virtual Class
class Calculable {
    public:
        virtual double valueCards() = 0;
};

class Cards : public Calculable {
    public:
        Cards (vector<Card*>);
        double valueCards() override;
        // int getSuit();
        // int getNumber();
    protected:
        double value;
        // int number;
        // int suit;
        vector<Card*> cards;
};

class Combo : public Calculable {
    public:
        Combo(vector<Card*>);
        double valueCards() override;
    protected:
        vector<Card*> cards;
        double value;
        string suit;
};

class HighCard : public Cards {
    public :
        HighCard(vector<Card*> &v);
        double valueCards() override;
};

class OnePair : public Cards {
    public :
        OnePair(vector<Card*> &v);
        double valueCards() override;
};

class TwoPair : public Cards {
    public :
        TwoPair(vector<Card*> &v);
        double valueCards() override;
};

class ThreeOfAKind : public Cards {
    public :
        ThreeOfAKind(vector<Card*> &v);
        double valueCards() override;
};

class Straight : public Cards {
    public :
        Straight(vector<Card*> &v);
        double valueCards() override;
};

class Flush : public Cards {
    public :
        Flush(vector<Card*> &v);
        double valueCards() override;
};

class FullHouse : public Cards {
    public :
        FullHouse(vector<Card*> &v);
        double valueCards() override;
};

class FourOfAKind : public Cards {
    public :
        FourOfAKind(vector<Card*> &v);
        double valueCards() override;
};

class StraightFlush : public Cards {
    public :
        StraightFlush(vector<Card*> &v);
        double valueCards() override;
};

#endif
