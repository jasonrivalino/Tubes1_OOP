
#include "class/SetGame/SetGame.hpp"
#include "class/Combination/Combination.hpp"
#include "class/Ability/AbilityCard.hpp"

using namespace std;

int main(){
    SetGame s(7);

    Table t;
    Card c1("A",1);
    Card c2("A",2);
    Card c3("A",3);
    Card c4("A",4);
    Card c5("A",5);
    Card c6("A",6);
    Card c7("A",7);

    t.addCard(c1);
    t.addCard(c4);
    t.addCard(c5);
    t.addCard(c6);
    t.addCard(c7);
//    t.addCard(c4);
//    t.addCard(c5);
    Player p("cek");
    p.addCard(c2);
    p.addCard(c3);


    // cout << "tes c\n";
    // cout << p.getCardsPlayer()[0]->getNameCard() << endl;
    // cout << p.getCardsPlayer()[1]->getNameCard() << endl;

    Combination c;
    // vector <Card*> v = c.isStraightFlush(p,t);
    // cout << c.isFourOfAKind(p,t)<<endl;
    cout << c.isStraight(p,t) << endl;
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