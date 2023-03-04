
#include "class/SetGame/SetGame.hpp"
#include "class/Combination/Combination.hpp"
#include "class/Ability/AbilityCard.hpp"

using namespace std;

int main(){
    SetGame s(7);

    Table t;
    Card c1("K",1);
    Card c2("B",3);
    Card c3("K",2);
    Card c4("M",3);
    Card c5("K",8);
    Card c6("H",3);
    Card c7("K",8);

    t.addCard(c1);
    t.addCard(c2);
    t.addCard(c3);
    t.addCard(c4);
    t.addCard(c5);
    Player p("cek");
    p.addCard( c7);
    p.addCard( c6);

    Combination c;
    cout<<c.isStraightFlush(p,t)<<endl;

    return 0;
}