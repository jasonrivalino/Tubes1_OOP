#ifndef __ABILITY__CARD__HPP__
#define __ABILITY__CARD__HPP__

#include <iostream>
#include "card.h"
using namespace std;

class ReRoll : public card{
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
}

class Quadruple : public card{
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
}

class Quarter : public card{
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
}

class ReverseDirection : public card{
    public:
        // Konstruktor
        ReverseDirection();
        // Destruktor
        ~ReverseDirection();
        // Setter and Getter
        void setReverseDirection(bool));
        bool getReverseDirection();
        void ReverseDirectionEffect();
    private:
        bool available;
}

class swap_card : public card{
    public:
        // Konstruktor
        swap_card();
        // Destruktor
        ~swap_card();
        // Setter and Getter
        void setSwapCard(bool);
        bool getSwapCard();
        void SwapCardEffect();
    private:
        bool available;
}

class switch : public card{
    public:
        // Konstruktor
        switch();
        // Destruktor
        ~switch();
        // Setter and Getter
        void setSwitch(bool);
        int getSwitch();
        void SwitchEffect();
    protected:
    private:
}

class abilityless : public card{
    public:
        // Konstruktor
        abilityless();
        // Destruktor
        ~abilityless();
        // Setter and Getter
        void setAbilityless(bool);
        int getAbilityless();
        void AbilitylessEffect();
    protected:
    private:
}

#endif