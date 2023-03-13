#ifndef DECKCARD_HPP
#define DECKCARD_HPP

#include <string>
#include <vector>
#include <iostream>
#include "../Card/Card.hpp"
using namespace std;

class DeckCard : public Card
{
    private:
        string nameDeckCard;
        bool deckCardUsed;
        int numberDeckCard;
    public:
        DeckCard();
        DeckCard(string, int);
        virtual void setNameDeckCard(string);
        virtual string getNameDeckCard();
        virtual void setDeckCardUsed(bool);
        virtual int getDeckCardUsed();
};

#endif