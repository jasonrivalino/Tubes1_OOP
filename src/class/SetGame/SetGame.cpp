//
// Created by lenovo on 28/02/2023.
//

#include "SetGame.hpp"



SetGame::SetGame(int jumPlayer, string path) {

    this->pointGame=64;

    string warna[4] = {"H","B","K","M"};
    for(int i=1;i<jumPlayer+1;i++){
        this->players.push_back(new Player("P"+i));
    }
    this->ability.push_back(new ReRoll);
    this->ability.push_back(new Quadruple);
    this->ability.push_back(new Quarter);
    this->ability.push_back(new ReverseDirection);
    this->ability.push_back(new SwapCard);
    this->ability.push_back(new Switch);
    this->ability.push_back(new Abilityless);

    random_shuffle(this->ability.begin(), this->ability.end());
    if(path == "") {
        for(int i=0;i<52;i++){
            int numCard = i%13+1;
            int numWarna = i/13;

            this->cards.push_back(new Card(warna[numWarna],numCard));
        }

        random_shuffle(this->cards.begin(), this->cards.end());
    }
    else {
        // cout << "fdfdfd";
        ifstream inFile(path);
        int numCard, numWarna;
        char ch;
        bool angka = false;
        
        cout << path << endl;
        if (!inFile) {
            std::cerr << "Unable to open file";
            exit(1);
        }

        while (inFile >> noskipws >> ch) {
            if(ch >= 'A' && ch <= 'Z'){
                if (ch == 'H'){
                    numWarna = 0;
                }
                else if (ch == 'B') {
                    numWarna = 1;
                }
                else if (ch == 'K') {
                    numWarna = 2;
                }
                else if (ch == 'M') {
                    numWarna = 3;
                }
            }
            else if(ch >= '0' &&  ch <= '9'){
                if(!angka) {
                    angka = true;
                    numCard = ch - '0';
                }
                else {
                    numCard = numCard*10 + ch - '0';
                }
            }
            else if(ch == '\n') {
                angka = false;
                this->cards.push_back(new Card(warna[numWarna],numCard));
            }
            // cout<<"warna : " << warna[numWarna]<<" angka : "<<numCard<<endl;
        }

        inFile.close();
    }
}
SetGame::~SetGame() {
    this->ability.clear();
    this->cards.clear();
    this->players.clear();
}
int SetGame::getSizeCards() {
    return this->cards.size();
}
void SetGame::addCard(Card card) {
    this->cards.push_back(&card);
}
void  SetGame::removeBackCard() {
    this->cards.pop_back();
}
void SetGame::removeAbilityCards() {
    this->ability.clear();
}
void SetGame::setPoint(long point) {
    this->pointGame = point;
}
void SetGame::showAllPoint() {
    for(int i=0;i< this->players.size();i++) cout<<"Player "<< this->players[i]->getTurn()<<endl;
}
void SetGame::shareCardToPlayer(int shareCard) {
    for(int i=0;i< this->players.size();i++){
        for(int j=1;j<=shareCard;j++){
            this->players[i]->addCard(*this->cards[this->cards.size()-j]);
        }
        this->cards.pop_back();
        this->cards.pop_back();
    }
}
void SetGame::shareAbilityCard() {
    for(int i=0;i< this->players.size();i++) this->players[i]->addCard(*this->ability[i]);
    this->removeBackCard();
}
void SetGame::printCards() {
    for(int i=0;i< this->cards.size();i++){
        cout<< this->cards[i]->getNameCard()<<" "<< this->cards[i]->getNumberCard()<<endl;
    }
}
void SetGame::endRound(Player &playerWin) {

    this->pointGame=64;

    string warna[4] = {"Kuning","Hijau","Merah","Biru"};

    for(int i=0; i< this->players.size();i++){
        this->players[i]->removeBackCard();
        this->players[i]->removeBackCard();
    }


    this->cards.clear();

    this->ability.push_back(new ReRoll);
    this->ability.push_back(new Quadruple);
    this->ability.push_back(new Quarter);
    this->ability.push_back(new ReverseDirection);
    this->ability.push_back(new SwapCard);
    this->ability.push_back(new Switch);
    this->ability.push_back(new Abilityless);
    random_shuffle(this->ability.begin(), this->ability.end());

    for(int i=0;i<52;i++){
        int numCard = i%13+1;
        int numWarna = i/13;

        this->cards.push_back(new Card(warna[numWarna],numCard));
    }
    random_shuffle(this->cards.begin(), this->cards.end());

    if(this->players[1]->getTurn()-this->players[0]->getTurn()==-1){
        reverseTurn();
    }



    playerWin.setPoint(this->pointGame);
    this->pointGame=64;
}
void SetGame::reverseTurn() {
    reverse(this->players.begin(), this->players.end());
}

vector<Card*> SetGame::getCards() {
    return this->cards;
}
vector<Card*> SetGame::getAbilityCards() {
    return this->ability;
}
vector<Player*> SetGame::getPlayers() {
    return this->players;
}
vector<Player*> SetGame::getPlayerTurn() {
    return this->playerTurn;
}

long int SetGame::getPointGame() {
    return this->pointGame;
}