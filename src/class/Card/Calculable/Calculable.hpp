#ifndef CALCULABLE_HPP
#define CALCULABLE_HPP

#include <iostream>
#include <vector>
#include "class/Combination/Combination.hpp"
using namespace std;

// Pure Virtual Class
class Calculable {
    public:
        virtual float valueCards() = 0;
};

class Cards : public Calculable {
    public:
        Cards (string, float);
        string getSuit();
        float valueCards() override;
    protected:
        float value;
        string suit;
};

class Combo : public Calculable {
    public:
        Combo(vector<Cards>);
        float valueCards() override;
    protected:
        vector<Cards*> cards;
        float value;
        string suit;
};

class CardAce : public Cards {
    public:
        CardAce(string, float);
        float valueCards() override;
};

class CardTwo : public Cards {
    public:
        CardTwo(string, float);
        float valueCards() override;
};

class CardThree : public Cards {
    public:
        CardThree(string, float);
        float valueCards() override;
};

class CardFour : public Cards {
    public:
        CardFour(string, float);
        float valueCards() override;
};

class CardFive : public Cards {
    public:
        CardFive(string, float);
        float valueCards() override;
};

class CardSix : public Cards {
    public:
        CardSix(string, float);
        float valueCards() override;
};

class CardSeven : public Cards {
    public:
        CardSeven(string, float);
        float valueCards() override;
};

class CardEight : public Cards {
    public:
        CardEight(string, float);
        float valueCards() override;
};

class CardNine : public Cards {
    public:
        CardNine(string, float);
        float valueCards() override;
};

class CardTen : public Cards {
    public:
        CardTen(string, float);
        float valueCards() override;
};

class CardJack : public Cards {
    public:
        CardJack(string, float);
        float valueCards() override;
};

class CardQueen : public Cards {
    public:
        CardQueen(string, float);
        float valueCards() override;
};

class CardKing : public Cards {
    public:
        CardKing(string, float);
        float valueCards() override;
};

class OnePair : public Combo {
    public:
        OnePair(vector<Cards>);
        float valueCards() override;
};

class TwoPair : public Combo {
    public:
        TwoPair(vector<Cards>);
        float valueCards() override;
};

class ThreeOfKind : public Combo {
    public:
        ThreeOfKind(vector<Cards>);
        float valueCards() override;
};

class Straight : public Combo {
    public:
        Straight(vector<Cards>);
        float valueCards() override;
};

class Flush : public Combo {
    public:
        Flush(vector<Cards>);
        float valueCards() override;
};

class FullHouse : public Combo {
    public:
        FullHouse(vector<Cards>);
        float valueCards() override;
};

class FourOfKind : public Combo {
    public:
        FourOfKind(vector<Cards>);
        float valueCards() override;
};

class StraightFlush : public Combo {
    public:
        StraightFlush(vector<Cards>);
        float valueCards() override;
};

#endif