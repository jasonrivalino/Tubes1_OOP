#include "../Player/Player.hpp"
#include "../Table/Table.hpp"
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

class Player;
class Combination
{
private:
    vector <Card*> allCard;
public:
    Combination(/* args */);
    ~Combination();
    vector<Card*> isStraightFlush(Player &player, Table &tableCard);
    vector<Card*> isFourOfAKind(Player &player, Table &tableCard);
    vector<Card*> isFullHouse(Player &player, Table &tableCard);
    vector<Card*> isFlush(Player &player, Table &tableCard);
    vector<Card*> isStraight(Player &player, Table &tableCard);
    vector<Card*> isThreeOfAKind(Player &player, Table &tableCard);
    vector<Card*> isTwoPair(Player &player, Table &tableCard);
    vector<Card*> isOnePair(Player &player, Table &tableCard);
    vector<Card*> isHighCard(Player &player, Table &tableCard);

};