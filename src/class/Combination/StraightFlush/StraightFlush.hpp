#include "./../Combination.hpp"

#ifndef STRAIGHTFLUSH_HPP
#define STRAIGHTFLUSH_HPP

class StraightFlush : public Combination{
    private:
    Player* p;
    Table* t; 
    public:
        StraightFlush(Player &player, Table &tableCard);
        ~StraightFlush();
        vector<Card*> comb();
};

#endif