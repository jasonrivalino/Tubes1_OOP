//
// Created by lenovo on 14/03/2023.
//

#ifndef TUBES1_OOP_NEXTACT_H
#define TUBES1_OOP_NEXTACT_H

#include "../Action.hpp"

class NextAct: public Action{
private:
    Player* p;
    SetGame* s;
public:
    NextAct(Player&,SetGame&);
    void Act();
};


#endif //TUBES1_OOP_NEXTACT_H
