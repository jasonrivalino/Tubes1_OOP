#ifndef __ABILITY__CARD__HPP__
#define __ABILITY__CARD__HPP__

#include <iostream>
#include "../Card/Card.hpp"
#include "../Player/Player.hpp"
#include "../SetGame/SetGame.hpp"



using namespace std;


class SetGame;

class ReRoll : public Card{

    public:
        // Konstruktor
        ReRoll();
        // Destruktor
        ~ReRoll();
        // Setter and Getter
        void setReRoll(bool);
        bool getReRoll();
        void ReRollEffect(Player &p,SetGame &s);
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
        void QuadrupleEffect(Player&, SetGame, string);
    private:
        int currentPoint;
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
        void QuarterEffect(Player&, SetGame, string);
    private:
        int currentPoint;
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
        void SwapCardEffect(Player &p1, Player &p2);
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
        void SwitchEffect(Player &p1,Player &p2);
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
        void AbilitylessEffect(Player &abilityPlayer, vector<Player*> p);
};

#endif