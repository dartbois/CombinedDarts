#include "sqlhandler.h"
#include "datahandler.h"
#include "player.h"
#include <stdio.h>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QVariant>


sqlHandler::sqlHandler(const QString& path) {
    bool failFlag = false;

    //Opening the db
    const QString DRIVER("QSQLITE");
    QSqlDatabase dartdb = QSqlDatabase::addDatabase(DRIVER);
    dartdb.setDatabaseName(path);

    //Check if opened
    if (!dartdb.open())
    {
       failFlag = true;
       printf("dartdb failed to open");
    }
    else{
        //Create tables
        //TODO: make sure tables don't exist before we create new ones
        //QSqlQuery query("CREATE TABLE players ([Player ID] INTEGER NOT NULL UNIQUE PRIMARY KEY AUTOINCREMENT, [First Name] STRING NOT NULL, [Last Name] STRING NOT NULL, Hometown STRING NOT NULL, Ranking INTEGER NOT NULL UNIQUE, [Avg 180s] REAL, [Avg 180s (Season)] REAL, [Last Game Win] INTEGER REFERENCES Games ([Game ID]), [Avg Throw Score] REAL, [Avg Throw Score (Season)] REAL, [Turn Score High] INTEGER, [Turn Score Low] INTEGER);");
        //QSqlQuery query2("CREATE TABLE games ([Game ID] INTEGER UNIQUE NOT NULL PRIMARY KEY AUTOINCREMENT, [Game Name] STRING NOT NULL UNIQUE, Date DATE NOT NULL, Location STRING NOT NULL, [Start Score] INTEGER DEFAULT (501) NOT NULL, [Max # Legs] INTEGER NOT NULL, Player1 INTEGER NOT NULL REFERENCES players ([Player ID]), Player2 INTEGER NOT NULL REFERENCES players ([Player ID]), Winner INTEGER REFERENCES players ([Player ID]));");
        //query.exec();
        //query2.exec();
    }
}

string sqlHandler::sqlGetFirstName(int playerID){
    QSqlQuery query;

    query.prepare("SELECT [First Name] FROM players WHERE [Player ID] = ?");
    query.bindValue(0, playerID);

    query.exec();
    query.first();

    return query.value(0).toString().toStdString();
}

string sqlHandler::sqlGetLastName(int playerID){
    QSqlQuery query;

    query.prepare("SELECT [Last Name] FROM players WHERE [Player ID] = ?");
    query.bindValue(0, playerID);

    query.exec();
    query.first();

    return query.value(0).toString().toStdString();
}

string sqlHandler::sqlGetHometown(int playerID){
    QSqlQuery query;

    query.prepare("SELECT Hometown FROM players WHERE [Player ID] = ?");
    query.bindValue(0, playerID);

    query.exec();
    query.first();

    return query.value(0).toString().toStdString();
}

int sqlHandler::sqlGetRanking(int playerID){
    QSqlQuery query;

    query.prepare("SELECT Ranking FROM players WHERE [Player ID] = ?");
    query.bindValue(0, playerID);

    query.exec();
    query.first();

    return query.value(0).toInt();
}

float sqlHandler::sqlGetAvg180s(int playerID){
    QSqlQuery query;

    query.prepare("SELECT [Avg 180s] FROM players WHERE [Player ID] = ?");
    query.bindValue(0, playerID);

    query.exec();
    query.first();

    return query.value(0).toFloat();
}

float sqlHandler::sqlGetAvg180sSeason(int playerID){
    QSqlQuery query;

    query.prepare("SELECT [Avg 180s (Season)] FROM players WHERE [Player ID] = ?");
    query.bindValue(0, playerID);

    query.exec();
    query.first();

    return query.value(0).toFloat();
}

int sqlHandler::sqlGetLastGameWin(int playerID){
    QSqlQuery query;

    query.prepare("SELECT [Last Game Win] FROM players WHERE [Player ID] = ?");
    query.bindValue(0, playerID);

    query.exec();
    query.first();

    return query.value(0).toInt();
}

float sqlHandler::sqlGetAvgThrowScore(int playerID){
    QSqlQuery query;

    query.prepare("SELECT [Avg Throw Score] FROM players WHERE [Player ID] = ?");
    query.bindValue(0, playerID);

    query.exec();
    query.first();

    return query.value(0).toFloat();
}

float sqlHandler::sqlGetAvgThrowScoreSeason(int playerID){
    QSqlQuery query;

    query.prepare("SELECT [Avg Throw Score (Season)] FROM players WHERE [Player ID] = ?");
    query.bindValue(0, playerID);

    query.exec();
    query.first();

    return query.value(0).toFloat();
}

int sqlHandler::sqlGetTurnScoreHi(int playerID){
    QSqlQuery query;

    query.prepare("SELECT [Turn Score High] FROM players WHERE [Player ID] = ?");
    query.bindValue(0, playerID);

    query.exec();
    query.first();

    return query.value(0).toInt();
}

int sqlHandler::sqlGetTurnScoreLo(int playerID){
    QSqlQuery query;
    QString querystring;

    query.prepare("SELECT [Turn Score Low] FROM players WHERE [Player ID] = ?");
    query.bindValue(0, playerID);

    query.exec();
    query.first();

    return query.value(0).toInt();
}

//Getter: needs to get all player information from SQLite (for populating lists)
string sqlHandler::sqlGetPlayerList() {
    int num_of_players = 0;
    QSqlQuery query;
    QString querystring;

    string playerInfoLine = "Yeet";

    //currently borked.
    /*querystring = "SELECT COUNT(*) FROM players";
    query.exec(querystring);
    num_of_players = query.value(0).toInt();

    string playerInfoLine[num_of_players];
    int i = 0;

    querystring = "SELECT * FROM players";
    query.exec(querystring);
    while (query.next()){
        playerInfoLine[i] = query.value(0).toString().toStdString();
    }*/

    return playerInfoLine;
}

//Setter: needs to set final player info into SQLite
void sqlHandler::sqlSetPlayerFinal(QString& playerID, player Player) {


}

//Setter: needs to add a new player to the SQLite db
