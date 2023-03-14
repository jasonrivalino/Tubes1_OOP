//
// Created by lenovo on 14/03/2023.
//

#ifndef TUBES1_OOP_ABILITYLESSACT_HPP
#define TUBES1_OOP_ABILITYLESSACT_HPP

#include "../Action.hpp"


class AbilityLessAct: public Action,public Abilityless{
private:
    Player* p;
    SetGame* s;
public:
    AbilityLessAct(Player&,SetGame&);
    void Act();
};


#endif //TUBES1_OOP_ABILITYLESSACT_HPP
