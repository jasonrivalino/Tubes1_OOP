#ifndef CALCULABLE_HPP
#define CALCULABLE_HPP

#include <iostream>
#include <vector>
using namespace std;

// Pure Virtual Class
class Calculable {
    public:
        virtual float valueCards() = 0;
};

class Cards : public Calculable {
    public:
        Cards (int, char);
        float valueCards() override;
    protected:
        float value;
        char suit;
};

class Combo : public Calculable {
    public:
        Combo(vector<Cards>);
        float valueCards() override;
    protected:
        vector<Cards> cards;
};

class CardAce : public Cards {
    public:
        CardAce(int, char);
        float valueCards() override;
};

class CardTwo : public Cards {
    public:
        CardTwo(int, char);
        float valueCards() override;
};

class CardThree : public Cards {
    public:
        CardThree(int, char);
        float valueCards() override;
};

class CardFour : public Cards {
    public:
        CardFour(int, char);
        float valueCards() override;
};

class CardFive : public Cards {
    public:
        CardFive(int, char);
        float valueCards() override;
};

class CardSix : public Cards {
    public:
        CardSix(int, char);
        float valueCards() override;
};

class CardSeven : public Cards {
    public:
        CardSeven(int, char);
        float valueCards() override;
};

class CardEight : public Cards {
    public:
        CardEight(int, char);
        float valueCards() override;
};

class CardNine : public Cards {
    public:
        CardNine(int, char);
        float valueCards() override;
};

class CardTen : public Cards {
    public:
        CardTen(int, char);
        float valueCards() override;
};

class CardJack : public Cards {
    public:
        CardJack(int, char);
        float valueCards() override;
};

class CardQueen : public Cards {
    public:
        CardQueen(int, char);
        float valueCards() override;
};

class CardKing : public Cards {
    public:
        CardKing(int, char);
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