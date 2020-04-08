#include "matchstartdata.h"
#include "datahandler.h"

MatchStartData::MatchStartData()
{
    DataHandler my_Handler;
    startScore =
    legNumber =
    matchNumber =
    playersParticipating[0] =
    playersParticipating[1] =

}

string MatchStartData::dataGet(string request){
    string answer;
    if (request == "startScore"){
        answer = to_string(startScore);
    }
    else if (request == "legNumber"){
        answer = to_string(legNumber);
    }
    else if (request == "matchNumber"){
        answer = to_string(matchNumber);
    }
    else if (request == "playersParticipating1"){
        answer = playersParticipating[0];
    }
    else if (request == "playersParticipating2"){
        answer = playersParticipating[1];
    }
    return answer;
}
