#include "NetworkRunner.h"

NetworkRunner::NetworkRunner()
{
    //ctor
}

NetworkRunner::~NetworkRunner()
{
    //dtor
}

void NetworkRunner::loadConfigurations()
{
    ifstream netFile;
    netFile.open(NetworkRunner::NET_CONF_PATH);
    string line;

    if (netFile.is_open())
    {
        while (!netFile.eof())
        {
            getline(netFile, line);
            cout << line;
        }
    }

    netFile.close();
}
