
#include "class/Ability/AbilityCard.cpp"
#include "class/Card/Card.cpp"
#include "class/Player/Player.cpp"
#include "class/Player/PlayerAction/PlayerAction.cpp"
#include "class/SetGame/SetGame.cpp"

using namespace std;

int main(){
    // SetGame s(7,"");
    SetGame s(7,"../test/tes.txt");
   s.printCards();
//    cout<<"=========="<<endl;
    s.shareCardToPlayer(2);
    // ReRoll r;
//    r.ReRollEffect(*s.getPlayers()[1],s);
   cout<<"=========="<<endl<<endl;
   s.printCards();
    // s.getPlayers()[0]->removeBackCard();
    s.shareAbilityCard();
    // for(int i=0;i<7;i++){
    //     s.getPlayers()[i]->printCards();
    //     cout<<"=================="<<endl;
    // }
    return 0;
}