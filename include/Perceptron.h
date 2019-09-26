#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include "DataSet.h"
#include "NeuralNetwork.h"

class Perceptron : public NeuralNetwork
{
    const float indefinitionRate; // delta

    public:
        Perceptron(float learningRate, float bias, float indefinitionRate, float thresholdError,
                   unsigned int maxIterations, unsigned int dimension) :
            NeuralNetwork(bias, nullptr, dimension, learningRate, thresholdError, maxIterations),
            indefinitionRate(indefinitionRate) {};

        int applyActivationFunction(float result);
        void run(const DataSet* dataSet);
};

#endif // PERCEPTRON_H
