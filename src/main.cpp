
#include "class/SetGame/SetGame.hpp"
#include "class/Combination/Combination.hpp"
#include "class/Player/PlayerAction/Action.hpp"
#include "class/Player/PlayerAction/AllAct/SwapAct.hpp"
#include "class/Player/PlayerAction/AllAct/NextAct.hpp"
#include "class/Player/PlayerAction/AllAct/DoubleAct.hpp"
#include "class/Player/PlayerAction/AllAct/HalfAct.hpp"
#include "class/Player/PlayerAction/AllAct/ReverseAct.hpp"
#include "class/Player/PlayerAction/AllAct/QuadrupleAct.hpp"
#include "class/Player/PlayerAction/AllAct/QuarterAct.hpp"
#include "class/Player/PlayerAction/AllAct/SwitchAct.hpp"
#include "class/Player/PlayerAction/AllAct/ReRollAct.hpp"
#include "class/Player/PlayerAction/AllAct/AbilityLessAct.hpp"
#include "class/Splash/Splash.hpp"
#include "class/Ability/AbilityCard.hpp"

using namespace std;

int actChoose(){
    int choose;
    cout<<"Silakan pilih aksi"<<endl;
    cout<<"1.  Next\n2.  Double\n3.  Half\n4.  Quarter\n5.  Quadruple\n6.  ReRoll\n7.  Reverse\n8.  Switch\n9.  Swap\n10. AbilityLess"<<endl;
    cout<<">>";
    cin>>choose;
    while (choose<1||choose>>10){
        cout<<"input salah, silakan ulang"<<endl;
        cout<<">>";
        cin>>choose;
    }
    return choose;
}


int main(){
    Splash splash;
    Table table;
    Player* playerCurrentTurn;
    Action* action;
    int playerTurn=1;
    int fileSourceCardChoose;

    splash.SplashOpening();

    cout<<"Apakah anda ingin kartu diacak sesuai card.txt:"<<endl;
    cout<<"1. Ya\n2. Tidak"<<endl;
    cout<<">>";
    cin>>fileSourceCardChoose;

    while (fileSourceCardChoose>2||fileSourceCardChoose<1){
        cout<<"input salah"<<endl;
        cout<<">>";
        cin>>fileSourceCardChoose;
    }




    SetGame game(7,fileSourceCardChoose);

    while (game.getRound()<7){
        cout<<"Ronde ke-"<<game.getRound()<<endl;
        while (playerTurn<8){

            playerCurrentTurn = game.playerTurn();
            cout<<"Player ke-"<<playerCurrentTurn->getTurn()<<endl;
            int choose = actChoose();

            bool rightChoose = false;
            while (!rightChoose) {
                switch (choose) {
                    case 1:
                        action = new NextAct(*playerCurrentTurn, game);
                        action->Act();
                        rightChoose = true;
                        break;
                    case 2:
                        action = new DoubleAct(*playerCurrentTurn, game);
                        action->Act();
                        rightChoose = true;
                        game.nextTurn();
                        break;
                    case 3:
                        action = new HalfAct(*playerCurrentTurn, game);
                        action->Act();
                        rightChoose = true;
                        game.nextTurn();
                        break;
                    case 4:
                        action = new QuarterAct(*playerCurrentTurn, game);

                        try {
                            action->Act();
                            cout<<"teset"<<endl;
                            rightChoose = true;
                            game.nextTurn();
                        } catch (notHaveQuarterCard e) {
                            cout << e.what() << endl;
                        } catch (quarterIsDeath e) {
                            cout << e.what() << endl;
                        }
                        break;
                    case 5:
                        action = new QuadrupleAct(*playerCurrentTurn, game);
                        try {
                            action->Act();
                            rightChoose = true;
                            game.nextTurn();
                        } catch (notHaveQuadrupleCard e) {
                            cout << e.what() << endl;
                        } catch (quadrupleIsDeath e) {
                            cout << e.what() << endl;
                        }
                        break;
                    case 6:
                        action = new ReRollAct(*playerCurrentTurn, game);
                        try {
                            action->Act();
                            rightChoose = true;
                            game.nextTurn();
                        } catch (notHaveReRollCard e) {
                            cout << e.what() << endl;
                        } catch (reRollIsDeath e) {
                            cout << e.what() << endl;
                        }
                        break;
                    case 7:
                        action = new ReverseAct(*playerCurrentTurn, game);
                        try {
                            action->Act();
                            rightChoose = true;
                            game.nextTurn();
                        } catch (notHaveReverseCard e) {
                            cout << e.what() << endl;
                        } catch (reverseIsDeath e) {
                            cout << e.what() << endl;
                        }
                        break;
                    case 8:
                        action = new SwitchAct(*playerCurrentTurn, game);
                        try {
                            action->Act();
                            rightChoose = true;
                            game.nextTurn();
                        } catch (notHaveSwitchCard e) {
                            cout << e.what() << endl;
                        } catch (switchIsDeath e) {
                            cout << e.what() << endl;
                        }
                        break;
                    case 9:
                        action = new SwapAct(*playerCurrentTurn, game);
                        try {
                            action->Act();
                            rightChoose = true;
                            game.nextTurn();
                        } catch (notHaveSwapCard e) {
                            cout << e.what() << endl;
                        } catch (swapIsDeath e) {
                            cout << e.what() << endl;
                        }
                        break;
                    case 10:
                        action = new AbilityLessAct(*playerCurrentTurn, game);
                        try {
                            action->Act();
                            rightChoose = true;
                            game.nextTurn();
                        } catch (notHaveAbilityCard e) {
                            cout << e.what() << endl;
                        } catch (allCardUsed e){
                            cout<<e.what()<<endl;
                        }
                        break;
                }
                if(!rightChoose) {
                    cout << "silakan masukan lagi karena pilihan anda tidak valid" << endl;
                    cout << ">>";
                    cin >> choose;
                }
            }
            playerTurn++;
        }
        playerTurn=1;
        game.endRound(table);
    }


    splash.SplashClosing();
    return 0;
}