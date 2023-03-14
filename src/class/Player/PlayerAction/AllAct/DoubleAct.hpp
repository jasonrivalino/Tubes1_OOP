//
// Created by lenovo on 14/03/2023.
//

#ifndef TUBES1_OOP_DOUBLEACT_H
#define TUBES1_OOP_DOUBLEACT_H

#include "../Action.hpp"


class DoubleAct: public Action{
private:
    Player* p;
    SetGame* s;
public:
    DoubleAct(Player&,SetGame&);
    void Act();
};


#endif //TUBES1_OOP_DOUBLEACT_H
