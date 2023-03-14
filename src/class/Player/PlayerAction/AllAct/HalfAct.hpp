//
// Created by lenovo on 14/03/2023.
//

#ifndef TUBES1_OOP_HALFACT_H
#define TUBES1_OOP_HALFACT_H

#include "../Action.hpp"


class HalfAct: public Action{
private:
    Player* p;
    SetGame* s;
public:
    HalfAct(Player&,SetGame&);
    void Act();
};


#endif //TUBES1_OOP_HALFACT_H
