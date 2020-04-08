#include "player.h"
#include "datahandler.h"

player::player(int playerID, int playerID2)
{
 //GET STUFF.
    DataHandler myD;
    string id1 = to_string(playerID);
    string id2 = to_string(playerID2);
    string req;
    //matctch180s is 0
    playerMatch180s[0] = 0;
    playerMatch180s[1] = 0;

    //score is 0 figure out what this means
    req = id1 + ":playerFirst";
    playerFirst[0] = myD.sqlGet(req);
    req = id2 + ":playerFirst";
    playerFirst[1] = myD.sqlGet(req);
    req = id1 + ":playerLast";
    playerLast[0] = myD.sqlGet(req);
    req = id2 + ":playerLast";
    playerLast[1] = myD.sqlGet(req);
    req = id1 + ":playerHometown";
    playerHometown[0] = myD.sqlGet(req);
    req = id2 + ":playerHometown";
    playerHometown[1] = myD.sqlGet(req);
    req = id1 + ":playerRanking";
    playerRanking[0] = stoi(myD.sqlGet(req));
    req = id2 + ":playerRanking";
    playerRanking[1] = stoi(myD.sqlGet(req));
    req = id1 + ":playerAvg180s";
    playerAvg180s[0] = stof(myD.sqlGet(req));
    req = id2 + ":playerAvg180s";
    playerAvg180s[1] = stof(myD.sqlGet(req));
    req = id1 + ":playerAvg180Season";
    playerAvg180Season[0] = stof(myD.sqlGet(req));
    req = id2 + ":playerAvg180Season";
    playerAvg180Season[1] = stof(myD.sqlGet(req));
    req = id1 + ":playerLastWin";
    playerLastWin[0] = stoi(myD.sqlGet(req));
    req = id2 + ":playerLastWin";
    playerLastWin[1] = stoi(myD.sqlGet(req));
    req = id1 + ":playerAvgThrow";
    playerAvgThrow[0] = stof(myD.sqlGet(req));
    req = id2 + ":playerAvgThrow";
    playerAvgThrow[1] = stof(myD.sqlGet(req));
    req = id1 + ":playerAvgThrowSeason";
    playerAvgThrowSeason[0] = stof(myD.sqlGet(req));
    req = id2 + ":playerAvgThrowSeason";
    playerAvgThrowSeason[1] = stof(myD.sqlGet(req));
    req = id1 + ":playerTurnScoreHi";
    playerTurnScoreHi[0] = stoi(myD.sqlGet(req));
    req = id2 + ":playerTurnScoreHi";
    playerTurnScoreHi[1] = stoi(myD.sqlGet(req));
    req = id1 + ":playerTurnScoreLo";
    playerTurnScoreLo[0] = stoi(myD.sqlGet(req));
    req = id2 + ":playerTurnScoreLo";
    playerTurnScoreLo[1] = stoi(myD.sqlGet(req));
}



string player::dataGet(string request) {
    string myAns;
    if (request == "leagueRank0"){
        myAns = to_string(this->playerRanking[0]);
    }
    else if (request == "leagueRank1"){
        myAns = to_string(this->playerRanking[1]);
    }
    else if (request == "playerAvgThrowSeason0"){
        myAns = to_string(this->playerAvgThrowSeason[0]);
    }
    else if (request == "playerAvgThrow0"){
        myAns = to_string(this->playerAvgThrow[0]);
    }
    else if (request == "playerMatch180s0"){
        myAns = to_string(this->playerMatch180s[0]);
    }
    else if (request == "playerAvg180Season0"){
        myAns = to_string(this->playerAvg180Season[0]);
    }
    else if (request == "playerAvg180s0"){
        myAns = to_string(this->playerAvg180s[0]);
    }
    else if (request == "playerHometown0"){
        myAns = this->playerHometown[0];
    }
    else if (request == "playerFirst0"){
        myAns = this->playerFirst[0];
    }
    else if (request == "playerLast0"){
        myAns = this->playerLast[0];
    }
    else if (request == "playerAvgThrowSeason1"){
        myAns = to_string(this->playerAvgThrowSeason[1]);
    }
    else if (request == "playerAvgThrow1"){
        myAns = to_string(this->playerAvgThrow[1]);
    }
    else if (request == "180sMatch1"){
        myAns = to_string(this->playerMatch180s[1]);
    }
    else if (request == "playerAvg180Season1"){
        myAns = to_string(this->playerAvg180Season[1]);
    }
    else if (request == "playerAvg180s1"){
        myAns = to_string(this->playerAvg180s[1]);
    }
    else if (request == "playerHometown1"){
        myAns = this->playerHometown[1];
    }
    else if (request == "playerFirst1"){
        myAns = this->playerFirst[1];
    }
    else if (request == "playerLast1"){
        myAns = this->playerLast[1];
    }
    return myAns;
}
