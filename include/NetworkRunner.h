#ifndef NETWORKRUNNER_H
#define NETWORKRUNNER_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class NetworkRunner
{
    public:
        NetworkRunner();
        virtual ~NetworkRunner();
        void loadConfigurations();

    protected:

    private:
        const string NET_CONF_PATH = "../net.conf";
        enum NetType { PERCEPTRON = 1, ADALINE };

        NetworkRunner::NetType netType;
        float learningRate;
        float bias;
        float thresholdError;
        unsigned int maxIterations;
};

#endif // NETWORKRUNNER_H
