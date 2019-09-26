#ifndef ADALINE_H
#define ADALINE_H

#include "NeuralNetwork.h"
#include "DataSet.h"

class Adaline : public NeuralNetwork
{
    float calculateCurrentError();

    public:
        static constexpr float LEARNING_DECREASE = 0.95;

        Adaline(float learningRate, float error, float bias, float* weights,
                unsigned int dimension, unsigned int iterations) :
            NeuralNetwork(bias, weights, dimension, learningRate, error, iterations) {};
        int applyActivationFunction(float result);
        void run(const DataSet* dataSet);
};

#endif // ADALINE_H
