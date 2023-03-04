
#include "class/SetGame/SetGame.hpp"
#include "class/Combination/Combination.hpp"
#include "class/Ability/AbilityCard.hpp"

using namespace std;

int main(){
    SetGame s(7);

    Table t;
    Card c1("B",6);
    Card c2("B",3);
    Card c3("B",2);
    Card c4("B",4);
    Card c5("B",5);
    Card c6("B",7);
    Card c7("B",1);

    t.addCard(c1);
    t.addCard(c2);
    t.addCard(c3);
    t.addCard(c4);
    t.addCard(c5);
    Player p("cek");
    p.addCard( c7);
    p.addCard( c6);

    Combination c;
    cout<<c.isStraightFlush(p,t)<<" pppppp"<<endl;

    return 0;
}