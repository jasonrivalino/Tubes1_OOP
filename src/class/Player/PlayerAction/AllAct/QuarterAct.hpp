//
// Created by lenovo on 14/03/2023.
//

#ifndef TUBES1_OOP_QUARTERACT_HPP
#define TUBES1_OOP_QUARTERACT_HPP

#include "../Action.hpp"

class QuarterAct: public Action,public Quarter{
private:
    Player* p;
    SetGame* s;
public:
    QuarterAct(Player&,SetGame&);
    void Act();
};


#endif //TUBES1_OOP_QUARTERACT_HPP
