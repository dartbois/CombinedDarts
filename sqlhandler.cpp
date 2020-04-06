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
    }
    else{
        //Create tables
        //TODO: make sure tables don't exist before we create new ones
        QSqlQuery query("CREATE TABLE players ([Player ID] INTEGER NOT NULL UNIQUE PRIMARY KEY AUTOINCREMENT, [First Name] STRING NOT NULL, [Last Name] STRING NOT NULL, Hometown STRING NOT NULL, Ranking INTEGER NOT NULL UNIQUE, [Avg 180s] REAL, [Avg 180s (Season)] REAL, [Last Game Win] INTEGER REFERENCES Games ([Game ID]), [Avg Throw Score] REAL, [Avg Throw Score (Season)] REAL, [Turn Score High] INTEGER, [Turn Score Low] INTEGER);");
        QSqlQuery query2("CREATE TABLE games ([Game ID] INTEGER UNIQUE NOT NULL PRIMARY KEY AUTOINCREMENT, [Game Name] STRING NOT NULL UNIQUE, Date DATE NOT NULL, Location STRING NOT NULL, [Start Score] INTEGER DEFAULT (501) NOT NULL, [Max # Legs] INTEGER NOT NULL, Player1 INTEGER NOT NULL REFERENCES players ([Player ID]), Player2 INTEGER NOT NULL REFERENCES players ([Player ID]), Winner INTEGER REFERENCES players ([Player ID]));");
        query.exec();
        query2.exec();
    }
}


