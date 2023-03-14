#ifndef __ABILITY__CARD__HPP__
#define __ABILITY__CARD__HPP__

#include <iostream>
#include <algorithm>
#include "../Card/Card.hpp"
#include "../Player/Player.hpp"
#include "../SetGame/SetGame.hpp"
#include "../Exception/Exception.hpp"



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
        string getNameCard() const;
        void ReRollEffect(Player &p,SetGame &s);
protected:
    string name;
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
        string getNameCard() const;
        void QuadrupleEffect(Player&, SetGame&);
protected:
    string name;
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
        string getNameCard() const;
        void QuarterEffect(Player&, SetGame&);
protected:
    string name;
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
        string getNameCard() const;
        void ReverseDirectionEffect(Player&,SetGame&);
protected:
    string name;
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
        string getNameCard() const;
        void SwapCardEffect(Player&, Player&, Player&, int, int, SetGame&);
protected:
    string name;
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
        string getNameCard() const;
        void SwitchEffect(Player&,Player&, SetGame&);
protected:
    string name;
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
        string getNameCard() const;
        void AbilitylessEffect(SetGame &s, Player &abilityPlayer, Player &Target);
protected:
    string name;
};

#endif