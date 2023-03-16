//
// Created by lenovo on 15/03/2023.
//

#ifndef TUBES1_OOP_STRAIGHTFLUSH_H
#define TUBES1_OOP_STRAIGHTFLUSH_H

#include "Combination.h"

class StraightFlushh: public Combination{
public:
    StraightFlushh(Player&,Table&);
    ~StraightFlushh();

    vector<Card*> comb();
private:
    Player* p;
    Table* t;
};


#endif //TUBES1_OOP_STRAIGHTFLUSH_H
