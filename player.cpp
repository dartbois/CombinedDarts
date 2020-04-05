#include "player.h"
#include "datahandler.h"

player::player()
{
 //GET STUFF.
    DataHandler initData;
    playerName[0] = initData.getData("SQLHandler:p1");
    playerName[1] = initData.getData("SQLHandler:p2");
    playerNickname[0] = initData.getData("SQLHandler:p1Nick");
    playerNickname[1] = initData.getData("SQLHandler:p2Nick");
    lastSeasonWin[0] = initData.getData("SQLHandler:p1SeasonWin");
    lastSeasonWin[1] = initData.getData("SQLHandler:p2SeasonWin");
    hometown[0] = initData.getData("SQLHandler:p1Hometown");
    hometown[1] = initData.getData("SQLHandler:p2Hometown");
    num180sLifetime[0] = stoi(initData.getData("SQLHandler:p1Life180s"));
    num180sLifetime[1] = stoi(initData.getData("SQLHandler:p2Life180s"));
    num180sSeason[0] = stoi(initData.getData("SQLHandler:p1Seas180s"));
    num180sSeason[1] = stoi(initData.getData("SQLHandler:p2Seas180s"));
    //matctch180s is 0
    num180sMatch[0] = 0;
    num180sMatch[1] = 0;
    avgScoreLifetime[0] = stoi(initData.getData("SQLHandler:p1AvgLife"));
    avgScoreLifetime[1] = stoi(initData.getData("SQLHandler:p2AvgLife"));
    avgScoreSeason[0] = stoi(initData.getData("SQLHandler:p1AvgSeas"));
    avgScoreSeason[1] = stoi(initData.getData("SQLHandler:p2AvgSeas"));
    playerLeagueRank[0] = stoi(initData.getData("SQLHandler:p1Rank"));
    playerLeagueRank[0] = stoi(initData.getData("SQLHandler:p2Rank"));
    //score is 0 figure out what this means
}
