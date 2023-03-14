#ifndef CALCULABLE_HPP
#define CALCULABLE_HPP

#include <iostream>
#include <vector>
using namespace std;

// Pure Virtual Class
class Calculable {
    public:
        virtual float valueCards() = 0;
    protected:
        float value;
        char suit;
        vector<Cards> cards;
};

class Cards : public Calculable {
    public:
        Cards (int, char);
        float valueCards() override;
};

class Combo : public Calculable {
    public:
        Combo(vector<Cards>);
        float valueCards() override;
};


class OnePair : public Calculable {
    public:
        OnePair(vector<int>);
        float valueCards() override;
};

class StraightFlush : public Calculable {
    public:
        StraightFlush(vector<int>);
        float valueCards() override;
};

class TwoPair : public Calculable {
    public:
        TwoPair(vector<int>);
        float valueCards() override;
};

class FullHouse : public Calculable {
    public:
        FullHouse(vector<int>);
        float valueCards() override;
};

class FourOfKind : public Calculable {
    public:
        FourOfKind(vector<int>);
        float valueCards() override;
};

class ThreeOfKind : public Calculable {
    public:
        ThreeOfKind(vector<int>);
        float valueCards() override;
};

class Flush : public Calculable {
    public:
        Flush(vector<int>);
        float valueCards() override;
};

class HighCard : public Calculable {
    public:
        HighCard(vector<int>);
        float valueCards() override;
};

class Straight : public Calculable {
    public:
        Straight(vector<int>);
        float valueCards() override;
};
#endif