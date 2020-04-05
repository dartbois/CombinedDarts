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
    player sqlGetPlayer(QString& name);
    void sqlSetPlayer(QString& name);
private:
    QSqlDatabase m_db;
};

#endif // SQLHANDLER_H
