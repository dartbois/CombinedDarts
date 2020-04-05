#include "matchstartdata.h"
#include "datahandler.h"

MatchStartData::MatchStartData()
{
    DataHandler my_Handler;
    startScore = stoi(my_Handler.getData("sqlhandler:startScore"));
    legNumber = stoi(my_Handler.getData("sqlhandler:legNumber"));
    matchNumber = stoi(my_Handler.getData("sqlhandler:matchNumber"));
    playersParticipating[0] = my_Handler.getData("sqlhandler:playPart1");
    playersParticipating[1] = my_Handler.getData("sqlhandler:playPart2");

}
