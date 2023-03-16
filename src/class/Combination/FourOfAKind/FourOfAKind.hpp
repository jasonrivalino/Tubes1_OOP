#ifndef FOUR_OF_A_KIND_HPP
#define FOUR_OF_A_KIND_HPP
#include "./../Combination.hpp"



class FourOfAKind : public Combination{
    private:
        Player* p;
        Table* t; 
    
    public: 
        FourOfAKind(Player&, Table&);
        ~FourOfAKind();
        
        int combFourOfAKind();
};

#endif