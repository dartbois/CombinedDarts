#ifndef DATAHANDLER_H
#define DATAHANDLER_H
#include <string>
#include "player.h"

using namespace std;


class DataHandler
{
public:
    DataHandler();
    string getData(string request);
    string setData(string request);

    string sqlGet(string request);
    string mathcGet(string request);
    string matchstartGet(string request);
    string playerGet(string request, player myP);
};

#endif // DATAHANDLER_H
