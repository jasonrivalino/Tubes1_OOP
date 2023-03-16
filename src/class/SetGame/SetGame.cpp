//
// Created by lenovo on 28/02/2023.
//

#include "SetGame.hpp"
#include "../Combination/Combination.hpp"




SetGame::SetGame(int jumPlayer,int choose) {
    string path = "././config/card.txt";
    
    this->turn=1;
    this->round=1;
    this->pointGame=64;



    string warna[4] = {"K","H","M","B"};
    string namaPlayer;
    for(int i=1;i<jumPlayer+1;i++){
        cout<<"masukkan nama player-"<<i<<": ";
        cin>>namaPlayer;
        this->players.push_back(new Player(namaPlayer));
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
        vector<int> sampleNum{1,2,3,4,5,6,7,8,9,10,11,12,13};
        for(int i=0;i<4;i++){
            vector<int> numCard;
            randomIndex(sampleNum,numCard);
            for(int j=0;j<13;j++){
                this->cards.push_back(new Card(warna[i],numCard[j]));
            }
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
void SetGame::removeAllCards() {
    this->cards.clear();
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
        string warna[4] = {"K","H","M","B"};


        vector<double> allPlayerComb;
        
        Player p1 = *this->players[0];
        Player p2 = *this->players[1];
        Player p3 = *this->players[2];
        Player p4 = *this->players[3];
        Player p5 = *this->players[4];
        Player p6 = *this->players[5];
        Player p7 = *this->players[6];
        // vector<Card*> p1=this->players[0]->getCardsPlayer();
        // vector<Card*> p2= this->players[1]->getCardsPlayer();
        // vector<Card*> p3= this->players[2]->getCardsPlayer();
        // vector<Card*> p4= this->players[3]->getCardsPlayer();
        // vector<Card*> p5= this->players[4]->getCardsPlayer();
        // vector<Card*> p6= this->players[5]->getCardsPlayer();
        // vector<Card*> p7= this->players[6]->getCardsPlayer();
        // vector<Card*> table = t.getCards();


        allPlayerComb.push_back(this->getHighCombinationPlayer(p1,t));
        allPlayerComb.push_back(this->getHighCombinationPlayer(p2,t));
        allPlayerComb.push_back(this->getHighCombinationPlayer(p3,t));
        allPlayerComb.push_back(this->getHighCombinationPlayer(p4,t));
        allPlayerComb.push_back(this->getHighCombinationPlayer(p5,t));
        allPlayerComb.push_back(this->getHighCombinationPlayer(p6,t));
        allPlayerComb.push_back(this->getHighCombinationPlayer(p7,t));

        double max = *max_element(allPlayerComb.begin(),allPlayerComb.end());

        int idxPlayer =0;
        for(int i=0;i<allPlayerComb.size();i++) if(max==allPlayerComb[i]) idxPlayer=i;

        cout<<"pemenang ronde ini adalah PLAYER "<< this->players[idxPlayer]->getTurn()<<" ("<< this->players[idxPlayer]->getName()<<")"<<endl;

        this->players[idxPlayer]->setPoint(this->players[idxPlayer]->getPoint()+ this->pointGame);



        this->pointGame=64;
        this->turn=1;
        if(this->players[1]->getTurn()-players[0]->getTurn()==-1) reverseTurn();
        t.removeTableCard();
        this->removeAllCards();
        for(int i=0; this->players.size();i++){
            this->players[i]->removeAbilityCard();
        }

        int choose;
        cout<<"pilih kartu random mengguakan txt atau tidak\n1. Ya\n2. Tidak"<<endl;
        cout<<">>";
        cin>>choose;
        while(choose>2||choose<1){
            cout<<"input salah"<<endl;
            cout<<">>";
            cin>>choose;
        }
        if(choose==2) {
            vector<int> sampleNum{1,2,3,4,5,6,7,8,9,10,11,12,13};
            for(int i=0;i<4;i++){
                vector<int> numCard;
                randomIndex(sampleNum,numCard);
                for(int j=0;j<13;j++){
                    this->cards.push_back(new Card(warna[i],numCard[j]));
                }
            }

            random_shuffle(this->cards.begin(), this->cards.end());
        }
        else {
            string path = "././config/card.txt";
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

    }


    if(round==2) this->shareAbilityCard();
    if(round>1|| round<7) this->shareCardToTable(t);
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
double SetGame::getHighCombinationPlayer(Player &player, Table &table) {
    vector<Card*> p;
    vector<Card*> t;

    for(int i = 0 ; i < player.getCardsPlayer().size(); i++) p.push_back(player.getCardsPlayer()[i]);
    for(int i = 0 ; i < table.getCards().size(); i++) t.push_back(table.getCards()[i]);
    
    
    
    vector<Card*> allCard;
    vector<double> allValue;
    for(int i=0;i<p.size();i++) allCard.push_back(p[i]);
    for(int i=0;i<t.size();i++) allCard.push_back(t[i]);


    // vector<Card*> tableee;
    // vector<Card*> playerrr;
    // Table tab;
    // Player play("temp");

    // Card c[0], c[1], c[2], c[3], c[4], c[5], c[6];
    // for(int i=1; i <= allCard.size(); i++){
    //     Card c[i](allCard[i]->getNameCard(), allCard[i]->getNumberCard());
    // }
    
    // for(int i=0; i < p.size(); i ++) playerrr.push_back(p[i]);
    // for(int i=0; i < t.size(); i ++) tableee.push_back(p[i]);

    Calculable *c0;
    Calculable *c1;
    Calculable *c2;
    Calculable *c3;
    Calculable *c4;
    Calculable *c5;
    Calculable *c6;
    Calculable *c7;
    Calculable *c8;

    Combination c;
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
        vector<Card*> v = c.isHighCard(player,table);
        if(v.size() != 0){
        cout << "High Card\n";
            c0 = new HighCard(v);
            allValue.push_back(c0->valueCards());
            delete c0;
        }
        else{
            allValue.push_back(0);
        }
    }catch (bad_array_new_length e){
        allValue.push_back(0);
    }catch (bad_alloc e){
        allValue.push_back(0);
    }


    try {
        vector<Card*> v = c.isOnePair(player,table);
        if(v.size() != 0){
        cout << "One Pair\n";
            c1 = new OnePair(v);
            allValue.push_back(c1->valueCards());
            delete c1;
        }
        else{
            allValue.push_back(0);
        }
    }catch (bad_array_new_length e){
        allValue.push_back(0);
    }catch (bad_alloc e){
        allValue.push_back(0);
    }

    try {
        vector<Card*> v = c.isTwoPair(player,table);
        if(v.size() != 0){
        cout << "Two Pair\n";
            c2 = new TwoPair(v);
            allValue.push_back(c2->valueCards());
            delete c2;
        }
        else{
            allValue.push_back(0);
        }
    }catch (bad_array_new_length e){
        allValue.push_back(0);
    }catch (bad_alloc e){
        allValue.push_back(0);
    }

    try {
        vector<Card*> v = c.isThreeOfAKind(player,table);
        if(v.size() != 0){
        cout << "ThreeOfAKind\n";
            c3 = new ThreeOfAKind(v);
            allValue.push_back(c3->valueCards());
            delete c3;
        }
        else{
            allValue.push_back(0);
        }
    }catch (bad_array_new_length e){
        allValue.push_back(0);
    }catch (bad_alloc e){
        allValue.push_back(0);
    }

    try {
        vector<Card*> v = c.isStraight(player,table);
        if(v.size() != 0){
        cout << "Straight\n";
            c4 = new Straight(v);
            allValue.push_back(c4->valueCards());
            delete c4;
        }
        else{
            allValue.push_back(0);
        }
    }catch (bad_array_new_length e){
        allValue.push_back(0);
    }catch (bad_alloc e){
        allValue.push_back(0);
    }

    try {
        vector<Card*> v = c.isFlush(player,table);
        if(v.size() != 0){
        cout << "Flush\n";
            c5 = new Flush(v);
            allValue.push_back(c5->valueCards());
            delete c5;
        }
        else{
            allValue.push_back(0);
        }
    }catch (bad_array_new_length e){
        allValue.push_back(0);
    }catch (bad_alloc e){
        allValue.push_back(0);
    }

    try {
        vector<Card*> v = c.isFullHouse(player,table);
        if(v.size() != 0){
        cout << "FullHouse\n";
            c6 = new FullHouse(v);
            allValue.push_back(c6->valueCards());
            delete c6;
        }
        else{
            allValue.push_back(0);
        }
    }catch (bad_array_new_length e){
        allValue.push_back(0);
    }catch (bad_alloc e){
        allValue.push_back(0);
    }


    try {
        vector<Card*> v = c.isFourOfAKind(player,table);
        if(v.size() != 0){
        cout << "FourOfAKind\n";
            c7 = new FourOfAKind(v);
            allValue.push_back(c7->valueCards());
            delete c7;
        }
        else{
            allValue.push_back(0);
        }
    }catch (bad_array_new_length e){
        allValue.push_back(0);
    }catch (bad_alloc e){
        allValue.push_back(0);
    }

    try {
        vector<Card*> v = c.isStraightFlush(player,table);
        if(v.size() != 0){
        cout << "StraightFlush\n";
            c8 = new StraightFlush(v);
            allValue.push_back(c8->valueCards());
            delete c8;
        }
        else{
            allValue.push_back(0);
        }
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