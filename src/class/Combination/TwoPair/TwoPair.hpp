#ifndef TWOPAIR_HPP
#define TWOPAIR_HPP
#include "./../Combination.hpp"

class TwoPair : public Combination {
    public:
        TwoPair(Player &p, Table &t);
        ~TwoPair();
        vector<Card*> combTwoPair();
    private:
    Player* p;
    Table* t;

};

#endif