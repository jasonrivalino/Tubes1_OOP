#ifndef ONEPAIR_HPP
#define ONEPAIR_HPP
#include "./../Combination.hpp"

class OnePair : public Combination {
    public:
        OnePair(Player&, Table&);
        ~OnePair();
        vector<Card*> comb();

    private:
        Player* p;
        Table* t;
};

#endif