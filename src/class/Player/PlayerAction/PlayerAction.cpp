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
        if(*s.getPlayers()[i]==p) idxPlayer=i;
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

    if(!(s.getPlayers()[idxPlayer]->getCardsPlayer()[idxCard]->getNameCard()=="ReRoll")) throw notHaveReRoll();
    if(s.getPlayers()[idxPlayer]->getCardsPlayer()[idxCard]->getIsCardDeath()) throw reRollIsDeath();

    ReRoll r;

    r.ReRollEffect(p,s);
}

void PlayerAction::quadrupleCard(Player &p, SetGame &s){
    int idxPlayer=0;
    int idxCard=0;

    for(int i=0;i<s.getPlayers().size();i++){
        if(*s.getPlayers()[i]==p) idxPlayer=i;
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

    if(!(s.getPlayers()[idxPlayer]->getCardsPlayer()[idxCard]->getNameCard()=="Quadruple")) throw notHaveQuadrupleCard();
    if(s.getPlayers()[idxPlayer]->getCardsPlayer()[idxCard]->getIsCardDeath()) throw quadrupleIsDeath();

    Quadruple q;

    q.QuadrupleEffect(p,s);
}

void PlayerAction::quarterCard(Player &p, SetGame &s){
    int idxPlayer=0;
    int idxCard=0;

    for(int i=0;i<s.getPlayers().size();i++){
        if(*s.getPlayers()[i]==p) idxPlayer=i;
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

    if(!(s.getPlayers()[idxPlayer]->getCardsPlayer()[idxCard]->getNameCard()=="Quarter")) throw notHaveQuarterCard();
    if(s.getPlayers()[idxPlayer]->getCardsPlayer()[idxCard]->getIsCardDeath()) throw quarterIsDeath();

    Quarter q;

    q.QuarterEffect(p,s);
}

void PlayerAction::reverseCard(Player &p, SetGame &s) {
    int idxPlayer=0;
    int idxCard=0;

    for(int i=0;i<s.getPlayers().size();i++){
        if(*s.getPlayers()[i]==p) idxPlayer=i;
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

    if(!(s.getPlayers()[idxPlayer]->getCardsPlayer()[idxCard]->getNameCard()=="Reverse")) throw notHaveReverseCard();
    if(s.getPlayers()[idxPlayer]->getCardsPlayer()[idxCard]->getIsCardDeath()) throw reverseIsDeath();


    ReverseDirection r;


    r.ReverseDirectionEffect(p,s);
}


//print akhirnya blm
void PlayerAction::swapCard(Player &p, SetGame &s) {
    int idxPlayer=0;
    int idxCard=0;
    int rightOrLeft1,rightOrLeft2=0;

    for(int i=0;i<s.getPlayers().size();i++){
        if(*s.getPlayers()[i]==p) idxPlayer=i;
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

    if(!(s.getPlayers()[idxPlayer]->getCardsPlayer()[idxCard]->getNameCard()=="SwapCard")) throw notHaveSwapCard();
    if(s.getPlayers()[idxPlayer]->getCardsPlayer()[idxCard]->getIsCardDeath()) throw swapIsDeath();

    vector<Player*> allPlayers;
    int idxFirstPlayer,idxSecondPlayer;

    for(int i=0;i<s.getPlayers().size();i++){
        if(*s.getPlayers()[i]!=p){
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

    cout<<"Pilih kartu: \n1.kiri\n2.kanan"<<endl;
    cout<<">>";
    cin>>rightOrLeft1;
    while (rightOrLeft1>2||rightOrLeft1<1){
        cout<<"input salah"<<endl;
        cout<<">>";
        cin>>rightOrLeft1;
    }

    Player *p1 = allPlayers[idxFirstPlayer-1];
    allPlayers.erase(allPlayers.begin()+(idxFirstPlayer-1));





    cout<<"Silahkan pilih pemain yang kartunya ingin anda tukar:"<<endl;
    for(int i=0;i<allPlayers.size();i++) cout<<i+1<<" Player "<<allPlayers[i]->getTurn()<<endl;

    cout<<">>";
    cin>>idxSecondPlayer;
    while(idxSecondPlayer>allPlayers.size()||idxSecondPlayer<1){
        cout<<"input anda salah"<<endl;
        cout<<">>";
        cin>>idxSecondPlayer;
    }

    cout<<"Pilih kartu: \n1.kiri\n2.kanan"<<endl;
    cout<<">>";
    cin>>rightOrLeft2;
    while (rightOrLeft2>2||rightOrLeft2<1){
        cout<<"input salah"<<endl;
        cout<<">>";
        cin>>rightOrLeft2;
    }

    Player *p2 = allPlayers[idxSecondPlayer-1];
    allPlayers.erase(allPlayers.begin()+(idxSecondPlayer-1));

    SwapCard sW;
    sW.SwapCardEffect(p,*p1,*p2,rightOrLeft1-1,rightOrLeft2-1,s);

}


//print akhirnya belum
void PlayerAction::switchCard(Player &p, SetGame &s) {
    int idxPlayer=0;
    int idxCard=0;

    for(int i=0;i<s.getPlayers().size();i++){
        if(*s.getPlayers()[i]==p) idxPlayer=i;
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

    if(!(s.getPlayers()[idxPlayer]->getCardsPlayer()[idxCard]->getNameCard()=="SwitchCard")) throw notHaveSwitchCard();
    if(s.getPlayers()[idxPlayer]->getCardsPlayer()[idxCard]->getIsCardDeath()) throw switchIsDeath();


    vector<Player*> allPlayers;
    int idxFirstPlayer;

    for(int i=0;i<s.getPlayers().size();i++){
        if(*s.getPlayers()[i]!=p){
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

void PlayerAction::abilityLessCard(Player &p, SetGame &s) {
    int idxPlayer=0;
    int idxCard=0;

    for(int i=0;i<s.getPlayers().size();i++){
        if(*s.getPlayers()[i]==p) idxPlayer=i;
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

    if(!(s.getPlayers()[idxPlayer]->getCardsPlayer()[idxCard]->getNameCard()=="AbilityLessCard")) throw notHaveAbilityCard();


    bool isAllUsed= true;
    for(int j=0;j< s.getPlayers().size();j++) {
        if(*s.getPlayers()[j]!=p) {
            for (int i = 0; i < s.getPlayers()[j]->getCardsPlayer().size(); i++) {
                bool abilityP1 =
                        s.getPlayers()[j]->getCardsPlayer()[i]->getNameCard() != "M" &&
                        s.getPlayers()[j]->getCardsPlayer()[i]->getNameCard() != "B" &&
                        s.getPlayers()[j]->getCardsPlayer()[i]->getNameCard() != "K" &&
                        s.getPlayers()[j]->getCardsPlayer()[i]->getNameCard() != "H";

                if (abilityP1) {
                    if((!s.getPlayers()[j]->getCardsPlayer()[i]->getIsCardUsed())) {
                        isAllUsed = false;
                    }
                }
            }
        }
    }


    if(isAllUsed){
        throw allCardUsed();
    }else{
        cout<<"Player "<<p.getTurn()<<" melakukan AbilityLess"<<endl;
        cout<<"silakan pilih pemain yang ingin dimatikan ability card-nya"<<endl;
        vector<Player*> allPlayers;
        int idxFirstPlayer;

        for(int i=0;i<s.getPlayers().size();i++){
            if(*s.getPlayers()[i]!=p){
                allPlayers.push_back(s.getPlayers()[i]);
            }
        }


        for(int i=0;i<allPlayers.size();i++) cout<<i+1<<" Player "<<allPlayers[i]->getTurn()<<endl;

        cout<<">>";
        cin>>idxFirstPlayer;
        while(idxFirstPlayer>allPlayers.size()||idxFirstPlayer<1){
            cout<<"input anda salah"<<endl;
            cout<<">>";
            cin>>idxFirstPlayer;
        }

        Player *p1 = allPlayers[idxFirstPlayer-1];

        Abilityless aB;
        try {
            aB.AbilitylessEffect(s, p, *p1);
        }catch (playerCardUsed e){
            cout<<e.what()<<endl;
        }
    }
}


