
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
    cout<<c.isFullHouse(p,t)<<endl;


    // for(int i=0;i<s.getPlayers().size();i++){
    //     cout<<s.getPlayers()[i]->getTurn()<<endl;
    // }
    // ReverseDirection r;
    // r.ReverseDirectionEffect(s);
    // for(int i=0;i<s.getPlayers().size();i++){
    //     cout<<s.getPlayers()[i]->getTurn()<<endl;
    // }
    return 0;
}