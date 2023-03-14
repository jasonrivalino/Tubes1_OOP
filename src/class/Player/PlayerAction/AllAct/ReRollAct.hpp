//
// Created by lenovo on 14/03/2023.
//

#ifndef TUBES1_OOP_REROLLACT_H
#define TUBES1_OOP_REROLLACT_H

#include "../Action.hpp"

class ReRollAct: public Action,public ReRoll{
private:
    Player* p;
    SetGame* s;
public:
    ReRollAct(Player&,SetGame&);
    void Act();
};


#endif //TUBES1_OOP_REROLLACT_H
