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

class Player;

class Ability{
public:
    // Konstruktor
    Ability(string,bool,bool);
    // Destruktor
    ~Ability();
    // Setter and Getter
    virtual void setIsCardUsed(bool);
    virtual void setIsCardDeath(bool);

    virtual bool getIsCardUsed()const;
    virtual bool getIsCardDeath()const;
    virtual string getNameCard() const;
    virtual void effect(Player &p,SetGame &s);
protected:
    string name;
    bool isDeath;
    bool isUsed;
};


class ReRoll:public Ability{

public:
    // Konstruktor
    ReRoll();
    // Destruktor
    ~ReRoll();
    // Setter and Getter
    void setIsCardUsed(bool);
    void setIsCardDeath(bool);

    bool getIsCardUsed()const;
    bool getIsCardDeath()const;
    string getNameCard() const;
    void effect(Player &p,SetGame &s);
protected:
    string name;
    bool isDeath;
    bool isUsed;
};

class Quadruple:public Ability{
public:
    // Konstruktor
    Quadruple();
    // Destruktor
    ~Quadruple();
    // Setter and Getter
    void setIsCardUsed(bool);
    void setIsCardDeath(bool);

    bool getIsCardUsed()const;
    bool getIsCardDeath()const;
    string getNameCard() const;
    void effect(Player&, SetGame&);
protected:
    string name;
    bool isDeath;
    bool isUsed;
};

class Quarter:public Ability{
public:
    // Konstruktor
    Quarter();
    // Destruktor
    ~Quarter();
    // Setter and Getter
    void setIsCardUsed(bool);
    void setIsCardDeath(bool);

    bool getIsCardUsed()const;
    bool getIsCardDeath()const;
    string getNameCard() const;
    void effect(Player&, SetGame&);
protected:
    string name;
    bool isDeath;
    bool isUsed;
};

class ReverseDirection:public Ability{
public:
    // Konstruktor
    ReverseDirection();
    // Destruktor
    ~ReverseDirection();
    // Setter and Getter
    void setIsCardUsed(bool);
    void setIsCardDeath(bool);

    bool getIsCardUsed()const;
    bool getIsCardDeath()const;
    string getNameCard() const;
    void effect(Player&,SetGame&);
protected:
    string name;
    bool isDeath;
    bool isUsed;
};

class SwapCard:public Ability{
public:
    // Konstruktor
    SwapCard();
    // Destruktor
    ~SwapCard();
    // Setter and Getter
    void setIsCardUsed(bool);
    void setIsCardDeath(bool);

    bool getIsCardUsed()const;
    bool getIsCardDeath()const;
    string getNameCard() const;
    void effect(Player&, Player&, Player&, int, int, SetGame&);
protected:
    string name;
    bool isDeath;
    bool isUsed;
};

class Switch:public Ability{
public:
    // Konstruktor
    Switch();
    // Destruktor
    ~Switch();
    // Setter and Getter
    void setIsCardUsed(bool);
    void setIsCardDeath(bool);

    bool getIsCardUsed()const;
    bool getIsCardDeath()const;
    string getNameCard() const;
    void effect(Player&,Player&, SetGame&);
protected:
    string name;
    bool isDeath;
    bool isUsed;
};

class Abilityless:public Ability{
public:
    // Konstruktor
    Abilityless();
    // Destruktor
    ~Abilityless();
    // Setter and Getter
    void setIsCardUsed(bool);
    void setIsCardDeath(bool);

    bool getIsCardUsed()const;
    bool getIsCardDeath()const;
    string getNameCard() const;
    void effect(SetGame &s, Player &abilityPlayer, Player &Target);
protected:
    string name;
    bool isDeath;
    bool isUsed;
};

#endif