#include "PlayerAction.hpp"

using namespace std;

PlayerAction::PlayerAction() {}
PlayerAction::~PlayerAction() {}

void PlayerAction::halfAct(Player &player, SetGame &pointGame){
    long pointBeforeAction = pointGame.getPointGame();
    if (pointBeforeAction != 1) {
    pointGame.setPoint(pointGame.getPointGame()/2);
    cout << &player << "melakukan HALF!" << "Poin hadiah turun dari " << pointBeforeAction << " menjadi " << pointGame.getPointGame() << endl;
    }
}

void PlayerAction::doubleAct(Player &player, SetGame &pointGame){
    long pointBeforeAction = pointGame.getPointGame();
    pointGame.setPoint(pointGame.getPointGame()*2);
    cout << &player << "melakukan DOUBLE!" << "Poin hadiah naik dari " << pointBeforeAction << " menjadi " << pointGame.getPointGame() << endl;
}

void PlayerAction::nextCard(){
    cout << "Giliran dilanjut ke pemain berikutnya" << endl;
}

void PlayerAction::reRoll(Player &p,SetGame &s){
    int idxPlayer=0;
    int idxCard=0;

    for(int i=0;i<s.getPlayers().size();i++){
        if(s.getPlayers()[i]->getTurn()==p.getTurn()) idxPlayer=i;
    }


    for(int i=0;i<s.getPlayers()[idxPlayer]->getCardsPlayer().size();i++){
        bool abilityP1 =
                s.getPlayers()[idxPlayer]->getCardsPlayer()[i]->getNameCard()!="M"&&
                s.getPlayers()[idxPlayer]->getCardsPlayer()[i]->getNameCard()!="B"&&
                s.getPlayers()[idxPlayer]->getCardsPlayer()[i]->getNameCard()!="K"&&
                s.getPlayers()[idxPlayer]->getCardsPlayer()[i]->getNameCard()!="H";

        if(abilityP1){
            idxCard=i;
        }
    }

    if(!(s.getPlayers()[idxPlayer]->getCardsPlayer()[idxCard]->getNameCard()=="ReRoll")){
        throw notHaveReRoll();
    }

    ReRoll r;

    r.ReRollEffect(p,s);
}

void PlayerAction::quadrupleCard(Player &p, SetGame &s){
    int idxPlayer=0;
    int idxCard=0;

    for(int i=0;i<s.getPlayers().size();i++){
        if(s.getPlayers()[i]->getTurn()==p.getTurn()) idxPlayer=i;
    }


    for(int i=0;i<s.getPlayers()[idxPlayer]->getCardsPlayer().size();i++){
        bool abilityP1 =
                s.getPlayers()[idxPlayer]->getCardsPlayer()[i]->getNameCard()!="M"&&
                s.getPlayers()[idxPlayer]->getCardsPlayer()[i]->getNameCard()!="B"&&
                s.getPlayers()[idxPlayer]->getCardsPlayer()[i]->getNameCard()!="K"&&
                s.getPlayers()[idxPlayer]->getCardsPlayer()[i]->getNameCard()!="H";

        if(abilityP1){
            idxCard=i;
        }
    }

    if(!(s.getPlayers()[idxPlayer]->getCardsPlayer()[idxCard]->getNameCard()=="Quadruple")){
        throw notHaveQuadrupleCard();
    }

    Quadruple q;

    q.QuadrupleEffect(p,s);
}

void PlayerAction::quarterCard(Player &p, SetGame &s){
    int idxPlayer=0;
    int idxCard=0;

    for(int i=0;i<s.getPlayers().size();i++){
        if(s.getPlayers()[i]->getTurn()==p.getTurn()) idxPlayer=i;
    }


    for(int i=0;i<s.getPlayers()[idxPlayer]->getCardsPlayer().size();i++){
        bool abilityP1 =
                s.getPlayers()[idxPlayer]->getCardsPlayer()[i]->getNameCard()!="M"&&
                s.getPlayers()[idxPlayer]->getCardsPlayer()[i]->getNameCard()!="B"&&
                s.getPlayers()[idxPlayer]->getCardsPlayer()[i]->getNameCard()!="K"&&
                s.getPlayers()[idxPlayer]->getCardsPlayer()[i]->getNameCard()!="H";

        if(abilityP1){
            idxCard=i;
        }
    }

    if(!(s.getPlayers()[idxPlayer]->getCardsPlayer()[idxCard]->getNameCard()=="Quarter")){
        throw notHaveQuarterCard();
    }

    Quarter q;

    q.QuarterEffect(p,s);
}

void PlayerAction::reverseCard(Player &p, SetGame &s) {
    int idxPlayer=0;
    int idxCard=0;

    for(int i=0;i<s.getPlayers().size();i++){
        if(s.getPlayers()[i]->getTurn()==p.getTurn()) idxPlayer=i;
    }


    for(int i=0;i<s.getPlayers()[idxPlayer]->getCardsPlayer().size();i++){
        bool abilityP1 =
                s.getPlayers()[idxPlayer]->getCardsPlayer()[i]->getNameCard()!="M"&&
                s.getPlayers()[idxPlayer]->getCardsPlayer()[i]->getNameCard()!="B"&&
                s.getPlayers()[idxPlayer]->getCardsPlayer()[i]->getNameCard()!="K"&&
                s.getPlayers()[idxPlayer]->getCardsPlayer()[i]->getNameCard()!="H";

        if(abilityP1){
            idxCard=i;
        }
    }

    if(!(s.getPlayers()[idxPlayer]->getCardsPlayer()[idxCard]->getNameCard()=="Reverse")){
        throw notHaveReverseCard();
    }



    ReverseDirection r;


    r.ReverseDirectionEffect(p,s);
}

