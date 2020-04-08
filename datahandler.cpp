#include "datahandler.h"
#include <cstring>
#include "sqlhandler.h"

using namespace std;

DataHandler::DataHandler()
{

}

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

string DataHandler::sqlGet(string request){
    //playerid:variable
    char requestHandler[65];
    char idHandler[10];
    char varGet[50];
    int idPlayer;
    string answer;
    sqlHandler mySql("./db/DartLeague.db");

    strcpy(requestHandler, request.c_str());
    strcpy(idHandler, strtok(requestHandler, ":"));
    strcpy(varGet, strtok(requestHandler, "\0\n"));
    idPlayer = stoi(idHandler);

    if (strcmp(varGet, "playerFirst")){
        answer = mySql.sqlGetFirstName(idPlayer);
    }
    else if (strcmp(varGet, "playerLast")){
        answer = mySql.sqlGetLastName(idPlayer);
    }
    else if (strcmp(varGet, "playerHometown")){
        answer = mySql.sqlGetHometown(idPlayer);
    }
    else if (strcmp(varGet, "playerRanking")){
        answer = mySql.sqlGetRanking(idPlayer);
    }
    else if (strcmp(varGet, "playerAvg180s")){
        answer = mySql.sqlGetAvg180s(idPlayer);
    }
    else if (strcmp(varGet, "playerAvg180Season")){
        answer = mySql.sqlGetAvg180sSeason(idPlayer);
    }
    else if (strcmp(varGet, "playerLastWin")){
        answer = mySql.sqlGetLastGameWin(idPlayer);
    }
    else if(strcmp(varGet, "playerAvgThrow")){
        answer = mySql.sqlGetAvgThrowScore(idPlayer);
    }
    else if(strcmp(varGet, "playerAvgThrowSeason")){
        answer = mySql.sqlGetAvgThrowScoreSeason(idPlayer);
    }
    else if(strcmp(varGet, "playerTurnScoreHi")){
        answer = mySql.sqlGetTurnScoreHi(idPlayer);
    }
    else if (strcmp(varGet, "playerTurnScoreLo")){
        answer = mySql.sqlGetTurnScoreLo(idPlayer);
    }

    return answer;
}
string DataHandler::mathcGet(string request){
    return NULL;
}
string DataHandler::playerGet(string request, player myPlayer){
    string answer = myPlayer.dataGet(request);
    return answer;
}
string DataHandler::matchstartGet(string request){
    return NULL;
}

