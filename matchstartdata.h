#ifndef MATCHSTARTDATA_H
#define MATCHSTARTDATA_H
#include <string>

using namespace std;

class MatchStartData
{
public:
    MatchStartData();
    int startScore;
    int legNumber;
    int matchNumber;
    string playersParticipating[2];
    string dataGet(string request);

};

#endif // MATCHSTARTDATA_H
