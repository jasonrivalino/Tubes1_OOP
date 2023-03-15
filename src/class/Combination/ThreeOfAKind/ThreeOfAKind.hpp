#ifndef THREEOFAKIND_HPP
#define THREEOFAKIND_HPP

#include "./../Combination.hpp"


class ThreeOfAKind : public Combination{
    public: 
        ThreeOfAKind(Player &player, Table &tableCard);
        ~ThreeOfAKind();
        vector<Card*> comb();
    private:
        Player* p;
        Table* t;
};

#endif