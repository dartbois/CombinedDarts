#ifndef PLAYER_H
#define PLAYER_H
#include <string>
using namespace std;


class player
{
public:
    player();
private:
    int playerMatch180s[2];
    string playerFirst[2];
    string playerLast[2];
    string playerHometown[2];
    int playerRanking[2];
    float playerAvg180s[2];
    float playerAvg180Season[2];
    string playerLastWin[2];
    float playerAvgThrow[2];
    float playerAvgThrowSeason[2];
    int playerTurnScoreHi[2];
    int playerTurnScoreLo[2];

};

#endif // PLAYER_H
