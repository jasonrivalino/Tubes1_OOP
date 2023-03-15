#ifndef FLUSH_HPP
#define FLUSH_HPP

#include "./../Combination.hpp"

class Flush : public Combination {
    public :
        Flush(Player&, Table&);
        ~Flush();

        vector<Card*> comb();

    private:
        Player* p;
        Table* t;
};

#endif