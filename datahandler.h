#ifndef DATAHANDLER_H
#define DATAHANDLER_H
#include <string>
#include "player.h"
#include "mathclass.h"
#include "matchstartdata.h"
#include "scorerview.h"

using namespace std;


class DataHandler
{
public:
    DataHandler();
    /*
    string getData(string request);
    string setData(string request);
*/
    string sqlGet(string request);
    string mathcGet(string request, mathClass myM);
    string matchstartGet(string request, MatchStartData myS);
    string playerGet(string request, player myP);
    void matchGSMtoSV(ScorerView * scW, int scoreStart);
};

#endif // DATAHANDLER_H
