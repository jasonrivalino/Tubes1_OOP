#include "../Player/Player.hpp"
#include "../Table/Table.hpp"
#include "../Card/Card.hpp"
#include <iostream>

#ifndef COMBINATION_HPP
#define COMBINATION_HPP

using namespace std;

class Combination
{
public:
    Combination(/* args */);
    ~Combination();
    virtual vector<Card*> comb();

};
#endif