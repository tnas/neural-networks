#ifndef ADALINE_H
#define ADALINE_H

#include "NeuralNetwork.h"
#include "../datasets/DataSet.h"

class Adaline : public NeuralNetwork
{
    public:
        static constexpr float LEARNING_DECREASE = 0.95;

        Adaline(float learningRate, float error, float bias, float* weights,
                unsigned int dimension, unsigned int iterations, ActivationFuncion actFunction) :
            NeuralNetwork(bias, weights, dimension, learningRate, error, iterations, actFunction) {};
        void run(const DataSet* dataSet);
};

#endif // ADALINE_H
