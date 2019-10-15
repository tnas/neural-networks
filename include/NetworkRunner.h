#ifndef NETWORKRUNNER_H
#define NETWORKRUNNER_H

#include "nets/NeuralNetwork.h"
#include "nets/Perceptron.h"
#include "nets/Adaline.h"
#include "nets/HardKohonen.h"
#include "datasets/DataSetFactory.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class NetworkRunner
{
    public:
        NetworkRunner();
        virtual ~NetworkRunner();
        void loadConfigurations();
        void printConfigurations();
        void execute();

    protected:

    private:
        const string COMMENT_CHARACTER = "#";
        const string NET_CONF_PATH = "net.conf";
        const string CONF_PARAM_NET = "NET";
        const string CONF_PARAM_LEARN_RATE = "LEARN_RATE";
        const string CONF_PARAM_BIAS = "BIAS";
        const string CONF_PARAM_ERROR = "ERROR";
        const string CONF_PARAM_ITERATIONS = "ITERATIONS";
        const string CONF_PARAM_DIMENSION = "INPUT_DIMENSION";
        const string CONF_PARAM_INDEFINITION_RATE = "INDEFINITION_RATE";
        const string CONF_PARAM_LEARN_DECREASE_RATE = "LEARN_DECREASE_RATE";
        const string CONF_PARAM_ACTIVATION_FUNCTION = "ACTIVATION_FUNCTION";
        const string CONF_PARAM_DATA_SET = "DATA_SET";
        const string CONF_PARAM_WEIGHTS = "WEIGHTS";
        const string CONF_PARAM_RADIUS = "RADIUS";
        const string CONF_PARAM_RADIUS_DECREASE_RATE = "RADIUS_DECREASE_RATE";

        enum NetType { PERCEPTRON = 1, ADALINE, MLP, HEBBE, HARD_KOHONEN };

        DataSetFactory dsFactory;
        NetworkRunner::NetType netType;
        float learningRate;
        float bias;
        float thresholdError;
        unsigned int maxIterations;
        unsigned int inputDimension;
        float indefinitionRate;
        float learningDecrease;
        float* weights;
        unsigned int radius;
        float radiusDecreaseRate;
        NeuralNetwork::ActivationFuncion activationFunction;
        DataSetFactory::DataSetType dsType;
};

#endif // NETWORKRUNNER_H
