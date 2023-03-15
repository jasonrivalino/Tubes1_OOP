#ifndef STRAIGHT_HPP
#define STRAIGHT_HPP
#include "./../Combination.hpp"


class Straight : public Combination{
    public: 
        Straight(Player &player, Table &tableCard);
        ~Straight();
        vector<Card*> combStraight();
    private:
        Player* p;
        Table* t;
};

#endif