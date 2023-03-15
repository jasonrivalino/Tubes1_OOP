//
// Created by lenovo on 14/03/2023.
//

#ifndef TUBES1_OOP_SWAPACT_HPP
#define TUBES1_OOP_SWAPACT_HPP

#include "../Action.hpp"

class SwapAct: public Action,public SwapCard{
private:
    Player* p;
    SetGame* s;
public:
    SwapAct(Player&,SetGame&);
    void Act();
};


#endif //TUBES1_OOP_SWAPACT_HPP
