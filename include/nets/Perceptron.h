#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include "../datasets/DataSet.h"
#include "NeuralNetwork.h"

class Perceptron : public NeuralNetwork
{
    public:
        Perceptron(float learningRate, float bias, float indefinitionRate, float thresholdError,
                   unsigned int maxIterations, unsigned int dimension,
                   ActivationFuncion actFunction) :
            NeuralNetwork(bias, nullptr, dimension, learningRate, thresholdError,
                          maxIterations, actFunction) {};
        void run(const DataSet* dataSet);
};

#endif // PERCEPTRON_H
