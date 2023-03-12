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
    vector<Card*> Combination::isStraightFlush(Player &player, Table &tableCard);
    int Combination::isFourOfAKind(Player &player, Table &tableCard);
    int Combination::isFullHouse(Player &player, Table &tableCard);
    vector<Card*> Combination::isFlush(Player &player, Table &tableCard);
    vector<Card*> Combination::isStraight(Player &player, Table &tableCard);
    vector<Card*> Combination::isThreeOfAKind(Player &player, Table &tableCard);
    vector<Card*> Combination::isTwoPair(Player &player, Table &tableCard);
    vector<Card*> Combination::isOnePair(Player &player, Table &tableCard);
    vector<Card*> Combination::isHighCard(Player &player, Table &tableCard);
    



};