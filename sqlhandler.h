#ifndef SQLHANDLER_H
#define SQLHANDLER_H
#include "player.h"
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>

class sqlHandler
{
public:
    sqlHandler(const QString& path);

    string sqlGetFirstName(int playerID);
    string sqlGetLastName(int playerID);
    string sqlGetHometown(int playerID);
    int sqlGetRanking(int playerID);
    float sqlGetAvg180s(int playerID);
    float sqlGetAvg180sSeason(int playerID);
    int sqlGetLastGameWin(int playerID);
    float sqlGetAvgThrowScore(int playerID);
    float sqlGetAvgThrowScoreSeason(int playerID);
    int sqlGetTurnScoreHi(int playerID);
    int sqlGetTurnScoreLo(int playerID);

    player sqlGetPlayer(int playerID1, int playerID2);
    string* sqlGetPlayerList();
    void sqlSetPlayerFinal(QString& playerID, player Player);
private:
    QSqlDatabase m_db;
};

#endif // SQLHANDLER_H
