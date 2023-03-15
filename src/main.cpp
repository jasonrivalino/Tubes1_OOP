
#include "class/SetGame/SetGame.hpp"
#include "class/Combination/Combination.hpp"
#include "class/Player/PlayerAction/Action.hpp"
#include "class/Player/PlayerAction/AllAct/SwapAct.hpp"
#include "class/Player/PlayerAction/AllAct/ReverseAct.hpp"
#include "class/Player/PlayerAction/AllAct/QuadrupleAct.hpp"
#include "class/Player/PlayerAction/AllAct/QuarterAct.hpp"
#include "class/Player/PlayerAction/AllAct/SwitchAct.hpp"
#include "class/Player/PlayerAction/AllAct/ReRollAct.hpp"
#include "class/Player/PlayerAction/AllAct/AbilityLessAct.hpp"
#include "class/Ability/AbilityCard.hpp"

using namespace std;

int main(){
    SetGame s(7);
    s.shareCardToPlayer(2);
    s.shareAbilityCard();

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

    cout<<s.getPlayers()[0]->getAbility()[0]->getNameCard()<<endl;
    cout<<s.getPlayers()[1]->getAbility()[0]->getNameCard()<<endl;
    cout<<s.getPlayers()[2]->getAbility()[0]->getNameCard()<<endl;
    cout<<s.getPlayers()[3]->getAbility()[0]->getNameCard()<<endl;
    cout<<s.getPlayers()[4]->getAbility()[0]->getNameCard()<<endl;
    cout<<s.getPlayers()[5]->getAbility()[0]->getNameCard()<<endl;
    cout<<s.getPlayers()[6]->getAbility()[0]->getNameCard()<<endl;

    Action *action = new QuarterAct(*s.getPlayers()[6],s);

    try {

//        pA.switchCard(*s.getPlayers()[5], s);
    action->Act();

    }catch (notHaveQuarterCard e){
        cout<<e.what()<<endl;
    }
    cout<<s.getPlayers()[0]->getAbility()[0]->getIsCardUsed()<<endl;
    cout<<s.getPlayers()[1]->getAbility()[0]->getIsCardUsed()<<endl;
    cout<<s.getPlayers()[2]->getAbility()[0]->getIsCardUsed()<<endl;
    cout<<s.getPlayers()[3]->getAbility()[0]->getIsCardUsed()<<endl;
    cout<<s.getPlayers()[4]->getAbility()[0]->getIsCardUsed()<<endl;
    cout<<s.getPlayers()[5]->getAbility()[0]->getIsCardUsed()<<endl;
    cout<<s.getPlayers()[6]->getAbility()[0]->getIsCardUsed()<<endl;


//    for(int i=0;i<s.getPlayers().size();i++){
//        cout<<s.getPlayers()[i]->getTurn()<<endl;
//    }
    // cout << "tes c\n";
    // cout << p.getCardsPlayer()[0]->getNameCard() << endl;
    // cout << p.getCardsPlayer()[1]->getNameCard() << endl;

    Combination c;
    // vector <Card*> v = c.isStraightFlush(p,t);
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