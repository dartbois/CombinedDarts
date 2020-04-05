#ifndef DATAHANDLER_H
#define DATAHANDLER_H
#include <string>

using namespace std;


class DataHandler
{
public:
    DataHandler();
    string getData(string request);
    string setData(string request);
private:
    string sqlGet(string request);
    string mathcGet(string request);
    string matchstartGet(string request);
    string playerGet(string request);
};

#endif // DATAHANDLER_H
