
#include "class/SetGame/SetGame.hpp"
#include "class/Combination/Combination.hpp"
#include "class/Ability/AbilityCard.hpp"

using namespace std;

int main(){
    SetGame s(7);

    Table t;
    Card c1("M",5);
    Card c2("B",5);
    Card c3("H",5);
    Card c4("K",6);
    Card c5("H",6);
    Card c6("K",3);
    Card c7("B",1);

    t.addCard(c1);
    t.addCard(c2);
    t.addCard(c3);
    t.addCard(c4);
    t.addCard(c5);
    Player p("cek");
    p.addCard(c7);
    p.addCard(c6);

    // cout << "tes c\n";
    // cout << p.getCardsPlayer()[0]->getNameCard() << endl;
    // cout << p.getCardsPlayer()[1]->getNameCard() << endl;

    Combination c;
    // vector <Card*> v = c.isStraightFlush(p,t);
    // cout << c.isFourOfAKind(p,t)<<endl;
    cout << c.isFullHouse(p,t) << endl;
    // cout << c.isFlush(p,t) << endl;
    // cout << "v size : " << v.size() << endl;
    // cout << v[4]->getNumberCard() << endl;
    // cout << v[4]->getNameCard() << endl;
    // for(auto x : v) {
    //     cout << x->getNameCard() << "   " << x->getNumberCard() << endl;
    //     // cout << x->getNameCard() << endl;
    //     // cout << x->getNumberCard() << endl;
    // }

    return 0;
}