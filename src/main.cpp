
#include "class/SetGame/SetGame.hpp"
#include "class/Combination/Combination.hpp"
#include "class/Player/PlayerAction/PlayerAction.hpp"
#include "class/Ability/AbilityCard.hpp"

using namespace std;

int main(){

    string path = "";
    cout << "Apakah ingin menggunakan file kartu dari txt ?(Y/N) ";
    char c;
    cin >> c;
    while(c != 'Y' and c != 'y' and c != 'N' and c != 'n'){
        cout << "Inputan tidak valid\nApakah ingin menggunakan file kartu dari txt ?(Y/N) ";
        cin >> c;
    }
    if(c == 'Y' or c == 'y') path = "./config/card.txt";
    else if(c == 'N' or c == 'n') path = "";

    // buat pathnya belom
    SetGame s(7,path);
    s.shareCardToPlayer(2);
    s.shareAbilityCard();

    Table t;
    Card c1("M",6);
    Card c2("K",8);
    Card c3("B",8);
    Card c4("M",8);
    Card c5("M",10);
    Card c6("H",8);
    Card c7("B",6);

    t.addCard(c2);
    t.addCard(c4);
    t.addCard(c5);
    t.addCard(c1);
    t.addCard(c3);
    Player p("cek");
    p.addCard(c6);
    p.addCard(c7);

//    for(int i=0;i<s.getPlayers().size();i++){
//        cout<<s.getPlayers()[i]->getTurn()<<endl;
//    }
//     // cout << "tes c\n";
//     // cout << p.getCardsPlayer()[0]->getNameCard() << endl;
//     // cout << p.getCardsPlayer()[1]->getNameCard() << endl;

    Combination comb;

    // cout << comb.isFourOfAKind(p,t) << endl;

    vector <Card*> v = comb.isOnePair(p,t);
    if(v.size() == 0) cout << "gaaada isinya\n";
    else{
        for(auto x : v) {
            cout << x->getNameCard() << "   " << x->getNumberCard() << endl;
            // cout << x->getNameCard() << endl;
            // cout << x->getNumberCard() << endl;
        }
    }
























    // cout << comb.isFourOfAKind(p,t)<<endl;

    // cout << c.isFlush(p,t) << endl;
    // cout << "v size : " << v.size() << endl;
    // cout << v[4]->getNumberCard() << endl;
    // cout << v[4]->getNameCard() << endl;


//     PlayerAction pA;

//     cout << s.getPlayers()[0]->getCardsPlayer()[2]->getNameCard()<<endl;
// try{
//     pA.swapCard(*s.getPlayers()[0],s);
// }catch(notHaveReRoll e){
//     cout<<e.what()<<endl;
// }


//     return 0;
}