//
// Created by lenovo on 14/03/2023.
//

#ifndef TUBES1_OOP_REVERSEACT_HPP
#define TUBES1_OOP_REVERSEACT_HPP

#include "../Action.hpp"

class ReverseAct: public Action,public ReverseDirection{
private:
    Player* p;
    SetGame* s;
public:
    ReverseAct(Player&,SetGame&);
    void Act();
};


#endif //TUBES1_OOP_REVERSEACT_HPP
