#ifndef PLAYER_H
#define PLAYER_H
#include <string>
using namespace std;


class player
{
public:
    player();
private:
    int playerScore[2];
    int playerLeagueRank[2];
    int avgScoreSeason[2];
    int avgScoreLifetime[2];
    int num180sMatch[2];
    int num180sSeason[2];
    int num180sLifetime[2];
    string hometown[2];
    string lastSeasonWin[2];
    string playerName[2];
    string playerNickname[2];
};

#endif // PLAYER_H
