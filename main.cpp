#include "NetworkRunner.h"

int main()
{
    NetworkRunner netRunner;
    netRunner.loadConfigurations();
    netRunner.execute();

    return 0;
}
