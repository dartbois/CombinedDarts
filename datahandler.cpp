#include "datahandler.h"
#include <cstring>
#include "sqlhandler.h"
#include "mathclass.h"
#include "matchstartdata.h"

using namespace std;

DataHandler::DataHandler()
{

}
/*
string DataHandler::getData(string request) {
    char requestHandler[40];
    char reqClass[20];
    char reqVar[20];
    string ansHandler;
    string cases;
    for(int i = 0; i < 20; i++){
        reqClass[i] = NULL;
        reqVar[i] = NULL;
        requestHandler[i] = NULL;
        requestHandler[i + 20] = NULL;
    }

    strcpy(requestHandler, request.c_str());
    strcpy(reqClass, strtok(requestHandler, ":\0"));
    strcpy(reqVar, strtok(requestHandler, "\0"));


    if (strcmp("sqlhandler", reqClass) == 0){

    }
    else if (strcmp("mathclass", reqClass) == 0){

    }
    else if (strcmp("matchstartdata", reqClass) == 0){

    }
    else if (strcmp("player", reqClass) == 0){

    }
    else {
        ansHandler = "Failure: Class not found";
    }



    return ansHandler;
}

string DataHandler::setData(string request) {
    char requestHandler[40];
    char reqClass[20];
    char reqVar[20];
    string ansHandler;
    for(int i = 0; i < 20; i++){
        reqClass[i] = NULL;
        reqVar[i] = NULL;
        requestHandler[i] = NULL;
        requestHandler[i + 20] = NULL;
    }

    strcpy(requestHandler, request.c_str());
    strcpy(reqClass, strtok(requestHandler, ":\0"));
    strcpy(reqVar, strtok(requestHandler, "\0"));

    //code to select between different functions for setting. switch statement.
    //there will be a series of private DataHandler functions
    //that send data to each other class.
    //Each will return a confirmation of success or failure, placed in ansHandler.


    return ansHandler;

}
*/
string DataHandler::sqlGet(string request){
    //playerid:variable
    char requestHandler[65] = {'\0'};
    char idHandler[10] = {'\0'};
    char varGet[50] = {'\0'};
    int id;
    string answer;


    QString path = QDir::currentPath();
    path = path + QString("/DartLeague.db");
    sqlHandler mySql(path);

    strcpy(requestHandler, request.c_str());
    strcpy(idHandler, strtok(requestHandler, ":"));
    strcpy(varGet, strtok(NULL, "\0"));
    id = stoi(idHandler);

    if (strcmp(varGet, "playerFirst") == 0){
        answer = mySql.sqlGetFirstName(id);
    }
    else if (strcmp(varGet, "playerLast") == 0){
        answer = mySql.sqlGetLastName(id);
    }
    else if (strcmp(varGet, "playerHometown") == 0){
        answer = mySql.sqlGetHometown(id);
    }
    else if (strcmp(varGet, "playerRanking") == 0){
        int temp = mySql.sqlGetRanking(id);
        answer = to_string(temp);
    }
    else if (strcmp(varGet, "playerAvg180s") == 0){
        float temp = mySql.sqlGetAvg180s(id);
        answer = to_string(temp);
    }
    else if (strcmp(varGet, "playerAvg180Season") == 0){
        float temp = mySql.sqlGetAvg180sSeason(id);
        answer = to_string(temp);
    }
    else if (strcmp(varGet, "playerLastWin") == 0){
        int temp = mySql.sqlGetLastGameWin(id);
        answer = to_string(temp);
    }
    else if(strcmp(varGet, "playerAvgThrow") == 0){
        float temp = mySql.sqlGetAvgThrowScore(id);
        answer = to_string(temp);
    }
    else if(strcmp(varGet, "playerAvgThrowSeason") == 0){
        float temp = mySql.sqlGetAvgThrowScoreSeason(id);
        answer = to_string(temp);
    }
    else if(strcmp(varGet, "playerTurnScoreHi") == 0){
        int temp = mySql.sqlGetTurnScoreHi(id);
        answer = to_string(temp);
    }
    else if (strcmp(varGet, "playerTurnScoreLo") == 0){
        int temp = mySql.sqlGetTurnScoreLo(id);
        answer = to_string(temp);
    }
    else if (strcmp(varGet, "playerGamesPlayed") == 0){
        int temp = mySql.sqlGetGamesPlayed(id);
        answer = to_string(temp);
    }
    else if (strcmp(varGet, "playerGamesWon") == 0){
        int temp = mySql.sqlGetGamesWon(id);
        answer = to_string(temp);
    }
    else if (strcmp(varGet, "gameName") == 0){
        answer = mySql.sqlGetGameName(id);
    }
    else if (strcmp(varGet, "gameDate") == 0){
        answer = mySql.sqlGetGameDate(id);
    }
    else if (strcmp(varGet, "gameLocation") == 0){
        answer = mySql.sqlGetGameLocation(id);
    }
    else if (strcmp(varGet, "gameStartScore") == 0){
        int temp = mySql.sqlGetGameStartScore(id);
        answer = to_string(temp);
    }
    else if (strcmp(varGet, "gameMatches") == 0){
        int temp = mySql.sqlGetGameMatches(id);
        answer = to_string(temp);
    }
    else if (strcmp(varGet, "gameLegs") == 0){
        int temp = mySql.sqlGetGameLegs(id);
        answer = to_string(temp);
    }
    else if (strcmp(varGet, "gameP1") == 0){
        int temp = mySql.sqlGetGameP1(id);
        answer = to_string(temp);
    }
    else if (strcmp(varGet, "gameP2") == 0){
        int temp = mySql.sqlGetGameP2(id);
        answer = to_string(temp);
    }
    else if (strcmp(varGet, "playerInfoList") == 0){
        answer = mySql.sqlGetPlayerList();
    }
    else if (strcmp(varGet, "gameInfoList") == 0){
        answer = mySql.sqlGetGameList();
    }
    else if (strcmp(varGet, "removePlayer") == 0){
        mySql.sqlRemovePlayer(id);
    }
    else if (strcmp(varGet, "removeGame") == 0){
        mySql.sqlRemoveGame(id);
    }

    mySql.sqlCloseConnection();

    return answer;
}
string DataHandler::mathcGet(string request, mathClass myM){
    //request should be score1 or score2
    string answer = myM.dataGet(request);
    return answer;
}
string DataHandler::playerGet(string request, player myPlayer){
    string answer = myPlayer.dataGet(request);
    return answer;
}
string DataHandler::matchstartGet(string request, MatchStartData myS){
    string answer = myS.dataGet(request);
    return answer;
}


