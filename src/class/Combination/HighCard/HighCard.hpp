#ifndef HIGHCARD_H
#define HIGHCARD_H
#include "./../Combination.hpp"
#include <map>

class HighCard : public Combination {
    public:
        HighCard(Player&, Table&);
        ~HighCard();
        vector<Card*> combHighCard();

    private:
        Player* p;
        Table* t;
};

#endif