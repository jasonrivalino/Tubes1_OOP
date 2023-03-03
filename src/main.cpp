

#include "class/setGame/SetGame.hpp"

using namespace std;

int main(){
    SetGame s(7);
//    s.printCards();
//    cout<<"=========="<<endl;
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
    for(int i=0;i<s.getPlayers().size();i++){
        cout<<s.getPlayers()[i]->getTurn()<<endl;
    }
    ReverseDirection r;
    r.ReverseDirectionEffect(s);
    for(int i=0;i<s.getPlayers().size();i++){
        cout<<s.getPlayers()[i]->getTurn()<<endl;
    }
    return 0;
}