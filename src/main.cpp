

#include "class/SetGame/SetGame.hpp"
#include "class/Combination/Combination.hpp"

using namespace std;

int main(){
    SetGame s(7);
//    s.printCards();
// //    cout<<"=========="<<endl;
//     s.shareCardToPlayer(2);
//     ReRoll r;
// //    r.ReRollEffect(*s.getPlayers()[1],s);
// //    cout<<"=========="<<endl;
// //    s.printCards();
//     s.getPlayers()[0]->removeBackCard();
//     s.shareAbilityCard();
//     for(int i=0;i<7;i++){
//         s.getPlayers()[i]->printCards();
//         cout<<"=================="<<endl;
//     }

    Table t;
    Card c1("K",1);
    Card c2("K",3);
    Card c3("K",2);
    Card c4("K",4);
    Card c5("K",5);
    Card c6("K",7);
    Card c7("B",6);

    t.addCard(c1);
    t.addCard(c2);
    t.addCard(c3);
    t.addCard(c4);
    t.addCard(c5);
    Player p("cek");
    p.addCard( c7);
    p.addCard( c6);

    Combination c;
    vector <Card*> ccd;
    cout<<c.isStraightFlush(p,t)<<endl;


    return 0;
}