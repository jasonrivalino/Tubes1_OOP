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
};

#endif