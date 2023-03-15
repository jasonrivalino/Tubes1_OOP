#ifndef HIGHCARD_H
#define HIGHCARD_H
#include "./../Combination.hpp"

class HighCard : public Combination {
    public:
        HighCard(Player&, Table&);
        ~HighCard();
        vector<Card*> comb();

    private:
        Player* p;
        Table* t;
};

#endif