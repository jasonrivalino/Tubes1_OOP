//
// Created by lenovo on 28/02/2023.
//

#include "SetGame.hpp"




SetGame::SetGame(int jumPlayer,int choose) {
    string path;
    this->turn=1;
    this->round=1;
    this->pointGame=64;



    string warna[4] = {"K","H","M","B"};
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
    if(choose==2) {
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
        
        // cout << path << endl;
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

    this->shareCardToPlayer(2);
}
SetGame::~SetGame() {
    this->ability.clear();
    this->cards.clear();
    this->players.clear();
}

void SetGame::addCard(Card card) {
    this->cards.push_back(&card);
}
void  SetGame::removeBackCard() {
    this->cards.pop_back();
}
void SetGame::removeFirstCard() {
    this->cards.erase(this->cards.begin());
}
void SetGame::removeAbilityCards() {
    this->ability.pop_back();
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
void SetGame::shareCardToTable(Table& t) {
    t.addCard(*this->cards[this->cards.size()-1]);

    this->cards.pop_back();
}
void SetGame::shareAbilityCard() {
    for(int i=0;i< this->players.size();i++) this->players[i]->addAbilityCard(*this->ability[i]);
    this->removeAbilityCards();
}
void SetGame::printCards() {
    for(int i=0;i< this->cards.size();i++){
        cout<< this->cards[i]->getNameCard()<<" "<< this->cards[i]->getNumberCard()<<endl;
    }
}
void SetGame::endRound(Table& t) {

    this->round++;
    if(round==7){
        vector<double> allPlayerComb;






    }
    if(round==2) this->shareAbilityCard();
    if(round>1) this->shareCardToTable(t);
    if (this->turn == 7) this->turn = 1; else this->turn++;












//    this->pointGame=64;



//    this->cards.clear();

//    this->ability.push_back(new ReRoll);
//    this->ability.push_back(new Quadruple);
//    this->ability.push_back(new Quarter);
//    this->ability.push_back(new ReverseDirection);
//    this->ability.push_back(new SwapCard);
//    this->ability.push_back(new Switch);
//    this->ability.push_back(new Abilityless);
//    random_shuffle(this->ability.begin(), this->ability.end());

//    for(int i=0;i<52;i++){
//        int numCard = i%13+1;
//        int numWarna = i/13;
//
//        this->cards.push_back(new Card(warna[numWarna],numCard));
//    }
//    random_shuffle(this->cards.begin(), this->cards.end());
//
//    if(this->players[1]->getTurn()-this->players[0]->getTurn()==-1){
//        reverseTurn();
//    }

//    int idxPlayer=0;
//    for(int i=0;i< this->players.size();i++){
//        if(*this->players[i]==playerWin) idxPlayer=i;
//    }
//
//
//    this->players[idxPlayer]->setPoint(this->players[idxPlayer]->getPoint()+this->pointGame);
//    this->pointGame=64;
}
void SetGame::reverseTurn() {
    this->turn=(8- this->turn);
    reverse(this->players.begin(), this->players.end());
}
void SetGame::nextTurn() {
    if(turn==7) turn=1; else turn++;
}
void SetGame::setTurn(int t) {
    turn=t-1;
}

vector<Card*> SetGame::getCards() const {
    return this->cards;
}
vector<Ability*> SetGame::getAbilityCards() const {
    return this->ability;
}
vector<Player*> SetGame::getPlayers() const{
    return this->players;
}
Player* SetGame::playerTurn() const {
    return this->players[this->turn-1];
}

long int SetGame::getPointGame() const{
    return this->pointGame;
}
int SetGame::getSizeCards() const {
    return this->cards.size();
}
int SetGame::getTurn() const {
    return this->turn;
}
int SetGame::getRound() const {
    return this->round;
}
int SetGame::getHighPointPlayer() const {
    vector<int> point;
    for(int i=0;i< this->players.size();i++) point.push_back(this->players[i]->getPoint());
    return *max_element(point.begin(),point.end());
}
float SetGame::getHighCombinationPlayer(vector<Card *> &p, vector<Card *> &t) {
    vector<Card*> allCard;
    vector<float> allValue;
    for(int i=0;i<p.size();i++) allCard.push_back(p[i]);
    for(int i=0;i<t.size();i++) allCard.push_back(t[i]);

    Calculable *c;
    c=new Straight(allCard);
    allValue.push_back(c->valueCards());

    c=new StraightFlush(allCard);
    allValue.push_back(c->valueCards());

    c=new OnePair(allCard);
    allValue.push_back(c->valueCards());

    c=new TwoPair(allCard);
    allValue.push_back(c->valueCards());

    c=new ThreeOfAKind(allCard);
    allValue.push_back(c->valueCards());

    c=new Flush(allCard);
    allValue.push_back(c->valueCards());

    c=new FullHouse(allCard);
    allValue.push_back(c->valueCards());

    c=new FourOfAKind(allCard);
    allValue.push_back(c->valueCards());


    return *max_element(allValue.begin(),allValue.end());
}