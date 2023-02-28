#ifndef __ABILITY__CARD__HPP__
#define __ABILITY__CARD__HPP__

#include <iostream>
#include "../Card/Card.hpp"
using namespace std;

class ReRoll : public Card{
    public:
        // Konstruktor
        ReRoll();
        // Destruktor
        ~ReRoll();
        // Setter and Getter
        void setReRoll(bool);
        bool getReRoll();
        void ReRollEffect();
    private:
        bool available;
};

class Quadruple : public Card{
    public:
        // Konstruktor
        Quadruple();
        // Destruktor
        ~Quadruple();
        // Setter and Getter
        void setQuadruple(bool);
        bool getQuadruple();
        void QuadrupleEffect();
    private:
        bool available;
};

class Quarter : public Card{
    public:
        // Konstruktor
        Quarter();
        // Destruktor
        ~Quarter();
        // Setter and Getter
        void setQuarter(bool);
        bool getQuarter();
        void QuarterEffect();
    private:
        bool available;
};

class ReverseDirection : public Card{
    public:
        // Konstruktor
        ReverseDirection();
        // Destruktor
        ~ReverseDirection();
        // Setter and Getter
        void setReverseDirection(bool);
        bool getReverseDirection();
        void ReverseDirectionEffect();
    private:
        bool available;
};

class SwapCard : public Card{
    public:
        // Konstruktor
        SwapCard();
        // Destruktor
        ~SwapCard();
        // Setter and Getter
        void setSwapCard(bool);
        bool getSwapCard();
        void SwapCardEffect();
    private:
        bool available;
};

class Switch : public Card{
    public:
        // Konstruktor
        Switch();
        // Destruktor
        ~Switch();
        // Setter and Getter
        void setSwitch(bool);
        bool getSwitch();
        void SwitchEffect();
    protected:
    private:
    bool available;
};

class Abilityless : public Card{
    public:
        // Konstruktor
        Abilityless();
        // Destruktor
        ~Abilityless();
        // Setter and Getter
        void setAbilityless(bool);
        bool getAbilityless();
        void AbilitylessEffect();
    protected:
    private:
    bool available;
};

#endif