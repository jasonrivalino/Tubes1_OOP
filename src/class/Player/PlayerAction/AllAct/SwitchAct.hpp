//
// Created by lenovo on 14/03/2023.
//

#ifndef TUBES1_OOP_SWITCHACT_H
#define TUBES1_OOP_SWITCHACT_H

#include "../Action.hpp"

class SwitchAct: public Action,public Switch{
private:
    Player* p;
    SetGame* s;
public:
    SwitchAct(Player&,SetGame&);
    void Act();
};


#endif //TUBES1_OOP_SWITCHACT_H