void PlayerAction::swapCard(Player &p, SetGame &s) {
    int idxPlayer=0;
    int idxCard=0;

    for(int i=0;i<s.getPlayers().size();i++){
        if(s.getPlayers()[i]->getTurn()==p.getTurn()) idxPlayer=i;
    }


    for(int i=0;i<s.getPlayers()[idxPlayer]->getCardsPlayer().size();i++){
        bool abilityP1 =
                s.getPlayers()[idxPlayer]->getCardsPlayer()[i]->getNameCard()!="M"&&
                s.getPlayers()[idxPlayer]->getCardsPlayer()[i]->getNameCard()!="B"&&
                s.getPlayers()[idxPlayer]->getCardsPlayer()[i]->getNameCard()!="K"&&
                s.getPlayers()[idxPlayer]->getCardsPlayer()[i]->getNameCard()!="H";

        if(abilityP1){
            idxCard=i;
        }
    }

    if(!(s.getPlayers()[idxPlayer]->getCardsPlayer()[idxCard]->getNameCard()=="SwapCard")){
        throw notHaveSwapCard();
    }


    vector<Player*> allPlayers;
    int idxFirstPlayer,idxSecondPlayer;

    for(int i=0;i<s.getPlayers().size();i++){
        if(s.getPlayers()[i]->getTurn()!=p.getTurn()){
            allPlayers.push_back(s.getPlayers()[i]);
        }
    }



    cout<<"Player "<<p.getTurn()<<" melakukan Swap"<<endl;
    cout<<"Silahkan pilih pemain yang kartunya ingin anda tukar:"<<endl;
    for(int i=0;i<allPlayers.size();i++) cout<<i+1<<" Player "<<allPlayers[i]->getTurn()<<endl;

    cout<<">>";
    cin>>idxFirstPlayer;
    while(idxFirstPlayer>allPlayers.size()||idxFirstPlayer<1){
        cout<<"input anda salah"<<endl;
        cout<<">>";
        cin>>idxFirstPlayer;
    }

    Player *p1 = allPlayers[idxFirstPlayer-1];
    allPlayers.erase(allPlayers.begin()+(idxFirstPlayer-1));




    for(int i=0;i<s.getPlayers().size();i++){
        if(s.getPlayers()[i]->getTurn()!=p.getTurn()){
            allPlayers.push_back(s.getPlayers()[i]);
        }
    }

    cout<<"Silahkan pilih pemain yang kartunya ingin anda tukar:"<<endl;
    for(int i=0;i<allPlayers.size();i++) cout<<i+1<<" Player "<<allPlayers[i]->getTurn()<<endl;

    cout<<">>";
    cin>>idxSecondPlayer;
    while(idxSecondPlayer>allPlayers.size()||idxSecondPlayer<1){
        cout<<"input anda salah"<<endl;
        cout<<">>";
        cin>>idxSecondPlayer;
    }

    Player *p2 = allPlayers[idxSecondPlayer-1];
    allPlayers.erase(allPlayers.begin()+(idxSecondPlayer-1));

    SwapCard sW;
    sW.SwapCardEffect(p,*p1,*p2,idxFirstPlayer-1,idxSecondPlayer-1,s);

}

void PlayerAction::switchCard(Player &p, SetGame &s) {
    int idxPlayer=0;
    int idxCard=0;

    for(int i=0;i<s.getPlayers().size();i++){
        if(s.getPlayers()[i]->getTurn()==p.getTurn()) idxPlayer=i;
    }


    for(int i=0;i<s.getPlayers()[idxPlayer]->getCardsPlayer().size();i++){
        bool abilityP1 =
                s.getPlayers()[idxPlayer]->getCardsPlayer()[i]->getNameCard()!="M"&&
                s.getPlayers()[idxPlayer]->getCardsPlayer()[i]->getNameCard()!="B"&&
                s.getPlayers()[idxPlayer]->getCardsPlayer()[i]->getNameCard()!="K"&&
                s.getPlayers()[idxPlayer]->getCardsPlayer()[i]->getNameCard()!="H";

        if(abilityP1){
            idxCard=i;
        }
    }

    if(!(s.getPlayers()[idxPlayer]->getCardsPlayer()[idxCard]->getNameCard()=="SwitchCard")){
        throw notHaveSwitchCard();
    }

    vector<Player*> allPlayers;
    int idxFirstPlayer;

    for(int i=0;i<s.getPlayers().size();i++){
        if(s.getPlayers()[i]->getTurn()!=p.getTurn()){
            allPlayers.push_back(s.getPlayers()[i]);
        }
    }



    cout<<"Player "<<p.getTurn()<<" melakukan Swap"<<endl;
    cout<<"Silahkan pilih pemain yang kartunya ingin anda tukar:"<<endl;
    for(int i=0;i<allPlayers.size();i++) cout<<i+1<<" Player "<<allPlayers[i]->getTurn()<<endl;

    cout<<">>";
    cin>>idxFirstPlayer;
    while(idxFirstPlayer>allPlayers.size()||idxFirstPlayer<1){
        cout<<"input anda salah"<<endl;
        cout<<">>";
        cin>>idxFirstPlayer;
    }

    Player *p1 = allPlayers[idxFirstPlayer-1];
    allPlayers.erase(allPlayers.begin()+(idxFirstPlayer-1));

    Switch sW;
    sW.SwitchEffect(p,*p1,s);
}


