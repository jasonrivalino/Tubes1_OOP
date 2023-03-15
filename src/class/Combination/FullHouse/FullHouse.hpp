#ifndef FULLHOUSE_HPP
#define FULLHOUSE_HPP

#include "./../Combination.cpp"

class FullHouse : public Combination{
    private:
    Player* p;
    Table* t;
    public:
        FullHouse(Player&, Table&);
        FullHouse();
        vector<Card*> combFullHouse();
};

#endif