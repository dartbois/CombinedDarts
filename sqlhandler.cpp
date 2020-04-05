#include "sqlhandler.h"
#include "datahandler.h"
#include "player.h"
#include <stdio.h>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>


sqlHandler::sqlHandler(const QString& path) {
    bool failFlag = false;

    m_db = QSqlDatabase::addDatabase("DartLeague");
    m_db.setDatabaseName(path);

    if (!m_db.open())
    {
       failFlag = true;
    }

}

//Getter: needs to get player info from SQLite
player sqlHandler::sqlGetPlayer(QString& name) {
    player myPlayer;
    return myPlayer;
}

//Setter: needs to set final player info into SQLite
void sqlHandler::sqlSetPlayer(QString& name) {


}
