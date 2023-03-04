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
    bool isStraightFlush(Player &player, Table &tableCard);
    // bool isFourOfAKind(Player &player, Table &tableCard);
    bool isFullHouse(Player &player, Table &tableCard);
    bool isFlush(Player &player, Table &tableCard);
    // bool isStraight(Player &player, Table &tableCard);
    // bool isThreeOfAKind(Player &player, Table &tableCard);
    // bool isTwoPair(Player &player, Table &tableCard);
    // bool isOnePair(Player &player, Table &tableCard);
    // bool isHighCard(Player &player, Table &tableCard);
    // void checkCombination(Player &player, Table &tableCard);
};