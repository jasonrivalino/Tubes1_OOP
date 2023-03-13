#include "../Player/Player.hpp"
#include "../Table/Table.hpp"
#include "../Card/Card.hpp"
#include <iostream>

using namespace std;

class Combination
{
private:
    vector <Card*> allCard;
public:
    Combination(/* args */);
    ~Combination();
    vector<Card*> isStraightFlush(Player &player, Table &tableCard);
    int isFourOfAKind(Player &player, Table &tableCard);
    int isFullHouse(Player &player, Table &tableCard);
    vector<Card*> isFlush(Player &player, Table &tableCard);
    vector<Card*> isStraight(Player &player, Table &tableCard);
    vector<Card*> isThreeOfAKind(Player &player, Table &tableCard);
    vector<Card*> isTwoPair(Player &player, Table &tableCard);
    vector<Card*> isOnePair(Player &player, Table &tableCard);
    vector<Card*> isHighCard(Player &player, Table &tableCard);
    



};