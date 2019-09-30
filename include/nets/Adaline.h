#ifndef ADALINE_H
#define ADALINE_H

#include "NeuralNetwork.h"
#include "../datasets/DataSet.h"

class Adaline : public NeuralNetwork
{
    const float learningDecrease;

    public:
        Adaline(float learningRate, float error, float bias, float* weights, float learningDecrease,
                unsigned int dimension, unsigned int iterations, ActivationFuncion actFunction) :
            NeuralNetwork(bias, weights, dimension, learningRate, error, iterations, actFunction),
            learningDecrease(learningDecrease) {};
        void run(const DataSet* dataSet);
};

#endif // ADALINE_H
