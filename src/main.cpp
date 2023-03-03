

#include "class/SetGame/SetGame.cpp"
#include "class/Combination/Combination.cpp"

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
    t.addCard( *new Card("K",1));
    t.addCard( *new Card("K",3));
    t.addCard( *new Card("K",2));
    t.addCard( *new Card("K",4));
    Player p("cek");
    p.addCard( *new Card("K",5));
    p.addCard( *new Card("M",6));

    Combination c;
    cout<<c.isStraightFlush(p,t)<<endl;


    return 0;
}