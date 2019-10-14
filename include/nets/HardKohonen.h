#ifndef HARDKOHONEN_H
#define HARDKOHONEN_H

#include "NeuralNetwork.h"
#include <limits>

using namespace std;

class HardKohonen : public NeuralNetwork
{
    public:
        HardKohonen(float learningRate, float error, float bias, float* weights,
                unsigned int dimension, unsigned int iterations, ActivationFuncion actFunction) :
            NeuralNetwork(bias, weights, dimension, learningRate, error, iterations, actFunction) {};
        void run(const DataSet* dataSet);

};

#endif // HARDKOHONEN_H
