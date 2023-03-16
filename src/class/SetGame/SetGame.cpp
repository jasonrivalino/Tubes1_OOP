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
void SetGame::setPoint(unsigned long int point) {
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

        vector<Card*> p1=this->players[0]->getCardsPlayer();
        vector<Card*> p2= this->players[1]->getCardsPlayer();
        vector<Card*> p3= this->players[2]->getCardsPlayer();
        vector<Card*> p4= this->players[3]->getCardsPlayer();
        vector<Card*> p5= this->players[4]->getCardsPlayer();
        vector<Card*> p6= this->players[5]->getCardsPlayer();
        vector<Card*> p7= this->players[6]->getCardsPlayer();
        vector<Card*> table = t.getCards();


        allPlayerComb.push_back(this->getHighCombinationPlayer(p1,table));
        allPlayerComb.push_back(this->getHighCombinationPlayer(p2,table));
        allPlayerComb.push_back(this->getHighCombinationPlayer(p3,table));
        allPlayerComb.push_back(this->getHighCombinationPlayer(p4,table));
        allPlayerComb.push_back(this->getHighCombinationPlayer(p5,table));
        allPlayerComb.push_back(this->getHighCombinationPlayer(p6,table));
        allPlayerComb.push_back(this->getHighCombinationPlayer(p7,table));

        double max = *max_element(allPlayerComb.begin(),allPlayerComb.end());

        int idxPlayer =0;
        for(int i=0;i<allPlayerComb.size();i++) if(max==allPlayerComb[i]) idxPlayer=i;

        cout<<"pemenang ronde ini adalah PLAYER "<< this->players[idxPlayer]->getTurn()<<endl;

        this->players[idxPlayer]->setPoint(this->players[idxPlayer]->getPoint()+ this->pointGame);



        this->pointGame=64;
        this->turn=1;
        if(this->players[1]->getTurn()-players[0]->getTurn()==-1) reverseTurn();
    
        t.removeTableCard();
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
void SetGame :: setRound(int t){
    this->round = t;
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

unsigned long int SetGame::getPointGame() const{
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
unsigned long int SetGame::getHighPointPlayer() const {
    vector<unsigned long int> point;
    for(int i=0;i< this->players.size();i++) point.push_back(this->players[i]->getPoint());
    for(int i = 0 ; i < point.size(); i++){
        cout << point[i] << endl;
    }
    return *max_element(point.begin(),point.end());
}
double SetGame::getHighCombinationPlayer(vector<Card *> &p, vector<Card *> &t) {
    vector<Card*> allCard;
    vector<double> allValue;
    for(int i=0;i<p.size();i++) allCard.push_back(p[i]);
    for(int i=0;i<t.size();i++) allCard.push_back(t[i]);



    Calculable *c1;
    Calculable *c2;
    Calculable *c3;
    Calculable *c4;
    Calculable *c5;
    Calculable *c6;
    Calculable *c7;
    Calculable *c8;
    Calculable *c9;

    for(auto x : allCard) {
        cout << x->getNameCard() << "     " << x->getNumberCard() << endl;
    }
    // cout << "-----------------\n";
    // cout << c1->valueCards() << endl;
    // cout << c2->valueCards() << endl;
    // cout << c3->valueCards() << endl;
    // cout << c4->valueCards() << endl;
    // cout << c5->valueCards() << endl;
    // cout << c6->valueCards() << endl;
    // cout << c7->valueCards() << endl;
    // cout << c8->valueCards() << endl;
    // cout << c9->valueCards() << endl;
    // cout << "------------------\n";


    try {
        cout << "masuk c1\n";
        c1 = new Straight(allCard);
        cout << c1->valueCards() << endl;
        cout << "fdfdfdfd\n";
        if(c1->valueCards() != 0){
            allValue.push_back(c1->valueCards());
            cout << c1->valueCards() << endl;
        }
        else{
            allValue.push_back(0);
        }
        delete c1;
    }catch (bad_array_new_length e){
        allValue.push_back(0);
    }catch (bad_alloc e){
        allValue.push_back(0);
    }

    try {
        cout << "masuk c2\n";
        c2 = new StraightFlush(allCard);
        if(c2->valueCards() != 0){
            allValue.push_back(c2->valueCards());
            cout << c2->valueCards() << endl;
        }
        else{
            allValue.push_back(0);
        }
        delete c2;
    }catch (bad_array_new_length e){
        allValue.push_back(0);
    }catch (bad_alloc e){
        allValue.push_back(0);
    }

    try {
        cout << "masuk c3\n";
        c3=new TwoPair(allCard);
        if(c3->valueCards() != 0){
            allValue.push_back(c3->valueCards());
            cout << c3->valueCards() << endl;
        }
        else{
            allValue.push_back(0);
        }
            delete c3;
    }catch (bad_array_new_length e){
        allValue.push_back(0);
    }catch (bad_alloc e){
        allValue.push_back(0);
    }


    try {
        cout << "masuk c4\n";
        c4 = new OnePair(allCard);
        if(c4->valueCards() != 0){
            allValue.push_back(c4->valueCards());
            cout << c4->valueCards() << endl;
        }
        else{
            allValue.push_back(0);
        }
            delete c4;
    }catch (bad_array_new_length e){
        allValue.push_back(0);
    }catch (bad_alloc e){
        allValue.push_back(0);
    }


    try {
        cout << "masuk c5\n";
        c5 = new ThreeOfAKind(allCard);
        if(c5->valueCards() != 0){
            allValue.push_back(c5->valueCards());
            cout << c5->valueCards() << endl;
        }
        else{
            allValue.push_back(0);
        }
            delete c5;
    }catch (bad_array_new_length e){
        allValue.push_back(0);
    }catch (bad_alloc e){
        allValue.push_back(0);
    }

    try {
        cout << "masuk c6\n";
        c6 = new Flush(allCard);
        if(c6->valueCards() != 0){
            allValue.push_back(c6->valueCards());
            cout << c6->valueCards() << endl;
        }
        else{
            allValue.push_back(0);
        }
            delete c6;
    }catch (bad_array_new_length e){
        allValue.push_back(0);
    }catch (bad_alloc e){
        allValue.push_back(0);
    }

    try {
        cout << "masuk c7\n";
        c7 = new FullHouse(allCard);
        if(c7->valueCards() != 0){
            allValue.push_back(c7->valueCards());
            cout << c7->valueCards() << endl;
        }else{
            allValue.push_back(0);
        }
            delete c7;
    }catch (bad_array_new_length e){
        allValue.push_back(0);
    }catch (bad_alloc e){
        allValue.push_back(0);
    }

    try {
        cout << "masuk c8\n";
        c8 = new FourOfAKind(allCard);
        if(c8->valueCards() != 0){
            allValue.push_back(c8->valueCards());
            cout << c8->valueCards() << endl;
        }
        else{
            allValue.push_back(0);
        }
            delete c8;
    }catch (bad_array_new_length e){
        allValue.push_back(0);
    }catch (bad_alloc e){
        allValue.push_back(0);
    }

    try {
        cout << "masuk c9\n";
        c9 = new HighCard(allCard);
        if(c9->valueCards() != 0){
            allValue.push_back(c9->valueCards());
            cout << c9->valueCards() << endl;
        }
        else{
            allValue.push_back(0);
        }
            delete c9;
    }catch (bad_array_new_length e){
        allValue.push_back(0);
    }catch (bad_alloc e){
        allValue.push_back(0);
    }


    cout << "allcard " << allCard.size() << endl;
    cout << "allValue " << allValue.size() << endl;





    cout << "\n\n\n\n----------------\n\n\n\n\n\n";

    float max = *max_element(allValue.begin(),allValue.end());
    allValue.clear();

    return max;
}