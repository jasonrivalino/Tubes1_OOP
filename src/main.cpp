
#include "class/SetGame/SetGame.hpp"
#include "class/Combination/Example/Combination.h"
#include "class/Combination/Example/StraightFlush.h"
//#include "class/Player/PlayerAction/PlayerAction.hpp"
//#include "class/Ability/AbilityCard.hpp"

using namespace std;

int main(){
    SetGame s(7);

    Table t;
    Card c1("M",1);
    Card c2("B",2);
    Card c3("H",3);
    Card c4("K",3);
    Card c5("H",4);
    Card c6("K",5);
    Card c7("B",6);

    t.addCard(c2);
    t.addCard(c4);
    t.addCard(c5);
    t.addCard(c6);
    t.addCard(c3);
//    t.addCard(c4);
//    t.addCard(c5);
    Player p("cek");
    p.addCard(c1);
    p.addCard(c7);



//    PlayerAction pA;
//
//    pA.reverseCard(p,s);

//    for(int i=0;i<s.getPlayers().size();i++){
//        cout<<s.getPlayers()[i]->getTurn()<<endl;
//    }
    // cout << "tes c\n";
    // cout << p.getCardsPlayer()[0]->getNameCard() << endl;
    // cout << p.getCardsPlayer()[1]->getNameCard() << endl;

    Combination *c= new StraightFlushh(p,t);

    vector<Card*> it=c->comb();

    cout<<it.size();
    for(int i=0;i<it.size();i++){
        cout<<it[0]->getNumberCard()<<endl;
    }
//     vector <Card*> v = c.isStraightFlush(p,t);
    // cout << c.isFourOfAKind(p,t)<<endl;
//    vector<Card*> itIs=c.isStraight(p,t);
//    for(int i=0;i<itIs.size();i++) cout <<itIs[i]->getNumberCard()  << endl;

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