//Getter: Given two competing player IDs, fills a player class with those players' information
player sqlHandler::sqlGetPlayer(int playerID1, int playerID2) {
    player myPlayer;

    QSqlQuery query;
    QString querystring[2];

    // 1 - Get Players' First Names
    querystring[0] = "SELECT [First Name] FROM players WHERE [Player ID] = ";
    querystring[0].append(playerID1);
    querystring[1] = "SELECT [First Name] FROM players WHERE [Player ID] = ";
    querystring[1].append(playerID2);
    query.exec(querystring[0]);
    myPlayer.playerFirst[0] = query.value(0).toString().toStdString();
    query.exec(querystring[1]);
    myPlayer.playerFirst[1] = query.value(0).toString().toStdString();

    // 2 - Get Players' Last Names
    querystring[0] = "SELECT [Last Name] FROM players WHERE [Player ID] = ";
    querystring[0].append(playerID1);
    querystring[1] = "SELECT [Last Name] FROM players WHERE [Player ID] = ";
    querystring[1].append(playerID2);
    query.exec(querystring[0]);
    myPlayer.playerLast[0] = query.value(0).toString().toStdString();
    query.exec(querystring[1]);
    myPlayer.playerLast[1] = query.value(0).toString().toStdString();

    // 3 - Get Players' Hometown
    querystring[0] = "SELECT Hometown FROM players WHERE [Player ID] = ";
    querystring[0].append(playerID1);
    querystring[1] = "SELECT Hometown FROM players WHERE [Player ID] = ";
    querystring[1].append(playerID2);
    query.exec(querystring[0]);
    myPlayer.playerHometown[0] = query.value(0).toString().toStdString();
    query.exec(querystring[1]);
    myPlayer.playerHometown[1] = query.value(0).toString().toStdString();

    // 4 - Get Players' Ranking
    querystring[0] = "SELECT Ranking FROM players WHERE [Player ID] = ";
    querystring[0].append(playerID1);
    querystring[1] = "SELECT Ranking FROM players WHERE [Player ID] = ";
    querystring[1].append(playerID2);
    query.exec(querystring[0]);
    myPlayer.playerRanking[0] = query.value(0).toInt();
    query.exec(querystring[1]);
    myPlayer.playerRanking[1] = query.value(0).toInt();

    // 5 - Get Players' Lifetime avg 180s
    querystring[0] = "SELECT [Avg 180s] FROM players WHERE [Player ID] = ";
    querystring[0].append(playerID1);
    querystring[1] = "SELECT [Avg 180s] FROM players WHERE [Player ID] = ";
    querystring[1].append(playerID2);
    query.exec(querystring[0]);
    myPlayer.playerAvg180s[0] = query.value(0).toFloat();
    query.exec(querystring[1]);
    myPlayer.playerAvg180s[1] = query.value(0).toFloat();

    // 6 - Get Players' Season avg 180s
    querystring[0] = "SELECT [Avg 180s (Season)] FROM players WHERE [Player ID] = ";
    querystring[0].append(playerID1);
    querystring[1] = "SELECT [Avg 180s (Season)] FROM players WHERE [Player ID] = ";
    querystring[1].append(playerID2);
    query.exec(querystring[0]);
    myPlayer.playerAvg180Season[0] = query.value(0).toFloat();
    query.exec(querystring[1]);
    myPlayer.playerAvg180Season[1] = query.value(0).toFloat();

    // 7 - Get Players' Last Game Win (by Game ID)
    querystring[0] = "SELECT [Last Game Win] FROM players WHERE [Player ID] = ";
    querystring[0].append(playerID1);
    querystring[1] = "SELECT [Last Game Win] FROM players WHERE [Player ID] = ";
    querystring[1].append(playerID2);
    query.exec(querystring[0]);
    myPlayer.playerLastWin[0] = query.value(0).toInt();
    query.exec(querystring[1]);
    myPlayer.playerLastWin[1] = query.value(0).toInt();

    // 8 - Get Players' Avg Throw Score
    querystring[0] = "SELECT [Avg Throw Score] FROM players WHERE [Player ID] = ";
    querystring[0].append(playerID1);
    querystring[1] = "SELECT [Avg Throw Score] FROM players WHERE [Player ID] = ";
    querystring[1].append(playerID2);
    query.exec(querystring[0]);
    myPlayer.playerAvgThrow[0] = query.value(0).toFloat();
    query.exec(querystring[1]);
    myPlayer.playerAvgThrow[1] = query.value(0).toFloat();

    // 9 - Get Players' Avg Throw Score for the Season
    querystring[0] = "SELECT [Avg Throw Score (Season)] FROM players WHERE [Player ID] = ";
    querystring[0].append(playerID1);
    querystring[1] = "SELECT [Avg Throw Score (Season)] FROM players WHERE [Player ID] = ";
    querystring[1].append(playerID2);
    query.exec(querystring[0]);
    myPlayer.playerAvgThrowSeason[0] = query.value(0).toFloat();
    query.exec(querystring[1]);
    myPlayer.playerAvgThrowSeason[1] = query.value(0).toFloat();

    // 10 - Get Players' Highest Turn Score
    querystring[0] = "SELECT [Turn Score High] FROM players WHERE [Player ID] = ";
    querystring[0].append(playerID1);
    querystring[1] = "SELECT [Turn Score High] FROM players WHERE [Player ID] = ";
    querystring[1].append(playerID2);
    query.exec(querystring[0]);
    myPlayer.playerTurnScoreHi[0] = query.value(0).toInt();
    query.exec(querystring[1]);
    myPlayer.playerTurnScoreHi[1] = query.value(0).toInt();

    // 11 - Get Players' Lowest Turn Score
    querystring[0] = "SELECT [Turn Score Low] FROM players WHERE [Player ID] = ";
    querystring[0].append(playerID1);
    querystring[1] = "SELECT [Turn Score Low] FROM players WHERE [Player ID] = ";
    querystring[1].append(playerID2);
    query.exec(querystring[0]);
    myPlayer.playerTurnScoreLo[0] = query.value(0).toInt();
    query.exec(querystring[1]);
    myPlayer.playerTurnScoreLo[1] = query.value(0).toInt();

    return myPlayer;
}

//Setter: needs to set final player info into SQLite
void sqlHandler::sqlSetPlayer(QString& playerID, player Player) {


}
