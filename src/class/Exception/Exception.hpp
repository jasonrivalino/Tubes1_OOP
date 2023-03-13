//
// Created by lenovo on 13/03/2023.
//

#ifndef TUBES1_OOP_EXCEPTION_H
#define TUBES1_OOP_EXCEPTION_H
#include <exception>

using namespace std;

struct notHaveReRoll: public exception{
    const char* const what() throw(){
        return "Kamu tidak memiliki ReRollCard";
    }
};
struct notHaveQuadrupleCard: public exception{
    const char* const what() throw(){
        return "Kamu tidak memiliki QuadrupleCard";
    }
};
struct notHaveQuarterCard: public exception{
    const char* const what() throw(){
        return "Kamu tidak memiliki QuarterCard";
    }
};
struct notHaveReverseCard: public exception{
    const char* const what() throw(){
        return "Kamu tidak memiliki ReverseCard";
    }
};
struct notHaveSwapCard: public exception{
    const char* const what() throw(){
        return "Kamu tidak memiliki SwapCard";
    }
};
struct notHaveSwitchCard: public exception{
    const char* const what() throw(){
        return "Kamu tidak memiliki SwitchCard";
    }
};
struct notHaveAbilityCard: public exception{
    const char* const what() throw(){
        return "Kamu tidak memiliki AbilityCard";
    }
};



struct reRollIsDeath: public exception{
    const char* const what() throw(){
        return "ReRollCard kamu dimatikan oleh seseorang";
    }
};
struct quadrupleIsDeath: public exception{
    const char* const what() throw(){
        return "QuadrupleCard kamu dimatikan oleh seseorang";
    }
};
struct quarterIsDeath: public exception{
    const char* const what() throw(){
        return "QuarterCard kamu dimatikan oleh seseorang";
    }
};
struct reverseIsDeath: public exception{
    const char* const what() throw(){
        return "ReverseCard kamu dimatikan oleh seseorang";
    }
};
struct swapIsDeath: public exception{
    const char* const what() throw(){
        return "SwapCard kamu dimatikan oleh seseorang";
    }
};
struct switchIsDeath: public exception{
    const char* const what() throw(){
        return "SwitchCard kamu dimatikan oleh seseorang";
    }
};

struct allCardUsed: public exception{
    const char* const what() throw(){
        return "Semua kartu ability pemain sudah digunakan";
    }
};

#endif //TUBES1_OOP_EXCEPTION_H
