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


//Getters: used to get individual player values from SQLite db
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

int sqlHandler::sqlGetGamesPlayed(int playerID){
    QSqlQuery query;
    QString querystring;

    query.prepare("SELECT [Num Games Played] FROM players WHERE [Player ID] = ?");
    query.bindValue(0, playerID);

    query.exec();
    query.first();

    return query.value(0).toInt();
}

int sqlHandler::sqlGetGamesWon(int playerID){
    QSqlQuery query;
    QString querystring;

    query.prepare("SELECT [Num Games Won] FROM players WHERE [Player ID] = ?");
    query.bindValue(0, playerID);

    query.exec();
    query.first();

    return query.value(0).toInt();
}

//Getter: needs to get all player information from SQLite (for populating lists)
string sqlHandler::sqlGetPlayerList() {
    QSqlQuery query;
    string temp;
    string playerInfoLine = "";

    query.prepare("SELECT [Player ID], [First Name], [Last Name], [Hometown], [Ranking], [Num Games Won] FROM players");
    query.exec();

    while (query.next()){
        temp = query.value(0).toString().toStdString();
        playerInfoLine.append(temp);
        playerInfoLine.append("\n");
    }

    return playerInfoLine;
}

//Getters: used to get individual game information from db
string sqlHandler::sqlGetGameName(int gameID){
    QSqlQuery query;
    QString querystring;

    query.prepare("SELECT [Game Name] FROM Games WHERE [Game ID] = ?");
    query.bindValue(0, gameID);

    query.exec();
    query.first();

    return query.value(0).toString().toStdString();
}

string sqlHandler::sqlGetGameDate(int gameID){
    QSqlQuery query;
    QString querystring;

    query.prepare("SELECT Date FROM Games WHERE [Game ID] = ?");
    query.bindValue(0, gameID);

    query.exec();
    query.first();

    return query.value(0).toString().toStdString();
}

string sqlHandler::sqlGetGameLocation(int gameID){
    QSqlQuery query;
    QString querystring;

    query.prepare("SELECT Location FROM Games WHERE [Game ID] = ?");
    query.bindValue(0, gameID);

    query.exec();
    query.first();

    return query.value(0).toString().toStdString();
}

int sqlHandler::sqlGetGameStartScore(int gameID){
    QSqlQuery query;
    QString querystring;

    query.prepare("SELECT [Start Score] FROM Games WHERE [Game ID] = ?");
    query.bindValue(0, gameID);

    query.exec();
    query.first();

    return query.value(0).toInt();
}

int sqlHandler::sqlGetGameMatches(int gameID){
    QSqlQuery query;
    QString querystring;

    query.prepare("SELECT [Max # Matches] FROM Games WHERE [Game ID] = ?");
    query.bindValue(0, gameID);

    query.exec();
    query.first();

    return query.value(0).toInt();
}

int sqlHandler::sqlGetGameLegs(int gameID){
    QSqlQuery query;
    QString querystring;

    query.prepare("SELECT [Max # Legs] FROM Games WHERE [Game ID] = ?");
    query.bindValue(0, gameID);

    query.exec();
    query.first();

    return query.value(0).toInt();
}

int sqlHandler::sqlGetGameP1(int gameID){
    QSqlQuery query;
    QString querystring;

    query.prepare("SELECT Player1 FROM Games WHERE [Game ID] = ?");
    query.bindValue(0, gameID);

    query.exec();
    query.first();

    return query.value(0).toInt();
}

int sqlHandler::sqlGetGameP2(int gameID){
    QSqlQuery query;
    QString querystring;

    query.prepare("SELECT Player2 FROM Games WHERE [Game ID] = ?");
    query.bindValue(0, gameID);

    query.exec();
    query.first();

    return query.value(0).toInt();
}



//Setter: needs to set final player info into SQLite
void sqlHandler::sqlSetPlayerFinal(QString& playerID, player Player) {


}

//Setter: needs to add a new player to the SQLite db
