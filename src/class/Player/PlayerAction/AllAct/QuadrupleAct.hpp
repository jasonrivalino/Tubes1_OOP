//
// Created by lenovo on 14/03/2023.
//

#ifndef TUBES1_OOP_QUADRUPLEACT_H
#define TUBES1_OOP_QUADRUPLEACT_H

#include "../Action.hpp"

class QuadrupleAct: public Action,public Quadruple{
private:
    Player* p;
    SetGame* s;
public:
    QuadrupleAct(Player&,SetGame&);
    void Act();
};


#endif //TUBES1_OOP_QUADRUPLEACT_H
