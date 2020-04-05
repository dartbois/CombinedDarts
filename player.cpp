#include "player.h"
#include "datahandler.h"

player::player()
{
 //GET STUFF.
    DataHandler initData;
    //matctch180s is 0
    playerMatch180s[0] = 0;
    playerMatch180s[1] = 0;

    //score is 0 figure out what this means
    playerFirst[0] = initData.getData("SQLHandler:p1First");
    playerFirst[1] = initData.getData("SQLHandler:p2First");
    playerLast[0] = initData.getData("SQLHandler:p1Last");
    playerLast[1] = initData.getData("SQLHandler:p2Last");
    playerHometown[0] = initData.getData("SQLHandler:p1Hometown");
    playerHometown[1] = initData.getData("SQLHandler:p2Hometown");
    playerRanking[0] = stoi(initData.getData("SQLHandler:p1Rank"));
    playerRanking[0] = stoi(initData.getData("SQLHandler:p2Rank"));
    playerAvg180s[0] = stof(initData.getData("SQLHandler:p1avg180s"));
    playerAvg180s[1] = stof(initData.getData("SQLHandler:p2avg180s"));
    playerAvg180Season[0] = stof(initData.getData("SQLHandler:p1avg180season"));
    playerAvg180Season[1] = stof(initData.getData("SQLHandler:p2avg180season"));
    playerLastWin[0] = initData.getData("SQLHandler:p1LastWin");
    playerLastWin[1] = initData.getData("SQLHandler:p2LastWin");
    playerAvgThrow[0] = stof(initData.getData("SQLHandler:p1AvgThrow"));
    playerAvgThrow[1] = stof(initData.getData("SQLHandler:p2AvgThrow"));
    playerAvgThrowSeason[0] = stof(initData.getData("SQLHandler:p1AvgThrowSeason"));
    playerAvgThrowSeason[1] = stof(initData.getData("SQLHandler:p2AvgThrowSeason"));
    playerTurnScoreHi[0] = stoi(initData.getData("SQLHandler:p1TurnScoreHi"));
    playerTurnScoreHi[1] = stoi(initData.getData("SQLHandler:p2TurnScoreHi"));
    playerTurnScoreLo[0] = stoi(initData.getData("SQLHandler:p1TurnScoreLo"));
    playerTurnScoreLo[1] = stoi(initData.getData("SQLHandler:p2TurnScoreLo"));
}
