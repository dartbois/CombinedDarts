#include "datahandler.h"
#include <cstring>
#include "sqlhandler.h"

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
    int idPlayer;
    string answer;
    sqlHandler mySql("C:\\Users\\Cassidy\\Documents\\School\\SeniorDesign\\CombinedDarts-master\\DartLeague.db");

    strcpy(requestHandler, request.c_str());
    strcpy(idHandler, strtok(requestHandler, ":"));
    strcpy(varGet, strtok(NULL, "\0"));
    idPlayer = stoi(idHandler);

    if (strcmp(varGet, "playerFirst") == 0){
        answer = mySql.sqlGetFirstName(idPlayer);
    }
    else if (strcmp(varGet, "playerLast") == 0){
        answer = mySql.sqlGetLastName(idPlayer);
    }
    else if (strcmp(varGet, "playerHometown") == 0){
        answer = mySql.sqlGetHometown(idPlayer);
    }
    else if (strcmp(varGet, "playerRanking") == 0){
        int temp = mySql.sqlGetRanking(idPlayer);
        answer = to_string(temp);
    }
    else if (strcmp(varGet, "playerAvg180s") == 0){
        float temp = mySql.sqlGetAvg180s(idPlayer);
        answer = to_string(temp);
    }
    else if (strcmp(varGet, "playerAvg180Season") == 0){
        float temp = mySql.sqlGetAvg180sSeason(idPlayer);
        answer = to_string(temp);
    }
    else if (strcmp(varGet, "playerLastWin") == 0){
        int temp = mySql.sqlGetLastGameWin(idPlayer);
        answer = to_string(temp);
    }
    else if(strcmp(varGet, "playerAvgThrow") == 0){
        float temp = mySql.sqlGetAvgThrowScore(idPlayer);
        answer = to_string(temp);
    }
    else if(strcmp(varGet, "playerAvgThrowSeason") == 0){
        float temp = mySql.sqlGetAvgThrowScoreSeason(idPlayer);
        answer = to_string(temp);
    }
    else if(strcmp(varGet, "playerTurnScoreHi") == 0){
        int temp = mySql.sqlGetTurnScoreHi(idPlayer);
        answer = to_string(temp);
    }
    else if (strcmp(varGet, "playerTurnScoreLo") == 0){
        int temp = mySql.sqlGetTurnScoreLo(idPlayer);
        answer = to_string(temp);
    }
    else if (strcmp(varGet, "playerGamesPlayed") == 0){
        int temp = mySql.sqlGetGamesPlayed(idPlayer);
        answer = to_string(temp);
    }
    else if (strcmp(varGet, "playerGamesWon") == 0){
        int temp = mySql.sqlGetGamesWon(idPlayer);
        answer = to_string(temp);
    }

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

