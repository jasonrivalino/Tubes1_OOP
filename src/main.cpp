#include "class/setGame/SetGame.hpp"

using namespace std;

int main(){
    SetGame s(7);
//    s.printCards();
//    cout<<"=========="<<endl;
    s.shareCardToPlayer(2);
//    s.getPlayers()[0].printCards();
//    cout<<"=========="<<endl;
//    s.printCards();
    s.shareAbilityCard();
    for(int i=0;i<7;i++){
        s.getPlayers()[i].printCards();
        cout<<"=================="<<endl;
    }
    return 0;
}